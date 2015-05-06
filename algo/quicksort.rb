#! /usr/bin/env ruby

def partition(array, l, r)
  i = l
  j = r-1
  v = array[r]
  while true
    while array[i] < v
      i += 1
    end
    while v < array[j]
      break if j == 1
      j -= 1
    end
    break if i >= j
    array[i], array[j] = array[j], array[i]
  end
  array[i], array[r] = array[r], array[i]
  return i
end

def quicksort(array, l, r)
  return if r <= l
  i = partition(array, l, r)
  quicksort(array, l, i-1)
  quicksort(array, i+1, r)
end


if __FILE__ == $0
  ary = [1, 7, 3, 9, 3, 98, 2, 99]
  quicksort(ary, 0, ary.length-1)
  puts ary.to_s
end