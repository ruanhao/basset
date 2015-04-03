#! /usr/bin/env ruby

@ruler = []

def mark(pos, h)
  @ruler[pos] = h
end

def ruler(l, r, h)
  m = (l+r)/2
  if h > 0
    ruler(l, m, h-1)
    mark(m, h)
    ruler(m, r, h-1)
  end
end

def print_ruler
  @ruler.each do |v|
    puts '=' * v if not v.nil?
  end
end

if __FILE__ == $0
  ruler(0, 2**6, 6)
  print_ruler
end