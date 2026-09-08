
from collections import deque
class Solution:
    '''
    [Hard Problem]

        You are given an integer array "nums" and an integer "sum".

        In one operation, choose an element with current value "x" and replace it with either "2 * x" 
        or "floor(x / 2)".

        For each element, multiplication and division operations may be performed in any order.

        Return the minimum number of operations needed so that some subset of the resulting array 
        has a sum exactly equal to "sum". If it is impossible return -1.

        The floor() function returns the integer part of the division.


    '''


    def minOperations(self, nums: list[int], sum: int) -> int:
        cache    = [float("inf")] * (sum + 1)
        cache[0] = 0

        for num in nums:
            options = {num: 0}
            queue   = deque([num])

            while queue:
                value = queue.popleft()
                cost  = options[value]

                next_value = value // 2
                if next_value not in options:
                    options[next_value] = cost + 1
                    queue.append(next_value)
                if value <= sum:
                    next_value = value * 2
                    if next_value not in options:
                        options[next_value] = cost + 1
                        queue.append(next_value)
            new_cache = cache[:]
            for current_sum in range(sum + 1):
                if cache[current_sum] == float("inf"):
                    continue
                for value, cost in options.items():
                    if value == 0:
                        new_cache[current_sum] = min(new_cache[current_sum], cache[current_sum] + cost)
                        continue
                    new_sum = current_sum + value
                    if new_sum <= sum:
                        new_cache[new_sum] = min(new_cache[new_sum], cache[current_sum] + cost)
            cache = new_cache

        return -1 if cache[sum] == float("inf") else cache[sum]


if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().minOperations(nums = [10,2], sum = 13)}")

    print(f"Want : {2}, Was : {Solution().minOperations(nums = [6,3], sum = 8)}")

    print(f"Want : {-1}, Was : {Solution().minOperations(nums = [2,2], sum = 7)}")