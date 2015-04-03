#! /usr/bin/env ruby

def dc_max(ary)
  l = ary.size

  if l == 1
    return ary.max
  else
    ## It is important to choose l/2-1
    return [dc_max(ary[0..(l/2-1)]), dc_max(ary[(l/2)..(l-1)])].max
  end
end


if __FILE__ == $0
  ary = [3, 2, 5, 7, 8, 3]
  ret = dc_max ary
  puts ret
end