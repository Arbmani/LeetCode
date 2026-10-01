class Solution:
    '''
    [Hard Problem]

        You are given an m x n integer array grid where grid[i][j] could be:
       
        -   1 representing the starting square. There is exactly one starting square.
        
        -   2 representing the ending square. There is exactly one ending square.
        
        -   0 representing empty squares we can walk over.
        
        -   -1 representing obstacles that we cannot walk over.
        
        Return the number of 4-directional walks from the starting square to the ending square, 
        that walk over every non-obstacle square exactly once.
    
    
    
    '''
    # best 
    def uniquePathsIII(self, grid: list[list[int]]) -> int: 
        rows, cols = len(grid), len(grid[0])
        start      = end = empty = 0
        cell_id    = [[-1] * cols for _ in range(rows)]
        cells      = []

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] != -1:
                    cell_id[row][col] = len(cells)
                    cells.append((row, col))

                    if grid[row][col] == 1:
                        start = cell_id[row][col]
                    elif grid[row][col] == 2:
                        end   = cell_id[row][col]
        empty = len(cells)
        valid_moves = [[] for _ in range(empty)]
        for i, (row, col) in enumerate(cells):
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                newRow = row + dr 
                newCol = col + dc 
                if 0 <= newRow < rows and 0 <= newCol < cols:
                    next_cell = cell_id[newRow][newCol]
                    if next_cell != -1:
                        valid_moves[i].append(next_cell)
        target = (1 << empty) - 1
        memo = {}
        def dfs(pos, visited):
            if pos == end: return int(visited == target)
            state = (pos, visited)
            if state in memo:
                return memo[state]
            ans = 0
            for next_pos in valid_moves[pos]:
                bit = 1 << next_pos
                if not visited & bit: 
                    ans += dfs(next_pos, visited | bit)
            memo[state] = ans 
            return ans 
        return dfs(start, 1 << start)






    def uniquePathsIII_fast(self, grid: list[list[int]]) -> int: 
        rows, cols = len(grid), len(grid[0])
        start = end = empty = 0
        cell_id = [[-1] * cols for _ in range(rows)]
        cells   = []

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] != -1:
                    cell_id[row][col] = len(cells)
                    cells.append((row, col))
                    if grid[row][col] == 1:
                        start = cell_id[row][col]
                    elif grid[row][col] == 2:
                        end = cell_id[row][col]
        empty = len(cells)
        valid_moves = [[] for _ in range(empty)]
        for i, (row, col) in enumerate(cells):
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                newRow = row + dr 
                newCol = col + dc 

                if 0 <= newRow < rows and 0 <= newCol < cols:
                    next_cell = cell_id[newRow][newCol]
                    if next_cell != -1:
                        valid_moves[i].append(next_cell)
        target = (1 << empty) - 1
        def dfs(pos, visited):
            if pos == end: return int(visited == target)
            ans = 0
            for next_pos in valid_moves[pos]:
                bit = 1 << next_pos
                if not visited & bit:
                    ans += dfs(next_pos, visited | bit)
            return ans 
        return dfs(start, 1 << start) 





    def uniquePathsIII_slow(self, grid: list[list[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        empty = set()
        start = (float("inf"), float("inf"))
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] % 2 == 0: empty.add((row, col))
                elif grid[row][col] == 1: start = (row, col)
        ans = 0
        valid_moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        def dfs(row, col):
            nonlocal ans 
            if grid[row][col] == 2: 
                ans += 1 if not empty else 0
            for dr, dc in valid_moves:
                if ((0 <= row + dr < rows and 0 <= col + dc < cols) and 
                    (row + dr, col + dc) in empty):
                    empty.remove((row + dr, col + dc)) 
                    dfs(row + dr, col + dc)
                    empty.add((row + dr, col + dc)) 
 
        dfs(start[0], start[1])
        return ans


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().uniquePathsIII(grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]])}")

    print(f"Want : {4}, Was : {Solution().uniquePathsIII(grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]])}")

    print(f"Want : {0}, Was : {Solution().uniquePathsIII(grid = [[0,1],[2,0]])}")

