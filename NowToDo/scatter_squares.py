#!/usr/bin/env python
#-*- coding:utf-8 -*-
# @Time    : 2020/1/9 13:13
# @Author  : Jefferey

import matplotlib.pyplot as plt

x_values = [1, 2, 3, 4, 5]
y_values = [1, 4, 9, 16, 25]
plt.scatter(x_values, y_values, s=100)

plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize = 14)
plt.ylabel("Square og Value", fontsize = 14)

#设置刻度标记大小
plt.tick_params(axis='both', which='major', labelsize=14)
plt.show()
