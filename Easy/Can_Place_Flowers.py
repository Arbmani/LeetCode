class Solution:
    '''
        You have a long flowerbed in which some of the plots are planted, and some are not.
        However, flowers cannot be planted in adjacent plots.

        Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1
        means not empty, and an integer n return true if n new flowers can be planted
        in the flowerbed without violating the no adjacent flowers rule and false otherwise.
    
    '''


    def canPlaceFlowers(self, flowerbed: list[int], n: int) -> bool:
        if n == 0: return True
        len_flowerbed = len(flowerbed)
        left = 0
        while left < len_flowerbed:
            if flowerbed[left] == 1: 
                left += 2
                continue
            left_empty  = left == 0 or flowerbed[left - 1] == 0
            right_empty = (left == len_flowerbed - 1 or flowerbed[left + 1] == 0)

            if left_empty and right_empty:
                flowerbed[left] = 1 
                n              -= 1
                if n == 0: return True
                left += 2
            else:
                left += 1
        return False


if __name__ == "__main__":
    print(f"Want: {True}, Was : {Solution().canPlaceFlowers(flowerbed  = [0,0,1,0,0,0,0,0], n = 1)}")
    print(f"Want: {True}, Was : {Solution().canPlaceFlowers(flowerbed  = [1,0,0,0,1], n = 1)}")
    print(f"Want: {False}, Was : {Solution().canPlaceFlowers(flowerbed = [1,0,0,0,1], n = 2)}")