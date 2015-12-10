#include <ruby.h>
#include "add.h"
#include "complex.h"

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

static VALUE call_complex_operation(VALUE rb_self) {
  complex_operation();
  return Qtrue;
}

// Function must be named Init_<gem name>"
int Init_fancy_math() {
  // Create new module to contain our method
  VALUE rb_module = rb_define_module("FancyMath");

  // Add the C "add" method to the FancyMath module
  rb_define_module_function(rb_module, "add", call_add, 2);

  // Add the C "complex_operation" method to the FancyMath module
  rb_define_module_function(rb_module, "complex_operation", call_complex_operation, 0);

  // Initialization complete and successful
  return 0;
}
