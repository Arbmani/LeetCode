from collections import defaultdict
class Solution:
    '''
    [Easy Problem]

        You are given an integer array "nums"

        An integer x is called special if :

        -   X appears exactly three times in num

        -   All three occurences of x are equally spaced in nums. In other words
            if all occurrences of x are at indices i_1, i_2, i_3 then i_2 - i_1 = i_3 - i_2.

        Return the number of distinct special integers in nums.

    '''

    def countSpecialIntegers(self, nums: list[int]) -> int:
        data = defaultdict(list)
        for index, num in enumerate(nums):
            data[num].append(index)
        res = 0
        for indexes in data.values():
            if len(indexes) == 3 and (indexes[1] - indexes[0] == indexes[2] - indexes[1]):
                res += 1

        return res


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().countSpecialIntegers(nums = [1,8,1,5,1,5,8,5])}")
    print(f"Want : {0}, Was : {Solution().countSpecialIntegers(nums = [8,8,8,8])}")
    print(f"Want : {0}, Was : {Solution().countSpecialIntegers(nums = [8,6,6,8,8])}")