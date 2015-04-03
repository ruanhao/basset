#! /usr/bin/env ruby

@pole_odd = [{-1 => 'A -> C', 1 => 'C -> A'},
             {-1 => 'B -> A', 1 => 'A -> B'},
             {-1 => 'C -> B', 1 => 'B -> C'}]

@pole_even = [{-1 => 'A -> B', 1 => 'B -> A'},
              {-1 => 'C -> A', 1 => 'A -> C'},
              {-1 => 'B -> C', 1 => 'C -> B'}]

def n_zeros(num)
  t = 0
  while (num % 2 == 0)
    t += 1
    num >>= 1
  end
  return t
end


def hanoi(height)
  pole = height%2 == 0 ? @pole_even : @pole_odd
  nsteps = 0
  number = 1
  while nsteps < 2**height-1
    nz = n_zeros(number)
    if nz > 0
      nsteps += 1
      puts pole.first[(-1)**nz]
      pole.rotate!
    end
    number += 1
  end
end



if __FILE__ == $0
  hanoi(10)
end