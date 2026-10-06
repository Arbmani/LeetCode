class Solution:
    '''
    [Medium Problem]


        Given an "n x n" matrix where each of the rows and columns are in sorted in ascending order,
        return the "kth" smallest element in the matrix.

        Note that it is the kth smallest element in the sorted order, not the kth distinct element.

        You must find a solution with a memory complexity better than O(n^2)
    
    
    '''
    def kthSmallest(self, matrix: list[list[int]], k: int) -> int:
        n = len(matrix)
        left, right = matrix[0][0], matrix[n - 1][n - 1]
        while left < right:
            mid     = left + (right - left) // 2
            count   = 0
            col     = n - 1
            for row in range(n):
                while col >= 0 and matrix[row][col] > mid:
                    col -= 1
                count += col + 1
            if count < k: left  = mid + 1
            else        : right = mid 
        return left


    def kthSmallest_b(self, matrix: list[list[int]], k: int) -> int:
        n = len(matrix)
        left = matrix[0][0]
        right = matrix[n - 1][n - 1]
        while left < right:
            mid = left + (right - left) // 2
            count = 0
            row = n -1
            col = 0
            while row >= 0 and col < n:
                if matrix[row][col] <= mid:
                    count += row + 1
                    col += 1
                else:
                    row -= 1
            if count < k:
                left = mid + 1
            else: 
                right = mid 
        return left


if __name__ == "__main__":
    print(f"Want : {13}, Was : {Solution().kthSmallest(matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8)}")

    print(f"Want : {-5}, Was : {Solution().kthSmallest(matrix = [[-5]], k = 1)}")