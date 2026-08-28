class Solution:
    '''
        You are given a string "s". You can convert "s" to a palindrome, by adding characters in front of it.

        Return the shortest palindrome you can find by performing this transformation.
    
    
    '''


    def shortestPalindrome(self, s: str) -> str:
        '''
            This solution is a rolling hash to find the longest palindromic prefix of "s"

            If the hash of the prefix read left -> right equals the hash of the same characters
            read right -> left, we treat that prefix as a palindrome. 
            
            This:
                prefix = (prefix * base) % mod 
                prefix = (prefix + char) % mod 
            
            Is the standard polynomial rolling hash.
            
                
        '''
        prefix      = 0
        suffix      = 0
        base        = 29

        last_index  = 0
        power       = 1
        mod         = 10**9 + 7

        for i, c in enumerate(s):
            char = (ord(c) - ord('a') + 1)

            prefix = (prefix * base) % mod 
            prefix = (prefix + char) % mod 
 
            suffix = (suffix + char * power) % mod 
            power  = (power * base) % mod 

            if prefix == suffix:
                last_index = i 
        suffix = s[last_index + 1:]
        return suffix[::-1] + s




if __name__ == "__main__":
    print(Solution().shortestPalindrome(s = "aabba"))