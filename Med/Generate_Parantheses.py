class Solution:
    '''
    [Medium Problem]
    
    Given "n" pairs of parantheses, write a function to 
    generate all combinations of well-formed parentheses
    '''

    #   Depth 0: [""]
    #   Depth 1: ["()"]
    #   Depth 2: [(()), "()()"], 
     

    #           Depth 2 är samma som [ "(" Depth_1 ")", "Depth_1 + Depth_1"]


    #   Depth 3: ["((()))","(()())","(())()","()(())","()()()"]


    #           Depth 3 är samma som [ "(" Depth_2 ")", "Depth_2 + Depth_1"]
                
                #   "(" Depth_2 ")"     =  "((()))", "(()())"
                #   "Depth_2 + Depth_1" =  "(())()", "()()()"

                # Men vi saknar nu :    = "()(())"

    #   Depth 3: Idea ? varje Deph är lika med (dfs(depth - 1)) + dfs(depth=1) + dfs(depth - 2)

    def generateParenthesis(self, n: int) -> list[str]:
        memo = {0: [""]}
        def dfs(depth):
            if depth in memo: return memo[depth]

            result = []
            for i in range(depth):
                lefts  = dfs(i)
                rights = dfs(depth - 1 - i)
                for left in lefts:
                    for right in rights:
                        result.append("(" + left + ")" + right)
            memo[depth] = result
            return result
        return dfs(n) 


if __name__ == "__main__":
    print(f"Want : {["((()))","(()())","(())()","()(())","()()()"]}, Was : {Solution().generateParenthesis(n = 3)}")
    print(f"Want : {["(())", "()()"]}, Was : {Solution().generateParenthesis(n = 2)}")
    print(f"Want : {["()"]}, Was : {Solution().generateParenthesis(n = 1)}")