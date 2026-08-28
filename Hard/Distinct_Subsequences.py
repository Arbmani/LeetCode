class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        cache = {}

        def Depth_First_Search(index_s: int, index_t: int) -> int:
            if index_t == len(t):
                return 1
            if index_s == len(s):
                return 0
            if (index_s, index_t) in cache:
                return cache[(index_s, index_t)]

            if s[index_s] == t[index_t]:
                cache[(index_s, index_t)] = (Depth_First_Search(index_s = index_s + 1, index_t = index_t + 1) + Depth_First_Search(index_s = index_s + 1, index_t = index_t))
            else:
                cache[(index_s, index_t)] = Depth_First_Search(index_s = index_s + 1, index_t = index_t)
            return cache[(index_s, index_t)]
        return Depth_First_Search(index_s= 0,index_t=0)


# Idea gör en substring där vi räcknar alla 
if __name__ == "__main__":
    sol = Solution()
    print(sol.numDistinct(s = "rabbbit", t = "rabbit"))