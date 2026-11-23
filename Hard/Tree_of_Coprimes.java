import java.util.*;


/*

There is a tree (i.e., a connected, undirected graph that has no cycles) consisting 
of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. Each node has a value 
associated with it, and the root of the tree is node 0.

To represent this tree, you are given an integer array nums and a 2D 
array edges. Each nums[i] represents the ith node's value, and each 
edges[j] = [uj, vj] represents an edge between nodes uj and vj in the tree.

Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) 
is the greatest common divisor of x and y.

An ancestor of a node i is any other node on the shortest path 
from node i to the root. A node is not considered an ancestor of itself.

Return an array ans of size n, where ans[i] is the closest ancestor 
to node i such that nums[i] and nums[ans[i]] are coprime, or -1 if there is no such ancestor.


*/

class Solution {
    private List<List<Integer>> graph;
    private boolean[][] coprimes;

    private int gcd(int a, int b){
        while (b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static class State {
        int node;
        int parent;
        int depth;
        boolean exit;
        State(int node, int parent, int depth, boolean exit){
            this.node   = node;
            this.parent = parent;
            this.depth  = depth;
            this.exit   = exit;
        }
    }


    public int[] getCoprimes(int[] nums, int[][] edges) {
        int n    = nums.length;
        graph    = new ArrayList<>();
        coprimes = new boolean[51][51];
        int [] ans = new int[n];

        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int []edge : edges){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        for (int a = 1; a <= 50; a++){
            for (int b = 1; b <= 50; b++) coprimes[a][b] = gcd(a, b) == 1;
        }
        int [] deepestNode  = new int[51];
        int [] deepestDepth = new int[51];

        Arrays.fill(deepestNode, -1);
        Arrays.fill(deepestDepth, -1);

        int[] previousNode  = new int[n];
        int[] previousDepth = new int[n];

        Deque<State> stack = new ArrayDeque<>();
        stack.push(new State(0, -1, 0, false));
        while (!stack.isEmpty()){
            State cur = stack.pop();
            int value = nums[cur.node];
            
            if (cur.exit){                
                deepestNode[value]   = previousNode[cur.node];
                deepestDepth[value]  = previousDepth[cur.node];
                continue;
            }
            int bestDepth = -1;
            for (int v = 1; v <= 50; v++){
                if (coprimes[value][v] && deepestDepth[v] > bestDepth){
                    bestDepth = deepestDepth[v];
                    ans[cur.node] = deepestNode[v];
                }
            }
            if (bestDepth == -1) ans[cur.node] = -1;
            previousNode[cur.node]  = deepestNode[value];
            previousDepth[cur.node] = deepestDepth[value];
            
            deepestNode[value]  = cur.node;
            deepestDepth[value] = cur.depth;
            cur.exit = true;
            stack.push(cur);
            for (int child : graph.get(cur.node)){
                if (child == cur.parent) continue;
                stack.push(new State(child, cur.node, cur.depth + 1, false));
            }
        }
        return ans;        
    }
}

public class Tree_of_Coprimes{
    public static void main(String[] args) {
        Solution s = new Solution();
        int [] nums1 = {2,3,3,2};
        int[][] edges1 = {{0,1}, {1,2}, {1,3}};

        int [] nums2 = {5,6,10,2,3,6,15};
        int[][] edges2 = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}};

        System.out.println("\nWant : [-1,0,0,1]\nWas  : " + Arrays.toString(s.getCoprimes(nums1, edges1)));
        System.out.println("\nWant : [-1,0,-1,0,0,0,-1]\nWas  : " + Arrays.toString(s.getCoprimes(nums2, edges2)));

    }
}