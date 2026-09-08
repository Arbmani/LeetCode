class Solution:
    '''
    [Easy Problem]

        You are given an integer array "nums".

        An integer "x" is special if all occurences of "x" in "nums" appear in a single 
        contiguous block.

        Return the number of distinct special integers in nums."
    
    '''

    def countSpecialIntegers(self, nums: list[int]) -> int:
        last, seen, special = None, set(), set()
        for num in nums:
            if num not in seen:
                seen.add(num)
                special.add(num)
            elif num != last:
                special.discard(num)
            last = num
        return len(special)


if __name__ =="__main__":
    print(f"Want{1}, Was{Solution().countSpecialIntegers([66,65,66,66,66])}")

    print(f"Want{1}, Was{Solution().countSpecialIntegers([1,2,2,1])}")

    print(f"Want{2}, Was{Solution().countSpecialIntegers([3,3,1,2,2,1])}")