class Solution:
    '''
    [Medium Problem]

        You are given an integer array nums consisting of positive integers and an integer "k".

        The prime factor set of a subarray is the union of the distinct prime factors of all its elements.

        Return the length of the longest subarray whose prime factor set contains at most "k"
        distinct prime factors. If no such subarray exists, return 0.
    
    
    '''

    def longestSubarray(self, nums: list[int], k: int) -> int:
        prime_frequency = {}
        left = ans = 0
        def get_prime_factors(number: int) -> set[int]:
            prime_factors   = set()
            divisor         = 2
            while(divisor * divisor <= number):
                while number % divisor == 0:
                    prime_factors.add(divisor)
                    number //= divisor
                divisor +=1
            if number > 1:
                prime_factors.add(number)
            return prime_factors

        for right in range(len(nums)):
            factors = get_prime_factors(nums[right])
            for prime in factors:
                prime_frequency[prime] = (prime_frequency.get(prime, 0) + 1)
            while(len(prime_frequency) > k):
                left_factors = get_prime_factors(nums[left])
                for prime in left_factors:
                    prime_frequency[prime] -= 1
                    if prime_frequency[prime] == 0:
                        del prime_frequency[prime]
                left += 1
            current_len = right - left + 1
            ans = max(ans, current_len)

        return ans


if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().longestSubarray(nums = [7,6,10,12,11], k = 3)}")

    print(f"Want : {4}, Was : {Solution().longestSubarray(nums = [4,6,9,18], k = 4)}")

    print(f"Want : {1}, Was : {Solution().longestSubarray(nums = [6,10,15], k = 2)}")