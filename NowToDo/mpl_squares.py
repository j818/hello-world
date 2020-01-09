#!/usr/bin/env python
#-*- coding:utf-8 -*-
# @Time    : 2020/1/9 13:09
# @Author  : Jefferey

import matplotlib.pyplot as plt

input_values = [1, 2, 3, 4, 5]
squares = [1, 4, 9, 16, 25]
plt.plot(input_values, squares, linewidth=5)

plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize = 14)
plt.ylabel("Square og Value", fontsize = 14)

#设置刻度标记大小
plt.tick_params(axis='both', labelsize=14)
plt.show()