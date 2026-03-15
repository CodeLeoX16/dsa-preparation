#include<iostream>
#include<stack>
using namespace std;
bool isValid(string &s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='('||ch=='['||ch=='{'){
            st.push(ch);
        }
        //not opening char
        else{
            //no charecter empty
            if(st.empty())return false;
            else if(ch==')' && st.top()!='('){
                return false;
            }
            else if(ch==']' && st.top()!='['){
                return false;
            }
            else if(ch=='}' && st.top()!='{'){
                return false;
            }else{
                st.pop();//matched
            }

        }
    }
    return st.empty();

}
int main(){
    string s;

    cout << "Enter a string: ";
    cin >> s;

    if(isValid(s))
        cout << "Valid parentheses" << endl;
    else
        cout << "Invalid parentheses" << endl;

    return 0;
}