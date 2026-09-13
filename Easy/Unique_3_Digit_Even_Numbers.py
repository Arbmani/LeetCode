class Solution:
    '''
    [Easy Problem]

        You are given an array of digits called "digits". Your task is to determine the number
        of distinct three-digit even numbers that can be formed using these digits.

        Note: Each copy of a digit can only be used once per number, and there may not be leading zeros
    '''
    def totalNumbers(self, digits: list[int]) -> int:
        count, result = [0] * 10, 0

        for digit in digits:
            count[digit] += 1
        for hundreds in range(1, 10):
            if count[hundreds] == 0:
                continue
            count[hundreds] -= 1
            for tens in range(10):
                if count[tens] == 0:
                    continue
                count[tens] -= 1
                for ones in (0, 2, 4, 6, 8):
                    if count[ones] > 0:
                        result += 1
                count[tens] += 1
            count[hundreds] += 1


        return result



if __name__ == "__main__":
    print(f"Want : {12}, Was : {Solution().totalNumbers( digits = [1,2,3,4])}")

    print(f"Want : {2}, Was : {Solution().totalNumbers(digits = [0,2,2])}")

    print(f"Want : {1}, Was : {Solution().totalNumbers(digits = [6,6,6])}")

    print(f"Want : {0}, Was : {Solution().totalNumbers(digits = [1,3,5])}")