class Solution:
    '''
    [Hard Problem]

        You are given a list of airline tickets, where tickets[i] = [from_i, to_i] represents the departure and the
        arrival airports of one flight. Reconstructs the itinerary in order and return it.

        All of the tickets belong to a man who departs from "JFK" thus, the itinerary must begin with "JFK". If there
        are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as
        a signel string.

        -   For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

        You may assume all tickets form at least one valid itinerary. You must use all the tickets once
        and only once. 
    
    '''


    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        adj = {}
        for src, dst in tickets : adj.setdefault(src, []).append(dst)
        for src      in adj     : adj[src].sort(reverse=True)
        
        ans = [] 
        def dfs(src):
            while adj.get(src):
                dst = adj[src].pop()
                dfs(dst)
            ans.append(src)
        dfs("JFK")
        return ans[::-1]



if __name__ == "__main__":
    print(f"Want : {["JFK","MUC","LHR","SFO","SJC"]}, Was : {Solution().findItinerary(tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]])}")

    print(f"Want : {["JFK","ATL","JFK","SFO","ATL","SFO"]}, Was : {Solution().findItinerary(tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]])}")