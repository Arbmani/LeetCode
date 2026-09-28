import numpy as np

class Solution:
    '''
    [Medium Problem]
    
        You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.

        You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.

        For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.

        Return an array answer, where answer[j] is the answer to the jth query.
    
    '''
    def countPoints(self, points: list[list[int]], queries: list[list[int]]) -> list[int]:
        points  = np.array(points) 
        queries = np.array(queries)
        distance = ((queries[:, None, :2] - points[None, :, :]) ** 2).sum(axis=2) ** 0.5
        return np.sum(distance <= queries[:,2, None], axis=1).tolist()



    def countPoints_Slow(self, points: list[list[int]], queries: list[list[int]]) -> list[int]:
        ans = [0] * len(queries)
        for index, query in enumerate(queries):
            counter = 0
            for point in points:
                if query[2] >= ((point[0] - query[0])**2  + (point[1] - query[1])**2)**0.5:
                    counter += 1
            ans[index] = counter

        return ans


if __name__ == "__main__":
    print(f"Want : {[3,2,2]}, Was : {Solution().countPoints(points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]])}")

    print(f"Want : {[2,3,2,4]}, Was : {Solution().countPoints(points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]])}")