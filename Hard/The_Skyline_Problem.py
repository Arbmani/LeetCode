from typing import List 
import heapq
class Solution:
    '''
        A city's skyline is the outer contour of the silhoutte formed by all the buildings in that city
        when viewed from a distance. Given the locations and heights of all the buildings, return the 
        skyline formed by these buildings collectively.

        The geometric information of each building is given in the array "buildings"
        where "buildings[i] = [left_i, right_i, height_i]:

        -   "left_i" is the x coordinate of the left edge of the "i"th building.

        -   "right_i" is the x coordinate of the right edge of the "i"th building.

        -   "height_i" is the height of the "i"th building.

        You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

        The skyline should be represented as a list of "key points" sorted by their x-coordinate in form 
        "[[x1, y1], [x2, y2], ...]". Each key point is the left endpoint of some horizontal segment 
        in the skyline except the last point in the list, which always has a y-coordiante "0" and is 
        used to mark the skyline's termination where the rightmost building ends. Any ground between 
        the leftmost and rightmost building should be part of the skyline's contour.

        Note:

            There must be no consecutive horizontal lines of equal height in the output skyline. For
            instance, "[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]" is not acceptable; the three lines 
            of height 5 should be merged into one in the final output 
            as such: "[...,[2 3],[4 5],[12 7],...]".
    
    
    '''

    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for left, right, height in buildings:
            events.append((left, -height, right))
            events.append((right, 0, right))
        events.sort()

        last_height, result, heap  = 0, [], [(0, float("inf"))]

        for left, negative_height, right in events:
            while heap[0][1] <= left:
                heapq.heappop(heap)
            if negative_height < 0:
                heapq.heappush(heap, (negative_height, right))
            height = -heap[0][0]
            if height != last_height:
                result.append([left, height])
                last_height = height
        return result


if __name__ == "__main__":
    def test(correct_answer, my_answer):
        assert correct_answer == my_answer, (
            f"\nExpected: {correct_answer}\n"
            f"Got:      {correct_answer}"
        )

    test([[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]], Solution().getSkyline(buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]))
    test([[0,3],[5,0]], Solution().getSkyline(buildings = [[0,2,3],[2,5,3]]))