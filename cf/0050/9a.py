#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin

w, y = map(int, srci.readline().rstrip().split())
mx = max(w, y)
raw_chance = 6 - mx + 1
dom = 6

if raw_chance % 2 == 0:
    raw_chance = raw_chance / 2;
    dom = dom / 2

if raw_chance % 3 == 0:
    raw_chance = raw_chance / 3;
    dom = dom / 3

print("{0}/{1}".format(raw_chance, dom))
