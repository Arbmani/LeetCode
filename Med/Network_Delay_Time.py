import heapq
class Solution:
    '''
    [Medium Problem]

        You are given a network of "n" nodes, labeled from 1 to n. You are also given times, a list of travel times 
        as directed edges times[i] = (u_i, v_i, w_i), where u_i is the souce node, v_i is the target node, and w_i
        is the time it takes for a signal to travel from source to target.

        We will send a signal from a given node k. Return the minimum time it takes for all the "n" nodes
        to recieve the signal. If it is impossible for all the "n" nodes to recieve
        the signal, return - 1.

    
    '''


    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        adjacency_list = [[] for _ in range(n + 1)]
        for u, v, w in times:
            adjacency_list[u].append((v, w))
        distance = [float("inf")] * (n + 1)
        distance[k] = 0
        heap = [(0, k)]
        while heap:
            current_distance, node = heapq.heappop(heap)
            if current_distance > distance[node]: continue

            for neighbor, weight in adjacency_list[node]:
                new_distance = current_distance + weight 
                if new_distance < distance[neighbor]:
                    distance[neighbor] = new_distance
                    heapq.heappush(heap, (new_distance, neighbor))
        answer = max(distance[1:])
        return -1 if answer == float("inf") else answer
        



if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().networkDelayTime(times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2)}")
    print(f"Want : {1}, Was : {Solution().networkDelayTime(times = [[1,2,1]], n = 2, k = 1)}")
    print(f"Want : {-1}, Was : {Solution().networkDelayTime(times = [[1,2,1]], n = 2, k = 2)}")