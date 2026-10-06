from math import sqrt 
import heapq
class Solution:
    '''
    [Medium Problem]

        Given an array of points where points[i] = [x_i, y_i] represents a point on the X-Y plane and an integer k,
        return the k closest points to the origin (0, 0).

        The distance between two points on the X-Y plane is the Euclidian distance (i.e., sqrt(x_1 - x_2)^2 + (y_1 + y_2)^2).

        You may return the answer in any order. The answer is guranteed to be unique (except for the order that it is in).
    
    
    '''
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        return heapq.nsmallest(k, points, key=lambda p: p[0]**2 + p[1]**2)

    def kClosest1(self, points: list[list[int]], k: int) -> list[list[int]]:
        heap = []
        for index, point in enumerate(points):
            distance = sqrt(point[0]**2 + point[1]**2)
            heapq.heappush(heap, (distance, index))
        ans = []
        for index in range(k):
            ans.append(points[heapq.heappop(heap)[1]])

        return ans


if __name__ == "__main__":
    print(f"Want : {[[-2,2]]}, Was : {Solution().kClosest(points = [[1,3],[-2,2]], k = 1)}")

    print(f"Want : {[[3,3],[-2,4]]}, Was : {Solution().kClosest(points = [[3,3],[5,-1],[-2,4]], k = 2)}")