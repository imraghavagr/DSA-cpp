#include<iostream>
using namespace std;
bool isPossible(int mid, int cartidges, int dollars, int recycleRewards, int perksCost){
	int reqDollars = mid*perksCost;
	if(reqDollars == dollars)	return true;
	else{
		int dollarsFromRecycle = (cartidges-mid)*recycleRewards;
		if(dollars+dollarsFromRecycle >= reqDollars){
			return true;
		}
		else{
			return false;
		}
	}
}
int maxPerksItems(int cartidges, int dollars, int recycleRewards, int perksCost){
	int s = 0;
	int e = cartidges;
	int ans = 0;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(isPossible(mid, cartidges,dollars,recycleRewards,perksCost)){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}
int main()
{	
	int cartidges, dollars, recycleRewards,perksCost;
	cin>>cartidges>>dollars>>recycleRewards>>perksCost;
	cout<<maxPerksItems(cartidges,dollars,recycleRewards,perksCost)<<endl;
	return 0;
}