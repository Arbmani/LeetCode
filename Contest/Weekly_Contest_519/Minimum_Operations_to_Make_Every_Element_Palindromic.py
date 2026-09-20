from bisect import bisect_left
class Palindromes:
    def __init__(self):
        self.allPalindromes = [[], []]
        for num in range(1, 10**5 + 1):
            str_num = str(num)

            even_len = int(str_num + str_num[::-1])
            odd_len  = int(str_num + str_num[:-1][::-1])

            self.allPalindromes[even_len % 2].append(even_len)
            self.allPalindromes[odd_len % 2].append(odd_len)
        self.allPalindromes[0].sort()
        self.allPalindromes[1].sort()



class Solution:
    allPalindromes = Palindromes().allPalindromes 
    '''
    You are given an integer array "nums".

    In one operation, you may choose an index "i" and either increment or decrement nums[i] by 2.

    Return the minimum number of operations required to make every element in nums a positive palindrome. 
    Different elements may be changed into different palindromic integers. 
    
    '''

    def minOperations(self, nums: list[int]) -> int:
        pal_0, pal_1 = self.allPalindromes
        ans          = 0
        for num in nums:
            palindromes = pal_1 if num & 1 else pal_0
            index = bisect_left(palindromes, num)
            best = palindromes[index] - num if index < len(palindromes) else float("inf")
            if index > 0:
                best = min(best, num - palindromes[index - 1])
            ans += best // 2
        return ans


    def minOperations_Slow(self, nums: list[int]) -> int:
        ans =  0
        for num in nums:
            palindromes = self.allPalindromes[num % 2]
            left, right = 0, len(palindromes) - 1
            while left <= right:
                mid = (left + right) // 2
                if palindromes[mid] < num:
                    left = mid + 1
                else:
                    right = mid - 1
            best = float("inf")
            if left < len(palindromes):
                best = min(best, palindromes[left] - num)
            if left > 0:
                best = min(best, num - palindromes[left - 1])
            ans += best // 2

        return ans

if __name__ == "__main__":
    print(f"Want : {9}, Was : {Solution().minOperations(nums = [10,12,14,16])}")
    print(f"Want : {2}, Was : {Solution().minOperations(nums = [9,10,11,10])}")
    print(f"Want : {2}, Was : {Solution().minOperations(nums = [125])}")

