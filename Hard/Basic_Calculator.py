


class Solution:
    '''
        Given a string "s" representing a valid expression, implement a basic calculator to evaluate it,
        and return the result of the evaluation.

        Note: You are not allowed to use any built-in-function which evaluates strings 
        as mathematical expressions, such as eval().
    
    
    '''

    def calculate(self, s: str) -> int:
        sign, num, result   = 1, 0, 0
        stack               = []

        for char in s:
            if char == ' ':
                continue
            elif char.isdigit():
                num = num * 10 + int(char)
            elif char in '+-':
                result += sign * num 
                num     = 0
                sign    = 1 if char == '+' else -1
            elif char == '(':
                stack += [result, sign]
                sign, num, result   = 1, 0, 0
            elif char == ')':
                result      += sign * num
                num         = 0
                sign        = stack.pop()
                old_result  = stack.pop()
                result = old_result + sign * result
        result += sign * num 
        return result



if __name__ == "__main__":
    print(Solution().calculate(s = "(1+(4+5+2)-3)+(6+8)"))