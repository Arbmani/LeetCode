from typing import List
from collections import defaultdict
'''
    Max Points on a Line


    Given an array of points where points[i] = [xi, yi] represents a point on the
    X - Y plane, return the maximum number of points that lie on the same straight line. 


'''



class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        result = 1
        for index_p1 in range(len(points)):
            p1 = points[index_p1]
            cache = defaultdict(int)
            for index_p2 in range(index_p1 + 1, len(points)):
                p2 = points[index_p2]
                if p1[0] == p2[0]:
                    slope = float("inf")
                else:
                    slope = (p2[1] - p1[1]) / (p2[0] - p1[0])
                cache[slope] += 1
                result = max(result, cache[slope] + 1)


        #if it has the same slop and lies on the same line as any given 2 points,
        #all other points that share the same will be aligned.

        return result


if __name__ == "__main__":
    sol = Solution()
    print(sol.maxPoints([[1,1],[2,2],[3,3]]))