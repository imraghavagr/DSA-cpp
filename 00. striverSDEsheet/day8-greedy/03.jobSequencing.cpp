//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
#include<iostream>
using namespace std;
bool  static  compare(Job  a,  Job b){
    return a.profit>b.profit;
}
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    vector<int>  ans;
    int  maxProfit  =  0;
    int  numJobs  =  0;
    //find the maximum deadline 
    int maxDeadline =  INT_MIN;
    for(int i  =  0; i<n; i++){
        maxDeadline =  max(maxDeadline,  arr[i].dead);
    }
    //now  sort  the  jobs  array in desceding  order  of  profit 
    sort(arr,  arr+n, compare);
    //now lets  make  the  days  array  
    vector<int> days(maxDeadline+1, -1);  //initially  all  days  are  available  
    
    //now  iterate through  the jobs  and try  to  perform  them  on  the  last  possible  day
    for(int i =  0;  i<n; i++){
        int j = arr[i].dead;
        //now find the last  possible day less than  or equal  to  deadline
        while(j>=1 && days[j]  != -1){
            j--;
        }
        
        //we could not  find a  plausible  day, then this  job  can  not be performed
        if(j==0) continue;
        
        //once we found the  last possible day, perform the activity  at that day 
        days[j]  = arr[i].id;
        maxProfit += arr[i].profit;
        numJobs++;
    }
    ans.push_back(numJobs);
    ans.push_back(maxProfit);
    return ans;
} 
int main()
{
    return 0;
}