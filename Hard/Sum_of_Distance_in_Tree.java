import java.util.*;

/*

There is an undirected connected tree with n nodes 
labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where 
edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] 
is the sum of the distances between the ith node in the tree and all other nodes.

*/

class SolutionsumOfDistancesInTree {
    private List<List<Integer>> graph;
    private int[] count;
    private int[] answer;

    private void dfs1(int node, int parent){
        count[node] = 1;
        for (int child : graph.get(node)){
            if (child == parent) continue;
            dfs1(child, node);
            count[node]  += count[child];
            answer[node] += answer[child] + count[child];
        }   
    }
    private void dfs2(int node, int parent){
        for (int child : graph.get(node)){
            if (child == parent) continue;
            answer[child] = answer[node] + count.length - 2*count[child];
            dfs2(child, node);
        }
    }



    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        graph  = new ArrayList<>();
        count  = new int[n];
        answer = new int[n];
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return answer;
    }
}


public class Sum_of_Distance_in_Tree{
    public static void main(String[] args) {
        SolutionsumOfDistancesInTree s = new SolutionsumOfDistancesInTree();
        
        int [][] edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}}; 
        int [][] edges2 = {}; 
        int [][] edges3 = {{1, 0}}; 

        System.out.println("\nWant : [8,12,6,10,10,10]\nWas  : " + Arrays.toString(s.sumOfDistancesInTree(6, edges1)));
        System.out.println("\nWant : [0]\nWas  : "               + Arrays.toString(s.sumOfDistancesInTree(1, edges2)));
        System.out.println("\nWant : [1,1]\nWas  : "             + Arrays.toString(s.sumOfDistancesInTree(2, edges3)));

    }
}