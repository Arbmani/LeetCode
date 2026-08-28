from typing import List
from collections import defaultdict



class Solution:
    def isValidSudoku(self, board: List[List[str]]):
        rows = defaultdict(set)
        cols = defaultdict(set)
        boxes = defaultdict(set)
        dot_dict = {}


        for row in range(9):
            for col in range(9):
                current_value = board[row][col]
                if current_value == ".":
                    dot_dict[len(dot_dict)] = (row, col)
                    continue
                if (current_value in rows[row] or
                    current_value in cols[col] or
                    current_value in boxes[row // 3, col //3]):
                    return None, None, None, None
                rows[row].add(int(current_value))
                cols[col].add(int(current_value))
                boxes[row // 3, col //3].add(int(current_value))
        return rows, cols, boxes, dot_dict

    def Minimum_Remaining_Values(self, rows, cols, boxes, dot_dict):
        least_index             = None 
        least_remaining_values  = None

        for index, (row, col) in dot_dict.items():
            remaining_values = []
            for num in range(1, 10):
                if (num not in rows[row] and
                    num not in cols[col] and
                    num not in boxes[row // 3, col //3]):

                    remaining_values.append(num)

            if least_remaining_values is None or len(remaining_values) < len(least_remaining_values):
                least_remaining_values = remaining_values
                least_index = index 
                if len(least_remaining_values) <= 1:
                    break

        return least_index, least_remaining_values

    def solveSudoku(self, board: List[List[str]]) -> None:
        rows, cols, boxes, dot_dict = self.isValidSudoku(board)


        def Depth_First_Search(rows, cols, boxes, dot_dict, board):
            if not dot_dict:
                return board
            
            index, remaining_values = self.Minimum_Remaining_Values(rows, cols, boxes, dot_dict)
            (row, col) = dot_dict[index]
            dot_dict.pop(index)

            for num in remaining_values:
                rows[row].add(num)
                cols[col].add(num)
                boxes[row // 3, col //3].add(num)
                board[row][col] = str(num) 

                result = Depth_First_Search(
                    rows,
                    cols,
                    boxes,
                    dot_dict,
                    board)
                if result:
                    return result

                rows[row].remove(num)
                cols[col].remove(num)
                boxes[row//3, col//3].remove(num)
                board[row][col] = "."
            dot_dict[index] = (row, col)
            return None
        #print(Depth_First_Search(rows, cols, boxes, dot_dict, board))
        return Depth_First_Search(rows, cols, boxes, dot_dict, board)



if __name__ == "__main__":
    sol = Solution()
    sol.solveSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])