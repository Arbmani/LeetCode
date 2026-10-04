class Solution:
    '''
    [Medium Problem]


        Given a string "s" containing only three types of characters '(', ')' and '*', return true if "s" is valid.

        The following rules define a valid string:

        -   Any left parenthesis '(' must have a corresponding right paranthesis ')'

        -   Any right parenthesis ')' must have a correspodning left parenthesis '('

        -   Left parenthesis '(' must go before the corresponding right parenthesis ')'.

        -   '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
    
    
    '''


    def checkValidString(self, s: str) -> bool:
        low  = 0
        high = 0
        for char in s:
            if char == '(':
                low  += 1
                high += 1
            elif char == ')':
                low   = max(0, low - 1)
                high -= 1
            else:
                low   = max(0, low - 1)
                high += 1
            if high < 0: return False

        return low == 0

if __name__ == "__main__":
    print(f"Want : {False}, Was : {Solution().checkValidString(s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())")}")
    # This case gives True ???
    print(f"Want : {False}, Was : {Solution().checkValidString(s = "(((()))())))*))())()(**(((())(()(*()((((())))*())(())*(*(()(*)))()*())**((()(()))())(*(*))*))())")}")
    


    print(f"Want : {True}, Was : {Solution().checkValidString(s = "()")}")
    print(f"Want : {True}, Was : {Solution().checkValidString(s = "(*)")}")
    print(f"Want : {True}, Was : {Solution().checkValidString(s = "(*))")}")
    print(f"Want : {False}, Was : {Solution().checkValidString(s = "(")}")