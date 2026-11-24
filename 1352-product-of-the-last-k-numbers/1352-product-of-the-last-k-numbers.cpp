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

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */