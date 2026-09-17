class Solution:
    '''
    [Medium Problem]

        You are given an array of integers "arr" and an integer "target".

        You have to find two non overlapping sub arrays of arr each with a sum equal "target".
        There can be multiple answers so you have to find an answer where the sum of the lengths
        of the two sub-arrays is minimum.

        Return the minimum sum of lengths of the two required sub-arrays, or return -1 
        if you cannot find such two sub-arrays
    
    '''


    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        len_arr = len(arr)
        min_len, cum_sum, left, = len_arr + 1, 0, 0 
        cache = [len_arr] * (len_arr + 1)

        for right in range(len_arr):
            cum_sum += arr[right]
            while cum_sum > target:
                cum_sum -= arr[left]
                left   += 1
            cache[right + 1] = cache[right]
            if cum_sum == target:
                current_len      = (right - left) + 1
                cache[right + 1] = min(cache[right], current_len)
                min_len          = min(min_len, cache[left] + current_len)  

        return -1 if min_len == len_arr + 1 else min_len

# 3 4 3
# Ska ge mig -1

if __name__ == "__main__":
    print(f"Want : {6}, Was : {Solution().minSumOfLengths(arr = [1,1,1,2,2,2,4,4], target = 6)}")

    print(f"Want : {2}, Was : {Solution().minSumOfLengths(arr = [3,2,2,4,3], target = 3)}")

    print(f"Want : {2}, Was : {Solution().minSumOfLengths(arr = [7,3,4,7], target = 7)}")

    print(f"Want : {-1}, Was : {Solution().minSumOfLengths(arr = [4,3,2,6,2,3,4], target = 6)}")