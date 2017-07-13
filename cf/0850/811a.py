#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division, print_function
import math
import sys
srci = sys.stdin

a, b = map(int, srci.readline().rstrip().split())
ra = int(math.sqrt(a))
rb = int((-1+math.sqrt(1+4*b))/2)
if ra > rb:
    print("Valera")
else:
    print("Vladik")
