#!/usr/bin/env python
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase
# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion



def main():
    t = int(input())
    for _ in range(t):
        v, e = map(int, input().split())
        adjLs = [[] for _ in range(v+1)]
        for i in range(e):
            u, v = map(int, input().split())
            adjLs[u].append(v)
            adjLs[v].append(u)
        ans = cycleDetection(adjLs, v, e)
        if ans:
            print("Yes")
        else:
            print("No")


def cycleDetection(adjLs, v, e) -> bool:
    vis = [0 for _ in range(v+1)]
    print(vis)
    for i in range(1, v+1):
        if not vis[i]:
            if dfs(i, -1, adjLs, vis):
                return True
    
    return False

import time
def dfs(index, par, adjLs, vis) -> bool:
    vis[index] = 1

    for node in adjLs[index]:
        if not vis[node]:
            if dfs(node, index, adjLs, vis):
                return True
        elif par != node:
            return True
        
    return False




if __name__ == "__main__":
    main()