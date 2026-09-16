class Solution:
    '''
    [Medium Problem]

        You are given an integer array "nums".

        For each integer "x" in "nums", start with a string consisting of exactly
        "x" lowercase 'a' characters.

        You may perform the following operation any number of times (including zero):

        -   Choose two adjacent equal letters and replace them with the next 
            letter in the alphabet.

        For example, "aa" can be replaced with "b" and "bb" can be replaced with "c".
        The pair "zz" cannot be replaced.

        For each "x" determine the lexicograpically largest string that can be obtained.

        Return an array of strings where the "i"th string is the answer for nums[i].

        A string "a" is lexicographically larger than a string "b" if, at the first 
        position where they differ, "a" contains a letter that appears later in the 
        alphabet than the corresponding letter in "b". If the first min(a.length, b.length)
        characters are equal the longer string is lexicographically larger. 
    
    
    
    
    '''
    def largestString(self, nums: list[int]) -> list[str]:
        result = []
        for num in nums:
            z_count, num = divmod(num, 1 << 25)
            cur = ['z'] * z_count
            while num:
                bit = num.bit_length() - 1
                cur.append(chr(97 + bit))
                num -= 1 << bit 
            result.append(''.join(cur))
        return result 



    def largestString_slow(self, nums: list[int]) -> list[str]:
        result, lexical_value = [], [2**i for i in range(26)]
        for num in nums:
            cur = []
            while num > 0:
                to_the_power = 25
                while lexical_value[to_the_power] > num:
                    to_the_power -= 1
                cur.append(chr(ord('a') + to_the_power))
                num -= lexical_value[to_the_power]
            result.append("".join(cur))

        return result


if __name__ == "__main__":
    print(f"Want : {["b","ca","cba"]}, Was : {Solution().largestString(nums = [2,5,7])}")

    print(f"Want : {["ba","da","a"]}, Was : {Solution().largestString(nums = [3,9,1])}")