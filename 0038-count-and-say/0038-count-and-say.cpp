class Solution {
public:
//O(2^n)
//\(O\left(\sum_{k=1}^{n} L_k\right)\), where \(L_k\) is the length of the \(k\)-th Count and
string gett(string s){
string ans="";
int n=s.size();
for (int i = 0; i < n; ) {
            int cnt = 0;
            char ch = s[i];

            while (i < n && s[i] == ch) {
                cnt++;
                i++;
            }

            ans += to_string(cnt);
            ans += ch;
        }

        return ans;
}
// string cs(int n){
    
// }
    string countAndSay(int n) {
         //BC
    if(n==1) return "1";


    return gett(countAndSay(n-1));// cntand say will provide the 1st attributes to gett when it hits bc n==1  

    }
};