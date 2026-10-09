import heapq
class Solution:
    '''
    [Hard Problem]
        
        You are given an n x n integer matrix grid where each value grid[i][j]
        represents the elevation at that point (i, j).

        It starts raining, and water gradually rises over time. 
        At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

        You can swim from a square to another 4-directionally adjacent square 
        if and only if the elevation of both squares individually are at most t. 
        
        You can swim infinite distances in zero time. 
        Of course, you must stay within the boundaries of the grid during your swim.

        Return the minimum time until you can reach the bottom right square (n - 1, n - 1) 
        if you start at the top left square (0, 0).

    '''
    
    def swimInWater(self, grid: list[list[int]]) -> int:
        rows, cols      = len(grid), len(grid[0])
        min_Heap        = [(0, 0, grid[0][0])]
        distance        = [[float("inf")] * cols for _ in range(rows)]
        distance[0][0]  = grid[0][0]
        moves           = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while min_Heap:
            row, col, dist = heapq.heappop(min_Heap)
            if dist > distance[row][col]: continue
            if row == rows - 1 and col == cols - 1: return dist 
            for dr, dc in moves:
                nr, nc = row + dr, col + dc
                if not(0 <= nr < rows and 0 <= nc < cols): continue
                new_dist = max(dist, grid[nr][nc])
                if new_dist < distance[nr][nc]:
                    distance[nr][nc] = new_dist
                    heapq.heappush(min_Heap, (nr, nc, new_dist))
        return -1



if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().swimInWater(grid = [[0,2],[1,3]])}")
    print(f"Want : {16}, Was : {Solution().swimInWater(grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]])}")