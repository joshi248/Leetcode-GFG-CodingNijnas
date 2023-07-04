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

from collections import deque

def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        grid = []
        for i in range(n):
            temp = list(map(int, input().split()))
            grid.append(temp)
        print(findIslands(grid, n, m))

def findIslands(grid, n, m) -> int:
    count = 0
    vis = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if not vis[i][j] and grid[i][j] == 1:
                count+=1
                bfs(i, j, vis, grid)
    
    
    return count

sys.setrecursionlimit(10**7)

def bfs(i, j, vis, grid):
    vis[i][j] = 1
    n = len(grid)
    m = len(grid[0])
    q = deque()
    q.append(i)
    q.append(j)
    while q:
        row = q.popleft()
        col = q.popleft()
        for Drow in range(-1, 2):
            for Dcol in range(-1, 2):
                Nrow = row + Drow
                Ncol = col + Dcol
                if Nrow >= 0 and Ncol >= 0 and Nrow < n and Ncol < m and not vis[Nrow][Ncol] and  grid[Nrow][Ncol] == 1:
                    bfs(Nrow, Ncol, vis, grid)









if __name__ == "__main__":
    main()