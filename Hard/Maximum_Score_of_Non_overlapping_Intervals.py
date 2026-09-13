import bisect 
class Solution:
    '''
    [Hard problem]

        You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. 
        Interval "i" starts at position "li" and ends at "ri", and has a weight of "weighti".
        You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is 
        defined as the total sum of their weights.

        Return the lexicographically smallest array of at most 4 indices from intervals with
        maximum score, representing your choice of non-overlapping intervals.

        Two intervals are said to be non-overlapping if they do not share any points. 
        In particular, intervals sharing a left or right bounardy are considered overlapping.

    '''

    def maximumWeight(self, intervals: list[list[int]]) -> list[int]:
        duplicates = {}
        for index, (start, end, weight) in enumerate(intervals):
            if (start, end, weight) not in duplicates:
                duplicates[(start, end, weight)] = index
        intervals       = sorted(duplicates.keys())
        len_intervals   = len(intervals)
        next_interval   = [0]*len_intervals

        for i in range(len_intervals):
            start, end, weight = intervals[i]
            next_interval[i]   = bisect.bisect_right(
                intervals,
                (end, float("inf"), float("inf")))      # what does bisect do ? 

        cache = [[(0, []) for _ in range(5)] for _ in range(len_intervals + 1)] # Why do we use len_intervals + 1
        for i in range(len_intervals - 1, -1, -1):
            start, end, weight  = intervals[i]
            original_index      = duplicates[(start, end, weight)]
            for k in range(1, 5):
                skip_weight, skip_index = cache[i + 1][k]
                next_weight, next_index = cache[next_interval[i]][k - 1]
                take_weight = weight + next_weight
                take_index  = sorted(next_index + [original_index])

                take = (take_weight, take_index)
                skip = (skip_weight, skip_index)

                if take_weight > skip_weight:
                    cache[i][k] = take 
                elif take_weight < skip_weight:
                    cache[i][k] = skip 
                else:
                    cache[i][k] = min(take, skip)

        return cache[0][4][1]



if __name__ == "__main__":
    '''
        
    How could I make the insight that leads to discovering the solution?







    '''

    print(f"Want : {[2,3]}, Was : {Solution().maximumWeight(intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]])}")

    print(f"Want : {[1,3,5,6]}, Was : {Solution().maximumWeight(intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]])}")


