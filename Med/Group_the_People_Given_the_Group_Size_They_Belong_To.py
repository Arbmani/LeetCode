from collections import defaultdict
class Solution:
    '''
    [Medium Problem]

        There are "n" people that are split into some unknown number of groups.
        Each person is labeled with a unique ID from 0 to n - 1.

        You are given an integer array groupSizes, where groupSizes[i] is the size
        of the group that person "i" is in. For example, if groupSizes[1] = 3,
        then person 1 must be in a group of size 3.

        Return a list of groups such that each person "i" is in group of size groupSizes[i].

        Each person should appear in exactly one group, and every person must be in a group.
        If there are multiple answers, return any of them. It is guranteed that there 
        will be at least one valid solution for the given input. 
    
    
    '''

    def groupThePeople(self, groupSizes: list[int]) -> list[list[int]]:
        sizes = defaultdict(list)
        for i, groupSize in enumerate(groupSizes):
            sizes[groupSize].append(i)
        ans = []
        for key, values in sizes.items():
            for i in range(0, len(values), key):
                ans.append(values[i:i + key])
        
        return ans


if __name__ == "__main__":
    print(f"Want : {[[5],[0,1,2],[3,4,6]]}, Was : {Solution().groupThePeople(groupSizes = [3,3,3,3,3,1,3])}")
    print(f"Want : {[[1],[0,5],[2,3,4]]}, Was : {Solution().groupThePeople(groupSizes = [2,1,3,3,3,2])}")