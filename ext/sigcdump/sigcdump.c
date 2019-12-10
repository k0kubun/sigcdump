#include <errno.h>
#include <execinfo.h>
#include <fcntl.h>
#include "sigcdump.h"

extern void rb_dump_backtrace_with_lines(int num_traces, void **traces);
static VALUE rb_mSigcdump;

static void
dump_to_stderr(void)
{
#define MAX_NATIVE_TRACE 1024
    static void *trace[MAX_NATIVE_TRACE];
    int n = (int)backtrace(trace, MAX_NATIVE_TRACE);
#if (defined(USE_ELF) || defined(HAVE_MACH_O_LOADER_H)) && defined(HAVE_DLADDR) && !defined(__sparc)
    rb_dump_backtrace_with_lines(n, trace);
#else
    char **syms = backtrace_symbols(trace, n);
    if (syms) {
	int i;
	for (i=0; i<n; i++) {
	    fprintf(stderr, "%s\n", syms[i]);
	}
	free(syms);
    }
#endif
    fprintf(stderr, "\n");
}

/*
 * When path is:
 *   "-" => stdout
 *   "+" => stderr
 *   other String => dump to the path
 *
 * IO object is not supported yet.
 */
static VALUE
rb_sigcdump_dump_internal(VALUE klass, VALUE path)
{
    int err = dup(STDERR_FILENO);
    if (strcmp("-", RSTRING_PTR(path)) == 0) {
        dup2(STDOUT_FILENO, STDERR_FILENO);
    }
    else if (strcmp("+", RSTRING_PTR(path)) == 0) {
        // none
    }
    else {
        int fd = open(RSTRING_PTR(path), O_CREAT|O_WRONLY|O_APPEND, 0644);
        if (fd < 0) {
            fprintf(stderr, "Failed to open %s: %s\n", "/tmp/hello", strerror(errno));
            return Qfalse;
        }
        dup2(fd, STDERR_FILENO);
        close(fd);
    }

    dump_to_stderr();

    dup2(err, STDERR_FILENO);
    close(err);
    return Qtrue;
}

void
Init_sigcdump(void)
{
    rb_mSigcdump = rb_define_module("Sigcdump");
    rb_define_singleton_method(rb_mSigcdump, "dump_internal", rb_sigcdump_dump_internal, 1);
}
