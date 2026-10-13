class Solution:
    '''
    [Hard Problem]

        You are given a 0-indexed integer array nums and a positive integer k.

        You can do the following operation on the array any number of times:

        -   Choose any two distinct indices i and j and simultaneously update the values of 
            nums[i] to (nums[i] AND nums[j]) and nums[j] to (nums[i] OR nums[j]). 
            Here, OR denotes the bitwise OR operation, and AND denotes the bitwise AND operation.

        You have to choose k elements from the final array and calculate the sum of their squares.

        Return the maximum sum of squares you can achieve.

        Since the answer can be very large, return it modulo 10^9 + 7.

    '''
    # 0 : 000 : 0
    # 1 : 000 : 1
    # 2 : 00  : 10
    # 3 : 00  : 11
    # 4 : 0   : 100
    # 5 : 0   : 101
    # 6 : 0   : 110
    # 7 : 0   : 111
    # 8 :     : 1000
    # 15:     : 1111
    
    # Makes sense to force as many numbers into largest as possible
    def maxSum(self, nums: list[int], k: int) -> int:
        modulo = 10**9 + 7
        largest_bit = max(nums).bit_length()
        bit_countR  = [0] * largest_bit

        for num in nums:
            for bit in range(largest_bit):
                if num & (1 << bit):
                    bit_countR[bit] +=1

        ans = 0
        for _ in range(k):
            num = 0
            for bit in range(largest_bit):
                if bit_countR[bit] > 0:
                    num |= 1 << bit
                    bit_countR[bit] -=1
            ans = (ans + num * num) % modulo
        return ans  




if __name__ == "__main__":
    print(f"Want : {261}, Was : {Solution().maxSum(nums = [2,6,5,8], k = 2)}")
    print(f"Want : {450}, Was : {Solution().maxSum( nums = [15, 15, 15,15], k = 2)}")
    print(f"Want : {90}, Was : {Solution().maxSum( nums = [4,5,4,7], k = 3)}")

    