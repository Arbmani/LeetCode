from typing import List

class Solution:
    '''
        Given an "m x n" integers "matrix" return the length of the longest increasing path in "matrix"

        From each cell, you can either move in four directions: left, right, up or down. You may not 
        move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
    
    
    '''

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0]) 
        path = [[0] * cols for _ in range(rows)]
        longest_increasing_path = 1

        def Depth_First_Search(row, col, parent_val):
            nonlocal path 
            nonlocal longest_increasing_path
            if (row < 0 or row == rows or 
                col < 0 or col == cols or
                matrix[row][col] <= parent_val):
                return 0
            if path[row][col] != 0:
                return path[row][col]
            result = 1 
            val    = matrix[row][col]
            result = max(result, 1 + Depth_First_Search(row + 1, col, val))
            result = max(result, 1 + Depth_First_Search(row - 1, col, val))
            result = max(result, 1 + Depth_First_Search(row, col + 1, val))
            result = max(result, 1 + Depth_First_Search(row, col - 1, val))
            path[row][col] = result
            longest_increasing_path = max(longest_increasing_path, result)
            return result
        for row in range(rows):
            for col in range(cols):
                Depth_First_Search(row, col, -1)


        return longest_increasing_path


if __name__ == "__main__":
    print(Solution().longestIncreasingPath(matrix = [[9, 9, 4], [6, 6, 8], [2, 1, 1]]))