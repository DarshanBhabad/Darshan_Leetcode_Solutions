
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          //TC= n(logk) ... for lop and sorting k=size of s // unordere map so tc=O(1)
          //and second for loop = O(size of map of no of unique strings)
          // SC=O(n)

        // as you know when sorted each anagram will look the same ex. eat, ate = aet 
        // so for them key will be same that is sorted order of tehm 

        // so created sorted order keys and store
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }

        // iterate the map and just copy those vectors 
        // or for ( auto p: m) ans.push_back(p.second);
        auto it=mp.begin();
        vector<vector<string>>ans;
        while(it!=mp.end()){
            ans.push_back(it->second);it++;
        }
        return ans;
    }
};



// MY METHOD :



// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {

//         //TC = O(N × (K + 26 log N)) // long n- find in  maps  // Creating frequency vector: O(K) k=size of str
//   // SC= O(N × 26 + total characters) = N* 26 for each str 26 lingth v and total charsc
// int n=strs.size();
// vector<vector<string>>ans;
//     map<vector<int>,int>m; //By default, the C++ Standard Template Library (STL) does not provide a built-in hash function for std::vector  so only map used here
//     int cnt=0;
//         for(auto s:strs){
//             vector<int>v(26,0);
//             for(int i=0;i<s.size();i++){
//                 v[s[i]-'a']++;
//             }

//             if(m.find(v)!=m.end()) ans[m[v]].push_back(s); // acceess already created grp
//             else {
//                 m[v]=cnt;
//                 ans.push_back({s});//creates new group
//                 cnt++;
//             }
            


//         }
//         return ans;
//     }
// };