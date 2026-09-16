class Solution:
    '''
    [Easy Problem]

        An axis-algined rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the
        coordinate of its bottom-left, corner, and (x2, y2) is the coordinate of its top-right corner.
        Its top and bottom edges are parallel to the X-axis, and its left and right edges are 
        parallel to the Y-axis.

        Two rectangles overlap if the area of their intersection is postive. To be clear, two rectangles
        that only touch at the corner or edge do not overlap.

        Given two axis-aligned rectangles rec1 and rec2, return "true" if they overlap, otherwise return false.
    
    '''


    def isRectangleOverlap(self, rec1: list[int], rec2: list[int]) -> bool:
        return (
            rec1[2] > rec2[0] and   #   right_1  > left_2
            rec1[3] > rec2[1] and   #   top_1    > bottom_2
            rec1[0] < rec2[2] and   #   left_1   < right_2
            rec1[1] < rec2[3])      #   bottom_1 < top_2




if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().isRectangleOverlap(rec1 = [0,0,2,2], rec2 = [1,1,3,3])}")

    print(f"Want : {False}, Was : {Solution().isRectangleOverlap(rec1 = [0,0,1,1], rec2 = [1,0,2,1])}")

    print(f"Want : {False}, Was : {Solution().isRectangleOverlap(rec1 = [0,0,1,1], rec2 = [2,2,3,3])}")

    