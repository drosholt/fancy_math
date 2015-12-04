#include <ruby.h>
#include "add.h"

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

// Function must be named Init_<gem name>"
int Init_fancy_math() {
  // Create new module to contain our method
  VALUE rb_module = rb_define_module("FancyMath");

  // Add the C method to the FancyMath module
  rb_define_module_function(rb_module, "add", call_add, 2);

  // Initialization complete and successful
  return 0;
}
