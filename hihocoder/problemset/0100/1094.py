#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys

inp = sys.stdin
#inp = open('data1.in', 'r')

n, m = map(int, inp.readline().strip().split())
mat = []
for i in xrange(n):
    mat.append(inp.readline().rstrip())

pos = []
for i in xrange(3):
    pos.append(inp.readline().rstrip())

rotates = []
rotates.append([])
for i in xrange(3):
    rotates[0].append([])
    for j in xrange(3):
        rotates[0][i].append(pos[i][j])

rotates.append([])
for i in xrange(3):
    rotates[1].append([])
    for j in xrange(3):
        rotates[1][i].append(pos[j][2-i])

rotates.append([])
for i in xrange(3):
    rotates[2].append([])
    for j in xrange(3):
        rotates[2][i].append(pos[2-i][2-j])

rotates.append([])
for i in xrange(3):
    rotates[3].append([])
    for j in xrange(3):
        rotates[3][i].append(pos[2-j][i])

for i in xrange(n-2):
    for j in xrange(m-2):
        for r in xrange(4):
            ok = True
            for x in xrange(3):
                if not ok:
                    break
                for y in xrange(3):
                    if mat[i+x][j+y] != rotates[r][x][y]:
                        ok = False
                        break
            if ok:
                print("{0} {1}".format(i+2, j+2))
                break
