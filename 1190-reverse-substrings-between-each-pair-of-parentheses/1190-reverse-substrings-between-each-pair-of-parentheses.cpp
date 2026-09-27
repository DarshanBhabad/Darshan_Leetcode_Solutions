class Solution {
public:
    string reverseParentheses(string s) {
        // int n=s.size();
        // string ans="";
        // string p="";
        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         i++;
        //         p="";
        //         while(s[i]!=')'){
        //             p.push_back(s[i]);
        //             i++;
        //         }
        //         reverse(p.begin(),p.end());
        //         ans+=p;
        //     }
        //     else{
        //         ans.push_back(s[i]);
        //     }
        // }
        // return ans;

        //STACK  tc=O(n) sc=O(n)
        int n=s.size();
        stack<char>st;
        string ans="";
        string p;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                p="";
                while(st.top()!='(')
                {
                   p.push_back(st.top());
                    st.pop();
                }
                //now p is in reverse order so put it again in stack 
                st.pop(); //remove the (
                for(auto c:p){
                    st.push(c);
                }


                
            }
            else
            st.push(s[i]);
        }
        // get final answer
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};