from typing import List 

'''
    Difference Between Maximum and Minimum Price Sum

    There exists an undirected and initially unrooted tree with "n" nodes indexed from "0" to "n - 1". 
    You are given the integer "n" and a "2D" integer array "edges" of length "n - 1", where "edges[i] = [ai, bi]"
    indicates that there is an edge between nodes "ai" and "bi" in the tree.

    Each node has an associated price. You are given an integer array "price", where "price[i]"
    is the price of the "ith" node.

    The price sum of a given path is the sum of the price of all nodes lying on that path.

    The tree can be rooted at any node "root" of your choice. The incurred cost after chossing "root"
    is the difference between the maximum and minimum price sum amongst all paths starting at "root".

    Return the maximum possible cost amongst all possible root choices.
'''


from collections import defaultdict


class Solution:
    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:
        graph = defaultdict(list)
        visited = [False] * n

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        result = 0

        def dfs(node):
            nonlocal result
            visited[node] = True

            include = price[node]
            exclude = 0

            for child in graph[node]:
                if not visited[child]:
                    child_include, child_exclude = dfs(child)

                    result = max(
                        result,
                        include + child_exclude,
                        exclude + child_include
                    )

                    include = max(
                        include,
                        price[node] + child_include
                    )

                    exclude = max(
                        exclude,
                        price[node] + child_exclude
                    )

            return include, exclude

        dfs(0)
        return result


if __name__ == "__main__":
    sol = Solution()
    print(sol.maxOutput(n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]))









