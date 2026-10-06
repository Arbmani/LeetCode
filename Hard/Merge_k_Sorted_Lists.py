class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

import heapq
class Solution:
    '''
    [Hard Problem]

        You are given an array of "k" linked lists, each linked-list is sorted 
        in ascending order.

        Merge all the linked-lists into one sorted linked list and return it.
    
    '''
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        heap = []
        for index, node in enumerate(lists):
            if node: heapq.heappush(heap, (node.val, index, node))
        dummy = ListNode()
        curr  = dummy

        while heap:
            _, index, node = heapq.heappop(heap)
            curr.next = node  
            curr      = curr.next
            if node.next:
                heapq.heappush(heap, (node.next.val, index, node.next))


        return dummy.next 