#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin

rcnt, ccnt = 0, 0

full_col = [True for i in xrange(8)]

for l in xrange(8):
    line = srci.readline().rstrip()

    full_row = True
    for i in xrange(len(line)):
        if line[i] == 'W':
            full_row = False
            full_col[i] = False

    if full_row:
        rcnt += 1

for c in xrange(8):
    if full_col[c]:
        ccnt += 1

ans = rcnt + ccnt if rcnt != 8 else rcnt
print("{0}".format(ans))
