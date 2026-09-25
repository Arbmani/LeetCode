class Solution:
    '''
    [Medium Problem]

        A string s represents a list of words.

        Each letter in the word has 1 or more options. If there is one option, the
        letter is represented as is. If there is more than one option, then curly braces
        delimit the options. For example, "{a,b,c}" represents options ["a","b","c"].

        Return all words that can be formed in this manner, in lexicographical order.
    
    
    '''


    def expand(self, s: str) -> list[str]:
        ans = []
        def dfs(i : int, word: list[str]) -> None:
            if i == len(s): 
                ans.append("".join(word))
                return
            if s[i] == "{":
                j = i 
                while s[j] != "}":
                    j += 1
                
                options = s[i + 1:j].split(",")
                options.sort()
                for char in options:
                    word.append(char)
                    dfs(j + 1, word)
                    word.pop()
            else:
                word.append(s[i])
                dfs(i + 1, word)
                word.pop()
        dfs(0, [])
        return ans


if __name__ == "__main__":
    print(f"Want : {["acdf", "acef", "bcdf", "bcef"]}, Was : {Solution().expand("{a,b}c{d,e}f")}")

    print(f"Want : {["abcd"]}, Was : {Solution().expand("abcd")}")

