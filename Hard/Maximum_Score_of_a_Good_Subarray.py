from typing import List

'''
    You are given an array of integers "nums" (0-indexed) and an integer k.

    The score of a subarray (i, j) is defined as "min(num[i], nums[i+1], ...., nums[j]) * (j - i + 1)".
    A good subarray is a subarray where "i <= k <= j.

    Return the maximum possible score of a good subarray.




'''

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left = right = k
        max_val = current_min = nums[k]

        while(left > 0 or right < n - 1):
            if left == 0:
                right += 1
            elif right == n - 1:
                left -= 1
            elif nums[left - 1] > nums[right + 1]:
                left -= 1
            else:
                right += 1

            current_min = min(current_min, nums[left], nums[right])
            max_val = max(max_val, current_min * (right - left + 1))

        return max_val


if __name__ == "__main__":
    sol = Solution()
    print(sol.maximumScore(nums = [6569,9667,3148,7698,1622,2194,793,9041,1670,1872], k = 5))