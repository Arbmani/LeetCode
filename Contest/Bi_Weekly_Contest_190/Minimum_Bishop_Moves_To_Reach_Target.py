class Solution:
    '''
    [Medium Problem]

        There are an 8x8 empty chessboard with 1-indexed rows and columns.

        You are given an array "source = [sr, sc]" representing the starting position
        of a bishop, and an array "taget = [tr, tc]" representing the target position.

        In one move, the bishop travels one or more squares along a single diagonal
        direction, staying within the board.

        Return the minimum number of moves for the bishop to land exactly on target.
        If it can never reach target return -1. 
    
    
    '''


    def minBishopMoves(self, source: list[int], target: list[int]) -> int:
        sr, sc = source[0], source[1]
        tr, tc = target[0], target[1]
        if (sr + sc) % 2 != (tr + tc) % 2:
            return -1
        if (abs(sr - tr) == abs(sc - tc)):
            return 1
        return 2

if __name__ == "__main__":
    print(f"Want : {1}, Was : {Solution().minBishopMoves(source = [8,1], target = [1,8])}")

    print(f"Want : {2}, Was : {Solution().minBishopMoves(source = [4,2], target = [1,3])}")

    print(f"Want : {-1}, Was : {Solution().minBishopMoves(source = [1,1], target = [3,4])}")