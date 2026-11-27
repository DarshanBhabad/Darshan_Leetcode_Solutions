class StockSpanner {
public:
vector<int>p;
stack<int>s;
    StockSpanner() {
        
    }
    //using previous greater or can also use variables see teh que 217 on strivers ;
    int next(int price) {
        p.push_back(price); //push teh current day price  price;
        
//    s.push(0);
    // vector<int>ans(n,0);
//    for(int i=0;i<n;i++){
    int n=p.size()-1;//current elemet 
    int ans=0;
    while(!s.empty()&& p[s.top()]<=price){
        s.pop();
    }
    if(s.empty()){
        // pg[i]=-1;
        ans= n+1;
    }
    else{
        //  pg[i]=s.top();
        ans = n-s.top();


    }
    s.push(n);
    return ans;
   }
   
   
        
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */