class Solution:
    '''
    [Hard Problem]

        You are given an integer array "nums" of length "n". You may rearrange its elements
        to form any permutation perm.

        Define an array power of length 15. For each 0 <= i < 15, power[i] is the largest integer "j",
        where 0 <= j <= n, such that the first j elements of perm all have the (14 - i)th bit set.

        Bit positions are indexed from right to left, starting with th 0th bit.

        Return the lexicographically largest possible power array. 
    
    '''

    # 1 = 001
    # 2 = 010
    # 3 = 011
    # 4 = 100
    # 5 = 101
    # 6 = 110
    # 7 = 111

    def largestPower(self, nums: list[int]) -> list[int]:
        groups, result = [nums], [0] * 15
        for bit in range(14, -1, -1):
            mask = 1 << bit 
            curr = 0
            nxt  = []
            flag = False
            for group in groups:
                if flag:
                    nxt.append(group)
                else:
                    s1 = all(num & mask for num in group)
                    if s1:
                        curr += len(group)
                        nxt.append(group)
                    else:
                        flag = True
                        gg   = [num for num in group if (num & mask)]
                        gw   = [num for num in group if not (num & mask)]
                        curr += len(gg)
                        if gg: nxt.append(gg)
                        if gw: nxt.append(gw)
            result[14 - bit] = curr 
            groups           = nxt   

        return result

    def largestPower_sol1_slow(self, nums: list[int]) -> list[int]:
        cache = [0]* 32_768
        for num in nums:
            cache[num] += 1
        for index in range(15):
            for mask in range(32_768):
                if not (mask & (1 << index)):
                    cache[mask] += cache[mask | (1 << index)]
        power = [0]*15
        def check(power):
            for value in set(power) | {len(nums)}:
                if value and cache[sum(1 << index for index in range(15) if power[14 - index] >= value)] < value:
                    return False
            return True

        for bit in range(14, -1, -1):
            index, left, right, result = 14 - bit, 0, len(nums), 0
            while left <= right:
                mid = (left + right) // 2
                power[index] = mid 
                if check(power):
                    result, left = mid, mid + 1
                else:
                    right = mid - 1
            power[index] = result
        return power 

if __name__ == "__main__":
    '''
        Understanding the problem

            power[i] = the longest prefix of "perm" where every element has bit (14 - i) set.

            We want this array lexicographically largest maximise power[0] first (highest bit), then power[1], and so on.

        Solution (1) SOS DP + Binary Search

            Idea:   Precompute c[mask] = number of elements in num that have all bits in mask set.
                    Then binary search for the maximum achievable prefix length per bit.

            Step 1: Sum Over Subsets (SOS) DP
                for index in range(15):
                    for mask in range(32768):
                        if not(mask & (1 << index))
                            c[mask] += c[m | (1 << index)]
                After this c[mask] answers "how many elements have ALL bits of mask set?
                Each mask absorbs the count of all its supersets.

            Step 2: Binary Search per bit 

                For each bit (14 -> 0), binary search the max v we can set for power[14-b]
                The check(p, v) function builds the mask of all bits that must be set in the 
                first v elements, then verify c[mask] >= v.
            
        Solution (2) Greedy Partition

            Idead:  Maintain a list of groups continguous blocks of the permutation we're building.
                    At each bit, scan groups left to right: fully set groups extend the prefix,
                    the first mixed group gets split into "gg" (bit set) and "gw" (bit unset),
                    everything after is deferred.

                    group = [nums]
                    for b in 14..0:
                        for each group g in group (stop after first split):
                            if all elements in g have bit b:
                                curr += len(g)                  # entire group extends prefix
                            else:
                            split -> gg (has bit) + gw (lacks bit)
                            curr += len(gg)
                            break                               # groups after this dont count

            Why does it work ? 

                Within each group elements are still freely reordered for future bits. 
                Splitting into gg/gw preserves that freedom while correctly
                counting the prefix for the current bit. 



    
    
    
    
    '''



    print(f"Want : {[0,0,0,0,0,0,0,0,0,0,0,0,2,1,2]}, Was : {Solution().largestPower(nums = [7,5])}")

    print(f"Want : {[0,0,0,0,0,0,0,0,0,0,0,0,1,2,3]}, Was : {Solution().largestPower(nums = [3,1,7])}")