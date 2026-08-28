from typing import List

class Solution:
    '''
    The demons had captured the princess and imprisoned her in the bottom-right corner
    of a dungeon. The dungeon consists of "m x n" rooms laid out in a 2D grid. Our valiant
    knight was initially positioned in the top-left room and must fight his way through "dungeon"
    to rescue the princess.

    The knight has an initial health point represented by a positive integer. If at any point his
    health point drops to "0" or below, he dies immediately.

    Some of the rooms are guarded by demons (represented by negative integers), so the knight loses
    health upon entering these rooms; other rooms are either empty (represented as 0) or contain
    magic orbs that increase the knight's health (represented by positve integers).

    To reach the princess as quickly as possible, the knight decides to move only rightward 
    or downwward in each step. 

    Return the knight's minimum initial health so that he can rescue the princess.

    Note that any room can contain threats or power-ups, even the first room the knight
    enters and the bottom-right room where the princess is imprisoned. 
    
    '''


    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows, cols = len(dungeon), len(dungeon[0]) 
        cost = [[0] * cols for _ in range(rows)]
        cost[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1]

        for row in range(rows - 1, -1, -1):
            for col in range(cols - 1, -1, -1):
                if row == rows - 1 and col == cols - 1:
                    continue
                under = cost[row + 1][col] if row + 1 < rows else float("-inf")
                right = cost[row][col + 1] if col + 1 < cols else float("-inf")

                #print(f"under and right is : {max(under, right)}")
                #print(f"current cell    is : {dungeon[row][col]}")
                cost[row][col] = min(dungeon[row][col], dungeon[row][col] + max(under, right))

        #for row in cost:
        #    print(row)

        return 1 if cost[0][0] > 0 else abs(cost[0][0] - 1)

if __name__ == "__main__":
    print(Solution().calculateMinimumHP(dungeon = [[-3,5]]))