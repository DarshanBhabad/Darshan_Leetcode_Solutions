class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        //tc = O(O(n + K))  // siz of stroing and size of knowledge ans also find takes O(1);
        for(auto &k:knowledge){
            m[k[0]]=k[1];
        }
int n=s.size();
string ans="";
string temp="";

        for(int i=0;i<n;i++){
            

            if(s[i]=='('){
                i++;
                temp="";
                while(s[i]!=')'){
                    
                   temp.push_back(s[i]);
                   i++;
                }
                if(m.find(temp)==m.end()) ans.push_back('?');
                else ans+=(m[temp]); //push_back only for charcters and += string also get pushed
            }
            else{
                ans.push_back(s[i]);
            }
        }

        
return ans;
        
    }
};