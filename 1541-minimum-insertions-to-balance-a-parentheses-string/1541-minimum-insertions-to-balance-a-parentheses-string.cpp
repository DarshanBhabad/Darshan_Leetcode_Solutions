class Solution {
public:
    int minInsertions(string s) {
     //O(n) and O(1)
     int n = s.size();
        int open = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;  // keep count of open
            }
            else {
                // We need two closing brackets(consecutive) for every opening bracket
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // consume the second ')'
                }
                else {
                    ans++; // insert the missing ')' if we dont have consecutive //track of close 
                }

                if (open > 0) {  // ex )) we have open =0 can cause -ve so check open >0
                    open--; // satisfiied for one open 
                }
                else {
                    ans++; // insert a missing '('  ex ))  needs one (
                }
            }
        }

        return ans + 2 * open;  // rem open should be close by 2 opens 
        
    }
};