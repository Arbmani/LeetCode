/**
 * In MATLAB, there is a handy function called reshape which can reshape an m x n 
 * matrix into a new one with a different size r x c keeping its original data.
 * 
 * You are given an m x n matrix mat and two integers r and c representing the 
 * number of rows and the number of columns of the wanted reshaped matrix.
 * 
 * The reshaped matrix should be filled with all the elements of the original 
 * matrix in the same row-traversing order as they were.
 * 
 * If the reshape operation with given parameters is possible and legal, 
 * output the new reshaped matrix; Otherwise, output the original matrix.
 * 
 */

class SolutionmatrixReshape {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int rows = mat.length;
        int cols = mat[0].length;
        if (rows * cols != r * c) return mat;
        int [][] ans = new int[r][c];
        for (int i = 0; i < rows * cols; i++){
            int oldRow = i / cols;
            int oldCol = i % cols;

            int newRow = i / c;
            int newCol = i % c;

            ans[newRow][newCol] = mat[oldRow][oldCol];
        }
        return ans;
    }
}


public class Reshape_the_Matrix {
    public static void main(String[] args){
        SolutionmatrixReshape s = new SolutionmatrixReshape();

        int [][] mat1 = {{1, 2}, {3, 4}};
        int [][] mat2 = {{1, 2}, {3, 4}};


        System.out.println("\nWant : [[1,2,3,4]]\nWas  : " + java.util.Arrays.deepToString(s.matrixReshape(mat1, 1, 4)));
        System.out.println("\nWant : [[1,2],[3,4]]\nWas  : " + java.util.Arrays.deepToString(s.matrixReshape(mat2, 2, 4)));

    }

}