class Solution:
    '''
        You are given a string "s" containing lowercase letters and an integer "k".

        You need to:

            -   First, change some characters of s to other lowercase English letters.
            
            -   Then divide "s" into "k" non-empty disjoint substrings such that each substring is a palindrome.

        Return the minimal number of characters that you need to change to divide the string.
    
    
    '''

    def palindromePartition(self, s: str, k: int) -> int:
        word_len = len(s)
        cost = [[0] * word_len for _ in range(word_len)]
        for substring_len in range(2, word_len + 1):
            for substring_start in range(word_len - substring_len + 1):
                substring_end = substring_start + substring_len - 1
                cost[substring_start][substring_end] = cost[substring_start + 1][substring_end - 1] + (s[substring_start] != s[substring_end])

        partition_cache         = [[float("inf")] * (word_len + 1) for _ in range(k + 1)]
        partition_cache[0][0]   = 0

        for partition in range(1, k + 1):
            for prefix_len in range(partition, word_len + 1):
                for split_index in range(partition - 1, prefix_len):
                    partition_cache[partition][prefix_len] = min(
                        partition_cache[partition][prefix_len],
                        partition_cache[partition - 1][split_index] + cost[split_index][prefix_len - 1])

        return partition_cache[k][word_len]


if __name__ == "__main__":
    print(f"Correct answer is 1 mine is : {Solution().palindromePartition(s = "abc", k = 2)}")
    print(f"Correct answer is 0 mine is : {Solution().palindromePartition(s = "aabbc", k = 3)}")
    print(f"Correct answer is 0 mine is : {Solution().palindromePartition(s = "leetcode", k = 8)}")