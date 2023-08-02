/*
Given N, find the sum of the proper divisors of all nums from 1 till N
*/
#include<iostream>
using namespace std;
//TC -> N*sqrt(N) and SC -> O(1)
long long solve(int N){
    long long int ans = 1; 
    //first lets find prime factorisation of N 
    for(int i = 2; i <= sqrt(N); i++){
        if(N % i == 0){
            //i is one of the prime factors 
            int sum = 1;
            int p = 1;
            while(N % i == 0){
                N = N / i; 
                sum += pow(i,p);
                p++;
            }
            ans = ans * sum;
        }
    }
    if(N != 1){
        ans = (ans * (1+N));
    }
    return ans;
}
long long sumOfDivisors(int N)
{   
    long long ans = 0; 
    for(int i = 1; i<=N; i++){
        ans += solve(i);
    }
    return ans;
}

//another approach using prime sieve -> NloglogN + NlogN |  Space-> O(N)
// NloglogN
void primeSeive(int *p, vector<int> &primes){
    for(int i = 3; i<=1000000; i+=2)    p[i] = 1;
    for(long long i = 3; i*i<=1000000; i+=2){
        if(p[i]){
            for(long long j = i*i; j<=1000000; j+=i)    p[j] = 0;
        }
    }
    p[0] = p[1] = 0;
    p[2] = 1;
    primes.push_back(2);
    for(int i = 3; i<=1000000; i+=2){
        if(p[i])    primes.push_back(i);
    }
}
//O(logN)
long long solve(int N, vector<int> &primes){
    long long int ans = 1; 
    int i = 0; 
    //first lets find prime factorisation of N 
    while(primes[i] <= sqrt(N)){
        if(N % primes[i] == 0){
            //i is one of the  factors 
            int sum = 1;
            int p = 1;
            while(N % primes[i] == 0){
                N = N / primes[i]; 
                sum += pow(primes[i],p);
                p++;
            }
            ans = ans * sum;
        }
        i++;
    }
    if(N != 1){
        ans = (ans * (1+N));
    }
    return ans;
}
long long sumOfDivisors(int N)
{   
    //first lets find all prime numbers upto 1e6
    int p[1000001] = {0};
    vector<int> primes;
    primeSeive(p,primes);
    
    long long ans = 0; 
    for(int i = 1; i<=N; i++){
        ans += solve(i, primes);
    }
    return ans;
}

//Optimal Approach -> O(N) time, O(1) space
int main()
{
    return 0;
}