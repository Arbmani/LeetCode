'''

------------------------------    
    60. Permutation Sequence
------------------------------    

        The set [1, 2, 3, ..., n] contains a total of "n!" unique permutations

        By listing and labeling all of the permutations in order, we get the following sequence for "n = 3":

            1.  "123"
            2.  "132"
            3.  "213"
            4.  "231"
            5.  "312"
            6.  "321"

        Given "n" and "k" return the Kth permutation sequence.

---------------    
    Notes:
---------------  

    If "k = 1" we return a sorted list
    If "k = n!" we return a reversed sorted list


    4123
    42


'''

import math 


import math

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        list_of_numbers = list(range(1, n + 1))
        result = []

        fact = [1] * n
        for i in range(1, n):
            fact[i] = fact[i - 1] * i

        k -= 1
        print(fact)
        for i in range(n - 1, -1, -1):
            bucket_size = fact[i]


            index = k // bucket_size
            k %= bucket_size

            result.append(list_of_numbers.pop(index))


        return "".join(map(str, result))


if __name__ == "__main__":
    sol = Solution()
    print(sol.getPermutation(4, 6))
