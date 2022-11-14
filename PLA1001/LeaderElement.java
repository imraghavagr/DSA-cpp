import java.util.Scanner;

class LeaderElement{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        //lets take the array input 
        int arr[] = new int[n];
        int x;
        for(int i = 0; i<n; i++){
            x = sc.nextInt();
            arr[i] = x;
        }
        for(int i = 0; i<n; i++){
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();

        for(int i = 1; i<n-1; i++){
            if(arr[i] < arr[i-1]){
                System.out.print(arr[i-1] + " ");
            }
        }
        System.out.println(arr[n-1]);

    }
}