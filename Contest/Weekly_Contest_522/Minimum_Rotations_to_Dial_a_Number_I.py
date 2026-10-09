class Solution:
    '''
    [Easy Problem]

        You are given a string s of length 10 consisting of digits.

        The dial contains the digits 0 through 9 in order and is circular, 
        so 0 and 9 are adjacent. The pointer initially points to 0.

        To dial each digit of s in order, 
        rotate the pointer until it points to that digit. 
        Each rotation moves the pointer to an adjacent digit, 
        and you may rotate in either direction. 
        Dialing a digit that the pointer already points to requires no rotations.

        Return the minimum total number of rotations needed to dial every digit of s.
    
    
    
    '''
    # -9 till 9 
    # 0 -> 0: 0

    # 0 -> 1: 1 
    # 0 -> 9: 1

    # 0 -> 2: 2
    # 0 -> 8: 2 

    # 0 -> 3: 3
    # 0 -> 7: 3 

    # 0 -> 4: 4
    # 0 -> 6: 4 

    # 0 -> 5: 5
    # 0 -> 5: 5 



    def minRotations(self, s: str) -> int:
        start = 0
        ans   = 0
        for char in s:
            end     = int(char)
            ans     += min(abs(end - start), 10 - abs(end - start))
            start   = end


        return ans


if __name__ == "__main__":
    print(f"Want : {25}, Was : {Solution().minRotations(s = "0192837465")}")
    print(f"Want : {12}, Was : {Solution().minRotations(s = "1200210200")}")