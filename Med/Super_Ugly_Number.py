class Solution:
    '''
    [Medium Problem]

        A super ugly number is a postive integer whose prime factors are in the same array primes.

        Given an integer "n" and an array of integers "primes", return the "nth" super ugly number.

        The nth super ugly number is guaranteed to fit in a 32-bit signed integer.     
    
    '''

    def nthSuperUglyNumber(self, n: int, primes: list[int]) -> int:
        ugly, len_primes = [1] * n, len(primes) 
        pointers         = [0] * len_primes

        for i in range(1, n):
            candidates = [ugly[pointers[j]] * primes[j] for j in range(len_primes)]
            ugly[i]    = min(candidates)
            for j in range(len_primes):
                if candidates[j] == ugly[i]:
                    pointers[j] += 1
        return ugly[-1]


if __name__ == "__main__":
    print(f"Want : {32}, Was : {Solution().nthSuperUglyNumber(n = 12, primes = [2,7,13,19])}")

    print(f"Want : {1}, Was : {Solution().nthSuperUglyNumber(n = 1, primes = [2,3,5])}")