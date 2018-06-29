#!/usr/bin/env python3

import sys
import os
srci = sys.stdin

def which_section(n, k, a):
    sm, ans = 0, 0
    for i, v in enumerate(a):
        if sm + v >= k:
            ans = i + 1
            break
        sm += v
    return ans

if __name__ == '__main__':
    fh = open(os.environ['OUTPUT_PATH'], 'w')
    t = int(srci.readline())
    for i in range(t):
        n, k, m = map(int, srci.readline().split())
        a = list(map(int, srci.readline().rstrip().split()))
        print(which_section(n, k, a), file=fh)
    fh.close()
