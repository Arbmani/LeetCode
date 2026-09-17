class Solution:
    '''
    [Medium Problem]

        You are given two strings "s" and "target", both having length "n",
        consisting of lowercase English letters.

        Return the lexicographically smallest permutation of "s" that is strictly greater than target.
        If no permutation of "s" is lexicographically strictly greater than target, return an empty string.

        A string "a" is lexicograhically strictly greater than a string "b" (of the same length) if 
        in the first position where "a" and "b" differ, string "a" has a letter that appears
        later in the alphabet than the corresponding letter in "b". 
    
    '''

    def lexGreaterPermutation(self, s: str, target: str) -> str:
        len_strs, ord_a, frequency_counter = len(s), ord('a'), [0] * 26

        for char in s:
            frequency_counter[ord(char) - ord_a] += 1
        prefix = []
        for i in range(len_strs):
            char_int = ord(target[i]) - ord_a
            if frequency_counter[char_int] == 0:
                break
            frequency_counter[char_int] -= 1
            prefix.append(target[i])

        def build(index: int, chars_int: int):
            nonlocal frequency_counter
            for char_int in range(chars_int + 1, 26):
                if frequency_counter[char_int]:
                    frequency_counter[char_int] -= 1
                    return (''.join(prefix[:index]) + chr(char_int + ord_a) + 
                            ''.join(chr(char + ord_a) * count for char, count in enumerate(frequency_counter)))
            return ""
        if len(prefix) < len(target):
            ans = build(len(prefix), ord(target[len(prefix)]) - ord_a)
            if ans:
                return ans
        for i in range(len(prefix) - 1, -1, -1):
            char_int = ord(prefix[i]) - ord_a
            frequency_counter[char_int] += 1
            ans = build(i, char_int)
            if ans:
                return ans
        return ""

if __name__ == "__main__":
    print(f"Want : {"baa"}, Was : {Solution().lexGreaterPermutation(s = "aab", target = "abb")}")

    print(f"Want : {"bca"}, Was : {Solution().lexGreaterPermutation(s = "abc", target = "bba")}")

    print(f"Want : {"eelt"}, Was : {Solution().lexGreaterPermutation(s = "leet", target = "code")}")

    print(f"Want : {""}, Was : {Solution().lexGreaterPermutation(s = "baba", target = "bbaa")}")