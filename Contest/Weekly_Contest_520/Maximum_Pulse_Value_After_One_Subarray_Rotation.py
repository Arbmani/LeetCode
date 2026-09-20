class Solution:
    '''
    [Medium Problem]

        You are given an integer array "nums" of length "n".

        Define the pulse value of an integer array "arr" as the alternating sum starting
        at index 0: pulse(arr) == arr[0] - arr[1] + arr[2] - arr[3] + ...

        You may perform at most one operation on nums:

        -   Choose two indices left and right such that 0 <= left < right < n

        -   Left-rotate the subarray nums[left ... right] by excatly one position
            For example, [a, b, c, d] becomes [b, c, d, a]
        
        Return the maximum pusle value that can be obtained after performing at most one such operation.


    
    
    '''

    def maxValue(self, nums: list[int]) -> int:
        ans = 0
        max_even, max_odd, max_improvement  = 0, float("-inf"), float("inf")
        for index, num in enumerate(nums):
            if index % 2:
                ans -= num
                max_improvement = min(max_improvement, ans - max_even)
                max_even        = max(max_even, ans)
            else:
                ans += num 
                max_improvement = min(max_improvement, ans - max_odd)
                max_odd         = max(max_odd, ans)

        return ans - (2 * min(0, max_improvement))

if __name__ == "__main__":
    print(f"Want : {6} Was : {Solution().maxValue(nums = [1,5,2])}")

    print(f"Want : {7} Was : {Solution().maxValue(nums = [6,4,3])}")

    print(f"Want : {2} Was : {Solution().maxValue(nums = [9,7])}")