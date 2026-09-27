class Solution:
    '''
    [Easy Problem]

        There is an "8 x 8" empty chessboard with 1-indexed rows and columns.

        You are given an array source = [sr, sc] representing the starting position
        of a queen, and an array target = [tr, tc] representing the target position.

        In one move, the queen travels one or more squares along a single row, column, or
        diagonal, staying within the board.

        Return the minimum number of moves for the queen to land exactly on target. 
    
    
    '''

    def minQueenMoves(self, source: list[int], target: list[int]) -> int:
        if source == target: return 0
        if (source[0] == target[0] or 
            source[1] == target[1] or 
            (abs(source[0] - target[0]) == abs(source[1] - target[1]))): return 1

        return 2


if __name__ == "__main__":
    print(f"Want : {1}, Was : {Solution().minQueenMoves(source = [8,1], target = [7,2])}")
    print(f"Want : {1}, Was : {Solution().minQueenMoves(source = [8,1], target = [1,8])}")
    print(f"Want : {2}, Was : {Solution().minQueenMoves(source = [4,2], target = [1,3])}")
    print(f"Want : {0}, Was : {Solution().minQueenMoves(source = [1,1], target = [1,1])}")