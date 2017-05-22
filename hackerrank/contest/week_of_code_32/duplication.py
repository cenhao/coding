#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
import math
srci = sys.stdin

Q = int(srci.readline().rstrip())

for q in xrange(Q):
    x = int(srci.readline().rstrip())
    cnt = 0
    while x > 0:
        cnt += 1
        x -= 1 << int(math.log(x, 2))
    print("{0}".format(cnt & 1))
