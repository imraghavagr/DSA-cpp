import java.util.Scanner;
public class ArraySpecialPoduct {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[n];

        int x;        
        for(int i = 0; i<n; i++){
            x = sc.nextInt();
            arr[i] = x;
        }

        //lets find the product of all elements of the array
        int product = 1;
        for(int i = 0; i<n; i++){
            product = product*arr[i];
        }

        //print the special product array
        for(int i = 0; i<n; i++){
            
            arr[i] = product/arr[i];
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
