#!/usr/bin/env python
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase



def main():
    s = input()
    t = input()
    # def f(i, j, s, t, dp)-> int:

    #     if i < 0  or j < 0:
    #         return 0
    #     if s[i] == t[j]:
    #         dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp)
    #         return dp[i][j]
    #     if dp[i][j] != -1:
    #         return dp[i][j]
    #     dp[i][j] = max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp))
    #     return dp[i][j]
        


    def lcs(s, t)->int:
        n, m = len(s), len(t)
        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]
        # return f(n-1, m-1, s, t, dp)
        for i in range(m+1):
            dp[0][i] = 0
        for j in range(n+1):
            dp[j][0] = 0
        for i in range(1, n+1):
            for j in range(1, m+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[n][m]


    print(lcs(s, t))
    





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

if __name__ == "__main__":
    main()