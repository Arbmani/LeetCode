class Solution:
    '''
    [Medium Problem]

        You are given a postive integer "n".

        A binary string "x" is valid if all substrings of x of length 2 contain at least one "1".

        Return all valid strings, with length "n", in any order. 
    
    
    '''
    # [0, 1] -> [01, 10, 11]
    def validStrings_With_Dfs(self, n: int) -> list[int]:
        ans = []
        def dfs(s):
            if len(s) == n:
                ans.append(s)
                return
            dfs(s + "1")
            if not s or s[-1] == "1":
                dfs(s + "0")
        dfs("")
        return ans


    def validStrings(self, n: int) -> list[int]:
        ans = ["0","1"]
        for _ in range(1, n):
            ans = [s + "1" for s in ans] + [s + "0" for s in ans if s[-1] == "1"]
        return ans


if __name__ == "__main__":
    print(f"Want : {["010","011","101","110","111"]}, Was : {Solution().validStrings(3)}")
    print(f"Want : {["0","1"]}, Was : {Solution().validStrings(1)}")