#include<iostream>
#include<algorithm>
using namespace std;
string AddTwostring(string&num1,string&num2){
    int i=num1.size()-1;
    int j=num2.size()-1;
    int carry=0;
    string ans;
    while(i>=0||j>=0||carry>0){
        int currentsum=0;
        if(i>=0){
            currentsum+=num1[i]-'0';
            i--;
        }
        if(j>=0){
            currentsum+=num2[j]-'0';
            j--;
        }
        currentsum+=carry;
        int lastdigit=currentsum%10;
        int digit=lastdigit+'0';
        ans.push_back(digit);
        carry=currentsum/10;
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    string num1 = "456";
    string num2 = "77";

    cout << AddTwostring(num1, num2) << endl;

    return 0;
}