from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return None 
        rabbit = head 
        turtle = head 

        while rabbit and rabbit.next:
            rabbit = rabbit.next.next
            turtle = turtle.next  
            if rabbit == turtle:
                turtle = head
                while rabbit != turtle:
                    turtle = turtle.next 
                    rabbit = rabbit.next 
                return turtle
    
        return None 
        