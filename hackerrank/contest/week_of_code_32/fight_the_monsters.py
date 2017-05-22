#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
import sys
srci = sys.stdin

n, hit, t = map(int, srci.readline().rstrip().split())
h = map(int, srci.readline().rstrip().split())
h.sort()

cnt = 0
for i in xrange(n):
    need = h[i] // hit + (1 if (h[i] % hit) != 0 else 0)
    if (need <= t):
        cnt += 1

    t = max(0, t-need)
    if t <= 0:
        break

print("{0}".format(cnt))
