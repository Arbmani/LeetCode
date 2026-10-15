import bisect
class Solution:
    '''
        [Hard Problem]

            You want to build some obstacle courses. 
            You are given a 0-indexed integer array obstacles of length n, 
            where obstacles[i] describes the height of the ith obstacle.

            For every index i between 0 and n - 1 (inclusive), 
            find the length of the longest obstacle course in obstacles such that:

            -   You choose any number of obstacles between 0 and i inclusive.
            
            -   You must include the ith obstacle in the course.
            
            -   You must put the chosen obstacles in the same order as they appear in obstacles.
        
            -   Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
        
            Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.
    '''
    def longestObstacleCourseAtEachPosition(self, obstacles: list[int]) -> list[int]:
        res = []
        dp  = [10**8] * (len(obstacles) + 1)

        for obstacle in obstacles:
            index = bisect.bisect(dp, obstacle)
            res.append(index + 1)
            dp[index] = obstacle
        return res 

if __name__ == "__main__":
    print(f"Want : {[1,2,3,3]}, Was : {Solution().longestObstacleCourseAtEachPosition(obstacles = [1,2,3,2])}")
    print(f"Want : {[1,2,1]}, Was : {Solution().longestObstacleCourseAtEachPosition(obstacles = [2,2,1])}")
    print(f"Want : {[1,1,2,3,2,2]}, Was : {Solution().longestObstacleCourseAtEachPosition(obstacles = [3,1,5,6,4,2])}")