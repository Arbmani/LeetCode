from typing import List

class Solution:
    '''
        Given an "m x n" grid of characters "board" and a string "word", return true if word exists in the grid.

        The word can be constructed from letters of sequentially adjacent cells, where adjacent cells
        are horizontally or vertically neighboring. The same letter cell may not be used 
        more than once. 
    
    
    '''


    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        def Depth_First_Search(row: int, col: int, index: int) -> bool:
            nonlocal board
            if index == len(word):
                return True
            if (row < 0 or rows <= row or 
                col < 0 or cols <= col or
                board[row][col] != word[index]):
                return False
            temp = board[row][col]
            board[row][col] = ''
            if (Depth_First_Search(row + 1, col, index + 1) or 
                Depth_First_Search(row - 1, col, index + 1) or 
                Depth_First_Search(row, col + 1, index + 1) or 
                Depth_First_Search(row, col - 1, index + 1)):
                return True
            board[row][col] = temp
            return False
        for row in range(rows):
            for col in range(cols):
                if Depth_First_Search(row, col, 0):
                    return True
        return False 

if __name__ == "__main__":
    print(Solution().exist(board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"))