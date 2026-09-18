class Solution:
    '''
    [Medium Problem]

        An ugly number is a positve integer whose prime factors are limited to 2, 3, and 5.

        Given an integer "n", return the nth ugly number.  
    
    
    
    '''


    def nthUglyNumber(self, n: int) -> int:
        ugly = [1] * n 
        index_of_Two = index_of_Three = index_of_Five = 0
        for index in range(1, n):
            two, three, five = ugly[index_of_Two] * 2, ugly[index_of_Three] * 3, ugly[index_of_Five] * 5
            ugly[index] = min(two, three, five)
            if ugly[index] == two:
                index_of_Two += 1
            if ugly[index] == three:
                index_of_Three += 1
            if ugly[index] == five:
                index_of_Five += 1
        return ugly[n - 1]

if __name__ == "__main__":
    print(f"Want : {4}, Was : {Solution().nthUglyNumber(3)}")
    print(f"Want : {12}, Was : {Solution().nthUglyNumber(10)}")
    print(f"Want : {1}, Was : {Solution().nthUglyNumber(1)}")