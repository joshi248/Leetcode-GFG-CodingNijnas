'''
4
3
1 2 4
4
2 1 4 9
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
'''
#!/usr/bin/env python
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase

# def bruteSolve(nums, index):
#     if index == 0:
#         return nums[index]
#     if index  < 0:
#         return 0
#     pick = nums[index] + bruteSolve(nums, index - 2)
#     notPick = bruteSolve(nums, index - 1)
#     ans = max(pick, notPick)
#     return ans

# def betterSolve(nums, dp, index):
#     if index == 0:
#         return nums[0]
#     if index < 0:
#         return 0
#     if dp[index] != -1:
#         return dp[index]
#     take = nums[index] + betterSolve(nums, dp, index - 2)
#     notTake = betterSolve(nums, dp, index - 1)
#     dp[index] = max(take, notTake)
#     return dp[index]

def optimalSolve(nums, index):
    prev, prev2 = nums[0], 0
    for i in range(len(nums)):
        take = nums[i]
        if i > 1:
            take += prev2
        notTake = prev
        curr = max(take, notTake)
        prev2 = prev
        prev = curr
    print(curr)


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        nums = list(map(int, input().split(' ')))
        # print(bruteSolve(nums, n-1))
        dp = [-1 for i in range(n+1)]
        # betterSolve(nums, dp, n-1)
        # print(dp[n-1])
        optimalSolve(nums, n)







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