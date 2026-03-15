// You are tasked with optimizing garbage collection in a city using three specialized garbage trucks:

// M → Metal garbage truck

// P → Paper garbage truck

// G → Glass garbage truck

// The city is represented as a linear sequence of houses.
// Input:
// garbage = ["G","P","GP","GG"]
// travel = [2,4,3]

// Output:
// 21
 
#include<iostream>
#include<vector>
using namespace std;
int GrabgeCollection(vector<string>&garbages,vector<int>travel){
    int pickP=0;
    int pickM=0;
    int pickG=0;
    int lastHouseP=0;
    int lastHouseM=0;
    int lastHouseG=0;
    for(int i=0;i<garbages.size();i++){
        string garbage=garbages[i];
        for(int j=0;j<garbage.size();j++){
            char Gtype=garbage[j];
            if(Gtype=='P'){
                pickP++;
                lastHouseP=i;
            }
            if(Gtype=='M'){
                pickM++;
                lastHouseM=i;
            }
            if(Gtype=='G'){
                pickG++;
                lastHouseG=i;
            }
        }
    }
    int totaltimeP=0;
    int totaltimeM=0;
    int totaltimeG=0;
        for(int i=0;i<lastHouseP;i++){
            totaltimeP+=travel[i];
        }
        for(int i=0;i<lastHouseM;i++){
            totaltimeM+=travel[i];
        }
        for(int i=0;i<lastHouseG;i++){
            totaltimeG+=travel[i];
        }

    int totaltime=((pickP+pickM+pickG)+(totaltimeM+totaltimeP+totaltimeG));
    return totaltime;
    
}
int main() {
    vector<string> garbage = {"G", "P", "GP", "GG"};
    vector<int> travel = {2, 4, 3};

    int result = GrabgeCollection(garbage, travel);
    cout << "Total time required: " << result << endl;

    return 0;
}
