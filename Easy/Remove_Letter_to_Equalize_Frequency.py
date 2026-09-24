class Solution:
    '''
    [Easy Problem]

        You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one
        index and remove the letter at that index from word so that thre frequency of every letter present in
        word is equal. 

        Return true if it is possible to remove one letter so that the frequency of all letters in word are equal,
        and false otherwise.

    
    '''
    def equalFrequency(self, word: str) -> bool:
        freaks, ord_a = [0] * 26, ord('a')
        for char in word:
            freaks[ord(char) - ord_a] += 1

        for i in range(26):
            if freaks[i] == 0: continue

            freaks[i] -= 1
            target     = 0
            valid      = True 

            for freak in freaks:
                if freak ==  0: continue
                if target == 0: target = freak
                elif freak != target:
                    valid = False
                    break 
            freaks[i] += 1 
            if valid: return True

        return False





if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().equalFrequency(word = "abcc")}")
    print(f"Want : {False}, Was : {Solution().equalFrequency(word = "aazz")}")