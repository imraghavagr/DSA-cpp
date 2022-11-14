/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
// 		System.out.println("Hello World");
        //print yes if sum of odd digits and sum of even digits is same. 
        
        int a = 312;
        int oddSum = 0;
        int evenSum = 0;
        while(a>0){
            int temp = a%10;
            if(temp%2 != 0){
                //oddSum
                oddSum = oddSum + temp;
            }
            else{
                evenSum = evenSum + temp;
            }
            a = a/10;
        }
        if(evenSum == oddSum){
            System.out.println("yes");
        }
        else{
            System.out.println("No");
        }
        
	}
}
