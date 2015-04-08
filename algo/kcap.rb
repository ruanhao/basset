#! /usr/bin/env ruby

@items = [{:name => :A, :size => 3, :value => 4},
          {:name => :B, :size => 4, :value => 5},
          {:name => :C, :size => 7, :value => 10},
          {:name => :D, :size => 8, :value => 11},
          {:name => :E, :size => 9, :value => 13}]

@cache = []

@selected = {}

def kcap_cache(cap)
  return @cache[cap] if not @cache[cap].nil?
  max = 0
  @items.each do |item|
    if (cap - item[:size]) >= 0
      t = item[:value] + kcap_cache(cap - item[:size])
      if t >= max
        max = t
        @selected[cap] = item
      end
    end
  end
  @cache[cap] = max
  return max
end

def kcap(cap)
  max = 0
  @items.each do |item|
    if (cap - item[:size]) >= 0
      t = item[:value] + kcap(cap - item[:size])
      max = t if t > max
    end
  end
  return max
end

def show_select(cap)
  result = []
  while not (t = @selected[cap]).nil?
    result << t[:name]
    cap -= t[:size]
  end
  puts result
end

if __FILE__ == $0
  puts kcap_cache(17)
  show_select(17)
  puts "done"
end