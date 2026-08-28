import heapq
from typing import List


class Solution:
    '''
    You are given an array "nums" of "n" positive integers.

    You can perform two types of operations on any element of the array any number of times:

    -   If the element is even, divide by 2.
        -   For example, if the array is [1, 2, 3, 4], then you can do this operation 
            on the last element, and the array will be [1, 2, 3, 2].

    -   If the element is odd, multiply it by 2.
        -   For example, if the array is [1, 2, 3, 4], then you can do this operation
            on the first element, and the array will be [2, 2, 3, 4].

    The deviation of the array is the maximum difference between any two elements in the array.

    Return the minimum deviation the array can have after performing some number of operations.
    '''
    def minimumDeviation(self, nums: List[int]) -> int:
        minHeap, heapMax = [], float("-inf")

        for num in nums:
            temp = num 
            while num % 2 == 0:
                num = num // 2
            minHeap.append((num, max(temp, 2* num)))
            heapMax = max(heapMax, num)
        result = float("inf")
        heapq.heapify(minHeap)

        while len(minHeap) == len(nums):
            num, numMax = heapq.heappop(minHeap)
            print(f"num     is : {num}")
            print(f"numMax  is : {numMax}")
            print(f"heapMax is : {heapMax}")
            result = min(result, heapMax - num)
            print(f"result  is : {result}")
            print(f"")
            if num < numMax:
                heapq.heappush(minHeap, (num *2, numMax))
                heapMax = max(heapMax, num * 2)
            else:
                print("we break it")
        return result

if __name__ == "__main__":
    print(Solution().minimumDeviation(nums = [4,9,4,5]))