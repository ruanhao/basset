#! /usr/bin/env ruby


def init_expr(ary, polyhash)
  ary ||= []
  polyhash.each do |exp, co|
    ary[exp] = co
  end
end

def do_compute(expr1, expr2)
  ret = []
  (0...expr1.length).each do |i1|
    (0...expr2.length).each do |i2|
      if (not expr1[i1].nil?) and (not expr2[i2].nil?)
        ret[i1 + i2] = expr1[i1] * expr2[i2]
      end
    end
  end
  retstr = ''
  ret.each_with_index do |v, idx|
    if not v.nil?
      retstr = case idx
               when 0
                 "#{v}"
               when 1
                 "#{v}x"
               else
                 "#{v}x^#{idx}"
               end + (idx == 0 ? "" : " + ") + retstr
    end
  end
  retstr
end

def poly
  expr1, expr2 = [], []
  init_expr(expr1, 5 => 2, 2 => 1, 0 => 1)
  init_expr(expr2, 1 => 6, 0 => 5)
  retstr = do_compute expr1, expr2
  puts retstr
end

if __FILE__ == $0
  poly
end