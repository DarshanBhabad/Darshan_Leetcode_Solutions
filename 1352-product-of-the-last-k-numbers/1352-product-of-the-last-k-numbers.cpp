class ProductOfNumbers {
public:
    vector<int>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int p=k;
        int gp=1;
        int n=v.size()-1;
        while(p!=0){
             gp*=v[n];
             n--;
             p--;
        }
        return gp;
    }
};


//optimized
// class ProductOfNumbers {

//     vector<int> p;

// public:
//     ProductOfNumbers() {
//         p.push_back(1); //initially push one as we have to multiply with last elemnt to store current ele 
//     }
    
//     void add(int num) {
//         int n = p.size();
//         if(num == 0) {
//             p = {1}; // all products will become 0; so reinitialize the p to 1; and we handle the case    in if(k >= n) {return 0;} as values decrese in p when we reinitialize the p;
//         }
//         else {
//             p.push_back(p[n-1] * num);// calucltesd upto now * current 
//         }
//     }
    
//     int getProduct(int k) {
//         int n = p.size();
//         if(k >= n) {
//             return 0;
//         }
        
//         return (p[n-1] / p[n-1-k]); // product of last  k will be upto last / before last k
//     }
// };

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */