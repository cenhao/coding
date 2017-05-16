#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin
#srci = open('data.in')

def update(mat, x, y, v):
    if mat[x][y] < 0 or v < mat[x][y]:
        mat[x][y] = v
        mat[y][x] = v

n, m = map(int, srci.readline().rstrip().split())
dp = [[-1]*n for i in xrange(n)]

for i in xrange(m):
    u, v, l = map(int, srci.readline().rstrip().split())
    u -= 1
    v -= 1
    update(dp, u, v, l)

for k in xrange(n):
    dp[k][k] = 0
    for i in xrange(n):
        for j in xrange(i+1, n):
            if dp[i][k] < 0 or dp[k][j] < 0:
                continue
            update(dp, i, j, dp[i][k]+dp[k][j])

for i in xrange(n):
    for j in xrange(n):
        print('{0} '.format(dp[i][j]), end='')
    print('')
