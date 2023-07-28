#include<iostream>
using namespace std;
//Brute force -> O(k*n) time and O(n) space
double minmaxGasDist(vector<int>& stations, int k) {
    int n = stations.size();
    vector<int> howMany(n-1, 0);
    //place k gas stations at their correct place
    for(int gas = 0; gas<k; gas++){
        double maxSectionLen = 0.0;
        int maxIndx = -1;
        for(int i = 0; i<n-1; i++){
            double sectionLen = (stations[i+1] - stations[i]) / ((double)howMany[i] + 1);
            if(sectionLen > maxSectionLen){
                maxSectionLen = sectionLen;
                maxIndx = i;
            }
        }
        howMany[maxIndx]++; 
    }
    //now find the maxDistance
    double maxSectionLen = 0.0;
    for(int i = 0; i<n-1; i++){
        double sectionLen = (stations[i+1] - stations[i]) / ((double)howMany[i] + 1);
        if(sectionLen > maxSectionLen){
            maxSectionLen = sectionLen;
        }
    }
    return maxSectionLen;
}
//k*logn
double minmaxGasDist(vector<int>& stations, int k) {
    int n = stations.size();
    vector<int> howMany(n-1, 0);

    priority_queue<pair<double,int>, vector<pair<double,int>>> pq; 

    for(int i = 0; i<n-1; i++){
        pq.push({stations[i+1] - stations[i], i});
    }

    //place k gas stations at their correct place
    for(int gas = 0; gas<k; gas++){
        auto it = pq.top(); pq.pop();
        int idx = it.second;
        howMany[idx] += 1;
        double sectionLen = (stations[idx+1] - stations[idx]) / ((double)howMany[idx] + 1);
        pq.push({sectionLen, idx});
    }
    return pq.top().first;
}
int main()
{
    return 0;
}