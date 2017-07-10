#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division, print_function
import math
import sys
srci = sys.stdin

n, vb, vs = map(int, srci.readline().rstrip().split())
stops = map(int, srci.readline().rstrip().split())
ux, uy = map(int, srci.readline().rstrip().split())

eps = 1e-7
mn = -1
pos = -1
mnd = -1
for i, x in enumerate(stops):
    if i == 0:
        continue
    t = x / vb
    dist = math.sqrt((x-ux)*(x-ux) + uy * uy)
    t = t + dist / vs

    if mn <= 0 or t+eps < mn:
        mn = t
        pos = i
        mnd = dist
    elif abs(t - mn) < eps and dist + eps < mnd:
        mnd = dist
        pos = i

print("{0}".format(pos+1))
