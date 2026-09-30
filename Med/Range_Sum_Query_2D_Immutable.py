class NumMatrix:
    '''
    [Medium Problem]

        Given a 2D matrix, handle multiple quieries of the following type:

        -   Calculate the sum of the elements of matrix inside the rectangle defined by its upper left
            corner (row1, col1) and lower right corner (row2, col2).

        Implement the NumMatrix class:

        -   __init__(self, matrix: list[list[int]]) Initializes the object with the integer matrix.

        -   sumRegion(self, row1: int, col1: int, row2: int, col2: int) Returns the sum of the elements of matrix
            inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

        You must design an algorithm where sumRegion works on O(1) time complexity. 
    
    
    '''


    def __init__(self, matrix: list[list[int]]):
        rows, cols = len(matrix), len(matrix[0])
        self.sumMatrix = [[0] * (cols + 1) for (row) in range(rows + 1)]
        for row in range(rows):
            prefix = 0
            for col in range(cols):
                prefix += matrix[row][col]
                above   = self.sumMatrix[row][col + 1]
                self.sumMatrix[row + 1][col + 1] = prefix + above
    
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        topLeft  = self.sumMatrix[row1][col1]
        top      = self.sumMatrix[row1][col2 + 1]
        left     = self.sumMatrix[row2 + 1][col1]
        botRight = self.sumMatrix[row2 + 1][col2 + 1]
        return botRight - top - left + topLeft


