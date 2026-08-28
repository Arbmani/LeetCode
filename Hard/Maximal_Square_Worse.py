from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows, cols, cache  = len(matrix), len(matrix[0]), {}
        max_val = 0 
        def helper(row: int, col: int) -> int:
            nonlocal max_val
            if row >= rows or col >= cols:
                return 0
            if (row, col) not in cache:
                down        = helper(row + 1, col)
                right       = helper(row, col + 1)
                diagonal    = helper(row + 1, col + 1)

                cache[(row, col)] = 0
                if matrix[row][col] == "1":
                    cache[(row, col)] = 1 + min(down, right, diagonal)
                    max_val = max(max_val, cache[(row, col)])
            return cache[(row, col)]

        helper(0, 0)
        return max_val**2

if __name__ == "__main__":
    sol = Solution()
    sol.maximalSquare([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])