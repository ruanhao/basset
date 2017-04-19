#! /usr/bin/env python3
# -*- coding: utf-8 -*-

a = 3
b = 33

print("a: {a}, b: {b}".format(**locals()))
print("a: %(a)s, b: %(b)s" % locals())