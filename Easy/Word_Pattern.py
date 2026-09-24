class Solution:
    '''
    [Easy Problem]

        Given a pattern and a string s, find if s follows the same pattern.

        Here follow means a full match, such that there is a bijection between a letter in 
        pattern and a non-empty word in s. Specifically:

        -   Each letter in pattern maps to exactly one unique word in "s".

        -   Each unique word in s maps to exactly one letter in pattern.

        -   No two letters maps to the same word, and no two words map to the same letter.
    
    '''

    def wordPattern(self, pattern: str, s: str) -> bool:
        cache, seen = {}, set()
        words = s.split()
        if len(pattern) != len(words): return False
        for letter, word in zip(pattern, words):
            if letter in cache:
                if cache[letter] != word: return False
            elif word in seen: return False
            cache[letter] = word 
            seen.add(word)
                
        return True


if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().wordPattern(pattern = "abba", s = "dog cat cat dog")}")
    print(f"Want : {False}, Was : {Solution().wordPattern(pattern = "abba", s = "dog cat cat fish")}")
    print(f"Want : {False}, Was : {Solution().wordPattern(pattern = "aaaa", s = "dog cat cat dog")}")