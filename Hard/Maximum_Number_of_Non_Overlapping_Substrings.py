class Solution:
    '''
    
    [Hard Problem]

        Given a string "s" of lowercase letters, you need to find the maximum number
        of non-empty substrings of s that meet the following conditions:

        1.  The substring do not overlap, that is for any two substrings s[i..j] 
            and s[x..y], either j < x or i > y is true.

        2.  A substring that contains a certain character "c" must also
            contain all occurrences of "c".

        Find the maximum number of substrings that meet the above conditions.
        If there are multiple solutions with the same number of substrings, return
        the one with the minimum total length. It can be shown that there exists 
        a unique solution of minimum total length.

        Notice that you can return the substring in any order. 
    
    
    '''

    def maxNumOfSubstrings(self, s: str) -> list[str]:
        len_s, ord_a            = len(s), ord('a')
        first, last, intervals  = [len_s] * 26, [-1] * 26, []
        for index, char in enumerate(s):
            char_code = ord(char) - ord_a
            first[char_code] = min(first[char_code], index)
            last[char_code]  = index 
        for char_code in range(26):
            if last[char_code] == -1:
                continue
            start, end      = first[char_code], last[char_code]
            index, valid    = start, True

            while(index <= end):
                current_code = ord(s[index]) - ord_a
                if first[current_code] < start:
                    valid = False
                    break 
                end     = max(end, last[current_code])
                index  += 1 
            if valid:
                intervals.append((end, start))
        intervals.sort()
        ans = []
        prevEnd = -1
        for end, start in intervals:
            if start > prevEnd:
                ans.append(s[start:end + 1])
                prevEnd = end
        return ans


if __name__ == "__main__":

    print(f"Want : {["e","f","ccc"]}, Was : {Solution().maxNumOfSubstrings(s = "adefaddaccc")}")

    print(f"Want : {["d","bb","cc"]}, Was : {Solution().maxNumOfSubstrings(s = "abbaccd")}")