class Solution {
public:
    int maxProduct(int n) {
        //TC=d(logd) d= number of digits
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


// class Solution {
//    public:
//     int maxProduct(int n) {
        //TC==logn
//         string s = to_string(n); //Tc= \(O(\log_{10} n)\)
//         sort(s.rbegin() , s.rend()); // logn
//         int maxProduct = (s[0]-'0')*(s[1]-'0');
//         return maxProduct;
//     }
// };
    }
};