'''
    Given an input string "s" and a pattern "p":
        
        Implement wildcard pattern matching with support for "?" and "*" where:

        -   "?" Matches any singel character

        -   "*" Matches any sequence of characters (including the empty sequence)

        The matching should cover the entire input string (not partial).

'''




class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        cache = {}
        def Depth_First_Search(s_index, p_index):
            if (s_index, p_index) in cache:
                return cache[s_index, p_index]
            if s_index >= len(s) and p_index >= len(p):
                return True
            elif p_index >= len(p):
                return False

            is_a_match = s_index < len(s) and (s[s_index] == p[p_index] or p[p_index] == "?")
            if p[p_index] == "*":
                if p_index + 1 < len(p) and p[p_index + 1] == "*":
                    cache[s_index, p_index] = Depth_First_Search(s_index, p_index + 1)
                    return cache[s_index, p_index]
                elif (s_index + 1) <= len(s):
                    cache[s_index, p_index] = Depth_First_Search(s_index + 1, p_index) or Depth_First_Search(s_index, p_index + 1) or Depth_First_Search(s_index + 1, p_index + 1)
                else: 
                    cache[s_index, p_index] = Depth_First_Search(s_index, p_index + 1)
                return cache[s_index, p_index]
            if is_a_match:
                cache[s_index, p_index] = Depth_First_Search(s_index + 1, p_index + 1)
                return cache[s_index, p_index]
            return False
        
        return Depth_First_Search(0, 0)


if __name__ == "__main__":
    sol = Solution()
    print(sol.isMatch("aa", "*"))
