class Solution:
    '''
    [Medium Problem]


    Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

    -   Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.

    -   Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.

    In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

    -   For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.

    You can insert the characters '(' and ')' at any position of the string to balance it if needed.

    Return the minimum number of insertions needed to make s balanced.
    
    
    '''
    def minInsertions(self, s: str) -> int:
        ans = need = 0
        for char in s:
            if char == '(':
                need += 2
                if need % 2:
                    ans  += 1
                    need -= 1 
            else:
                need -= 1
                if need < 0:
                    ans += 1
                    need = 1
        return ans + need

if __name__ == "__main__":
    print(f"Want {12}: Was : {Solution().minInsertions(s = "((((((")}")

    print(f"Want {1}: Was : {Solution().minInsertions(s = "(()))")}")
    print(f"Want {0}: Was : {Solution().minInsertions(s = "())")}")
    print(f"Want {3}: Was : {Solution().minInsertions(s = "))())(")}")