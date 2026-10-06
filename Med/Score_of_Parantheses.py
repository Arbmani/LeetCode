import heapq
class Solution:
    '''
        [Medium Problem]


            Given a balanced parentheses string "s", return the score of the string.

            The score of a balanced parenteses string is based on the following rule:

            -   "()" has score 1

            -   AB has score A + B, where A and B are balanced parentheses strings.

            -   (A) has score 2 * A, where A is a balanced parentheses string

    '''

    def scoreOfParentheses(self, s: str) -> int:
        ans = 0
        depth = 0
        for i, char in enumerate(s):
            if char == '(':
                depth += 1
            else:
                depth -= 1
                if s[i - 1] == '(':
                    ans += 2**depth
        return ans


if __name__ == "__main__":
    print(f"Want : {1}, Was : {Solution().scoreOfParentheses(s = "()")}")
    print(f"Want : {2}, Was : {Solution().scoreOfParentheses(s = "(())")}")
    print(f"Want : {2}, Was : {Solution().scoreOfParentheses(s = "()()")}")

    print(f"Want : {4}, Was : {Solution().scoreOfParentheses(s = "((()))")}")

    print(f"Want : {6}, Was : {Solution().scoreOfParentheses(s = "(()(()))")}")