class Node:
    def __init__(self, key: int, value: int):
        self.key, self.value  = key, value 
        self.prev = self.next = None
        

class LRUCache:
    '''
    [Medium Problem]

        Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

        Implement the LRUCache class:

        -   LRUCache(int capacity) Initializes the LRU cache with positive size capcaity.

        -   int get(int key) Return the value of the key if they exists, otherwise return -1.

        -   void put(int key, int value) Update the value of the key if the key exists. Otherwise,
            add the key-value pair to the cache. If the number of keys exceeds the capacity from
            this operation, evict the least recently used key.

        The function get and put much each run in O(1) average time complexity.
    
    
    '''

    def __init__(self, capacity: int):
        self.capacity   = capacity
        self.cache      = {}
        self.left, self.right = Node(0,0), Node(0,0)
        self.left.next, self.right.prev = self.right, self.left

    def remove(self, node: Node) -> None:
        prv, nxt           = node.prev, node.next 
        prv.next, nxt.prev = nxt, prv

    # Insert Node as Most Recently Used:
    def insert(self, node: Node) -> None:
        prv, nxt  = self.right.prev, self.right 
        prv.next  = nxt.prev = node 
        node.next = nxt 
        node.prev = prv 

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].value
        return -1
    
    def put(self, key: int, value: int) -> None: 
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])
        if len(self.cache) > self.capacity:
            Least_Recently_Used_Node = self.left.next
            self.remove(Least_Recently_Used_Node)
            del self.cache[Least_Recently_Used_Node.key]

if __name__ == "__main__":
    '''
    Your LRUCache object will be instantiated and called as such:

        obj = LRUCache(capacity)
        param_1 = obj.get(key)
        obj.put(key, value)
    
    '''
    print("Least Recently Used (LRU) Cache")