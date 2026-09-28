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
                if(tcnt>=1) tcnt--; //they are at same level so count only onr of them so we reduce tcnt each time to amintain it to one //so alredy counted of same lvel will  be removed/reduced and only current one will be holded /added
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