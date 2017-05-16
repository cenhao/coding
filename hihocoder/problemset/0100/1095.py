#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
import sys
srci = sys.stdin

n, k = map(int, srci.readline().rstrip().split())
d = map(int, srci.readline().rstrip().split())

l = 0
r = 100000

while l <= r:
    m = (l + r) // 2
    cnt_hi = 0
    cnt_ho = 0
    water = 0
    for i in xrange(n):
        water += m
        if water <= d[i]:
            cnt_hi += 1
        else:
            cnt_ho += 1
        water = max(0, water - d[i])

    if (cnt_ho > cnt_hi):
        r = m - 1
    else:
        l = m + 1

print("{0}".format(l))
