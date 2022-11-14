import java.util.Scanner;
public class StringQuestion2 {
    public static void main(String[] args)  
    {  
        Scanner sc= new Scanner(System.in);  //System.in is a standard input stream  
        String str= sc.next();   //reads string before the space  
        // System.out.println(str);   
        
        String[] arr = str.split("[.]");
        
        for (int i = arr.length-1; i>=0; i--) {
            if(i>0)
                System.out.print(arr[i] + ".");
            else
                System.out.println(arr[i]);
        }
    }  
}