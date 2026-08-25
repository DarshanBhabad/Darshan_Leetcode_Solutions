class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // int prod=1;
        // for(int i=1;;i++){
        //     prod=i*k;
        //     int j=0;
        //     bool isthere=false;
        //     while(j<nums.size()){
        //         if(nums[j]==prod){
        //             isthere=true;
        //             break;
        //         }
        //         j++;
        //     }
        //     if(!isthere)
        //         return prod;
            
        // }
        // return 0;

//tc=O(n)
//only if numbers arent duplicate of
    set<int>s;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%k==0){
        s.insert(nums[i]);
        }
    }
int i=1;
int m=k;
    while(m<=100){
        if(s.find(m)==s.end()) return m;
        i++;
        m=k*i;

    }

return k*(s.size()+1); //missing element isnt present in betn;
    }
};