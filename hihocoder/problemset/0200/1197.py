#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
srci = sys.stdin

for line in srci:
    words = line.rstrip().lower().split()
    lst = []
    cap = True
    for w in words:
        if w == "." or w == ",":
            lst[-1] = lst[-1] + w
        else:
            if cap:
                lst.append(w[0].upper() + w[1:])
            else:
                lst.append(w)

        cap = True if w[-1] == '.' else False

    print(" ".join(lst))
