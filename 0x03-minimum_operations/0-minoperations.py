#!/usr/bin/python3
"""Given a number n, write a method that calculates the fewest
number of operations needed to result in exactly n 'H'
characters in the file"""


def minOperations(n):
    i = 2
    min = 0

    while i <= n:
        if n % i == 0:
            min += i
            n = n/i
        else:
            i += 1
    return min
