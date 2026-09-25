class Solution {
public:

bool checkfrog(int k,int st,vector<int>& stones,int &last,set<int>& s,  map<pair<int,int>, bool>&dp){
    //TC = TC = O(N² log N)  .. N2 states (st,k) and find function of map logn2 =logn
    // in the worst case, each of the N stones could have up to N different possible jump sizes. i.e k=N2
    //sc memoization max n2 states so O(n2)
    //bc
    if(k<=0) return false ; //jump not possible // jump can be -ve
    if(st+k==last) return true;// reached last stone
    if(s.find(st+k)==s.end()) return false; // no stone at this position
     // already calculated this state
        if(dp.find({st, k}) != dp.end())
            return dp[{st, k}];
    // 3 choices  k-1,k+1,k
  return dp[{st,k}]=(checkfrog(k-1,st+k,stones,last,s,dp)||
checkfrog(k,st+k,stones,last,s,dp)||
checkfrog(k+1,st+k,stones,last,s,dp))  ;  // if anyone of thes ereturn true then we also return true;




}
    bool canCross(vector<int>& stones) {
        //as from recursive we can see that we can calculate the big problem from subproblems and also it has overlapping subproblemms at sing call from 1 position 3 options so most  the calls from that 3 verlapps  so lets use memoization in current recursion
        

        // DP by stroing the which particular st,k has alredy been circulated and calculated

         if(stones[0]!=0 || stones[1]!=1) return false; 
        // 1st jump should be of unit of and also initially frong is  on 1st stone i.e zero 

        int n=stones.size(); //last stone sposition 
     set<int>s;
     for(int i=0;i<n;i++){
        s.insert(stones[i]);
     }
     //using memoization
     // we store if frome current stones i we can get ans;

     map<pair<int,int>, bool> dp; // map dp
        return checkfrog(1,0,stones,stones[n-1],s,dp);
        
    }
};

//RECURSIVE SOLUTION BUILT BY ME BUT TLE ERROR 
// class Solution {
// public:

// bool checkfrog(int k,int st,vector<int>& stones,int &last,set<int>& s){
    
//     //bc
//     if(k<=0) return false ; //jump not possible // jump can be -ve
//     if(st+k==last) return true;// reached last stone
//     if(s.find(st+k)==s.end()) return false; // no stone at this position
//     // 3 choices  k-1,k+1,k
//   return (checkfrog(k-1,st+k,stones,last,s)||
// checkfrog(k,st+k,stones,last,s)||
// checkfrog(k+1,st+k,stones,last,s))  ;  // if anyone of thes ereturn true then we also return true;




// }
//     bool canCross(vector<int>& stones) {
//         if(stones[0]!=0 || stones[1]!=1) return false; 
//         // 1st jump should be of unit of and also initially frong is  on 1st stone i.e zero 

//         int n=stones.size(); //last stone sposition 
//      set<int>s;
//      for(int i=0;i<n;i++){
//         s.insert(stones[i]);
//      }
//         return checkfrog(1,0,stones,stones[n-1],s);
//     }
// };