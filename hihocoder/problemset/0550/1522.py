#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
import sys
srci = sys.stdin

n = int(srci.readline().rstrip())
tp, tn, fp, fn = [0, 0, 0, 0]
for i in xrange(n):
    fact, predict = srci.readline().rstrip().split()
    if predict == '+':
        if predict == fact:
            tp += 1
        else:
            fp += 1
    else:
        if predict == fact:
            tn += 1
        else:
            fn += 1

print("{0:.2f}%".format(200*tp/(2*tp+fp+fn)))
