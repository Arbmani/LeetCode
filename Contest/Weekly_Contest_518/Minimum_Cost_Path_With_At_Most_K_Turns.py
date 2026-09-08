import numpy as np

class Solution:
    '''
    [Hard Problem]

        You are given a 2D integer array "grid" of size "m x n", where "grid[i][j]" represents
        the cost of visiting cell "(i, j)", and an integer "k".

        You start at the "top-left" cell (0, 0) and want to reach the "bottom-right" cell "(m - 1)(n - 1)".

        From each cell, you may move one step in any four directions: up, down, left, right.

        The cost of a path is the sum of the values of all visited cells, including the starting and ending cells.
        If a cell is visisted more than once, its value is included each time it is visisted.

        Return the minimum possible path cost to reach "(m - 1)(n - 1)" using at most "k" turns. If no such 
        path exists, return -1.

        A turn occurs when the direction changes between two consecutive moves. For example, moving right and then down 
        counts as one turn, while moving right and then right does not. 
    
    
    '''


    def minCost(self, grid: list[list[int]], k: int) -> int:
        rows, cols = len(grid), len(grid[0])
        if rows == 1 and cols == 1:
            return grid[0][0]
        grid        = np.array(grid, dtype=np.int64)
        inf         = 10**18
        cache       = np.full((rows, cols), inf, dtype=np.int64)
        cache[0][0] = grid[0][0]
        for _ in range(k + 1):
            new_cache = np.full((4, rows, cols), inf, dtype=np.int64)
            for col in range(1, cols):        
                new_cache[0, :, col] = (np.minimum(new_cache[0, :, col - 1], cache[:, col - 1]) + grid[:, col])
            for col in range(cols - 2, -1, -1):    
                new_cache[1, :, col] = (np.minimum(new_cache[1, :, col + 1], cache[:, col + 1]) + grid[:, col])
            for row in range(1, rows):           
                new_cache[2, row, :] = (np.minimum(new_cache[2, row - 1, :], cache[row - 1, :]) + grid[row, :])
            for row in range(rows - 2, -1, -1):     
                new_cache[3, row, :] = (np.minimum(new_cache[3, row + 1, :], cache[row + 1, :]) + grid[row, :])
            cache = np.min(new_cache, axis = 0)
        return -1 if cache[rows - 1, cols -1] >= inf else int(cache[rows - 1, cols -1])


if __name__ == "__main__":
    print(f"Want : {12}, Was : {Solution().minCost(grid = [[2,7,3],[1,4,5]], k = 1)}")

    print(f"Want : {20}, Was : {Solution().minCost(grid = [[4,1,9],[3,2,5],[4,8,6]], k = 2)}")

    print(f"Want : {-1}, Was : {Solution().minCost(grid = [[1,9],[3,4]], k = 0)}")