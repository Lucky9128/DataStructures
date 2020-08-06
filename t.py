# #!/bin/python3

# import math
# import os
# import random
# import re
# import sys



# #
# # Complete the 'NumberOfSwapsForRoy' function below.
# #
# # The function is expected to return an INTEGER.
# # The function accepts 2D_INTEGER_ARRAY matrix as parameter.
# #
# def Swap(matrix):
#     lst = [2,3,5,7,11,13,17,19]
#     if matrix[0][0] + matrix[0][1] not in lst:
#         return 0
#     if matrix[0][0] + matrix[1][0] not in lst:
#         return 0
#     if matrix[0][1] + matrix[1][1] not in lst:
#         return 0
#     if matrix[0][1] + matrix[0][2] not in lst:
#         return 0
#     if matrix[0][2] + matrix[1][2] not in lst:
#         return 0
#     if matrix[1][0] + matrix[1][1] not in lst:
#         return 0
#     if matrix[1][0] + matrix[2][0] not in lst:
#         return 0
#     if matrix[1][1] + matrix[1][2] not in lst:
#         return 0
#     if matrix[1][1] + matrix[2][1] not in lst:
#         return 0
#     if matrix[1][2] + matrix[2][2] not in lst:
#         return 0
#     if matrix[2][0] + matrix[2][1] not in lst:
#         return 0
#     if matrix[2][2] + matrix[2][1] not in lst:
#         return 0
#     return 1

# def NumberOfSwapsForRoy(matrix):
#     lst = [[1,2,3],[4,5,6],[7,8,9]]
#     if lst == matrix:
#         return 0
#     if Swap(matrix) == 0:
#         return -1
#     return 
#     # Write your code here

# if __name__ == '__main__':

from random import randint as rd

# lst=[]
for i in range(1,5):
    # lst.append(30-i)
    print(rd(-15,15))