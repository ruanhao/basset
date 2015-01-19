# coding: utf-8
## A block created with lambda behaves like a method when you use return and simply exits the block, handing control back to the calling method.
def a_method
  lambda { return "we just returned from the block" }.call
  return "we just returned from the calling method"
end
puts a_method
## A block created with Proc.new behaves like it’s a part of the calling method when return is used within it, and returns from both the block itself as well as the calling method.
def a_method
  Proc.new { return "we just returned from the block" }.call
  return "we just returned from the calling method"
end
puts a_method

## As a consequence, Proc.new is something that’s hardly ever used to explicitly create blocks because of these surprising return semantics.
## It is recommended that you avoid using this form unless absolutely necessary.






## The -> literal form is a shorter version of Kernel#lambda.
## The following two lines produce identical results.
short = ->(a, b) { a + b }
puts short.call(2, 3)

long = lambda { |a, b| a + b }
puts long.call(2, 3)

## Kernel#proc factory method is identical to Proc.new
## The following two lines produce identical results.
short = proc { |a, b| a + b }
puts short.call(2, 3)

long = Proc.new { |a, b| a + b }
puts long.call(2, 3)