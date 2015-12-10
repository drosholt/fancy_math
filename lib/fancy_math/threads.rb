require 'fancy_math'

module FancyMath
  def self.threaded_complex_operation
    multithread { |i, j| FancyMath.complex_operation(i, j) }
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
