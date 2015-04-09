#! /usr/bin/env ruby



class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left  = left
    @right = right
  end
  attr_accessor :value, :left, :right
end

@tree = nil
@stack = nil
def init_tree
  node_a = Node.new(:A, nil, nil)
  node_c = Node.new(:C, nil, nil)
  node_b = Node.new(:B, node_a, node_c)
  node_d = Node.new(:D, node_b, nil)
  node_g = Node.new(:G, nil, nil)
  node_f = Node.new(:F, nil, node_g)
  node_h = Node.new(:H, node_f, nil)
  node_e = Node.new(:E, node_d, node_h)
  @tree = node_e
end

def pre_tranverse(tree)
  if tree.nil?
    return
  end
  print "#{tree.value} "
  pre_tranverse(tree.left)
  pre_tranverse(tree.right)
end

def post_tranverse(tree)
  if tree.nil?
    return
  end
  post_tranverse(tree.left)
  post_tranverse(tree.right)
  print "#{tree.value} "
end

def in_tranverse(tree)
  if tree.nil?
    return
  end
  in_tranverse(tree.left)
  print "#{tree.value} "
  in_tranverse(tree.right)
end


def pre_tranverse2(tree)
  @stack ||= [tree]
  while true
    root = @stack.pop
    if root.nil?
      return
    end
    print "#{root.value} "
    @stack << root.left if not root.left.nil?
    @stack << root.right if not root.right.nil?
  end
end

def seq(n)
  for i in (1..n)
    nzero = 0
    while (i % 2 == 0)
      nzero += 1
      i /= 2
    end
    print "#{nzero} " if not nzero.zero?
  end
  puts
end

if __FILE__ == $0
  seq 32
  init_tree
  puts 'pre tranverse:'
  pre_tranverse(@tree)
  puts
  puts 'post tranverse:'
  post_tranverse(@tree)
  puts
  puts 'in tranverse:'
  in_tranverse(@tree)
  puts
  pre_tranverse2 @tree
end