import java.util.Scanner;

class SurpriseTestQ1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 1; i<=n; i++){
            //for each row, num of cols <= row num
            //print 1 and 0 alternatively
            for(int j = 1; j<=i; j++){
                if(j % 2 != 0){
                    System.out.print(1 + " ");
                }
                else{
                    System.out.print(0 + " ");
                }
            }
            System.out.println();
        }
    }
}