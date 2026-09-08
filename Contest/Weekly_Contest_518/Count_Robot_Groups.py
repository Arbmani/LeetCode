class Solution:
    '''
    [Medium Problem]

        You are given a "strictly increasing" integer array positions, where position[i]
        is the initial position of the "ith" robot at time t = 0.

        You are also given an integer array "speed", where "speed[i]" is the constant speed 
        of the "ith" robot in units per second, and an integer "distance".

        Time is continuous and measured in seconds. A robot or group with speed "v" moves
        "v * t" units to the right over any interval of "t" seconds.

        Whenever the distance between two robots or groups becomes at most "distance", they merge into a single group.

        If multiple robots or groups satisfy the merging condition at the same time, all merges happen simultaneously.
        In particular, every connected collection of robots or groups whose consecutive position differ by at most
        distance merges into one group. 

        After a merge, the resoluting group takes the current position and speed of the rightmost robot in that group.
        Once merged, robots never separate.

        Return the number of groups remaining after all possible merges have occured.  
    
    
    '''


    def countGroups(self, position: list[int], speed: list[int], distance: int) -> int:
        len_arrays, groups = len(position), 1
        prev       = (speed[len_arrays - 1], position[len_arrays - 1])
        for index in range(len_arrays - 2, -1, -1):
            if speed[index] > prev[0] or prev[1] - position[index] <= distance:
                prev = (prev[0], position[index])
            else:
                groups += 1
                prev = (speed[index], position[index])     
        return groups


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().countGroups(position = [1,5,6,20], speed = [4,3,2,3], distance = 1)}")

    print(f"Want : {2}, Was : {Solution().countGroups(position = [1,5,9], speed = [3,2,2], distance = 2)}")

    print(f"Want : {1}, Was : {Solution().countGroups(position = [9], speed = [8], distance = 5)}")