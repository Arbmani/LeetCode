class Solution:
    '''
    [Easy Problem]

    You are given a string s. 
    The score of a string is defined as the sum of the absolute difference 
    between the ASCII values of adjacent characters.

    Return the score of s.
    
    '''




    def scoreOfString(self, s: str) -> int:
        ans = 0
        for index in range(1, len(s)):
            ans += abs(ord(s[index]) - ord(s[index -1]))

        return ans 



if __name__ == "__main__":
    print(f"Want : {13}, Was : {Solution().scoreOfString(s = "hello")}")
    print(f"Want : {50}, Was : {Solution().scoreOfString(s = "zaz")}")