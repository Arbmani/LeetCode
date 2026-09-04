from typing import List 
class Solution:
    '''
        Convert a non-negative integer "num" to its English words representation.
    '''
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        sub_20 = [
            "", "One", "Two", "Three", "Four",
            "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen",
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        ]
        ten = [
            "", "", "Twenty", "Thirty", "Forty",
            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        ]
        def three_digits_to_words(digit: int) -> str:
            result = []
            if digit >= 100:
                result.append(sub_20[digit // 100])
                result.append("Hundred")
                digit %= 100
            if digit >= 20:
                result.append(ten[digit // 10])
                digit %= 10
            if digit > 0:
                result.append(sub_20[digit])
            return " ".join(result)

        mymap = [
            (1_000_000_000, "Billion"),
            (1_000_000, "Million"),
            (1_000, "Thousand"),
        ]
        result = []
        for value, name in mymap:
            if num >= value:
                result.append(three_digits_to_words(num // value))
                result.append(name)
                num %= value
        if num > 0:
            result.append(three_digits_to_words(num))
        return " ".join(result)

if __name__ == "__main__":
    print(Solution().numberToWords(123))
    print(Solution().numberToWords(12345))
    print(Solution().numberToWords(1234567))