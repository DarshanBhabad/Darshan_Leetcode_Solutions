class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        stack<int>st;
        int cnt=0;
        int tcnt=0;
        for(int i=0;i<n;i++){
              if(s[i]=='('){
                st.push(s[i]);
                if(tcnt>=1) tcnt--; //they are at same level so reset likein ex 3
              }
              else if(s[i]==')'){
                   
                st.pop();
                tcnt++;
                if(st.empty()) {
                    cnt=max(cnt,tcnt);
                    tcnt=0;
                }

              }
        }
        return cnt;
    }
};