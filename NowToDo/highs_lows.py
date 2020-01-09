#!/usr/bin/env python
#-*- coding:utf-8 -*-
# @Time    : 2020/1/9 14:00
# @Author  : Jefferey

import csv
from matplotlib import pyplot as plt

filename = r'C:\Users\Jefferey\Desktop\pyLearning\scrapy\spider\douban.csv'
with open(filename) as f:
    reader = csv.reader(f)
    header_row = next(reader)
    #print(header_row)

    for index, column_header in enumerate(header_row):
        print(index, column_header)

    highs = []
    for row in reader:
        high = float(row[1])*10
        highs.append(high)

    print(highs)

fig = plt.figure(dpi=128, figsize=(10,6))
plt.plot(highs[:30], c='red')

plt.title("Daily high temperatures, July 2014", fontsize=24)
plt.xlabel("",fontsize=16)
plt.ylabel("Temperature (F)", fontsize=16)
plt.tick_params(axis='both', which='major', labelsize=16)

plt.show()