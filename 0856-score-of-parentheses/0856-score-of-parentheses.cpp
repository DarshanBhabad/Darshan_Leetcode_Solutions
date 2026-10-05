class Solution {
public:
void gets(string &s,int st,int n,int depth,int & ans){
    //BC
    if(st==n) return;
    if(st == n)
            return;

        if(s[st] == '(') {
            depth++;
        }
        else {
            depth--;

            if(s[st - 1] == '(') {
                ans += pow(2, depth);
            }
        }

        gets(s, st + 1, n, depth, ans);

        return;

}
    int scoreOfParentheses(string s) {
       int ans=0;
    int n=s.size();
    gets(s,0,n,0,ans);
    return ans;
        
    }
};