#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin

def merge_sort(arr):
    cnt = 0
    rng = 1 # range
    while rng < len(arr):
        for i in xrange(0, len(arr), rng*2):
            ls, le = [i, min(i+rng, len(arr))]
            rs, re = [le, min(i+2*rng, len(arr))]
            buff = []
            while ls < le and rs < re:
                if arr[rs] < arr[ls]:
                    cnt += le - ls
                    buff.append(arr[rs])
                    rs += 1
                else:
                    buff.append(arr[ls])
                    ls += 1
            for j in xrange(ls, le):
                buff.append(arr[j])
            for j in xrange(rs, re):
                buff.append(arr[j])
            for j in xrange(re-i):
                arr[i+j] = buff[j]
        rng <<= 1
    return cnt

n = int(srci.readline())
a = map(int, srci.readline().split())
cnt = merge_sort(a)
print(cnt)
