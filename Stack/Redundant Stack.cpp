#include <bits/stdc++.h> 
#include <stack>


bool isredundant(stack <char> &st){
    bool redundant=true;
    while(st.top()!='('){
        if(st.top()!='('){

            redundant=false;
        }
        st.pop();
    }
    st.pop();
    return redundant ;    
    
    
}


bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack <char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*'){
           st.push(s[i]);
        }
        else{
            if(s[i]==')'){
                if(isredundant(st)){
                   return true;
                };
            }
            
        }
    }
    return false;
}
