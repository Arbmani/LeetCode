class Solution:
    '''
    [Hard Problem]

    Given a list of words, list of  single letters (might be repeating) and score of every character.

    Return the maximum score of any valid set of words formed by using the given letters 
    (words[i] cannot be used two or more times).

    It is not necessary to use all characters in letters and each letter can only be used once. 
    Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.
    
    
    '''


    def maxScoreWords(self, words: list[str], letters: list[str], score: list[int]) -> int:
        len_words, ord_a = len(words), ord('a')
        available = [0] * 26
        for char in letters:
            available[ord(char) - ord_a] += 1
        word_count = [[0] * 26 for _ in range(len_words)]
        word_score = [0] * len_words

        for index, word in enumerate(words):
            total = 0
            counts = word_count[index]

            for char in word:
                j = ord(char) - ord_a
                counts[j] += 1
                total     += score[j]
            word_score[index] = total 

        best = 0
        for mask in range(1 << len_words):
            used = [0] * 26
            total_score = 0
            valid = True
            for i in range(len_words):
                if mask & (1 << i):
                    counts = word_count[i]
                    for char in range(26):
                        used[char] += counts[char]
                        if used[char] > available[char]:
                            valid = False
                            break
                    if not valid:
                        break
                    total_score += word_score[i]
            if valid:
                best = max(best, total_score)

        return best


if __name__ == "__main__":

    print(f"Want : {23}, Was : {Solution().maxScoreWords(words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0])}")

    print(f"Want : {27}, Was : {Solution().maxScoreWords(words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10])}")

    print(f"Want : {0}, Was : {Solution().maxScoreWords(words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0])}")