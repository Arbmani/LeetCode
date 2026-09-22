class Solution:
    '''
    [Hard Problem]

        You are given an array of positve integers nums and a positive integer k. 
        You are also given a 2D array queries, where queries[i] = [index_i, value_i, start_i, x_i]

        You are allowed to perform an operation once on nums, where you can remove any suffix
        from nums such that nums remains non-empty.

        The x-value of nums for a given x is defined as the number of ways to perform this operation
        so that the product of the remaining elements leaves a remainder of x modulo k.

        For each query in queries you need to determine the x-value of nums for x_i 
        after performing the following actions.

        -   Update nums[index_i] to value_i. Only this step persists for the rest of the queries.

        -   Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
        
        Return an array result of size queries.length where result[i] is the answer for the ith query.

        A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

        A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

        Note that the prefix and suffix to be chosen for the operation can be empty.

        Note that x-value has a different definition in this version.

    '''

    def resultArray(self, nums: list[int], k: int, queries: list[list[int]]) -> list[int]:
        size            = 1 << (len(nums) - 1).bit_length()
        suffix_count    = [[0] * k for _ in range(2 * size)]
        segment_product = [1] * (2 * size)
        def combine(base, extra, multiplier):
            result = base[:]
            for remainder, count in enumerate(extra):
                if count:
                    result[multiplier * remainder % k] += count
            return result
 
        def merge(node):
            left, right = node * 2, node * 2 + 1
            suffix_count[node]    = combine(suffix_count[left], suffix_count[right], segment_product[left])
            segment_product[node] = (segment_product[left] * segment_product[right] % k)


        for i, num in enumerate(nums):
            node        = size + i 
            remainder   = num % k

            suffix_count[node][remainder] = 1
            segment_product[node]         = remainder

        for node in range(size - 1, 0, -1):
            merge(node)

        def update(index, value):
            node        = size + index 
            remainder   = value % k 

            suffix_count[node]            = [0] * k 
            suffix_count[node][remainder] = 1
            segment_product[node]         = remainder

            node //= 2 
            while node:
                merge(node)
                node //= 2

        def query(left, right):
            left_counts, right_counts = [0] * k, [0] * k
            left_product = 1

            left  += size 
            right += size
            while(left < right):
                if left & 1:
                    left_counts  = combine(left_counts, suffix_count[left], left_product)
                    left_product = (left_product * segment_product[left] % k)
                    left += 1
                if right & 1:
                    right -= 1
                    right_counts = combine(suffix_count[right], right_counts, segment_product[right])
                left  //= 2
                right //= 2
            return combine(left_counts, right_counts, left_product)

        result = []
        for index, value, start, x in queries:
            update(index, value)
            result.append(query(start, len(nums))[x])

        return result

if __name__ == "__main__":
    print(f"Want : {[2,2,2]}, Was : {Solution().resultArray([1,2,3,4,5], k = 3, queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]])}")

    print(f"Want : {[1,0]}, Was : {Solution().resultArray(nums = [1,2,4,8,16,32], k = 4, queries = [[0,2,0,2],[0,2,0,1]])}")

    print(f"Want : {[5]}, Was : {Solution().resultArray(nums = [1,1,2,1,1], k = 2, queries = [[2,1,0,1]])}")