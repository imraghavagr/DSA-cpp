class Practice{
    boolean isSorted(int[] arr, int n){
        if(n == 0 || n == 1)    return true;

        if(arr[0]<arr[1] && isSorted(arr+1, n-1)){
            return true;
        }
        else{
            return false;
        }
    }
    public static void main(String args[]){
        int arr[] = {1,2,3,4,5};
        int n = arr.length;
        if(isSorted(arr,n)){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }
}