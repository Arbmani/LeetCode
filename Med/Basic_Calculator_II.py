from typing import List
class Solution:
    '''
        Given a string "s" which represents an expression, evaluate this
        expression and return its value.

        The integer division should truncate towards zero.

        You may assume that the given expression is always valid. 
        All intermediate results will be in the range of [-2^31, 2^31 -1].

        Note:
            You are NOT allowed to use any built-in function which evaluates strings
            as mathematical expressions, such as eval().
    
    '''

    def calculate(self, s: str) -> int:
        num, nums, last_operation = 0, [], '+'
        def operation_handler() -> None:
            if last_operation == '/':
                nums.append(int(nums.pop() / num))
            elif last_operation == '*':
                nums.append(nums.pop() * num)
            elif last_operation == '+':
                nums.append(num)
            else:
                nums.append(num * -1)

        for char in s:
            if char == ' ':
                continue
            elif char.isdigit():
                num = num * 10 + int(char)
            else:
                operation_handler()
                last_operation  = char 
                num             = 0
        operation_handler()
        return sum(nums)


if __name__ == "__main__":
    print(Solution().calculate(s = " 3+5 / 2 "))
