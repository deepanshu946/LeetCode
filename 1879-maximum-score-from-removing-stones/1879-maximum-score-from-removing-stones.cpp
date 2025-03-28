class Solution {
// private:
// int solve(int a , int b , int c){
//     if((a==0 && b==0) || (a==0 && c==0) || (b==0 && c==0) ){
//         return 0;
//     }
//     int ans = 0;
//     if(a!=0 && b!=0){
//         ans = max(ans , 1+solve(a-1,b-1,c));
//     }
//     if(a!=0 && c!=0){
//         ans = max(ans , 1+solve(a-1,b,c-1));
//     }
//     if(c!=0 && b!=0){
//         ans = max(ans , 1+solve(a,b-1,c-1));
//     }
//     return ans;
// }
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
    
        int ans = 0;
        while(pq.size() > 1){
            int top1 = pq.top();

            pq.pop();
            int top2=pq.top();

            pq.pop();
            ans++;
            top1--;
            top2--;
            if(top1 != 0){
                pq.push(top1);
            }
            if(top2 != 0){
                pq.push(top2);
            }
        }
        return ans;


    }
};