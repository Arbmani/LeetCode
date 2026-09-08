class Solution:
    '''
    [Medium Problem]

        You are given an integer array "nums" and an integer "sum".

        In one operation, choose an element with current value "x" and replace it with either "2 * x" or floor (x / 2).

        For each element, all multiplication operations performed on it must occur before any division operation on it.
        -   Meaning we cant divide an element and then multiply it.

        Return the minimum number of operations needed so that some subset of the resulting array has a sum exactly equal
        to sum. If it is impossible return -1. 

        The floor() function returns the integer part of the division. 
    
    '''

    def minOperations(self, nums: list[int], sum: int) -> int:
        cache       = [float("inf")] * (sum + 1)
        cache[0]    = 0

        for num in nums:
            options     = {num : 0}
            value       = num 
            operations  = 0

            while(value * 2 <= sum):
                value       *=2
                operations  += 1
                options[value] = operations

            value       = num 
            operations  = 0
            while value > 0:
                value       //= 2
                operations  += 1

                if value == 0:
                    break 
                options[value] = operations

            new_cache = cache[:]

            for current_sum in range(sum + 1):
                if cache[current_sum] == float("inf"):
                    continue
                for value, cost in options.items():
                    new_sum = current_sum + value 
                    if new_sum <= sum:
                        new_cache[new_sum] = min(new_cache[new_sum], cache[current_sum] + cost)
            cache = new_cache
        
        return -1 if cache[sum] == float("inf") else cache[sum]

if __name__ == "__main__":
    print(f"Want : { 3}, Was : {Solution().minOperations(nums = [(4 + 1), (4 + 2), (4*2 + 2)], sum = 4)}")

    print(f"Want : { 3}, Was : {Solution().minOperations(nums = [(13 - 3), (13 - 11)], sum = 13)}")

    print(f"Want : {-1}, Was : {Solution().minOperations(nums = [(8 - 2), (8 - 5)], sum = 8)}")