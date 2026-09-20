class Solution:
    '''
    [Easy Problem]

        You are given an integer "n", a 2D integer array grid of size "n x n", and two 
        integer arrays rowShift, and colShift, each of length n, where:

        -   rowShift[i] represents the number of positions to cyclically shift the "ith" row of grid to the left.

        -   colShift[i] represents the number of positions to cyclically shift the "jth" column of grid upward.

        First, cyclically shift each row according to rowShift, then cyclically shift each column
        of the resulting grid according to colShift.

        Return the resulting grid after performing all the shifts. 

        A cyclic left shift of a row by "k" positions moves the element at column "j"
        to column (j - k + n) % n. All other rows remain unchanged.

        A cyclic upward shift of a column by k positions moves the element at row i
        to row (i - k + n) % n. All other columns remain unchanged. 
    
    
    '''

    def cyclicShift(self, n: int, grid: list[list[int]], rowShift: list[int], colShift: list[int]) -> list[list[int]]:
        for row, shift in enumerate(rowShift):
            shift %= n 
            if shift == 0:
                continue
            grid[row] = grid[row][shift:] + grid[row][:shift]
        for col, shift in enumerate(colShift):
            shift %= n 
            if shift == 0:
                continue
            column = [grid[row][col] for row in range(n)]
            column = column[shift:] + column[:shift]
            for row in range(n):
                grid[row][col] = column[row]
        return grid



if __name__ == "__main__":
    print(f"Want : {[[2,4],[3,1]]}, Was : {Solution().cyclicShift(n = 2, grid = [[1,2],[3,4]], rowShift = [1,0], colShift = [0,1])}")

    print(f"Want : {[[7,8,5],[2,3,9],[6,4,1]]}, Was : {Solution().cyclicShift( n = 3, grid = [[1,2,3],[4,5,6],[7,8,9]], rowShift = [1,2,0], colShift = [2,2,1])}")