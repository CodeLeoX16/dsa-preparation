#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void letterrComHelp(unordered_map<int,string>&map,vector<int>&arr,string&output,vector<string>&ans,int i){
    if(i==arr.size()){
        ans.push_back(output);
        return;
    }
    int num=arr[i];
    if(map.find(num)==map.end()){
        letterrComHelp(map,arr,output,ans,i+1);
        return;
    }
    string mapedstring=map[num];
    for(int j=0;j<mapedstring.size();j++){
        char c=mapedstring[j];
        output.push_back(c);
        letterrComHelp(map,arr,output,ans,i+1);
        output.pop_back();
    }

}

vector<string>letterCombi(vector<int>arr){
if(arr.size()==0)return{};
        unordered_map<int,string>map;
        
        map[2]="abc";
        map[3]="def";
        map[4]="ghi";
        map[5]="jkl";
        map[6]="mno";
        map[7]="pqrs";
        map[8]="tuv";
        map[9]="wxyz";
        string output="";
        vector<string>ans;
        letterrComHelp(map,arr,output,ans,0);
        return ans;
        
}
int main() {
    vector<int> arr = {2, 3};
    vector<string> result = letterCombi(arr);

    for (auto &s : result) {
        cout << s << " ";
    }
    return 0;
}        