class Solution {
public:
void generate(int open , int close, int n, string s,vector<string>& ans){
    //BC
       if(s.size()==2*n){
            ans.push_back(s);
            return;
       }
       //add open bracket (
       if(open<n) generate(open+1,close,n,s+'(',ans);
       if(close<open) generate(open,close+1,n,s+')',ans);

       return;
}
    vector<string> generateParenthesis(int n) {
        //recursive approach
        // The recursion does not generate every possible string and then check it. It prevents invalid strings from being generated in the first place using close < open.
        //at each step we jhave option either we close or open 
        // we can intoduce open only when <n ansd close only when close<open 
        // if close> current open then will give invalid string
        vector<string>ans;
        generate(0,0,n,"",ans);
        return ans;
    }
};