class Solution:
    '''
    [Easy Problem]

        Given a valid parentheses string s, return the nesting depth of s. 
        The nesting depth is the maximum number of nested parentheses.
    
    '''
    def maxDepth(self, s: str) -> int:
        ans = counter = 0
        for char in s:
            if char == "(":
                counter += 1 
            elif char == ")":
                counter -= 1
            ans = max(counter, ans)

        return ans


if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().maxDepth(s = "(1+(2*3)+((8)/4))+1")}")
    print(f"Want : {3}, Was : {Solution().maxDepth(s = "(1)+((2))+(((3)))")}")
    print(f"Want : {3}, Was : {Solution().maxDepth(s = "()(())((()()))")}")