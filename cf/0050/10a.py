#!/usr/bin/env python
# -*- coding: utf-8 *-*

from __future__ import print_function
import sys
srci = sys.stdin

n, p1, p2, p3, t1, t2 = map(int, srci.readline().rstrip().split())

psum = 0
last = 0
for i in xrange(n):
    l, r = map(int, srci.readline().rstrip().split())
    psum = psum + (r - l) * p1
    if i != 0:
        away = l - last
        idle = min(away, t1)
        psum = psum + idle * p1
        screen = min(l - last - idle, t2)
        psum = psum + screen * p2
        sleep = l - last - idle - screen
        psum = psum + sleep * p3
    last = r

print("{0}".format(psum))
