from typing import List
from collections import defaultdict

'''
    The solution works well because it uses the right data structure for the job. 
    Instead of repeatedly scanning rows, columns and boxes looking for duplicates,
    it remembers what it has already seen.

    Lets walk throught the idea.

    
------------------------------------
    Without sets (slow approach)
------------------------------------


    Suppose you're at cell (4, 7) containing "5".

    To check if its valid, you might:

        - Scan the entire row       (9 cells)

        - Scan the entire column    (9 cells)

        - Scan the entire box       (9 cells)

    Thats 27 comparisions for every filled cell.


    

---------------
    With sets
---------------
    
    1. You keep three dictionaries

    2. As you visit each cell, you immediately record its value, into these dictonaries.

    3. And check if this value has been encountered before in constant time.    

    Each dictionary enforces one Sudoku rule. 

    1. Rows tracks what number have appeared in each row.

    2. Cols tracks what numbers have appeared in each column.

    3. Squares tracks what numbers have appeared in each box.

        And the key to squares maps cells to one of the nine boxes. 


---------------
    Notes
---------------
    
    The solution does NOT prove that the sudoku is solvable. 
    
    It only proves that the current filled-in cells do not violate Sudoku rules.






'''


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> None:
        cols    = defaultdict(set)
        rows    = defaultdict(set)
        squares = defaultdict(set)

        for row in range(9):
            for col in range(9):
                if board[row][col] == ".":
                    continue
                if (board[row][col] in rows[row] or
                    board[row][col] in cols[col] or
                    board[row][col] in squares[row // 3, col // 3]):
                    return False
                cols[col].add(board[row][col])
                rows[row].add(board[row][col])
                squares[(row // 3, col // 3)].add(board[row][col])
        return True

if __name__ == "__main__":
    print("hello world")
    sol = Solution()
    sol.isValidSudoku(None)