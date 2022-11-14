import java.util.Scanner;

public class SpirtalPrint {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();
        //m -> row, n ->col
        int arr[][] = new int[m][n];
        int x = 1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                arr[i][j] = x++;
            }
        }

        //we will maintain four pointers - sr, er, sc, ec

        int startRow = 0;
        int endRow = m - 1;
        int startCol = 0;
        int endCol = n - 1;
    
        //Outer Loop (Traverse array boundary)
        while(startCol<= endCol && startRow <=endRow){
    
            //Start Row
            for(int col = startCol ; col<=endCol; col++){
                System.out.print(arr[startRow][col] + " ");
            }
    
            //End Col
            for(int row=startRow + 1;row<=endRow;row++){
                System.out.print(arr[row][endCol] + " ");
            }
    
            //End Row
            for(int col=endCol - 1; col>=startCol;col--){
                if(startRow==endRow){
                    //Avoid Duplicate Printing of elements
                    break;
                }
                System.out.print(arr[endRow][col] + " ");
            }   
    
            //Start Col
            for(int row = endRow-1; row >=startRow + 1;row--){
                // Avoid Duplicate Printing of elements
                if(startCol==endCol){
                    break;
                }
                System.out.print(arr[row][startCol] + " ");
            }
    
            //update the variables to point to inner spiral
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        System.out.println();        
    }
}
