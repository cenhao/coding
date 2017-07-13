#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin

n, f = map(int, srci.readline().rstrip().split())
gain = []
gsum = 0
for i in xrange(n):
    s, c = map(int, srci.readline().rstrip().split())
    gsum = gsum + min(s, c)
    gain.append(min(s*2, c)-min(s, c))

gain.sort(reverse=True)
for idx, v in enumerate(gain):
    if (idx == f):
        break
    gsum = gsum + v

print("{0}".format(gsum))
