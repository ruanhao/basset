#! /usr/bin/env ruby

def partition(a, l, r)
  i = l-1; j = r; v = a[r]
  while true
    while a[i+=1] < v; end
    while v < a[j-=1]; break if j == l; end
    break if i >= j
    a[i], a[j] = a[j], a[i]
  end
  a[i], a[r] = a[r], a[i]
  return i
end

def quicksort(a, l, r)
  return if r <= l
  i = partition(a, l, r)
  quicksort(a, l, i-1)
  quicksort(a, i+1, r)
end

def quicksort2(a, l, r)
  s = []
  s.push r; s.push l
  while not s.empty?
    l = s.pop; r = s.pop
    next if r <= l
    i = partition(a, l, r)
    s.push i-1; s.push l
    s.push r; s.push i+1
  end
end


if __FILE__ == $0
  ary = [1, 7, 3, 9, 3, 98, 2, 99]
  quicksort2(ary, 0, ary.length-1)
  puts ary.to_s
end