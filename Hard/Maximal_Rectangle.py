from typing import List


'''

    85. Maximal Rectangle

    Given a rows x cols binary matrix filled with 0's and 1's,
    Find the largest rectangle containing only 1's and return its area.




'''
#    def largestRectangleArea(self, heights: List[int]) -> int:
#        '''
#            We will utilize a Monotonic Stack
#        '''
#
#        maxArea = 0
#        stack = []
#
#        for position, height in enumerate(heights):
#            start = position
#            while stack and stack[-1][1] > height:
#                current_position, current_height = stack.pop()
#                maxArea = max(maxArea, current_height * (position - current_position))
#                start = current_position
#            stack.append((start, height))
#
#        for position, height in stack:
#            maxArea = max(maxArea, height * (len(heights) - position))
#
#        return maxArea

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area    = 0 
        stack       = []

        for position, height in enumerate(heights):
            start = position
            while stack and stack[-1][1] > height:
                current_position, current_height = stack.pop()


                max_area    = max(max_area, current_height * (position - current_position))
                start       = current_position
            stack.append((start, height))

        for position, height in stack:
            max_area = max(max_area, height * (len(heights) - position))
        return max_area  

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        height      = [0] * len(matrix[0])
        max_area    = 0
        
        for row in range(len(matrix)):
            for col in range(len(matrix[row])):
                value = matrix[row][col]


                if value == "1":
                    height[col] += 1
                else:
                    height[col] = 0

            area = self.largestRectangleArea(height)
            max_area = max(max_area, area)
        return max_area



if __name__ == "__main__":
    sol = Solution()
    sol.maximalRectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])