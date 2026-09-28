class UnionFind:
    def __init__(self, number_of_elements):
        self.number_of_elements = number_of_elements
        self.parent             = [element for element in range(number_of_elements + 1)]
        self.group_size         = [1] *(number_of_elements + 1)

    def find(self, element):
        while element != self.parent[element]:
            self.parent[element] = self.parent[self.parent[element]]
            element = self.parent[element]
        return element

    def union(self, left_element, right_element):
        left_root   = self.find(left_element)
        right_root = self.find(right_element)
        if left_root == right_root: return 0
        if self.group_size[left_root] > self.group_size[right_root]:
            self.group_size[left_root] += self.group_size[right_root]
            self.parent[right_root]     = self.parent[left_root]
        else:
            self.group_size[right_root] += self.group_size[left_root]
            self.parent[left_root]       = self.parent[right_root]
        self.number_of_elements -= 1
        return 1

    def fully_connected(self):
        return self.number_of_elements <= 1

    
    



class Solution:
    '''
    [Hard Problem]

        Alice and Bob have an undirected graph of "n" nodes and three types of edges:

        -   Type 1: Can be traversed by Alice only.

        -   Type 2: Can be traversed by Bob only.

        -   Type 3: Can be traversed by both Alice and Bob.

        Given an array edges where edges[i] = [type_i, u_i, v_i] represents a bidirectional edge of type
        "type_i" between nodes u_i and v_i, find the maximum number of edges you can remove so that after
        removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully
        traversed by Alice and Bob if starting from any node, they can reach all other nodes.

        Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot 
        fully traverse the graph.
    
    
    '''


    def maxNumEdgesToRemove(self, n: int, edges: list[list[int]]) -> int:
        alice, bob = UnionFind(n), UnionFind(n)
        needed_edges = 0
        for typ, src_node, dst_node in edges:
            if typ == 3: needed_edges += (alice.union(src_node, dst_node) | bob.union(src_node, dst_node))
        for typ, src_node, dst_node in edges:
            if typ == 1: needed_edges += alice.union(src_node, dst_node)
            elif typ == 2: needed_edges += bob.union(src_node, dst_node)
        if bob.fully_connected() and alice.fully_connected():
            return len(edges) - needed_edges

        return -1
    


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().maxNumEdgesToRemove(n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]])}")

    print(f"Want : {0}, Was : {Solution().maxNumEdgesToRemove(n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]])}")

    print(f"Want : {-1}, Was : {Solution().maxNumEdgesToRemove(n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]])}")