#! /usr/bin/env ruby




def hanoi(n, left, middle, right)
  return if n.zero?
  hanoi(n - 1, left, right, middle)
  puts "#{left} -> #{right}"
  hanoi(n - 1, middle, left, right)
end

if __FILE__ == $0
  hanoi(5, 'A', 'B', 'C')
end