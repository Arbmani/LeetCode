class UnionFind:
    def __init__(self, nodes: int) -> None:
        self.parent = [i for i in range(nodes)]
        self.rank   = [1] * nodes 

    def find(self, v1: int) -> int:
        while v1 != self.parent[v1]:
            self.parent[v1] = self.parent[self.parent[v1]]
            v1 = self.parent[v1]
        return v1

    def union(self, v1: int, v2: int) -> int:
        parent_1, parent_2 = self.find(v1), self.find(v2)
        if parent_1 == parent_2: return False
        if self.rank[parent_1] > self.rank[parent_2]:
            self.parent[parent_2] = parent_1
            self.rank[parent_1] += self.rank[parent_2]
        else:
            self.parent[parent_1] = parent_2
            self.rank[parent_2] += self.rank[parent_1]
        return True
    
class Solution:
    '''
    [Hard Problem]

        Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, 
        and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional 
        and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a 
        subset of the graph's edges that connects all vertices without cycles and 
        with the minimum possible total edge weight.

        Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST).
        An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. 
        On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

        Note that you can return the indices of the edges in any order.
    
    '''

    
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: list[list[int]]) -> list[list[int]]:
        for index, edge in enumerate(edges):
            edge.append(index)
        edges.sort(key=lambda edge: edge[2])
        mst_weight = 0
        uf = UnionFind(n)
        for v1, v2, weight, index in edges:
            if uf.union(v1, v2):
                mst_weight += weight
        ciritcal, psudo = [], []
        for n1, n2, edge_weight, index in edges:
            weight  = 0
            uf      = UnionFind(n)
            for v1, v2, w, j, in edges:
                if index != j and uf.union(v1, v2):
                    weight += w 
            if max(uf.rank) != n or weight > mst_weight:
                ciritcal.append(index)
                continue
            uf = UnionFind(n)
            uf.union(n1, n2)
            weight = edge_weight
            for v1, v2, w, j in edges:
                if uf.union(v1, v2):
                    weight += w 
            if weight == mst_weight:
                psudo.append(index)



        return [ciritcal, psudo]


if __name__ == "__main__":
    print(f"Want : {[[0,1],[2,3,4,5]]}, Was : {Solution().findCriticalAndPseudoCriticalEdges(n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]])}")
    print(f"Want : {[[],[0,1,2,3]]}, Was : {Solution().findCriticalAndPseudoCriticalEdges(n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]])}")