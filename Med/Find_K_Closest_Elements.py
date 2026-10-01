class Solution:
    '''
    [Medium Problem]

        Given a sorted integer array "arr", two integers "k" and "x", return the "k" closest integers to "x" in the array.
        The result should also be sorted in ascending order.

        An integer "a" is closer to "x" than na integer "b" if:

        -   |a - x| < |b - x|, or

        -   |a - x| == |b - x| and a < b

        (a = -5) x = 0, b = 5 abs(-5) !< abs(5)
        but case 2 holdes now 
    
    '''


    def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
        left, right = 0, len(arr) - k 
        while left < right:
            mid = left + (right - left) // 2
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid 


        return arr[left: left + k]


if __name__ == "__main__":
    print(f"Want : {[1,2,3,4]}, Was : {Solution().findClosestElements(arr = [1,2,3,4,5], k = 4, x = 3)}")

    print(f"Want : {[1,1,2,3]}, Was : {Solution().findClosestElements(arr = [1,1,2,3,4,5], k = 4, x = -1)}")