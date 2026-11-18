class Solution {
public:
    int minChanges(string s) {
        
        // int n=s.size();
        // int mid=(n-1)/2; //st + e-st/2 st=0
        // int i=0;
        // int j=mid+1;
        // int c=0;
        // while(i<=mid && j<=n-1){
        //     if(s[i]!=s[j])c++;
        //     i++;
        //     j++;
        // }
int n=s.size();
int c=0;
//minimumm substring size ha sto be 2; even length 
for(int i=1;i<n;i+=2){
    if(s[i]!=s[i-1]) c++;
}
        return c;
    }
};