#!/usr/bin/env python
#-*- coding:utf-8 -*-
# @Time    : 2020/1/9 13:17
# @Author  : Jefferey

import matplotlib.pyplot as plt

x_values = list(range(1, 1001))
y_values = [x**2 for x in x_values]
plt.scatter(x_values, y_values, c=y_values, cmap=plt.cm.Blues, edgecolors='none', s=40)

plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize = 14)
plt.ylabel("Square og Value", fontsize = 14)
#设置刻度标记大小
plt.tick_params(axis='both', which='major', labelsize=14)

plt.axis([0, 1100, 0, 1100000])
#plt.show()
plt.savefig('squares_plot.png', bbox_inches='tight')