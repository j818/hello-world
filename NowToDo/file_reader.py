#!/usr/bin/env python
#-*- coding:utf-8 -*-
# @Time    : 2020/1/8 23:39
# @Author  : Jefferey

with open('pi_digits.txt') as file_object:
    contents = file_object.read()

print(type(contents))
'''   
    lines = file_object.readlines()

for line in lines:
    print(line.rstrip())
print(type(lines))
'''