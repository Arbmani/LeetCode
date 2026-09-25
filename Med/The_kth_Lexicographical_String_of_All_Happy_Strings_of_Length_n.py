class Solution:
    '''
    [Medium Problem]

    A happy string is a string that:

    -   consists only of letters of the set ['a', 'b', 'c'].

    -   s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed)

    For example, strings "abc", "ac", "b", and "abcbabcbcb" are all happy strings and 
    strings "aa", "baa", and "ababbc" are not happy strings.

    Given two integers "n" and "k", considering a list of all happy strings of length
    n sorted in lexicographical order.

    Return the kth string of this list or return an empty string if there are less than 
    k happy strings with len n.
    
    
    '''
    # 3 * n 
    # n = 1, h = 3 a, b, c
    # n = 2, h = 6 ab, ac, ba, bc, ca, cb  
    # n = 3, h = 12  "aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"
    # n = 4, h = 24
    # 
    #          abc, aba, aca, bab, bac, bca 

    # given n first pos can b 3, 2, 3, 2, 3, 2

    # happy = 2^(n-1) * 3

    def getHappyString(self, n: int, k: int) -> str:
        ans, max_happy = "", 3 * 2**(n - 1)
        if k > max_happy: return ans
        prev = ""
        for i in range(n):
            choices = [c for c in "abc" if c != prev]
            bucket_size = 2**(n - (i + 1))
            bucket      = (k - 1) // bucket_size
            ans         += choices[bucket]
            prev         = choices[bucket]
            k = (k - 1) % bucket_size + 1
        return ans


    def getHappyString_WIP(self, n: int, k: int) -> str:
        ans, max_happy = "", 2**(n-1) * 3
        if k > max_happy: return ans
        buckets = ["a", "b", "c"]
        while(max_happy > 0):
            bucket_size, bucket = max_happy // 3, 1
            print(bucket_size)
            while bucket * bucket_size < k:
                bucket += 1
            print(bucket)
            ans = ans + buckets[bucket - 1]
            n -=1
            k = k - (bucket - 1) * bucket_size
            max_happy = 2**(n-1) * 3


        # lets say k = 9 max_happy = 12 


        return ans



if __name__ == "__main__":
    print(f"Want : {"c"}, Was : {Solution().getHappyString(n = 1, k = 3)}")

    print(f"Want : {""}, Was : {Solution().getHappyString(n = 1, k = 4)}")

    print(f"Want : {"cab"}, Was : {Solution().getHappyString(n = 3, k = 9)}")