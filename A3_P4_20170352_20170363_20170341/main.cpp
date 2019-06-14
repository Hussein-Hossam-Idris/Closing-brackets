#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool commented = false;
bool Apair(char Top,char index,char index2){
    if(Top == '(' && index == ')') return true;
    else if(Top == '[' && index == ']') return true;
    else if(Top == '{' && index == '}') return true;
}

bool balanced(stack<char> st,string s){

    for(int i = 0 ; i < s.size();i++){
        if(s[i] == '/' && s[i+1] == '*'){
            commented = true;
            i=i+2;
        }
        if(s[i] == '*' && s[i+1] == '/'){
            commented = false;
            i=i+2;

        }
        if(commented==false){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
           }else{
            if(st.empty() || (!Apair(st.top(),s[i],s[i+1]))){
                cout<<"not Valid"<<endl;
                return false;
            }
            else{
                st.pop();
            }

        }
    }
    }

    if(commented == true){
            cout<<"not Valid"<<endl;
            return false;
    }
    else if(st.empty()){
            return true;
        }else{
            return false;
        }

}
int main()
{
    stack<char> st;
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    if(balanced(st,s)){
        cout<<"Valid!"<<endl;
    }

}
