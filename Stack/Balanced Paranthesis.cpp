class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]);
                continue;
            }
            else{
                if(st.empty()) return false;
                if(st.top()== '('  &&  s[i]==')'){
                    st.pop();
                    continue;
                }

                if(st.top()== '['  &&  s[i]==']'){
                    st.pop();
                    continue;
                }

                if(st.top()== '{'  &&  s[i]=='}'){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};