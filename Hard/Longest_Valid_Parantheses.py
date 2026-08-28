class Solution:
    def longestValidParentheses(self, s: str) -> int:
        llc = lrc = rlc = rrc = lbr = rbr = 0

        for i in range(len(s)):
            if s[i] == "(":
                llc  += 1
            else:
                lrc += 1

            if llc == lrc:
                lbr = max(lbr, llc)
            elif lrc > llc:
                llc = lrc = 0

            if s[len(s) - (i + 1)] == "(":
                rlc  += 1
            else:
                rrc += 1

            if rlc == rrc:
                rbr = max(rbr, rlc)
            elif rrc < rlc:
                rlc = rrc = 0

        return 2*(max(lbr, rbr)) 






if __name__ == "__main__":
    sol = Solution()
    
    sol.longestValidParentheses("()(()")


    print("old\n\n")

    sol.longestValidParentheses("(()")
    sol.longestValidParentheses(")()())")
    sol.longestValidParentheses("")