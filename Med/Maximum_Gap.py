class Solution:
    '''
    [Medium Problem]

        Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
        If the array contains less than two elements, return 0.

        You must write an algorithm that runs in linear time and uses linear extra space.
    '''
    def maximumGap(self, nums: list[int]) -> int:
        len_nums = len(nums)
        if len_nums < 2: return 0

        min_num, max_num = min(nums), max(nums)
        if min_num == max_num: return 0

        gap     = max(1, (max_num - min_num) // (len_nums - 1))
        buckets = [[None, None] for _ in range((max_num - min_num) // gap + 1)]

        for num in nums:
            index = (num - min_num) // gap 
            if buckets[index][0] is None:
                buckets[index][0] = buckets[index][1] = num 
            else:
                buckets[index][0] = min(buckets[index][0], num)
                buckets[index][1] = max(buckets[index][1], num)
        max_gap     = 0
        prev_max    = min_num
        for bucket in buckets:
            if bucket[0] is not None:
                max_gap  = max(max_gap, bucket[0] - prev_max)
                prev_max = bucket[1]
        return max_gap




if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().maximumGap(nums = [3,6,9,1])}")
    print(f"Want : {0}, Was : {Solution().maximumGap(nums = [10])}")