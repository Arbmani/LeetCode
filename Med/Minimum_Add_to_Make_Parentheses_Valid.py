class Solution:
    '''
    [Medium Problem]

    A parentheses string is valid if and only if:

    -   It is the empty string,
    
    -   It can be written as AB (A concatenated with B), where A and B are valid strings, or
    
    -   It can be written as (A), where A is a valid string.

    You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

    -   For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
    
    Return the minimum number of moves required to make s valid.
    
    
    
    '''

    def minAddToMakeValid(self, s: str) -> int:
        balance = additions = 0
        for char in s:
            if char == '('  : balance   += 1
            elif balance    : balance   -= 1
            else            : additions += 1
        return balance + additions
        

if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().minAddToMakeValid(s = "(()(")}")

    print(f"Want : {2}, Was : {Solution().minAddToMakeValid(s = ")(")}")

    print(f"Want : {1}, Was : {Solution().minAddToMakeValid(s = "())")}")

    print(f"Want : {3}, Was : {Solution().minAddToMakeValid(s = "(((")}")