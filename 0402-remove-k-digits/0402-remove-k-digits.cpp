class Solution {
public:
    string removeKdigits(string num, int k) {
        //we can use the monotonic stack 
        //maintain smaller elemnts in the stack of size k 
       // as from test case you can understand that you have remove elements in sequence only noy random num = "1432219", k = 3  1129 - clould be teh smallest but ans isj 1219 
// we maintain smallest start 
       string ans="";
       int n=num.size();
       int asize=n-k; //size of ans string 
       if(n==k) return "0"; //as all eleemnts are removed 
       stack<int>s;
       int rem=0; //remaining elemnts
       for(int i=0;i<n;i++){
        rem=n-i-1;
          while(!s.empty() && s.top()>num[i]-'0' && s.size()+rem>=asize){
            s.pop(); //pop greater elemnts 
            //s.top()>num[i]-'0'  equal digits no need to remove

          }
          
          s.push(num[i]-'0');
         
       }
    //    //thes ewill sometimes add extra eleemnt  as we use push afterwards  also 
    while (s.size() > asize) {
            s.pop();
        }
    //    if(s.size()>asize) s.pop(); //remove extra
       while(!s.empty()){
        ans+=s.top()+'0'; //convert back to string
        s.pop();

       }
       reverse(ans.begin(),ans.end()); //O(n)

//remove leading zeros 
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i); //return substring starting from i after removing leading 0s

        if (ans.empty()) return "0";

        return ans;
    }
};