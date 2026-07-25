class Solution {
public:
    int maxProduct(int n) {
        //we need 2 max digits from the number so that the product will be maximum
        //so use priority queue
        priority_queue<int>q; //max heap max element at root
        while(n!=0){
            q.push(n%10);
            n=n/10;
        }
        int a=q.top();
        q.pop();
        int b=q.top();
        return a*b;
    }
};