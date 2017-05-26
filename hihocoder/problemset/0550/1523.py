#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin

n = int(srci.readline().rstrip())
a = map(int, srci.readline().rstrip().split())

last = 0
mx = 0
for ai in a:
    if ai > last:
        last = ai
    else:
        mx = max(mx, ai)

print(mx)
