#! /usr/bin/env ruby
# coding: utf-8

##        E
##       / \
##      D   H
##     /   /
##    B   F
##   / \   \
##  A   C   G


class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left  = left
    @right = right
  end
  attr_accessor :value, :left, :right
end

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

def in_tranverse2(tree)
  root = tree
  stack = [root]
  while (not stack.length.zero?)
    if root.nil?
      root =  stack.pop
      print "#{root.value} "
      root = root.right
    else
      stack.push(root)
      root = root.left
    end
  end
end

def in_tranverse3(tree)
  stack = [tree]
  result = []
  while not stack.length.zero?
    root = stack.pop
    if not root.nil?
      stack << root.right
      stack << root
      stack << root.left
    else
      v = stack.pop
      print "#{v.value} " if not v.nil? ## this 'if' is needed
    end
  end
end

def pre_tranverse2(tree)
  stack = [tree]
  while true
    root = stack.pop
    if root.nil?
      return
    end
    print "#{root.value} "
    stack << root.right if not root.right.nil?
    stack << root.left if not root.left.nil?
  end
end

## 因为后序遍历的顺序是：左子树->右子树->根节点
## 在前序遍历的代码中，当访问完当前节点后，先把当前节点的左子树入栈，再把右子树入栈
## 这样最终得到的顺序为：根节点->右子树->左子树，刚好是后序遍历倒过来的版本
## 于是把这个结果做一次翻转即为真正的后序遍历
def post_tranverse2(tree)
  stack = [tree]
  result = []
  while true
    root = stack.pop
    if root.nil?
      break
    end
    result << root
    stack << root.left if not root.left.nil?
    stack << root.right if not root.right.nil?
  end
  for n in result.reverse
    print "#{n.value} "
  end
end

def layer_tranverse(tree)
  stack = [tree]
  while not stack.size.zero?
    root = stack.shift
    print "#{root.value} "
    stack << root.left if not root.left.nil?
    stack << root.right if not root.right.nil?
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




def transpose(pre, mid)
  #pre = 'EDBACHFG'
  #mid = 'ABCDEFGH'

  root = Node.new(pre[0])
  return root if (pre == mid) and (pre.length == 1)
  idx = mid.index(pre[0])
  if idx == 0
    left = nil ## in case pre='AC' and mid='AC'
  else
    left = transpose(pre[1..(idx)], mid[0..(idx-1)])
  end

  right = transpose(pre[(idx+1)..-1], mid[(idx+1)..-1])
  root.left = left
  root.right = right
  return root
end

if __FILE__ == $0
  init_tree
  print 'pre   tranverse :  '
  pre_tranverse(@tree)
  puts
  print 'pre   tranverse2:  '
  pre_tranverse2 @tree
  puts
  print 'post  tranverse :  '
  post_tranverse(@tree)
  puts
  print 'post  tranverse2:  '
  post_tranverse2(@tree)
  puts
  print 'in    tranverse :  '
  in_tranverse(@tree)
  puts
  print 'in    tranverse2:  '
  in_tranverse2(@tree)
  puts
  print 'in    tranverse3:  '
  in_tranverse3 @tree
  puts
  print 'layer tranverse :  '
  layer_tranverse @tree
  puts
  print 'transpose post  :  '
  #r = transpose 'EDBACHFG', 'ABCDEFGH'
  r = transpose 'AC', 'AC'
  puts
  post_tranverse r

end