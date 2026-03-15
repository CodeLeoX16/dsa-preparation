#include<iostream>
#include<vector>

using namespace std;
string Zigzag(string &s,int numRows){
    vector<string>rows(numRows);
    int row=0;
    int step=1;//1-UP or -1 Down
    for(char c:s){
        rows[row]+=c;
        if(row==0)step=1;
        if(row==numRows-1) step=-1;
        row+=step;

    }
    string ans="";
    for(auto it:rows){
        ans+=it;
    }
    return ans;
    
}
int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;

    string result = Zigzag(s, numRows);
    cout << result << endl;   // Output: PAHNAPLSIIGYIR

}