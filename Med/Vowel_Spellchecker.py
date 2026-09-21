class Solution:
    '''
    [Medium Problem]
    
        Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

        For a given query word, the spell checker handles two categories of spelling mistakes:

        -   Capitalization: If the query matches a word in the wordlist (case-insensitive), 
            then the query word is returned with the same case as the case in the wordlist.

            -   Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"

            -   Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"

            -   Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
        -   Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of 
            the query word with any vowel individually, it matches a word in the wordlist 
            (case-insensitive), then the query word is returned with the same case as the match in the wordlist.

            -   Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"

            -   Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)

            -   Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

        In addition, the spell checker operates under the following precedence rules:

        -   When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.

        -   When the query matches a word up to capitalization, you should return the first such match in the wordlist.

        -   When the query matches a word up to vowel errors, you should return the first such match in the wordlist.

        -   If the query has no matches in the wordlist, you should return the empty string.

        Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].
    
    '''

    def spellchecker(self, wordlist: list[str], queries: list[str]) -> list[str]:
        ans, exact, caseMap, vowelMap = [], set(wordlist), {}, {}
        for word in wordlist:
            to_lower     = word.lower()
            remove_vowel = ''.join('*' if char in 'aeiou' else char for char in to_lower)
            if to_lower not in caseMap: caseMap[to_lower] = word
            if remove_vowel not in vowelMap: vowelMap[remove_vowel] = word
        for query in queries:
            if query in exact: ans.append(query)
            else:
                to_lower = query.lower()
                remove_vowel = ''.join('*' if char in 'aeiou' else char for char in to_lower)
                if to_lower in caseMap: ans.append(caseMap[to_lower])
                elif remove_vowel in vowelMap: ans.append(vowelMap[remove_vowel])
                else: ans.append("")
        return ans


if __name__ == "__main__":
    print(f"Want : {["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]}, Was : {Solution().spellchecker(wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"])}")

    print(f"Want : {["yellow"]}, Was : {Solution().spellchecker(wordlist = ["yellow"], queries = ["YellOw"])}")