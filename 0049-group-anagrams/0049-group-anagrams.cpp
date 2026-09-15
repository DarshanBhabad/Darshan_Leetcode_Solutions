class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //TC = O(N × (K + 26 log N)) // long n- find in  maps  // Creating frequency vector: O(K) k=size of str
  // SC= O(N × 26 + total characters) = N* 26 for each str 26 lingth v and total charsc
int n=strs.size();
vector<vector<string>>ans;
    map<vector<int>,int>m; //By default, the C++ Standard Template Library (STL) does not provide a built-in hash function for std::vector  so only map used here
    int cnt=0;
        for(auto s:strs){
            vector<int>v(26,0);
            for(int i=0;i<s.size();i++){
                v[s[i]-'a']++;
            }

            if(m.find(v)!=m.end()) ans[m[v]].push_back(s); // acceess already created grp
            else {
                m[v]=cnt;
                ans.push_back({s});//creates new group
                cnt++;
            }
            


        }
        return ans;
    }
};