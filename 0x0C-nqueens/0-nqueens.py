#!/usr/bin/python3
"""solves the N queens problem."""
from sys import argv

argc = len(argv)
if (argc != 2):
    print('Usage: nqueens N')

num = argv[1]
try:
    num = int(num)
except ValueError:
    print('N must be a number')
    exit(1)

if num < 4:
    print("N must be at least 4")
    exit(1)
