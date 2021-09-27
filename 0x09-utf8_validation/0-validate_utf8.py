#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    n_bytes = 0
    bit_1 = 1 << 7
    bit_2 = 1 << 6

    if not data or len(data) == 0:
        return True

    for num in data:
        bit = 1 << 7
        if n_bytes == 0:
            while (bit & num):
                n_bytes += 1
                bit = bit >> 1

            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num & bit_1 and not (num & bit_2)):
                return False
        n_bytes -= 1

    if n_bytes:
        return False
    else:
        return True
