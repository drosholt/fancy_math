#include <ruby.h>
#include <ruby/thread.h>
#include "complex.h"
#include "time_reporter.h"

static void *thread_call_complex_operation_without_gvl(void *ptr) {
  complex_operation();
  return (void *) Qtrue;
}

VALUE call_complex_operation_without_gvl(VALUE rb_self, VALUE rb_id, VALUE rb_occurrence) {
  int id = FIX2INT(rb_id);
  int occurrence = FIX2INT(rb_occurrence);

  report_time("Enter", id, occurrence);
  rb_thread_call_without_gvl(&thread_call_complex_operation_without_gvl, NULL, NULL, NULL);
  report_time("Leave", id, occurrence);

  return Qtrue;
}
