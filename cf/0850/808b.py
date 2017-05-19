#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
import sys
srci = sys.stdin

n, k = map(int, srci.readline().rstrip().split())
t = map(int, srci.readline().rstrip().split())

tsum = 0
ssum = 0
l = 0
r = 0
for i in xrange(k-1, n, 1):
    while r <= i:
        tsum += t[r]
        r += 1

    while l < i-k+1:
        tsum -= t[l]
        l += 1

    ssum = ssum + tsum

ans = ssum / (n-k+1)
print("{:.7f}".format(ans))
