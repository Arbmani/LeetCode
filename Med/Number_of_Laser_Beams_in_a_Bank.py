class Solution:
    '''
    [Medium Problem]
    
        Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank
        representing the floor plan of the bank, which is an "m x n" 2D matrix. bank[i] represents the ith row,
        consisting of '0's and '1's. '0' mean the cell is empty, while '1' means the cell has a security device.

        There is one laser beam between any two security devices if both conditions are met:

        -   The two devices are located on two different rows r_1 and r_2 where r_1 < r_2.

        -   For each row i where r_1 < i < r_2, there are no security devices in the ith row

        Laser beams are independent, i.e., one beam does not interfere nor join with another.

        Return the total number of laser beams in the bank. 
    
    
    
    '''

    def numberOfBeams(self, bank: list[str]) -> int:
        ans = prev = 0 
        for row in bank:
            curr = row.count('1')
            ans += prev * curr
            if curr: prev = curr 
        return ans 


if __name__ == "__main__":
    print(f"Want : {8}, Was : {Solution().numberOfBeams(bank = ["011001","000000","010100","001000"])}")
    print(f"Want : {0}, Was : {Solution().numberOfBeams(bank = ["000","111","000"])}")