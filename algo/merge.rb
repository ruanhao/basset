#! /usr/bin/env ruby


def mscreen(ary1, ary2)
  ary = *ary1, *ary2
  i, j, k = 0, 0, 0
  while i < ary1.length and j < ary2.length
    ary[k] = [ary1[i], ary2[j]].min
    ary1[i] < ary2[j] ? i += 1 : j += 1
    k += 1
  end
  ary[k..-1] = ary1[i..-1]  if i < ary1.length
  return ary
end

def worker(ary)
  return ary if ary.length == 1
  m = ary.length/2 - 1
  ary1 = worker(ary[0..m])
  ary2 = worker(ary[m+1..-1])
  return mscreen(ary1, ary2)
end

if __FILE__ == $0
  puts worker([9, 1,2, 5, 3]).to_s
end