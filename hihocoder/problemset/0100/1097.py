#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin
#srci = open('data.in')

n = int(srci.readline().rstrip())

dist = []
for i in xrange(n):
    dist.append(map(int, srci.readline().rstrip().split()))

dist_sum = 0
pick = [False] * n

mnd = []
for i in xrange(n):
    mnd.append(dist[0][i])

for i in xrange(n):
    mn = 0x7fffffff
    pos = -1
    for j in xrange(n):
        if (not pick[j]) and mnd[j] < mn:
            mn = mnd[j]
            pos = j
    pick[pos] = True
    dist_sum += mnd[pos]

    for j in xrange(n):
        mnd[j] = min(mnd[j], dist[pos][j])

print("{0}".format(dist_sum))
