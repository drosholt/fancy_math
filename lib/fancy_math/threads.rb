require 'fancy_math'
require 'fancy_math/ruby_complex'

module FancyMath
  def self.threaded_complex_operation
    multithread { |i, j| FancyMath.complex_operation(i, j) }
  end

  def self.threaded_complex_operation_without_gvl
    multithread { |i, j| FancyMath.complex_operation_without_gvl(i, j) }
  end

  def self.threaded_complex_operation_with_ruby_component
    multithread { |i, j| FancyMath.complex_operation_with_ruby_component(i, j) }
  end

  def self.threaded_ruby_complex_operation
    multithread do |i, j|
      printf("%d|%d|%s|%s\n", i, j, 'Enter', Time.now.to_s)
      FancyMath.ruby_complex_operation
      printf("%d|%d|%s|%s\n", i, j, 'Leave', Time.now.to_s)
    end
  end

  def self.multithread
    threads = []

    5.times.each do |i|
      threads << Thread.new do
        5.times.each do |j|
          yield(i, j)
        end
      end
    end

    threads.map(&:join)
  end

  private_class_method :multithread
end
