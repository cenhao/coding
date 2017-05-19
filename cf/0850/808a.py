#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
import sys
srci = sys.stdin

n = int(srci.readline())

nn = n
base = 1
while nn >= 10:
    nn //= 10
    base *= 10

nn = (nn+1) * base

print("{0}".format(nn-n))
