class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next



class Solution:
    '''
    [Medium Problem]
    
    You are given the head of a linked list, 
    which contains a series of integers separated by 0's. 
    The beginning and end of the linked list will have Node.val == 0.

    For every two consecutive 0's, 
    merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. 
    The modified list should not contain any 0's.

    Return the head of the modified linked list.
    
    '''


    def mergeNodes(self, head: ListNode | None) -> ListNode | None:
        write = head 
        read  = head.next 
        mysum = 0
        while read:
            if read.val == 0:
                write     = write.next 
                write.val = mysum
                mysum     = 0
            else:
                mysum += read.val 
            read = read.next 
        write.next = None
        return head.next


if __name__ == "__main__":
    a_in  = ListNode(val=0, next=(ListNode(val=3, next=(ListNode(val=1, next=(ListNode(val=0, next=(ListNode(val=4, next=(ListNode(val=5, next=(ListNode(val=2, next=(ListNode(val=0)))))))))))))))
    a_out = ListNode(val=4, next=(ListNode(val=11)))

    print(f"Want : {a_out}, Was : {Solution().mergeNodes(a_in)}")