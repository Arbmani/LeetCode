class Solution:
    '''
    [Hard Problem]

        Given a string "s" that contains parentheses and letters, remove the minimum number
        of invalid parentheses to make the input string valid.

        Return a list of unique strings that are valid with the minimum
        number of removals. You may return the answer in any order. 

    
    '''
    def minAddToMakeValid(self, s: str) -> int:
        balance = additions = 0
        for char in s:
            if char.isalpha(): continue

            if char == '('  : balance   += 1
            elif balance    : balance   -= 1
            else            : additions += 1
        return balance + additions


    def removeInvalidParentheses(self, s: str) -> list[str]:
        left = right = 0
        ans, len_s = set(), len(s)
        for char in s:
            if     char == '(': left += 1
            elif   char == ')': 
                if left       : left -= 1
                else          : right += 1    

        def dfs(index: int, path: list[str], balance: int, left: int, right: int, prev_removed :bool) -> None:
            if index == len_s:
                if 0 == balance == left == right: ans.add("".join(path))
                return
            char = s[index]
            if char.isalpha():
                path.append(char)
                dfs(index + 1, path, balance, left, right, False)
                path.pop()
                return
            can_remove_dup = (index > 0 and s[index] == s[index -1] and not prev_removed)


            if char == '(':
                if left > 0 and not can_remove_dup:
                    dfs(index + 1, path, balance, left - 1, right, True)
                path.append(char)
                dfs(index + 1, path, balance + 1, left, right, False)
                path.pop()
            else:
                if right > 0 and not can_remove_dup:
                    dfs(index + 1, path, balance, left, right - 1, True)
                if balance > 0:
                    path.append(char)
                    dfs(index + 1, path, balance - 1, left, right, False)
                    path.pop()
        dfs(0, [], 0, left, right, False)
        
        return list(ans)

if __name__ == "__main__":
    print(f"Want : {["(())()","()()()"]}, Was : {Solution().removeInvalidParentheses(s = "()())()")}")
    print(f"Want : {["(a())()","(a)()()"]}, Was : {Solution().removeInvalidParentheses(s = "(a)())()")}")
    print(f"Want : {[""]}, Was : {Solution().removeInvalidParentheses(s = ")(")}")

    print(f"Want : {["()"]}, Was : {Solution().removeInvalidParentheses(s = ")()(")}")

    print(f"Want : {[""]}, Was : {Solution().removeInvalidParentheses(s = "))")}") 