class Solution:
    '''
    [Hard Problem]

        A password is considered strong if the below conditions are all met:

        -   It has at least 6 characters and at most 20 characters

        -   It contains at least one lowercase letter, at least one uppercase letter, and at least one digit

        -   It does not contain three repeating characters in a row(i.e., "Baaabb0" is weak but "Baaba0" is strong).

        Given a string password, return the minimum numbers of steps required to make password strong, if password is
        already strong return 0.

        In one step, you can:

        -   Insert one character to password,

        -   Delete one character from password, or

        -   Replace one character of password with another character
    
    
    '''
    
    def strongPasswordChecker(self, password: str) -> int:
        digit = lower = upper = 1
        rangesOfThree = []
        start = 0
        len_password = len(password)

        for index, char in enumerate(password):
            if   char.isupper(): upper = 0
            elif char.islower(): lower = 0
            elif char.isdigit(): digit = 0

            if index == len_password - 1 or password[index + 1] != password[start]:
                length = index - start + 1
                if length >= 3: rangesOfThree.append(length)
                start = index + 1
        
        missing     = digit + lower + upper 
        replacement = sum(length // 3 for length in rangesOfThree)

        if len_password < 6  : return max(missing, 6 - len_password)
        if len_password <= 20: return max(missing, replacement)
        
        deletions = len_password - 20
        for remainder, needed in ((0,1), (1, 2), (2, 3)):
            for i in range(len(rangesOfThree)):
                if deletions < needed or rangesOfThree[i] % 3 != remainder: continue
                use                 = min(deletions, needed)
                rangesOfThree[i]   -= use
                deletions          -= use 

        for i in range(len(rangesOfThree)):
            if deletions < 3: break 
            use                  = min(deletions, rangesOfThree[i] - 2)
            rangesOfThree[i]    -= use 
            deletions           -= use

        replacement = sum(length // 3 for length in rangesOfThree)


        return (len_password - 20) + max(replacement, missing)

if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().strongPasswordChecker(password = "aaaaaaA1")}")
    print(f"Want : {23}, Was : {Solution().strongPasswordChecker(password = "FFFFFFFFFFFFFFF11111111111111111111AAA")}")

    print(f"Want : {2}, Was : {Solution().strongPasswordChecker(password = "ABABABABABABABABABAB1")}")

    print(f"Want : {2}, Was : {Solution().strongPasswordChecker(password = "aaaabbb")}")

    print(f"Want : {5}, Was : {Solution().strongPasswordChecker(password = "a")}")
    print(f"Want : {3}, Was : {Solution().strongPasswordChecker(password = "aA1")}")
    print(f"Want : {0}, Was : {Solution().strongPasswordChecker(password = "1337C0d3")}")