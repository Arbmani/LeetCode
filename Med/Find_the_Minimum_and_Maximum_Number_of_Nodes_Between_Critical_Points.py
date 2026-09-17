from typing import Optional

class ListNode:
    def __init__(self, val = 0, next=None):
        self.val    = val 
        self.next   = next        


class Solution:
    '''
    [Medium Problem]

        A critical point in a linked list is defined as either a local maxima or a local minima

        -   A node is a local maxima if the current node has a value strictly greater 
            than the previous node and the next node.

        -   A node is a local minima if the current node has a value strictly smaller
            than the previous node and the next node.

        Note that a node can only be a local maxima/minima if there exists both a previous node
        and a next node.

        Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where
        minDistance is the minimum distance between any two distinct critical points and maxDistance
        is the maximum distance between any two distinct critical points. If there are fewer than two
        critical points, return [-1, -1]. 
    
    '''
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> list[int]:
        prev, cur, index = head, head.next, 1
        first, last, minDist = None, None, float("inf") 

        while(cur.next):
            next_node = cur.next
            if ((cur.val > prev.val and cur.val > next_node.val) or 
                (cur.val < prev.val and cur.val < next_node.val)):
                if first == None:
                    first = index
                else:
                    minDist = min(minDist, index - last)
                last = index 
            prev, cur = cur, next_node
            index     += 1

        if first is None or first == last:
            return [-1, -1]
        return [minDist, last - first]


if __name__ == "__main__":
    a = ListNode(val=3, next=ListNode(val=1))

    b = ListNode(val=5, next=ListNode(val=3,next=ListNode(val=1,next=ListNode(val=2,next=ListNode(val=5,next=ListNode(val=1,next=ListNode(val=2)))))))

    c = ListNode(val=1, next=ListNode(val=3,next=ListNode(val=2,next=ListNode(val=2,next=ListNode(val=3,next=ListNode(val=2,next=ListNode(val=2,next=ListNode(val=2,next=ListNode(val=7)))))))))


    print(f"Want : {[-1, -1]}, Was : {Solution().nodesBetweenCriticalPoints(a)}")

    print(f"Want : {[1,3]}, Was : {Solution().nodesBetweenCriticalPoints(b)}")

    print(f"Want : {[3,3]}, Was : {Solution().nodesBetweenCriticalPoints(c)}")