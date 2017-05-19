#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
import sys
srci = sys.stdin

class Cup:
    def __init__(self, volumn, idx):
        self.volumn = volumn
        self.idx = idx
        self.water = 0

n, w = map(int, srci.readline().rstrip().split())
volumn = map(int, srci.readline().rstrip().split())
cups = []
for i in xrange(n):
    cups.append(Cup(volumn[i], i))

cups.sort(key=lambda c: c.volumn)

ok = True
for i in xrange(n):
    need = cups[i].volumn // 2 + (cups[i].volumn & 1)
    if need > w:
            ok = False
            break
    cups[i].water += need
    w -= need

if ok:
    for i in xrange(n-1, -1, -1):
        poured = min(w, cups[i].volumn-cups[i].water)
        cups[i].water += poured
        w -= poured

    ok = (w == 0)

if ok:
    cups.sort(key=lambda c: c.idx)
    for i in xrange(n):
        print("{0}".format(cups[i].water), end=(' ' if i < n-1 else '\n'))
else:
    print("-1")

