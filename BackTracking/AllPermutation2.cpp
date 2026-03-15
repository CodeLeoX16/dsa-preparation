#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void AllPermutationHelper(vector<int>&arr,int st,vector<vector<int>>&ans){
    if(st>=arr.size()){
        ans.push_back(arr);
        return;
    }
    unordered_map<int,bool>visited;
    for(int i=st;i<arr.size();i++){
        if(visited.find(arr[i])!=visited.end()){
            continue;
        }

        visited[arr[i]]=true;
        swap(arr[i],arr[st]);
        AllPermutationHelper(arr,st+1,ans);
        swap(arr[i],arr[st]);
        
    }
}
vector<vector<int>>Allpermutation(vector<int>&arr){
    
    vector<vector<int>>ans;
    AllPermutationHelper(arr,0,ans);
    return ans;
    
}
int main(){
    vector<int>arr={1,2,3};
    vector<vector<int>>ans=Allpermutation(arr);
    for(auto it:ans){
        for(auto n:it){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    
    
}