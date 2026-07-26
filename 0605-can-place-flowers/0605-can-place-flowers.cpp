class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // int n=flowerbed.size();
        //  int count=0;
        //  vector<int>v;
        
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         count++;
        //     }
        //     else{
        //         count=0;
        //     }
        //     v.push_back(count);
           

        // }
        int m=flowerbed.size();
        bool planted=false;
        for(int i=0;i<m-1;i++){
            if(flowerbed[i]==1 && flowerbed[i+1]==1 ) return false;

            if(flowerbed[i]==0 && flowerbed[i+1]!=1 && !planted){
            n--; 
           planted=true;

            } 
           else if(flowerbed[i]==1) planted=true;
           else{
            planted=false;
           }
            
           
          
        }
        if(flowerbed[m-1]!=1 && !planted) n--;
           
        if(n>0) return false;
        return true;

    }
};