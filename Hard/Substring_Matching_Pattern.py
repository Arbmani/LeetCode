'''
    Substring Matching Pattern

        You are given a string "s" and a pattern string "p", where "p" contains exactly one "*" character.

        The "*" in p can be replaced with any sequence of zero or more characters.

        Return "True" if "p" can be made a substring of "s" and "False otherwise.



'''




class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        prefix, suffix = p.split("*")
        start_of_prefix = s.find(prefix)
        return start_of_prefix != -1 and s.find(suffix, start_of_prefix + len(prefix)) != -1




if __name__ == "__main__":
    sol = Solution()
    print(sol.hasMatch("xks", "s*"))