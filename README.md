# FancyMath

A small sample project to demonstrate the boundaries of MRI Ruby's GIL/GVL.  The git history provides good documentation for how this project was built.

## Usage

It is not recommended that you install this gem.  Use bin/console to start an IRB session that will automatically have loaded the FancyMath module.

There is only one core module function available, FancyMath.add.  Use it with integers: ```FancyMath.add(1, 2)```

For testing the GIL boundaries, the following functions/methods are available.  All of them are available on the FancyMath module; none of them take parameters.  They all ultimately call a "complex_operation" function, which emulates complexity by sleeping for 1 second.
* FancyMath.threaded_complex_operation - execute multiple threads against a GIL-bound operation.  Thread executions will not overlap.
* FancyMath.threaded_ruby_complex_operation - a partial ruby implementation of a threaded complex operation.  Threads will overlap, though the execution of complex_operation will be serial.
* FancyMath.threaded_complex_operation_without_gvl - execute multiple threads against an operation, where the GIL is freed for other use when executing complex_operation.
* FancyMath.threaded_complex_operation_with_ruby_component - execute multiple threads against a C extension, which in turn calls a Ruby method.  Thread executions will overlap.

## Development

After checking out the repo, run `bin/setup` to install dependencies. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/rosholt/fancy_math. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [Contributor Covenant](contributor-covenant.org) code of conduct.


## License

The gem is available as open source under the terms of the [MIT License](http://opensource.org/licenses/MIT).

