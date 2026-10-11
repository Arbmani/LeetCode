class MinStack:
    '''
        [Medium Problem]

        Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

        Implement the MinStack class:

        -   MinStack() initializes the stack object.

        -   void push(int value) pushes the element value onto the stack.

        -   void pop() removes the element on the top of the stack.

        -   int top() gets the top element of the stack.
        
        -   int getMin() retrieves the minimum element in the stack.

        You must implement a solution with O(1) time complexity for each function.
    
    
    '''



    def __init__(self):
        self.memory = []
        self.min    = []

    def push(self, value: int) -> None:
        self.memory.append(value)
        if not self.min or value <= self.min[-1]:
            self.min.append(value)
        else:
            self.min.append(self.min[-1])

    def pop(self) -> None:
        self.memory.pop()
        self.min.pop()

    def top(self) -> int:
        return self.memory[-1]
    
    def getMin(self) -> int:
        return self.min[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()