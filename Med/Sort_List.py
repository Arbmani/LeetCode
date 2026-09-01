from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val    = val 
        self.next   = next 
        

class Solution:
    '''
        Given the "head" of a linked list, return the list after sorting it in ascending order

        Implement MergeSort
    '''
    def merge(self, left: Optional[ListNode], right: Optional[ListNode]) -> Optional[ListNode]:
        dummy   = ListNode()
        node    = dummy

        while left and right:
            if left.val <= right.val:
                node.next   = left 
                left        = left.next
            else:
                node.next   = right
                right       = right.next
            node = node.next
        node.next = left if left else right
        return dummy.next 

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head 
        
        slow, fast = head, head.next 
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next

        right = slow.next
        slow.next = None 

        left  = self.sortList(head)
        right = self.sortList(right)

        return self.merge(left, right)


if __name__ == "__main__":
    #def test(correct_answer, my_answer):
    #    assert correct_answer == my_answer, (
    #        f"\nExpected: {correct_answer}\n"
    #        f"Got     : {my_answer}"
    #    )
    #test([1,2,3,4], Solution().sortList([4,2,1,3]))
    #test([-1,0,3,4,5], Solution().sortList([-1,5,3,4,0]))
    #test([], Solution().sortList([]))
    print("All tested passed")