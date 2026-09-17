class Solution:
    '''
    [Easy Problem]

        Given an integer array nums and an integer k, return the smallest 
        positive multiple of k that is missing from nums. 

        A multiple of k is any positive integer divisible by k.

    '''


    def missingMultiple(self, nums: list[int], k: int) -> int:
        seen = set(nums)
        multiple = k 
        while multiple in seen:
            multiple += k 
        return multiple


if __name__ == "__main__":
    print(f"Want : {10}, Was : {Solution().missingMultiple( nums = [8,2,3,4,6], k = 2)}")

    print(f"Want : {5}, Was : {Solution().missingMultiple(nums = [1,4,7,10,15], k = 5)}")


