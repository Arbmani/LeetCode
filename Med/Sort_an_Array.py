import random
class Solution:
    '''
    [Medium Problem]

    Given an array of integers nums, sort the array in ascending order and return it.

    You must solve the problem without using any built-in function in O(nlog(n)) time complexity
    and with the smallest space complexity possible.
    
    '''
    def insertionSort(self, nums: list[int]) -> list[int]:
        '''

            1.  Insertion Sort Algorithm

        '''

        for i in range(1, len(nums)):
            num = nums[i]
            j   = i - 1
            while j >= 0 and nums[j] > num:
                nums[j + 1] = nums[j]
                j           -= 1  
            nums[j + 1] = num 
        return nums

    def merge(self, nums: list[int], left: int, mid: int, right: int) -> None:
        '''

            2.  Merge Sort Algorithm

        '''
        left_nums, right_nums = nums[left: mid + 1], nums[mid + 1: right + 1]
        i = left 
        j = k = 0
        while j < len(left_nums) and k < len(right_nums):
            if left_nums[j] <= right_nums[k]:
                nums[i] = left_nums[j]
                j       +=1 
            else: 
                nums[i] = right_nums[k]
                k       += 1
            i += 1
        while(j < len(left_nums)):
            nums[i] = left_nums[j]
            j += 1
            i += 1
        while(k < len(right_nums)):
            nums[i] = right_nums[k]
            k += 1
            i += 1


    def mergeSort(self, nums: list[int], left: int, right: int) -> None:
        '''

            2.  Merge Sort Algorithm
            
        '''
        if left >= right: return
        mid = left + (right - left) // 2
        self.mergeSort(nums, left, mid)
        self.mergeSort(nums, mid + 1, right)
        self.merge(nums, left, mid, right)
        return nums


    def quickSort(self, nums: list[int], left: int, right: int) -> None:
        '''

            3.  Quick Sort Algorithm

        '''
        if left >= right: return 
        pivot = nums[random.randint(left, right)]
        i = left
        j = right 
        while i <= j:
            while nums[i] < pivot:
                i += 1
            while nums[j] > pivot:
                j -= 1

            if i <= j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        if left < j:
            self.quickSort(nums, left, j)
        if i < right:
            self.quickSort(nums, i, right)

    def heapify(self, nums: list[int], n: int, i: int) -> None:
        '''

            3.  Heap Sort Algorithm

        '''
        largest = i 
        left    = 2 * i + 1
        right   = 2 * i + 2

        if left < n and nums[left] > nums[largest]:
            largest = left 
        if right < n and nums[right] > nums[largest]:
            largest = right 
        if largest != i:
            nums[i], nums[largest] = nums[largest], nums[i]
            self.heapify(nums, n, largest)
    
    def heapSort(self, nums: list[int]) -> None:
        '''

            3.  Heap Sort Algorithm

        '''
        n = len(nums)
        for i in range(n // 2 -1, -1, -1):
            self.heapify(nums, n, i)
        for i in range(n - 1, 0, -1):
            nums[0], nums[i] = nums[i], nums[0]
            self.heapify(nums, i, 0)

    # Intro Sort
    THRESHOLD = 16
    def insertionSort(self, nums: list[int], left: int, right: int) -> None:
        for i in range(left + 1, right + 1):
            num = nums[i]
            j   = i -1
            while j >= left and nums[j] > num:
                nums[j + 1] = nums[j]
                j          -= 1
            nums[j + 1] = num
    def heapify(self, nums: list[int], start: int, heap_size:int, root: int) -> None:
        while True:
            largest = root 
            left    = 2 * root + 1
            right   = 2 * root + 2
            if (left < heap_size and nums[start + left] > nums[start + largest]):
                largest = left 
            if (right < heap_size and nums[start + right] > nums[start + largest]):
                largest = right 
            if largest == root:
                break 
            nums[start + root], nums[start + largest] = nums[start + largest], nums[start + root]
            root = largest
    def heapSortRange(self, nums: list[int], left: int, right: int) -> None:
        heap_size = right - left + 1
        for i in range(heap_size // 2 - 1, -1, -1):
            self.heapify(nums, left, heap_size, i)
        for i in range(heap_size - 1, 0, -1):
            nums[left], nums[left + i] = nums[left + i], nums[left]
            self.heapify(nums, left, i, 0)
    def medianOfThree(self, nums: list[int], left: int, right: int) -> int:
        mid = left + (right - left) // 2
        a = nums[left]
        b = nums[mid]
        c = nums[right]

        if a < b:
            if b < c:
                return b
            return c if a < c else a
        else:
            if a < c:
                return a
            return c if b < c else b 
    def partition(self, nums: list[int], left: int, right: int) -> tuple[int, int]:
        pivot = self.medianOfThree(nums, left, right)
        i = left 
        j = right 
        while i <= j:
            while nums[i] < pivot:
                i += 1 
            while nums[j] > pivot:
                j -= 1
            if i <= j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        return j, i 
    def introSort(self, nums: list[int], left: int, right:int, max_depth: int) -> None:
        while left < right:
            if right - left + 1 <= self.THRESHOLD:
                self.insertionSort(nums, left, right)
                return
            if max_depth == 0:
                self.heapSortRange(nums, left, right)
                return
            max_depth -=1 
            j, i = self.partition(nums, left, right)
            if j - left < right - i:
                if left < j:
                    self.introSort(nums, left, j, max_depth)
                left = i 
            else: 
                if i < right:
                    self.introSort(nums, i, right, max_depth)
                right = j



    def sortArray(self, nums: list[int]) -> list[int]:
        #nums = self.insertionSort(nums)
        #self.mergeSort(nums, 0, len(nums) - 1)
        #self.quickSort(nums, 0, len(nums) - 1)
        #self.heapSort(nums)
        self.introSort(nums, 0, len(nums) - 1, 2 * (len(nums).bit_length() - 1))
        return nums


if __name__ == "__main__":
    print(f"Want : {[1,2,3,5]}, Was : {Solution().sortArray(nums = [5,2,3,1])}")

    print(f"Want : {[0,0,1,1,2,5]}, Was : {Solution().sortArray(nums = [5,1,1,2,0,0])}")