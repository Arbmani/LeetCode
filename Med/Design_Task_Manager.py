
import heapq


class TaskManager:
    '''
    [Medium Problem]

        There is a task management system that allows users to manage their tasks, each associated with 
        a priority. The system should efficently handle adding, modifying, executing, and removing tasks.

        Implement the TaskManager class:

        -   TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task
            priority triples. Each element in the input list is of the form [userId, taskId, priority],
            which adds a task to the specified user with the given priority.
 
        -   void add(int userId, int taskId, int prioirty) adds a task with the specified taskId and priority
            to the user with userId. It is guaranteed that taskId does not exist in the system. 

        -   void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPrioirty.
            It is guaranteed that taskId exists in the system.

        -   void rmv(int taskId) removes the task identified by taskId from the system. It is guranteed that
            taskId exists in the system.

        -   int execTop() executes the task with the highest priority across all users. If there are multiple
            tasks with the same highest priority, execute the one with the highest taskId. After executing,
            the taskId is removed from the system. Return the userId associated with the executed task.
            If not tasks are available, return -1. 
        
        Note that a user may be assigned multiple tasks.
    
    '''

    def __init__(self, tasks: list[list[int]]):
        self.tasks = {}
        self.heap  = []
        for userId, taskId, priority in tasks:
            self.add(userId, taskId, priority)


    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.tasks[taskId] = (priority, userId)
        heapq.heappush(self.heap, (-priority, -taskId))


    def edit(self, taskId: int, newPriority: int) -> None:
        _, usedId = self.tasks[taskId]
        self.tasks[taskId] = (newPriority, usedId)
        heapq.heappush(self.heap, (-newPriority, -taskId))


    def rmv(self, taskId: int) -> None:
        del self.tasks[taskId]

    def execTop(self) -> int:
        while self.heap:
            priority, taskId = heapq.heappop(self.heap)
            priority *= -1 
            taskId   *= -1 
            if taskId not in self.tasks:
                continue
            currentPriority, userId = self.tasks[taskId]
            if currentPriority != priority:
                continue
            del self.tasks[taskId]
            return userId
        return -1