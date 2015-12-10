#ifndef NO_GVL_H
#define NO_GVL_H

#include <ruby.h>

VALUE call_complex_operation_without_gvl(VALUE rb_self, VALUE rb_id, VALUE rb_value);

#endif
