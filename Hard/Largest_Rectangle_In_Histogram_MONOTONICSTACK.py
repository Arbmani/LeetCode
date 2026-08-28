from typing import List


'''
    84. Largest_Rectangle_In_Histogram


    Given an array of integers "heights" representing the histogram's bar height where 
    the width of each bar is 1, return the area of the largest rectangle in the histogram. 



'''

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        '''
            We will utilize a Monotonic Stack
        '''

        maxArea = 0
        stack = []

        for position, height in enumerate(heights):
            start = position
            while stack and stack[-1][1] > height:          # We remove all elements that are larger than the current height
                current_position, current_height = stack.pop()
                maxArea = max(maxArea, current_height * (position - current_position))  # Does the current stack elem, with its start and height make a larger area
                start = current_position        # Once we found an elem with the same height
            stack.append((start, height))

        for position, height in stack:
            maxArea = max(maxArea, height * (len(heights) - position))

        return maxArea


