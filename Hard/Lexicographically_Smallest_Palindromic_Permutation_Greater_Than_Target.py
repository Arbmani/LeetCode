class Solution:
    '''
    [Hard Problem]

        You are given two strings "s" and "target", each of length "n", consisting of lowercase
        English letters.

        Return the lexicographically smallest string that is both a palindromic permutation
        of "s" and strictly greater than "target". If no such permutation exists,
        return an empty string. 
    
    '''

    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        len_strs, ord_a, frequency_counter, odd = len(s) // 2, ord('a'), [0] * 26, ""
        def build(index: int, chars_int: int):
            for char_int in range(chars_int + 1, 26):
                if frequency_counter[char_int]:
                    frequency_counter[char_int] -= 1
                    half = (''.join(prefix[:index]) + chr(char_int + ord_a) + 
                            ''.join(chr(char + ord_a) * count for char, count in enumerate(frequency_counter)))
                    return half + odd + half[::-1]
            if index == len_strs:
                half = ''.join(prefix)
                ans = half + odd + half[::-1]
                if ans > target:
                    return ans
            return ""

        for char in s:
            frequency_counter[ord(char) - ord_a] += 1
        for index, count in enumerate(frequency_counter):
            if count % 2:
                if odd:
                    return ""
                odd = chr(index + ord_a)
            frequency_counter[index] = count // 2

        new_target, prefix = target[:len_strs], [] 

        for i in range(len_strs):
            char_int = ord(new_target[i]) - ord_a
            if frequency_counter[char_int] == 0:
                ans = build(i, char_int)
                if ans:
                    return ans 
                break
            frequency_counter[char_int] -= 1
            prefix.append(new_target[i])


        if len(prefix) == len(new_target):
            half = ''.join(prefix)
            ans  = half + odd + half[::-1]
            if ans > target:
                return ans
        for i in range(len(prefix) - 1, -1, -1):
            char_int = ord(prefix[i]) - ord_a
            frequency_counter[char_int] += 1
            ans = build(i, char_int)
            if ans:
                return ans
        return ""


if __name__ == "__main__":

    print(f"Want : {"bb"}, Was : {Solution().lexPalindromicPermutation(s = "bb", target = "aa")}")

    print(f"Want : {"baab"}, Was : {Solution().lexPalindromicPermutation(s = "baba", target = "abba")}")

    print(f"Want : {""}, Was : {Solution().lexPalindromicPermutation(s = "baba", target = "bbaa")}")

    print(f"Want : {""}, Was : {Solution().lexPalindromicPermutation(s = "abc", target = "abb")}")

    print(f"Want : {"aca"}, Was : {Solution().lexPalindromicPermutation(s = "aac", target = "abb")}")