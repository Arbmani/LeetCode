class Solution:
    '''
    [Medium Problem]

        You are given a string "s" that consits of lower case English letters and brackets.

        Reverse the strings in each pair of matching parantheses, starting from the innermost one.

        Your result should not contain any brackets.
    
    '''
    def reverseParentheses_best(self, s: str) -> str:
        stack = [[]]
        for char in s:
            if char == "(":
                stack.append([])
            elif char == ")":
                stack[-2].extend(reversed(stack.pop()))
            else:
                stack[-1].append(char)
        return "".join(stack[0])

    def reverseParentheses(self, s: str) -> str:
        pair, stack = {}, []
        for i, char in enumerate(s):
            if char == "(":
                stack.append(i)
            elif char == ")":
                j = stack.pop()
                pair[i] = j
                pair[j] = i
        result = []
        i = 0
        direction = 1
        while 0 <= i < len(s):
            if s[i] == "(" or s[i] == ")":
                i = pair[i]
                direction *= -1
            else:
                result.append(s[i])
            i += direction
        return "".join(result)



    def reverseParentheses_semi_slow(self, s: str) -> str:
        stack = [""]
        for char in s:
            if char == "(": stack.append("")
            elif char == ")":
                temp_stack = stack.pop()
                stack[-1] += temp_stack[::-1]
            else: stack[-1] += char 
        return stack[0]

    def reverseParentheses_slow(self, s: str) -> str:
        stack = []
        for char in s:
            if char == ")":
                temp_stack = []
                while stack[-1] != "(": temp_stack.append(stack.pop())
                stack.pop()
                for char in temp_stack: stack.append(char)
            else: stack.append(char)
        return "".join(stack)



if __name__ == "__main__":
    print(f"Want : {"dcba"}, Was : {Solution().reverseParentheses(s = "(abcd)")}")

    print(f"Want : {"iloveu"}, Was : {Solution().reverseParentheses(s = "(u(love)i)")}")

    print(f"Want : {"leetcode"}, Was : {Solution().reverseParentheses(s = "(ed(et(oc))el)")}")