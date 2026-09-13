class Solution:
    '''
    [Medium Problem]

        You are given two images, img1 and img2, represented as binary, square matrices of size
        "n x n". A binary matrix has only "0s" and "1s" as values.

        We translate one image however we choose by sliding all the "1" bits left, right up,
        and/or down any number of units. We then place it on top of the other image. We can 
        then calculate the overlap by counting the number of positions that have a "1" in both images.

        Note also that a translation does not include any kind of rotation. Any 1 bits that are 
        translated outside of the matrix borders are erased.

        Return the largest possible overlap. 
    
    
    '''

    def largestOverlap(self, img1: list[list[int]], img2: list[list[int]]) -> int:
        n = len(img1)
        if n == 1:
            return 1 if img1[0][0] == img2[0][0] == 1 else 0
        img1_ones = [(row, col) for row in range(n) for col in range(n) if img1[row][col] == 1]
        img2_ones = [(row, col) for row in range(n) for col in range(n) if img2[row][col] == 1]
        hash_counter = {}
        max_count    = 0
        for img1_row, img1_col in img1_ones:
            for img2_row, img2_col in img2_ones:
                key = ((img1_row - img2_row), (img1_col - img2_col))
                hash_counter[key] = hash_counter.get(key, 0) + 1
                max_count = max(max_count, hash_counter[key])
        return max_count

if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().largestOverlap(img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]])}")

    print(f"Want : {1}, Was : {Solution().largestOverlap(img1 = [[1]], img2 = [[1]])}")

    print(f"Want : {0}, Was : {Solution().largestOverlap(img1 = [[0]], img2 = [[0]])}")