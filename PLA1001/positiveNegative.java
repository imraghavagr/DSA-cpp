import java.util.Scanner;
public class positiveNegative {
    public static void main(String[] args)  
    {  
        Scanner sc= new Scanner(System.in);  //System.in is a standard input stream  
        
        int n = sc.nextInt();

        int[] arr = new int[n];

        int x;
        for(int i = 0; i<n; i++){
            x = sc.nextInt();
            arr[i] = x;

        }

        //lets make two separate arrays - one consisting of positives and another of negatives
        for(int i = 0; i<n; i++){
            if(arr[i] >= 0){
                //positive
            }
        }
        

    

    }  
}
