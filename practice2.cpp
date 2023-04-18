#include<iostream>
#include<vector> 
#include<string>
using namespace std;
float getFare(string source, string dest, vector<string> &busStops, vector<int> &distances){
    //we need to go from source to destination
    int srcIndex, destIndex;
    for(int i = 0; i<busStops.size(); i++){
        if(busStops[i] == source)   srcIndex = i;
        if(busStops[i] == dest) destIndex = i;
    }
    cout<<srcIndex<<" "<<destIndex<<endl;
    //now we need to find the fare from src index to dest index 
    //now find the sum from distances[srcIndex] to distances[destIndex]
    int toatalDistanceCovered = 0;
    if(destIndex < srcIndex){
        // find sum from srcIndex to last and 0 to destIndex 
        for(int i = srcIndex; i < distances.size(); i++){
            toatalDistanceCovered += distances[i];
        }
        for(int i = 0; i<destIndex; i++){
            toatalDistanceCovered += distances[i];
        }
    }
    else{
        for(int i = srcIndex; i< destIndex; i++){
            toatalDistanceCovered += distances[i];
        }
    }

    float distInKM = (float)toatalDistanceCovered/1000;

    cout<<distInKM<<endl;
    
    if(toatalDistanceCovered < 1000)    return 8;

    else    return (toatalDistanceCovered/1000)*10;
}
int main()
{   
    int n = 8;
    vector<string> busStops = {"TH", "GA", "IC", "HA", "TE", "LU", "NI", "CA"};
    vector<int> distances = {200, 400, 500, 544, 244, 230, 456, 567};
    string src,dest;
    cin>>src>>dest;
    cout<<getFare(src, dest, busStops, distances)<<endl;
    return 0;
}