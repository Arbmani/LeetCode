class Solution:
    '''
    [Medium Problem]

        Given a list of strings "words" and a string "pattern", return a list of words[i] that match pattern.
        You may return the answer in any order.

        A Word matches the pattern if there exists a permutation of letters "p" so that after replacing every 
        letter "x" pattern with p(x), we get the desired word.

        Recall that a permutation of letters is a bijection from letters to letters:
        every letter maps to another letter, and no two letters map to the same letter. 
    
    '''

    def findAndReplacePattern(self, words: list[str], pattern: str) -> list[str]:
        result, ord_a, len_pattern  = [], ord('a'), len(pattern)
        for word in words:
            pattern_to_word = [-1] * 26
            word_to_pattern = [-1] * 26
            match = True
            for index in range(len_pattern):
                code_pattern = ord(pattern[index]) - ord_a
                code_word    = ord(word[index])    - ord_a
                if pattern_to_word[code_pattern] != -1 and pattern_to_word[code_pattern] != code_word:
                    match = False
                    break 
                if word_to_pattern[code_word] != -1 and word_to_pattern[code_word] != code_pattern:
                    match = False
                    break 
                pattern_to_word[code_pattern] = code_word
                word_to_pattern[code_word] = code_pattern
            if match:
                result.append(word)
        return result


if __name__ == "__main__":
    print(f"Want : {["mee","aqq"]}, Was : {Solution().findAndReplacePattern(words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb")}")

    print(f"Want : {["a","b","c"]}, Was : {Solution().findAndReplacePattern(words = ["a","b","c"], pattern = "a")}")

    print(f"Want : {["abab","dede"]}, Was : {Solution().findAndReplacePattern(words = ["badc","abab","dddd","dede","yyxx"], pattern = "baba")}")