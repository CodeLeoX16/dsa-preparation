#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int convert(string & time){
    int hr=stoi(time.substr(0,2));
    int min=stoi(time.substr(3,2));
    return hr*60+min;
}
int minimum_timediff(vector<string>timepoints){
    vector<int>mins;
    int mindiff=INT_MAX;
    for(int i=0;i<timepoints.size();i++){
        mins.push_back(convert(timepoints[i]));
    }
     sort(mins.begin(),mins.end());
     for(int i=1;i<timepoints.size();i++){
        mindiff=min(mindiff,(mins[i]-mins[i-1]));
     }
    int lastdiff=1440-(mins[mins.size()-1]-mins[0]);
    mindiff=min(mindiff,lastdiff);
     
    return mindiff;
}
int main() {
    int n;
    cin >> n;                       // number of time points

    vector<string> timepoints(n);
    for(int i = 0; i < n; i++){
        cin >> timepoints[i];       // HH:MM format
    }

    cout << minimum_timediff(timepoints);
    return 0;
}

// 3
// 23:59
// 00:00
// 12:30
