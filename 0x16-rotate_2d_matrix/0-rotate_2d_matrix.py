#!/usr/bin/python3
"""Rotate 2D Matrix Algo
"""


def rotate_2d_matrix(matrix):
    """Rotates a matrix 90 degrees clockwise
    """

    mat_length = len(matrix)
    mat = []

    for column in range(0, mat_length):
        for row in range(mat_length - 1, -1, -1):
            mat.append(matrix[row][column])

    for row in range(0, mat_length):
        for column in range(0, mat_length):
            new_mat = mat.pop(0)
            matrix[row][column] = new_mat
