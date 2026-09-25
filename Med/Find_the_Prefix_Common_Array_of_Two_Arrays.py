class Solution:
    '''
    [Medium Problem]

        You are given two 0-indexed integer permutations A and B of length n.

        A prefix common array of A and B is an array C such that C[i] is equal to the 
        count of number that are present at or before the index i in both A and B.

        Return the prefix common array of A and B.

        A sequence of n integers is called a permutation if it contains all integers 
        from 1 to n exactly once.
    
    
    '''

    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        freak_A, freak_B = {}, {}
        ans, common = [], 0
        for index, num_A, in enumerate(A):
            num_B = B[index]
            freak_A[num_A] = freak_A.get(num_A, 0) + 1
            freak_B[num_B] = freak_B.get(num_B, 0) + 1
            if num_A == num_B: common += 1
            else:
                if freak_B[num_B] == freak_A.get(num_B, 0):
                    common += 1
                if freak_A[num_A] == freak_B.get(num_A, 0):
                    common += 1
            ans.append(common)

        return ans

if __name__ == "__main__":
    print(f"Want : {[0,2,3,4]}, Was : {Solution().findThePrefixCommonArray(A = [1,3,2,4], B = [3,1,2,4])}")

    print(f"Want : {[0,1,3]}, Was : {Solution().findThePrefixCommonArray(A = [2,3,1], B = [3,1,2])}")