class Solution {
public:
//TC=O(3^n) //3 choice i.e all stars in input
  bool check(int st,string &s ,int n,int balance,vector<vector<int>>& dp ){

    //BC 
    // Invalid if closing brackets exceed opening brackets
        // if (close > open) return false; //as  tehs eclose wont be closed  tehre is no closeing for ) in future
        //0 false 1 true

         if (balance < 0) return false;

        if (st == n)
            return balance == 0;//open-close

        if (dp[st][balance] != -1)
            return dp[st][balance];

        if (s[st] == '(') {
            return dp[st][balance] =
                check(st + 1, s, n, balance + 1, dp);
        }
        else if (s[st] == ')') {
            return dp[st][balance] =
                check(st + 1, s, n, balance - 1, dp);
        }
        
    //     if(st==n) {
    //         return open==close; 
    //     }
    //     if(dp[st]!=-1) return dp[st];

    //  if (s[st] == '(') {
    //         return dp[st]=check(st + 1, s, n, open + 1, close);
    //     }
    //     else if (s[st] == ')') {
    //         return dp[st]=check(st + 1, s, n, open, close + 1);
    //     }
        else { // '*'

            // // Choice 1: '*' acts as '('
            // if (check(st + 1, s, n, open + 1, close))
            //     return true;

            // // Choice 2: '*' acts as ')'
            // if (check(st + 1, s, n, open, close + 1))
            //     return true;

            // // Choice 3: '*' acts as empty
            // if (check(st + 1, s, n, open, close))
            //     return true;

            // return false;

             // '*' acts as '('
            // '*' acts as ')'
            // '*' acts as empty
            return dp[st][balance] =
                check(st + 1, s, n, balance + 1, dp) || //open increment so +1
                check(st + 1, s, n, balance - 1, dp) || //close dec so open-(close+1)= bal-1
                check(st + 1, s, n, balance, dp);
        }


    

   }
    bool checkValidString(string s) {
        //lets teh do with recursion as * has 3 choices ),( ""
        int n=s.size();
// DP memoization 3 chocies so there aere overlapping subproblems in each chocie 
// two state variables as state depends on 2 variables - st and (open,close ) i.e balance = open-close
// For example, at st = 3, you could have:
// - open = 2, close = 1
// - open = 3, close = 0
vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return check(0,s,n,0,dp);
        
    }
};