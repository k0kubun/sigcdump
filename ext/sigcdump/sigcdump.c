#include "sigcdump.h"

VALUE rb_mSigcdump;

void
Init_sigcdump(void)
{
  rb_mSigcdump = rb_define_module("Sigcdump");
}
