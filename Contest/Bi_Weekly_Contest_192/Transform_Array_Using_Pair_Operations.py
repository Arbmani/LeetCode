class Solution:
    '''
    [Medium Problem]

        You are given two integer arrays source and target.

        In one operation, you may choose two distinct indices i and j 
        in source, along with any integer delta. Then update source as follows:

        -   source[i] = source[i] + source[j] - delta

        -   source[j] = delta

        Return True if it is possible to make source equal to target after performing
        the operation any (including zero) number of times. Otherwise, return False.
    
    '''
    def canTransform(self, source: list[int], target: list[int]) -> bool:
        source = source.copy()
        reservior = len(source) -1
        for i in range(reservior):
            delta = source[i] + source[reservior] - target[i]
            source[i] = source[i] + source[reservior] - delta 
            source[reservior] = delta 
        return source == target


    def canTransform_best(self, source: list[int], target: list[int]) -> bool:
        return sum(source) == sum(target)


if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().canTransform(source = [1,2,3], target = [0,2,4])}")

    print(f"Want : {True}, Was : {Solution().canTransform(source = [-5,-5], target = [-15,5])}")

    print(f"Want : {False}, Was : {Solution().canTransform(source = [1,2,1], target = [0,2,5])}")