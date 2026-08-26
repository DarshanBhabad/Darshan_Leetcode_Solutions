class Solution {
public:
    int balancedStringSplit(string s) {
int fcnt=0;
int cntl=0;
int cntr=0;
       for(int i=0;i<s.size();i++){
            if(s[i]=='R') cntr++;
            else cntl++;
            if(cntl==cntr) {
                fcnt++;
                cntl=0;
                cntr=0;
            }
        
       }
        return fcnt;
    }
};