import java.util.*;

/*

You are given a tree (i.e. a connected, undirected graph that has no cycles) 
consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. 
The root of the tree is the node 0, and each node of the tree has a label 
which is a lower-case character given in the string labels (i.e. The node with the number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], 
which means there is an edge between nodes ai and bi in the tree.

Return an array of size n where ans[i] is the number of 
nodes in the subtree of the ith node which have the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.


*/

class SolutionNumber_of_Nodes_in_the_SubTree_With_the_Same_Label {
    private List<List<Integer>> graph;
    private int[][] freq;
    private int[]   ans;
    private String  labels;

    private void dfs(int node, int parent){
        int cha = labels.charAt(node) - 'a';
        freq[node][cha]++;

        for (int child : graph.get(node)){
            if (child == parent) continue;
            dfs(child, node);
            for (int i = 0; i < 26; i++) freq[node][i] += freq[child][i];
        }
        ans[node] = freq[node][cha];
    }



    public int[] countSubTrees(int n, int[][] edges, String labels) {
        this.labels = labels;
        graph       = new ArrayList<>();
        freq        = new int[n][26];
        ans         = new int[n];

        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        dfs(0, -1);


        return ans;
    }
}

public class Number_of_Nodes_in_the_SubTree_With_the_Same_Label {
    public static void main(String[] args) {
        SolutionNumber_of_Nodes_in_the_SubTree_With_the_Same_Label s = new SolutionNumber_of_Nodes_in_the_SubTree_With_the_Same_Label();

        int [][] edges1 = {{0,1}, {0,2}, {1,4}, {1,5}, {2,3}, {2,6}};
        int [][] edges2 = {{0,1}, {1,2}, {0,3}};
        int [][] edges3 = {{0,1}, {0,2}, {1,3}, {0,4}};

        System.out.println("\nWant : [2,1,1,1,1,1,1]\nWas  : " + Arrays.toString(s.countSubTrees(7, edges1, "abaedcd")));
        System.out.println("\nWant : [4,2,1,1]\nWas  : " + Arrays.toString(s.countSubTrees(4, edges2, "bbbb")));
        System.out.println("\nWant : [3,2,1,1,1]\nWas  : " + Arrays.toString(s.countSubTrees(5, edges3, "aabab")));


    }
}
