import java.util.Scanner;
public class StringQuestion {
    public static void main(String[] args)  
    {  
        Scanner sc= new Scanner(System.in);  //System.in is a standard input stream  
        String str= sc.next();   //reads string before the space  
        // System.out.println(str);   
        
        String[] arr = str.split("-");
        int numHyphens = arr.length-1;
        for(int i = 0; i<numHyphens; i++){
            System.out.print("- ");
        }
        
        for (String ch: arr) {
            System.out.print(ch+" ");
        }
        System.out.println();

    }  
}
