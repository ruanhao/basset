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
  puts ary.to_s
end

if __FILE__ == $0
  mscreen([11], [2, 4, 6])
end