class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:
        dummy = curr = ListNode()
        while list1 and list2:
            if list1.val <= list2.val:
                curr.next = list1 
                list1     = list1.next 
            else:
                curr.next = list2 
                list2     = list2.next 
            curr = curr.next 
        curr.next = list1 or list2
        return dummy.next

if __name__ == "__main__":
    list1 = ListNode(1, ListNode(2, ListNode(4)))
    list2 = ListNode(1, ListNode(3, ListNode(4)))

    merged = Solution().mergeTwoLists(list1, list2)

    while merged:
        print(merged.val, end=" -> ")
        merged = merged.next
    print("None")