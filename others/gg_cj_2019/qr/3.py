#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin
#srci = open('data.in')

def gcd(a, b):
    while b != 0:
        tmp = b
        b = a % b
        a = tmp
    return a

T = int(srci.readline().rstrip())

for t in xrange(1, T+1):
    n, l = map(int,srci.readline().split())
    p = map(int, srci.readline().split())
    pos = 0
    for i in xrange(0, l-1):
        if p[i] != p[i+1]:
            pos = i
            break

    pv = [0] * (l + 1)
    pv[pos + 1] = gcd(p[pos], p[pos+1])
    for i in xrange(pos, -1, -1):
        pv[i] = p[i] / pv[i+1]
    for i in xrange(pos+2, l+1):
        pv[i] = p[i-1] / pv[i-1]

    ordered = sorted(list(set(pv)))
    mapping = { v: chr(ord('A') + i) for i, v in enumerate(ordered) }

    ans = ""
    for v in pv:
        ans += mapping[v]
    print("Case #{0}: {1}".format(t, ans))
