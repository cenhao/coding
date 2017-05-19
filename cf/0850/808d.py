#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
from collections import Counter
import sys
srci = sys.stdin

n = int(srci.readline().rstrip())
a = map(int, srci.readline().rstrip().split())

asum = 0L
for i in xrange(n):
    asum += a[i]

if (asum & 1) != 0:
    print("NO")
    sys.exit(0)

rcnt = Counter(a)
lcnt = Counter()
target = asum // 2
ssum = 0L
found = False
for i in xrange(n):
    ssum += a[i]
    rcnt[a[i]] -= 1
    if (rcnt[a[i]] == 0):
        del rcnt[a[i]]
    lcnt[a[i]] += 1

    if ssum > target:
        need = ssum - target
        if need == 0 or lcnt[need] != 0:
            found = True
            break
    else:
        need = target - ssum
        if need == 0 or rcnt[need] != 0:
            found = True
            break

print("YES" if found else "NO")
