class Solution {
public:
    int maximumLengthSubstring(string s) {
int n=s.size();
        //sliding window just k=2
        int i=0;
        int maxl=0;
    

    // here you have to just make sure the count of charcters presnt in the current substring in less than 2 and not alll unique chars in complete s;
    vector<int>a(26,0);
        for(int j=0;j<n;j++){
            a[s[j]-'a']++;

            while(a[s[j]-'a']>2){ // until count of s[j] in curre window becomes less than 2
            a[s[i]-'a']--;
            i++; 
        
            }

           
         
          maxl=max(j-i+1,maxl);

        }
        return maxl;
    }
};