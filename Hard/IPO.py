import heapq
class Solution:
    '''
    [Hard Problem]

        Suppose LeetCode will start its IPO soon. In order to sell a good pirce of its shares to Venture Capital,
        LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources,
        it can only finish at most "k" projects before the IPO. Help LeetCode design the best way to maximize its 
        total ccapital after finishing at most "k" distinct projcets.

        You are given "n" projects where the "i"th projcet has a pure profit profits[i] and a minimum capital
        of capital[i] is needed to start it.

        Initially, you have "w" capital. When you finish a project, you will obtain its pure profit and 
        the profit will be added to your capital.

        Pick a list of at most "k" distinct projects from given projects to maximize your final
        capital, and return the final maximized capital.

        The answer is guaranteed to fit in a 32-bit signed integer. 
    
    
    '''
    def findMaximizedCapital(self, k: int, w: int, profits: list[int], capital: list[int]) -> int:
        projects        = sorted(zip(capital, profits))
        max_profit      = []
        i, len_projects = 0, len(projects)

        for _ in range(k):
            while i < len_projects and projects[i][0] <= w:
                heapq.heappush(max_profit, -projects[i][1]) 
                i += 1
            if not max_profit:
                break
            w -= heapq.heappop(max_profit)
        return w


    def findMaximizedCapital_slow(self, k: int, w: int, profits: list[int], capital: list[int]) -> int:
        maxProfit = []
        minCapital = [(capital_i, profits_i) for capital_i, profits_i in zip(capital, profits)]
        heapq.heapify(minCapital)

        for _ in range(k):
            while minCapital and minCapital[0][0] <= w: 
                _, profits_i  = heapq.heappop(minCapital)
                heapq.heappush(maxProfit, -1*profits_i)
            if not maxProfit:
                break 
            w -= heapq.heappop(maxProfit)
        return w

    


if __name__ == "__main__":
    print(f"Want : {4}, Was : {Solution().findMaximizedCapital( k = 2, w = 0, profits = [1,2,3], capital = [0,1,1])}")

    print(f"Want : {6}, Was : {Solution().findMaximizedCapital( k = 3, w = 0, profits = [1,2,3], capital = [0,1,2])}")