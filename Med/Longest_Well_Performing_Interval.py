class Solution:
    '''
    [Medium Problem]

        We are given hours, a list of the number of hours worked per day for a given employee.

        A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8. 

        A well-performing interval is an interval of days for which the number of tiring days is strictly larger 
        than the number of non-tiring days.

        Return the length of the longest well-performing interval.
    
    '''

    def longestWPI(self, hours: list[int]) -> int:
        prefix = [0]
        for hour in hours:
            prefix.append(prefix[-1] + (1 if hour > 8 else -1))
        stack = []
        for i in range(len(prefix)):
            if not stack or prefix[i] < prefix[stack[-1]]:
                stack.append(i)
        ans = 0
        for right in range(len(prefix) - 1, -1, -1):
            while stack and prefix[right] > prefix[stack[-1]]:
                left = stack.pop()
                ans  = max(ans, right - left)

        return ans


if __name__ == "__main__":
    print(f"Want : {9}, Was : {Solution().longestWPI(hours = [9,0,0,0,0,9,9,9,9])}")
    print(f"Want : {1}, Was : {Solution().longestWPI(hours = [9])}")


    print(f"Want : {3}, Was : {Solution().longestWPI(hours = [9,9,6,0,6,6,9])}")

    print(f"Want : {0}, Was : {Solution().longestWPI(hours = [6,6,6])}")