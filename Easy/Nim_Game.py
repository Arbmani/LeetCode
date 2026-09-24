class Solution:
    '''
    [Easy Problem]

        You are playing the following Nim Game with your friend:

        -   Initially, there is a heap of stones on the table

        -   You and your friend will alternate taking turns, and you go first.

        -   On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.

        -   The one who removes the last stone is the winner

    Given "n", the number of stones in the heap, return true if you can win the game assuming
    both you and your friend play optimally, otherwise return false. 
    
    
    '''
    #   If last stones are 4 we lose 
    #   If last stones are 5 we win
    #   If last stones are 6 -> 1 5 
    #   If last stones are 7 -> we win


    def canWinNim(self, n: int) -> bool:
        return False if n % 4 == 0 else True




if __name__ == "__main__":
    print(f"Want : {False}, Was : {Solution().canWinNim(4)}")
    print(f"Want : {True}, Was : {Solution().canWinNim(1)}")
    print(f"Want : {True}, Was : {Solution().canWinNim(2)}")