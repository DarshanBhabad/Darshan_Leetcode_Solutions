class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        // The test cases will be generated such that the target with maximum count is unique.
        // so there will be no tragets with same count 

        //to count freq of all possible targets 
        //priority queue allows the duplicates 
        //so to store count of distinct targets we have to use map
        // and then priority queue(max heap) to get maximum 

        //method 1 priority queue and map
        //TC O(n+plogp)//plogp push operations for each pair
        unordered_map<int,int>m;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==key)m[nums[i+1]]++;
        }

//         priority_queue<pair<int,int>>q;
//         for(auto p:m){
//             //have to considered by freq so should pass freq as first for priority queue
//             q.push({p.second,p.first}); //for q p.second is first and p.first is second
//         }
// return q.top().second;

//part 2 apply customize sort on map itself 
// for that copy all pairs in map to vector and apply sort on vector
// TC=logn
vector<pair<int,int>>v;
for(auto p:m){
    v.push_back(p);
}

sort(v.begin(),v.end(), [](const auto& a, const auto& b)
{
        return a.second > b.second; // sort according to des order of freq
    });

    return v[0].first;
    }
};