from collections import deque
class Solution:
    '''
    [Medium Problem]

        You are given an "m x n" grid "classroom" where a student volunteer is tasked with cleaning
        up litter scattered around the room. Each cell in the grid is one of the following:

        -   "S":    Starting position of the student.

        -   "L":    Litter that must be collected (once collected, the cell becomes empty).

        -   "R":    Reset area that restores the students energy to full capacity, regardless
                    of their current energy level (can be used multiple times).

        -   "X":    Obstacle the student cannot pass through.

        -   ".":    Empty space.

        You are also given an integer "energy", representing the students maximum energy capacity.
        The student starts with this energy from the starting point "S".

        Each move to an adjacent cell (up, down, left, right) costs 1 unit of energy. If the 
        energy reaches 0, the student can only continue if they are on a reset area "R",
        which resets the energy to its maximum capacity "energy".

        Return the minimum number of moves required to collect all litter items, or -1 if its impossible.
    
    '''

    def minMoves(self, classroom: list[str], energy: int) -> int:
        rows = len(classroom)
        cols = len(classroom[0])

        starting_row = starting_col = -1
        bit_id = [[-1] * cols for _ in range(rows)]
        litter_counter = 0
        for row in range(rows):
            for col in range(cols):
                if classroom[row][col] == 'S':
                    starting_row = row 
                    starting_col = col 
                elif classroom[row][col] == 'L':
                    bit_id[row][col] = litter_counter
                    litter_counter += 1
        masks = 1 << litter_counter
        fullMask = masks - 1
        best = [[[-1] * masks for _ in range(cols)] for _ in range(rows)]
        q = deque()
        q.append((starting_row, starting_col, 0, energy, 0))
        best[starting_row][starting_col][0] = energy
        delta_row = [-1, 1, 0, 0]
        delta_col = [0, 0, -1, 1]
        while(q):
            row, col, mask, current_energy, moves = q.popleft()
            if mask == fullMask:
                return moves
            if current_energy == 0:
                continue
            for action in range(4):
                new_row = row + delta_row[action]
                new_col = col + delta_col[action]

                if (new_row < 0     or 
                    new_row >= rows or 
                    new_col < 0     or 
                    new_col >= cols or
                    classroom[new_row][new_col] == 'X'):
                    continue
                
                new_Energy  = current_energy - 1
                new_Mask     = mask 

                if classroom[new_row][new_col] == 'L':
                    new_Mask |= (1 << bit_id[new_row][new_col])
                if classroom[new_row][new_col] == 'R':
                    new_Energy = energy
                if best[new_row][new_col][new_Mask] >= new_Energy:
                    continue
                best[new_row][new_col][new_Mask] = new_Energy
                q.append((new_row, new_col, new_Mask, new_Energy, moves + 1))

        return -1



if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().minMoves(classroom = ["S.", "XL"], energy = 2)}")

    print(f"Want : {3}, Was : {Solution().minMoves(classroom = ["LS", "RL"], energy = 4)}")

    print(f"Want : {-1}, Was : {Solution().minMoves(classroom = ["L.S", "RXL"], energy = 3)}")

    