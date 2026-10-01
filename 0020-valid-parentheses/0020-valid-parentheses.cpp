class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')' && !st.empty()&& st.top()=='(') {
                st.pop();
                
            }
            else if(s[i]==']'&& !st.empty() && st.top()=='[' ){
                st.pop();
                
            }
            else if(s[i]=='}' && !st.empty() && st.top()=='{'){
                 st.pop();
                

            }
            //else foe (,{,[)
            else
            st.push(s[i]);
        }
        return st.empty();
    }
};