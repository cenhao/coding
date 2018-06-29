#!/usr/bin/env python3
import os
import sys

def minuteToWinIt(a, k):
    hm = {}
    for i, v in enumerate(a):
        vv = v - k * i
        if vv not in hm: hm[vv] = 0
        hm[vv] += 1

    mx = 0
    for k, v in hm.items():
        mx = max(mx, v)

    return len(a) - mx

if __name__ == '__main__':
    fh = open(os.environ['OUTPUT_PATH'], 'w')
    #fh = sys.stdout
    n, k = map(int, sys.stdin.readline().rstrip().split())
    a = list(map(int, sys.stdin.readline().rstrip().split()))
    result = minuteToWinIt(a, k)

    fh.write(str(result) + '\n')
    fh.close()

