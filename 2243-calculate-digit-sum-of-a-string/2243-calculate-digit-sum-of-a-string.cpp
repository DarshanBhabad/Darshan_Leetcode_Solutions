class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        // string temp;
        if(n<=k) return s; //can complete a single round;
// string s="";

        while(s.size()>k){
             int temp=0;
             string p="";
             int cnt=0;
             bool c=true; //to prevent unncessary adding temps 0;
            for(int i=0;i<s.size();i++){
             c=true;
              cnt++;
              temp+=s[i]-'0';
              if(cnt==k){
                cnt=0;
                p+=to_string(temp);
                temp=0;
                c=false;
                

              }
            }
           if(c)   p+=to_string(temp);//remaining last part
            s=p;
        } 

        return s;
    }
};