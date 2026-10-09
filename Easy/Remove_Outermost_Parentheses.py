class Solution:
    '''
    [Easy Problem]
    
        A valid parentheses string is either empty "", "(" + A + ")", or A + B, 
        where A and B are valid parentheses strings, and + represents string concatenation.

        -   For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
        
        A valid parentheses string s is primitive if it is nonempty, 
        and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

        Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, 
        where Pi are primitive valid parentheses strings.

        Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
    '''
    def removeOuterParentheses(self, s: str) -> str:
        depth, ans = 0, []
        for char in s:
            depth += 1 if char == '(' else -1
            if (char == '(' and depth > 1) or (char == ')' and depth > 0): ans.append(char)        
        return ''.join(ans)
    
    def removeOuterParentheses_slow(self, s: str) -> str:
        depth   = 0
        pointer = 0
        ans = ""
        for index, char in enumerate(s):
            if char == '(': depth += 1
            else          :
                depth -= 1
                if depth == 0:
                    ans += s[pointer + 1:index]
                    pointer = index + 1

        return ans


if __name__ == "__main__":
    print(f"Want : {"()()()"}, Was : {Solution().removeOuterParentheses(s = "(()())(())")}")
    print(f"Want : {"()()()()(())"}, Was : {Solution().removeOuterParentheses(s = "(()())(())(()(()))")}")
    print(f"Want : {""}, Was : {Solution().removeOuterParentheses(s = "()()")}")