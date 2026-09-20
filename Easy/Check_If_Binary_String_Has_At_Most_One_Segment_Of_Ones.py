class Solution:
    '''
    [Easy Problem]

        Given a binary string "s" without leading zeros, return true if s contains at most one contiguoues
        segment of ones. Otherwise, return false.
    
    '''

    def checkOnesSegment(self, s: str) -> bool:
        seen_one = False
        for index, char in enumerate(s):
            if char == '1':
                if seen_one and s[index - 1] == '0':
                    return False
                seen_one = True

        return True


if __name__ == "__main__":
    print(f"Want : {False}, Was : {Solution().checkOnesSegment(s = "1001")}")

    print(f"Want : {True}, Was : {Solution().checkOnesSegment(s = "110")}")