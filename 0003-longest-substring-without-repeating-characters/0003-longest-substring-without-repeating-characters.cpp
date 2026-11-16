class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window 
        int n=s.size();
        int i=0;
      set<char>p;
      //sliding window
     // tc = nlogc  c= no of distinct charcters find function of set for each distinct charcter   // set only will have disticnt chatcters and its func tc is logn here it will be c
      int ans=0;
        for(int j=0;j<n;j++){


               while(p.find(s[j])!=p.end()){ //elelemts are present // till the current elemnt is present in the window pop the elemnts from the set 
                p.erase(s[i]);
                i++;
            }
         

          
          p.insert(s[j]);

            ans=max(ans,j-i+1);
        }
    
        return ans;
    }
};