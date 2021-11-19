#!/usr/bin/python3
"""Rain"""


def cal_rain(wall, n):
    """Function that calculate how many square units of water
    will be retained after it rains
    """
    rainwater = 0

    for i in range(1, n - 1):
        w = wall[i]
        for j in range(i):
            w = max(w, wall[j])
        l = wall[i]
        for j in range(i + 1, n):
            l = max(l, wall[j])
        rainwater = rainwater + (min(w, l) - wall[i])
    return rainwater


def rain(walls):
    """returns integer indicating total amount of rainwater retained
    """
    res = cal_rain(walls, len(walls))

    return res
