#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division, print_function
import sys

srci = sys.stdin

eps = 1e-7
n, k = map(int, srci.readline().rstrip().split())
a = map(int, srci.readline().rstrip().split())
asum = sum(a)
cnt = len(a)
while asum / cnt + 0.5 + eps < k:
    asum = asum + k
    cnt = cnt + 1

print("{0}".format(cnt-len(a)))
