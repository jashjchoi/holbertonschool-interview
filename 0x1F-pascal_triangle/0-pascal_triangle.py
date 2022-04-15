#!/usr/bin/python3
"""Pascal's Triangle
"""


def pascal_triangle(n):
    """returns a list of lists of integers representing
    the Pascal’s triangle of n
    """
    if n <= 0:
        return []
    res = []
    lastrow = []
    for i in range(1, n + 1):
        listrow = []
        for num in range(i):
            if num == 0:
                listrow.append(1)
            elif i > 2:
                try:
                    listrow.append(lastrow[num - 1] + lastrow[num])
                except:
                    listrow.append(1)
            else:
                listrow.append(1)
        lastrow[:] = listrow
        res.append(listrow)
    return res
