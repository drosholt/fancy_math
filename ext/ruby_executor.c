#include <ruby.h>
#include "time_reporter.h"

VALUE call_complex_operation_with_ruby_component(VALUE rb_self, VALUE rb_id, VALUE rb_value) {
  int id = FIX2INT(rb_id);
  int value = FIX2INT(rb_value);

  VALUE rb_module = rb_define_module("FancyMath");

  report_time("Enter", id, value);
  rb_funcall(rb_module, rb_intern("ruby_complex_operation"), 0, NULL);
  report_time("Leave", id, value);

  return Qtrue;
}
