from sortedcontainers import SortedList
class Solution:
    '''
    [Hard Problem]

        You are given an integer array "nums" of length "n".

        A pair of indices (i, j) is called a shadow pair if all
        of the following conditions are satisfied:

        -   0 <= i < j < n

        -   min(middle) <= nums[i] < nums[j]

        -   There does not exist an index "k" such that i < k < j and 
            nums[i] < nums[k] < nums[j].

        Return the total number of shadow pairs. 
    
    
    '''
    # Copied
    def shadowPairs(self, nums: list[int]) -> int:
        ASK, OPEN, CLOSE = 0, 1, 2
        def count_crossing(left: int, right: int) -> int:
            events, seen = [], SortedList([float("inf")])
            for low in reversed(left):
                ceiling = seen[seen.bisect_right(low)]
                events += [(low, OPEN, low), (ceiling, CLOSE, low)]
                seen.add(low)
            seen = SortedList([float("-inf")])
            for high in right:
                floor = seen[seen.bisect_left(high) - 1]
                events.append((high, ASK, floor))
                seen.add(high)
            count, active = 0, SortedList()
            for value, kind, payload in sorted(events):
                if kind == OPEN:
                    active.add(payload)
                elif kind == CLOSE:
                    active.remove(payload)
                else:
                    count += len(active) - active.bisect_left(payload)
            return count
        def solve(nums: list[int]) -> int:
            if len(nums) <= 1:
                return 0
            mid = len(nums) // 2
            left, right = nums[:mid], nums[mid:]
            return solve(left) + solve(right) + count_crossing(left, right)
        return solve(nums)

if __name__ == "__main__":
    print(f"Want : {5}, Was : {Solution().shadowPairs(nums = [3,1,4,2,5])}")

    print(f"Want : {3}, Was : {Solution().shadowPairs(nums = [6,7,8,9])}")

