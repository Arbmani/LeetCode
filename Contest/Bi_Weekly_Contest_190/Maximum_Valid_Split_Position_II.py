from itertools import accumulate
from math import gcd
from operator import eq

class Solution:
    '''
    [Hard Problem]

        You are given an integer array nums.

        You may remove at most one element from nums. Let arr be the remaining elements
        in thier original order, and let m be its length.

        A split position "i" of "arr" is valid if:

        -   0 <= i < m - 1, and 

            -   gcd(arr[0..i]) == gcd(arr[i+1..m-1])

        The score of arr is the number of valid split positions in it.

        Return the maximum possible score of arr.

        Here, gcd(a) denotes the greatest common divisor of all elements in
        the array "a".          
    '''
    def maxValidSplits(self, nums: list[int]) -> int:
        len_num = len(nums)
        prefix = list(accumulate(nums, gcd, initial=0))
        suffix = list(accumulate(reversed(nums), gcd, initial=0))[::-1]
        total = prefix[len_num]

        def walk(index: int, addition: int, current_gcd: int, total_gcd: int):
            while total_gcd != current_gcd:
                current_gcd = gcd(current_gcd, nums[index])
                index       += addition
            return index 

        best = sum(map(eq, prefix, suffix))
        for index in range(len_num):
            total_gcd = gcd(prefix[index], suffix[index + 1])
            if total_gcd == total:
                continue
            left = walk(index=0, addition=1, current_gcd=0,total_gcd=total_gcd) if (prefix[index] == total_gcd) else (
                walk(index=index+1, addition=1, current_gcd=prefix[index],total_gcd=total_gcd))

            right = walk(index=len_num-1, addition=-1, current_gcd=0,total_gcd=total_gcd) if (suffix[index + 1] == total_gcd) else (
                walk(index=index-1, addition=-1, current_gcd=suffix[index+1],total_gcd=total_gcd))
            best = max(best, right - left + 2 - (left <= index <= right))
        return best


#
#    def maxValidSplits(self, nums: list[int]) -> int:
#        len_nums    = len(nums)
#        tree        = [0] * (4* len_nums)
#
#        def build(node, left, right):
#            if left == right:
#                tree[node] = nums[left]
#                return
#            mid = (left + right) // 2
#            build(node * 2, left, mid)
#            build(node * 2 + 1, mid + 1, right)
#            tree[node] = gcd(
#                tree[node * 2],
#                tree[node * 2 + 1])
#        def update(node, left, right, index, value):
#            if left == right:
#                tree[node] = value
#                return
#            mid = (left + right) // 2
#            if index <= mid:
#                update(node * 2, left, mid, index, value)
#            else:
#                update(node * 2 + 1, mid + 1, right, index, value)
#            tree[node] = gcd(
#                tree[node * 2], 
#                tree[node * 2 + 1])
#
#        def find_left(node, left, right, current, target):
#            if left == right:
#                return left 
#            mid = (left + right) // 2
#            left_gcd = gcd(current, tree[node * 2])
#            if left_gcd == target:
#                return find_left(node*2, left, mid, current, target)
#            return find_left(node * 2 + 1, mid + 1, right, left_gcd, target)
#
#        def find_right(node, left, right, current, target):
#            if left == right:
#                return left 
#            mid = (left + right) // 2
#            right_gcd = gcd(
#                current, 
#                tree[node * 2 + 1])
#            if right_gcd == target:
#                return find_right(node * 2 + 1, mid + 1, right, current, target)
#            return find_right(node * 2, left, mid, right_gcd, target)
#
#        build(node = 1, left = 0, right = len_nums - 1)
#        answer = 0
#        for remove in range(len_nums):
#            update(node = 1, left = 0, right = len_nums - 1, index = remove, value = 0)
#            total_gcd = tree[1]
#            l = find_left(node = 1, left = 0, right = len_nums - 1, current = 0, target = total_gcd)
#            r = find_right(node = 1, left = 0, right = len_nums - 1, current = 0, target = total_gcd)
#            if remove < l:
#                l -= 1
#            if remove < r:
#                r -= 1
#            answer = max(answer, r - l)
#            update(node = 1, left = 0, right = len_nums - 1, index = remove, value = nums[remove])
#        total_gcd = tree[1]
#        l = find_left(node = 1, left = 0, right = len_nums - 1, current = 0, target = total_gcd)
#        r = find_right(node = 1, left = 0, right = len_nums - 1, current = 0, target = total_gcd)
#        answer = max(answer, r - l)
#
#
#        return answer


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().maxValidSplits([10,30,15,10])}")

    print(f"Want : {1}, Was : {Solution().maxValidSplits([2,10,14])}")

    print(f"Want : {0}, Was : {Solution().maxValidSplits([2,4])}")
    