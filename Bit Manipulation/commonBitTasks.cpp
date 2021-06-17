#include<iostream>
using namespace std;

bool isOdd(int n){
	//will return 1 for odd, 0 for even
	return (n&1);

}
int getBit(int n, int i){
	//extracting ith bit of a binary representation of a number n
	//from the right side
	// for n = 5 => 000101
	//2nd bit from right of 5 will be 0 
	//we can create a mask
	int mask = (1<<i);
	int x  = (n&mask);
	if(x==0){
		return 0;
	}
	else{
		return 1;
	}
}
int setBit(int &n, int i){
	int mask = (1<<i);
	int ans = n|mask;
	return ans;
}
void clearBit(int &n, int i){
	int mask = ~(1<<i);
	n = n&mask;
}
void updateBit(int &n, int i, int v){
	
	//step 1 : clearing the ith bit
	int m1 = ~(1<<i);
	int cleared_bit_no = n&m1;

	//step 2: cleared_bit_no | mask m2
	int m2 = v<<i;
	n = (cleared_bit_no|m2);
}
int clearLastBits(int n, int i){

	//~0,-1 will give us all ones
	int mask = ((~0)<<i);
	//or mask = -1 << i
	return (n&mask);


}
int clearRangeOfBits(int n, int i, int j){

		int a  = (~0) << (j+1);
		int b = (1<<i) - 1;
		int mask = a|b;
		int ans = n&mask;
		return ans;
}

int main(){

	int n =5; 
	int i = 2;
	
	cout<<isOdd(n)<<endl;
	cout<<getBit(n,i)<<endl;
	cout<<setBit(n,i)<<endl;
	clearBit(n,i);
	cout<<n<<endl;
	
	int m = 5;
	updateBit(m,2,0);
	updateBit(m,3,1);
	cout<<m<<endl;

	//clearing last 3 bits from position 2 to 0
	cout<<clearLastBits(15,2)<<endl;
	cout<<clearRangeOfBits(31,1,3)<<endl;
	return 0;
}
