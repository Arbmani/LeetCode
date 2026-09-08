class Solution:
    '''
    [Medium Problem]

        You are given an integer array "nums".

        Each "nums[i]" is an encoded integer representing two positive integers
        "xi" and "yi". To decode nums[i], define:

        -   width_i = nums[i] % 10.

        -   di      = floor(nums[i] / 10)

        -   xi as the integer formed by the first width_i digits of the decimal representation of di.

        -   yi as the integer formed by all remaining digits of the decimal representation of di.

        It is guaranteed that the decimal representation of "di" contains more than "widthi" digits.
        Therefore, both "xi" and "yi" contian at least one digit.

        The decoded value of nums[i] is xi^yi

        Return the sum of the decoded values of all elements in nums, modulo 10^9 + 7.

        The floor() function returns the integer part of the division. 
    
    
    '''
    def sumDecoded(self, nums: list[int]) -> int:
        result, modulo = 0, 10**9 + 7
        for num in nums:
            width, d    = num % 10, num // 10
            d_str       = str(d)
            x, y        = int(d_str[:width]), int(d_str[width:])
            result      = (result + pow(x, y, modulo)) % modulo
        return result


if __name__ == "__main__":
    print(f"Want {8}, Was {Solution().sumDecoded([231])}")

    print(f"Want {1649}, Was {Solution().sumDecoded([2252, 2101])}")

    print(f"Want {73741817}, Was {Solution().sumDecoded([2301])}")




