import heapq 
class Solution:
    '''
    [Medium Problem]

        You are a hiker preparing for an upcoming hike. You are given heights, 
        a 2D array of size rows x columns, where heights[row][col] represents the 
        height of cell (row, col). 
        
        You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, 
        (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, 
        and you wish to find a route that requires the minimum effort.
    
        A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

        Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
    
    '''

    def minimumEffortPath(self, heights: list[list[int]]) -> int:
        rows, cols      = len(heights), len(heights[0])
        min_Heap        = [(0, 0, 0)]  # starting top-left cell, (0, 0) distance = 0
        distance        = [[float("inf")] * cols for _ in range(rows)]
        distance[0][0]  = 0
        moves           = [(-1, 0), (1, 0), (0, -1), (0, 1)]


        while min_Heap:
            dist, row, col = heapq.heappop(min_Heap)
            if dist > distance[row][col]            : continue
            if row == rows -1 and col == cols - 1   : return dist

            for dr, dc in moves:
                nr, nc = row + dr, col + dc 
                if 0 <= nr < rows and 0 <= nc < cols:
                    new_dist     = max(dist, abs(heights[row][col] - heights[nr][nc]))
                    if new_dist < distance[nr][nc]:
                        distance[nr][nc] = new_dist 
                        heapq.heappush(min_Heap, (new_dist, nr, nc))
        return 0


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().minimumEffortPath(heights = [[1,2,2],[3,8,2],[5,3,5]])}")
    print(f"Want : {1}, Was : {Solution().minimumEffortPath(heights = [[1,2,3],[3,8,4],[5,3,5]])}")
    print(f"Want : {0}, Was : {Solution().minimumEffortPath(heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]])}")