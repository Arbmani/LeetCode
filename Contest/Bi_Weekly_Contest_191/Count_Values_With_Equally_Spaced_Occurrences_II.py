from collections import defaultdict

class Solution:
    '''
    [Medium Problem]
    
        You are given an integer array nums.

        An integer "x" is called special if:

        -   x appears at least three times in nums:

        -   All occurences of x are equally spreed in nums. In other words, if all occurences of x 
            are at indices i_1 < i_2 ... i_m, then i_2 - i_1 == i_3 - i_2 == .. == i_m - i_(m-1)

        return the number of distinct special integers in nums.
    
    '''


    def countSpecialIntegers(self, nums: list[int]) -> int:
        dick = defaultdict(list)
        for index, num in enumerate(nums):
            dick[num].append(index)
        ans = 0
        for indices in dick.values():
            if len(indices) > 2:
                dist = indices[1] - indices[0]
                ans += 1 if all(indices[i] - indices[i-1] == dist for i in range(1, len(indices))) else 0

        return ans


if __name__ == "__main__":
   print(f"Want : {2}, Was : {Solution().countSpecialIntegers(nums = [1,8,1,5,1,5,8,5])}")
   print(f"Want : {1}, Was : {Solution().countSpecialIntegers(nums = [8,8,8,8])}")
   print(f"Want : {0}, Was : {Solution().countSpecialIntegers(nums = [8,6,6,8,8])}")