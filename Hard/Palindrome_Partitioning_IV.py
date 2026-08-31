class Solution:
    '''
        Given a string "s", return "true" if it is possible to split the string "s"
        into three non-empty palindromic substrings. Otherwise, return "False".

        A string is said to be palindrome if it is the same string when reversed.
    '''

    def checkPartitioning(self, s: str) -> bool:
        word_len = len(s)
        is_palindrome = [[False] * word_len for _ in range(word_len)]
        for substring_len in range(1, word_len + 1):
            for substring_start in range(word_len - substring_len + 1):
                substring_end = substring_start + substring_len - 1
                if s[substring_start] == s[substring_end] and (
                    substring_len <= 2 or 
                    is_palindrome[substring_start + 1][substring_end - 1]):
                    is_palindrome[substring_start][substring_end] = True

        for first_split in range(word_len - 2):
            if not is_palindrome[0][first_split]:
                continue
            for second_split in range(first_split + 1, word_len - 1):
                if(is_palindrome[first_split + 1][second_split] and 
                   is_palindrome[second_split + 1][word_len - 1]):
                    return True
        return False


if __name__ == "__main__":
    print(f"Correct Answer is True  mine is : {Solution().checkPartitioning(s = "abcbdd")}")
    print(f"Correct Answer is False mine is : {Solution().checkPartitioning(s = "bcbddxy")}")