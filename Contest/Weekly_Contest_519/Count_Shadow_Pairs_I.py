class Solution:
    '''
    [Medium Problem]

        You are given an integer array "nums" of length "n".

        A pair of indices (i, j) is called a shadow pair if all 
        of the following conditions are satisfied:

        -   0 <= i < j < n 

        -   nums[i] < nums[j]

        -   There does not exist an index "k" such that i < k < j
            and nums[k] < nums[i] < nums[j].
        
        return the total number of shadow pairs.
    
    '''

    def shadowPairs(self, nums: list[int]) -> int:
        pairs, total, stack = 0, 0, []
        for num in nums:
            while stack and stack[-1][0] > num:
                total -= stack.pop()[-1]
            equal = stack[-1][1] if stack and stack[-1][0] == num else 0
            pairs += total - equal
            if stack and stack[-1][0] == num:
                stack[-1][1] += 1
            else:
                stack.append([num, 1])
            total += 1

        return pairs


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().shadowPairs(nums = [8,12,10])}")   

    print(f"Want : {3}, Was : {Solution().shadowPairs(nums = [3,1,4,1,5])}")   

    print(f"Want : {4}, Was : {Solution().shadowPairs(nums = [6,7,6,6,7])}")  

    print(f"Want : {6}, Was : {Solution().shadowPairs(nums = [1,2,3,4])}")  

