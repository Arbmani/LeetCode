from typing import List

class Solution:
    '''
        You are given an integer array "pref" of size "n". Find and 
        return the array "arr" of size "n" that satisfies:

            - pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]

            is equal to:

            - pref[i] = pref[ i - 1] ^ arr[i]

            is equal to:

            arr[i] = pref[i] ^ pref[i - 1]


        Note that ^ denotes the bitwise-xor operation.

        It can be proven that the answer is unique.

        0 = 000
        1 = 001
        2 = 010
        3 = 011
        4 = 100
        5 = 101

        010 xor 101 = 111 or 7
    
    '''


    def findArray(self, pref: List[int]) -> List[int]:
        arr     = [0] * len(pref)
        arr[0]  = pref[0] 

        for i in range(1, len(pref)):
            arr[i] = pref[i - 1] ^ pref[i]
        return arr


if __name__ == "__main__":
    print(Solution().findArray(pref = [5, 2, 0, 3, 1]))