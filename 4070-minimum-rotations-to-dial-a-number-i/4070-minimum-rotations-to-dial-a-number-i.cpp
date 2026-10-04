class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        //we have to selecte as they are in circular order there are two ways to reach each digit in forward or bacward direction , so either abs(prevpos -digit) or (10-digit )
        //we have to choose 
        int n=s.size();
        //inigtially dia points at 0 so to type first number 
        int first=s[0]-'0'; //to int
        ans=min(first,10-first);//forward,backward
        int temp;
        for(int i=1;i<n;i++){
            int curr=s[i]-'0';
            int prev=s[i-1]-'0';
            temp=abs(curr-prev);
            ans+=min(temp,10-temp);

        }
        return ans;
    }
};