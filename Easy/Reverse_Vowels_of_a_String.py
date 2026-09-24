class Solution:
    '''
    [Easy Problem]

        Given a string "s", reverse only all vowels in the string and return it.

        The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower 
        and upper cases, more than once.
    
    '''

    def reverseVowels(self, s: str) -> str:
        vowels, input_string = set("AaEeIiOoUu"), list(s)
        left, right          = 0, len(input_string) - 1

        while (left < right):
            while left < right and input_string[left] not in vowels:
                left  += 1
            while left < right and input_string[right] not in vowels:
                right -= 1
            input_string[left], input_string[right] = input_string[right], input_string[left]
            left  += 1
            right -= 1
        return ''.join(input_string)

if __name__ == "__main__":
    print(f"Want : {"AceCreIm"}, Was : {Solution().reverseVowels("IceCreAm")}") 
    print(f"Want : {"leotcede"}, Was : {Solution().reverseVowels("leetcode")}") 