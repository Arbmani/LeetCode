from typing import Optional
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    '''
    [Medium Problem]

        A linked list of length n is given such that each node contains an additional random pointer, 
        which could point to any node in the list, or null.

        Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
        where each new node has its value set to the value of its corresponding original node. 
        Both the next and random pointer of the new nodes should point to new nodes in the 
        copied list such that the pointers in the original list and copied list represent the same list state. 
        None of the pointers in the new list should point to nodes in the original list.

        For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
        then for the corresponding two nodes x and y in the copied list, x.random --> y.

        Return the head of the copied linked list.

        The linked list is represented in the input/output as a list of n nodes. 
        Each node is represented as a pair of [val, random_index] where:

        -   val: an integer representing Node.val
        
        -   random_index: the index of the node (range from 0 to n-1) that the random pointer points to, 
            or null if it does not point to any node.
        
        Your code will only be given the head of the original linked list.
    
    '''
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head: return None 
        nodeMap = {None: None}
        curr = head 
        while curr:
            nodeMap[curr] = Node(curr.val)
            curr          = curr.next 
        curr = head 
        while curr:
            nodeMap[curr].next      = nodeMap[curr.next]
            nodeMap[curr].random    = nodeMap[curr.random]
            curr                    = curr.next  


        return nodeMap[head]



    def copyRandomList_slow(self, head: 'Optional[Node]') -> 'Optional[Node]':
        dummy   = Node(x=1)
        nodeMap = {}


        def dfs(index: int, node: 'Node', copy: 'Node') -> None:
            if node:
                copy.next = Node(x=node.val, next=None)
                nodeMap[node] = copy.next 
                dfs(index + 1, node.next, copy.next)
                if node.random:
                    copy.next.random = nodeMap[node.random]
        dfs(0, head, dummy)
        return dummy.next


def build_linked_list(data):
    """Convert [[val, random_index], ...] into a linked list."""
    if not data:
        return None

    nodes = [Node(val) for val, _ in data]

    for i, (_, random_index) in enumerate(data):
        if i + 1 < len(nodes):
            nodes[i].next = nodes[i + 1]

        if random_index is not None:
            nodes[i].random = nodes[random_index]

    return nodes[0]


def linked_list_to_list(head):
    """Convert a linked list into [[val, random_index], ...]."""
    nodes = []
    current = head

    while current:
        nodes.append(current)
        current = current.next

    node_indices = {node: i for i, node in enumerate(nodes)}

    result = []
    for node in nodes:
        random_index = (
            node_indices[node.random]
            if node.random is not None
            else None
        )
        result.append([node.val, random_index])

    return result


if __name__ == "__main__":
    test_cases = [
        {
            "input": [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]],
            "expected": [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]],
        },
        {
            "input": [[1, 1], [2, 1]],
            "expected": [[1, 1], [2, 1]],
        },
        {
            "input": [[3, None], [3, 0], [3, None]],
            "expected": [[3, None], [3, 0], [3, None]],
        },
    ]

    for i, test in enumerate(test_cases, start=1):
        input_head = build_linked_list(test["input"])
        actual = Solution().copyRandomList(input_head)
        actual_output = linked_list_to_list(actual)

        print(f"\nTest Case {i}")
        print(f"Want: {test['expected']}")
        print(f"Was:  {actual_output}")
        print(f"Pass: {actual_output == test['expected']}")