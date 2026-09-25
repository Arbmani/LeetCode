class Solution:
    '''
    [Easy Problem]

        Given an array points where points[i] = [x_i, y_i] represents the 
        X-Y plane, return true if these points are a boomerang.

        A boomerang is a set of three points that are all distinct and not
        in a straight line. 
    
    '''


    def isBoomerang(self, points: list[list[int]]) -> bool:
        if (points[0] == points[1] or 
            points[0] == points[2] or 
            points[1] == points[2]):
            return False 


        return ((points[1][0] - points[0][0]) * (points[2][1] - points[0][1]) != ((points[2][0] - points[0][0]) * (points[1][1] - points[0][1])))


if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().isBoomerang(points = [[1,1],[2,2],[1,1]])}")

    print(f"Want : {True}, Was : {Solution().isBoomerang(points = [[1,1],[2,3],[3,2]])}")

    print(f"Want : {False}, Was : {Solution().isBoomerang(points = [[1,1],[2,2],[3,3]])}")