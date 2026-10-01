class Solution:
    '''
    [Easy Problem]

    Given two integers, num and t. 
    A number x is achievable if it can become equal to num after applying the following operation at most t times:

    Increase or decrease x by 1, and simultaneously increase or decrease num by 1.
    Return the maximum possible value of x.

    '''

    def theMaximumAchievableX(self, num: int, t: int) -> int:
        return num + 2*t



if __name__ == "__main__":
    print(f"Want : {6}, Was : {Solution().theMaximumAchievableX(num = 4, t = 1)}")
    print(f"Want : {7}, Was : {Solution().theMaximumAchievableX(num = 3, t = 2)}")