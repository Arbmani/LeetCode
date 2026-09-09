class Solution:
    '''
    [Medium Problem]

        You are given an integer "n".

        Return the total number of commas used when writing all integers from [1, n] (inclusive) in 
        standard number formatting.

        In standard formatting:

        -   A comma is inserted after every three digits from the right.

        -   Numbers with fewer than 4 digits contain no commas.
    '''

    def countCommas(self, n: int) -> int:
        result  = 0
        divider = 1000
        while(n >= divider):
            result  += (n + 1) - divider
            divider *= 1000
        return result

if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().countCommas(1002)}")

    print(f"Want : {0}, Was : {Solution().countCommas(998)}")
