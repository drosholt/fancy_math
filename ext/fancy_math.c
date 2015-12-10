#include <ruby.h>
#include "add.h"
#include "complex.h"
#include "no_gvl.h"
#include "ruby_executor.h"
#include "time_reporter.h"

static VALUE call_add(VALUE rb_self, VALUE rb_a, VALUE rb_b) {
  // Convert ruby values to C integers
  int a = FIX2INT(rb_a);
  int b = FIX2INT(rb_b);

  // Call C function
  int result = add(a, b);

  // Convert C integer into ruby value and return it
  VALUE rb_result = INT2FIX(result);
  return rb_result;
}

static VALUE call_complex_operation(VALUE rb_self, VALUE rb_id, VALUE rb_occurrence) {
  int id = FIX2INT(rb_id);
  int occurrence = FIX2INT(rb_occurrence);

  report_time("Enter", id, occurrence);
  complex_operation();
  report_time("Leave", id, occurrence);

  return Qtrue;
}

// Function must be named Init_<gem name>"
int Init_fancy_math() {
  // Create new module to contain our method
  VALUE rb_module = rb_define_module("FancyMath");

  // Include the FancyMath logic that is coded in ruby
  rb_require("fancy_math/threads");
  rb_require("fancy_math/ruby_complex");

  // Add the C "add" method to the FancyMath module
  rb_define_module_function(rb_module, "add", call_add, 2);

  // Add the C "complex_operation" method to the FancyMath module
  rb_define_module_function(rb_module, "complex_operation", call_complex_operation, 2);
  rb_define_module_function(rb_module, "complex_operation_without_gvl", call_complex_operation_without_gvl, 2);
  rb_define_module_function(rb_module, "complex_operation_with_ruby_component", call_complex_operation_with_ruby_component, 2);

  // Initialization complete and successful
  return 0;
}
