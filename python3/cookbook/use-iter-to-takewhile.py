#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# iter(object[, sentinel])

# If the second argument, sentinel, is given, then object must be a callable object.
# The iterator created in this case will call object with no arguments for each call to its __next__() method;
# if the value returned is equal to sentinel, StopIteration will be raised, otherwise the value will be returned.

import random

def my_fun():
    return random.randint(0, 30)

for i in iter(my_fun, 29):
    print(i)


# with open('mydata.txt') as fp:
#     for line in iter(fp.readline, ''):
#         process_line(line)