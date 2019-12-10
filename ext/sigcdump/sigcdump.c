#include "sigcdump.h"

extern void rb_dump_backtrace_with_lines(int num_traces, void **traces);
static VALUE rb_mSigcdump;

static VALUE
rb_sigcdump_dump(VALUE klass, VALUE path)
{
    rb_dump_backtrace_with_lines(0, NULL);
    return Qnil;
}

void
Init_sigcdump(void)
{
    rb_mSigcdump = rb_define_module("Sigcdump");
    rb_define_singleton_method(rb_mSigcdump, "dump", rb_sigcdump_dump, 1);
}
