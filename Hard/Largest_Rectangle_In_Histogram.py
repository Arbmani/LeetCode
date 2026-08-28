from typing import List


'''
    84. Largest_Rectangle_In_Histogram


    Given an array of integers "heights" representing the histogram's bar height where 
    the width of each bar is 1, return the area of the largest rectangle in the histogram. 



'''
from collections import defaultdict
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:

        
        height_to_position = defaultdict(list)
        for position, height in enumerate(heights):
            height_to_position[height].append(position)

        height_to_position = dict(sorted(height_to_position.items(), reverse=True))

        visited_heights = []

        for height in height_to_position:
            visited_heights.extend(height_to_position[height])
            visited_heights.sort()
            height_to_position[height] = visited_heights.copy()


        max_area        = float("-inf")
        current_area    = 0

        for height, positions in height_to_position.items():
            current_area = 0
            for i in range(len(positions)):
                if i == 0 or positions[i] - positions[i - 1] > 1:
                    current_area = height
                else:
                    current_area += height
                max_area = max(max_area, current_area)


        return max_area



if __name__ == "__main__":
    sol = Solution()
    print(sol.largestRectangleArea([2,1,5,6,2,3]))