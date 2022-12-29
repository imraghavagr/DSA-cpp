    int minStoneSum(vector<int>& piles, int k) {
        long long ans = 0;
        int i = piles.size()-1;
        sort(piles.begin(), piles.end());
        while(k>0){
            //go from i till n-1 and find the i value where piles[i] is max
            for(int j = i+1; j<piles.size(); j++){
                if(piles[j]>piles[i]){
                    i = j;
                }
            }
            piles[i] -= piles[i]/2;
            i--;
            k--;
            
        }
        for(int i = 0; i<piles.size(); i++){
            ans += piles[i];
        }
        return ans;
    }