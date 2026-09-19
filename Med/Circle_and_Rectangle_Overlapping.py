class Solution:
    '''
    [Medium Problem]

        You are given a circle represented as (radius, xCenter, yCenter) and an axis- aligned
        rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the 
        bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

        Return "true" if the circle and rectangle are overlapped otherwise return "false". 
        In other words, check if there is any point (xi, yi) that belongs to the circle
        and the rectangle at the same time.

    '''


    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        return ((xCenter - (max(x1, min(xCenter, x2))))**2 + (yCenter - (max(y1, min(yCenter, y2))))**2 <= radius**2)

#dx = xCenter - (max(x1, min(xCenter, x2)))
#dy = yCenter - (max(y1, min(yCenter, y2)))
if __name__ == "__main__":
    '''
        We have a circle and a rectangle, and we need to knwo whether they overlap.
        
        Instead of checking infinitely many points, find just one: the closest point of the rectangle to the circle's center.
        If that single point lies inside of the circle, the two shapes overlap. Or if the closest point is to far
        away, nothing else can be closer either.

        The rectangles spans x1 -> x2 horizontally, and we want the x-coordiante nearest to xCenter, but it must stay Within
        that range this is called CLAMPING.

        -   The closest x is : max(x1, min(xCenter, x2))
        -   The closest y is : max(y1, min(yCenter, y2))

        After both clamps, (closestX, closestY) is the point in or on the rectangles nearest to the circle's center. 

        dx = xCenter - closestX
        dy = yCenter - closestY

    
    
    '''



    print(f"Want : {True}, Was : {Solution().checkOverlap(radius = 5, xCenter = 0, yCenter = 0, x1 = -10, y1 = -1, x2 = 10, y2 = 1)}")

    print(f"Want : {True}, Was : {Solution().checkOverlap(radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1)}")

    print(f"Want : {False}, Was : {Solution().checkOverlap(radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1)}")

    print(f"Want : {True}, Was : {Solution().checkOverlap(radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1)}")

    print(f"Want : {True}, Was : {Solution().checkOverlap(radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = -0.5, y2 = 0.5)}")