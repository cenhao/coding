#!/usr/bin/env python3

from heapq import heappush, heappop
import os
import sys

srci = sys.stdin

# Complete the leastTimeToInterview function below.
def leastTimeToInterview(n, k, m):
    adj = [[] for i in range(n+1)]
    for i in range(m):
        u, v, l = map(int, srci.readline().rstrip().split())
        adj[u].append((v, l))
        adj[v].append((u, l))

    dist = [-1 for i in range(n+1)]
    dist[1] = 0
    pq = []
    heappush(pq, (0, 1))

    while pq:
        d, p = heappop(pq)
        if dist[p] < d: continue
        for key, val in adj[p]:
            dd = d + val
            slot = dd // k
            if n!=key and (slot&1): dd = k * (slot + 1) # if at destination, dont wait for traffic light
            if dist[key]==-1 or dist[key]>dd:
                dist[key] = dd
                if n != key: heappush(pq, (dd, key))

    return dist[n]

if __name__ == '__main__':
    fh = open(os.environ['OUTPUT_PATH'], 'w')
    #fh = sys.stdout

    n = int(srci.readline().rstrip())
    k = int(srci.readline().rstrip())
    m = int(srci.readline().rstrip())

    print(leastTimeToInterview(n, k, m), file=fh)
    fh.close()
