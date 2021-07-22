#!/usr/bin/python3
"""
You have n number of locked boxes in front of you
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes
"""


def canUnlockAll(boxes):
    """ determines if all the boxes in a list of lists can be opened
    """
    # check if the list of lists (boxes) exists
    if not boxes:
        return False
    # check if boxes is the list or not
    if type(boxes) is not list:
        return False
    # first box boxes[0] is unlocked. for loop to go through the list of lists
    openedBox = [0]
    for n in openedBox:
        # A key with the same number as a box opens that box
        for k in boxes[n]:
            if k not in openedBox and k < len(boxes):
                openedBox.append(k)
    # Return True if all boxes can be opened
    if len(openedBox) == len(boxes):
        return True
    # else return False
    else:
        return False
