#include<iostream>
#include<vector>
using namespace std;
vector<int> findPrimes(int n){
    vector<int> arr(1000, 0);
    
    //mark all odd numbers as potential primes 
    for(int i = 3; i<=1000; i+=2){
        arr[i] = 1;
    }
    //now mark all multiples of prime as non prime 
    for(long long i = 3; i*i<=1000; i+=2){
        //if the current number is non prime .. mark all its multiples as prime
        if(arr[i]){
            for(long long j = i*i; j*j<=1000; j+=i){
                arr[j] = 0;
            }
        }        
    }
    //special cases 
    arr[0] = arr[1] = 0;
    arr[2] = 1;
    
    vector<int> ans;
    for(int i = 0; i<=n; i++){
        if(arr[i]){
            // cout<<i<<" ";
            ans.push_back(i);
        }
    }
    // cout<<endl;
    return ans;
}
int main()
{   
    int n;
    cin>>n;
    //first find the array of all prime numbers till N using prime sieve
    vector<int> primes = findPrimes(n);
    int i = 0; 
    int p = primes[i]; // our first prime is at index 0
    vector<pair<int,int>> primeFactors;
    while(p*p <= n){
        int cnt = 0;
        while(n%p == 0){
            n = n/p;
            cnt++;
        }
        primeFactors.push_back({p,cnt});
        i++;
        p = primes[i];
    }
    if(n != 1){
        //this means that number n is itself a factor now 
        primeFactors.push_back({n,1});
    }
    
    int sum = 0;

    for(auto it : primeFactors){
        cout<<it.first<<" "<<it.second<<endl;
        sum += it.first;
    }
    cout<<sum<<endl;
    
    return 0;
}