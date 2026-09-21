class Solution:
    '''
    [Medium Problem]

        You are given an array of positive integers "nums", and a positive integer "k".

        You are allowed to perform an operation once on nums, where in each operation
        you can remove any non-overlapping prefix and suffix from nums such that 
        nums remains non-empty.

        You need to find the x-value of nums, which is the number of ways to perform
        this operation so that the product of the remaining elements leaves a 
        remainder of "x" when divided by "k".

        Return an array result of size "k" where result[x] is the x-value of 
        nums for 0 <= x <= k -1

        A prefix of an array is a subarray that starts from the beginning
        of the array and extends to any point within it.

        A suffix of an array is a subarray that starts at any point within
        the array and extends to the end of the array.

        Note that the prefix and suffix to be chosen for the operation can be empty. 
    
    '''
    def resultArray(self, nums: list[int], k: int) -> list[int]:
        dp, res = [0] * k, [0] * k
        for num in nums:
            num    %= k 
            new_dp  = [0] * k 
            new_dp[num] += 1
            for product in range(k):
                new_product = (product * num) % k 
                new_dp[new_product] += dp[product]
            dp = new_dp 
            for product in range(k):
                res[product] += dp[product]
        return res


    def resultArray_verySlow(self, nums: list[int], k: int) -> list[int]:
        len_nums = len(nums)
        nums     = [num % k for num in nums]
        res      = [0] * k 

        for req in range(k):
            dp = {}
            def solve(i, prevProd):
                if i >= len_nums:
                    return 0
                if (i, prevProd) in dp:
                    return dp[(i, prevProd)]
                skip = take = 0
                if prevProd == k:
                    skip = solve(i + 1, k)
                    curProd = nums[i]
                else:
                    curProd = (prevProd * nums[i]) % k 
                take += 1 if curProd == req else 0
                take += solve(i + 1, curProd)
                dp[(i, prevProd)] = take + skip 
                return dp[(i, prevProd)]
            res[req] = solve(0, k)


        return res



if __name__ == "__main__":
    print(f"Want : {[9,2,4]}, Was : {Solution().resultArray(nums = [1,2,3,4,5], k = 3)}")

    print(f"Want : {[18,1,2,0]}, Was : {Solution().resultArray(nums = [1,2,4,8,16,32], k = 4)}")

    print(f"Want : {[9,6]}, Was : {Solution().resultArray(nums = [1,1,2,1,1], k = 2)}")