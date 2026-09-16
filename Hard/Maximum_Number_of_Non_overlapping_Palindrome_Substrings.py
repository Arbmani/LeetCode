class Solution:
    '''
    [Hard Problem]

        You are given a string "s" and a positive integer "k".

        Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

        -   The length of each substring is at least k.

        -   Each substring is a palindrome.

        Return the maximum number of substrings in an optimal selection.

        A substring is a contiguous sequence of characters within a string.
    
    '''
    


    def maxPalindromes(self, s: str, k: int) -> int:
        '''
            Manacher's Algorithm
        '''
        def isPalindrome(left: int, right: int) -> bool:
            while left <= right:
                if s[left] != s[right]:
                    return False 
                left  += 1
                right -= 1
            return True

        len_s = len(s)
        cache = [0] * (len_s + 1)

        for i in range(k, len_s + 1):
            cache[i] = cache[i - 1]
            if isPalindrome(i - k, i - 1):
                cache[i] = max(cache[i], cache[i - k] + 1)
            if i >= k + 1 and isPalindrome(i - k - 1, i - 1):
                cache[i] = max(cache[i], cache[i - k - 1] + 1)
        return cache[len_s]




    def maxPalindromes_Slow(self, s: str, k: int) -> int:
        len_s, result, end = len(s), 0, -1
        for index in range(len_s):
            for center in (index - 1, index):
                left, right = center, index 
                while left >= 0 and right < len_s and s[left] == s[right]:
                    if right - left + 1 >= k and left > end:
                        result += 1
                        end = right 
                        break
                    left  -= 1
                    right += 1
        return result


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().maxPalindromes(s = "abaccdbbd", k = 3)}")

    print(f"Want : {0}, Was : {Solution().maxPalindromes(s = "adbcda", k = 2)}")




