from typing import List

class Solution:
    def monotonic_stack(self, heights: List[int]) -> int:
        max_area = 0
        stack    = []

        for position, height in enumerate(heights):
            start = position
            while(stack and stack[-1][1] > height):
                current_position, current_height = stack.pop()
                max_area = max(max_area, min(position - current_position, current_height)**2)
                start = current_position

            stack.append((start, height))

        for position, height in stack:
            max_area = max(max_area, min(height, (len(heights) - position))**2)

        return max_area


    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0 

        heights     = [0] * len(matrix[0])
        max_area    = 0

        for row in range(len(matrix)):
            for col in range(len(matrix[row])):
                value = matrix[row][col]
                if value == "1":
                    heights[col] += 1
                else:
                    heights[col] = 0

            max_area = max(max_area, self.monotonic_stack(heights))
        #print(max_area)
        return max_area



if __name__ == "__main__":
    sol = Solution()
    sol.maximalSquare([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])