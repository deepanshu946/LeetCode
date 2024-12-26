// class Solution {
// private:
// bool check(vector<int>& bloom, int m, int k ,int day){
//     int ans = 0;
//     for(int i=0 ; i<bloom.size() ; i++){
//         int count=0;
//         while(i<bloom.size() && bloom[i]<=day && count<k){
//             count++;
//             i++;

//         }
        // if(count==k){
        //     ans++;
        //     i--;
        // }
//         if(ans==m){
//             return true;
//         }
//     }
//     return false;
// }
// public:
//     int minDays(vector<int>& bloom, int m, int k) {
//         if(bloom.size()<(long)m*k){
//             return -1;
//         }
//         int maxi=INT_MIN ;
//         int mini=INT_MAX ;
//         for(int i=0 ; i<bloom.size() ; i++){
//             mini = min(mini , bloom[i]);
//             maxi = max(maxi,bloom[i]);
//         }
//         while(mini < maxi){
//             int mid = (mini+maxi)/2;
//             if(check(bloom,m,k,mid)){
//                 maxi = mid;
//             }
//             else{
//                 mini = mid+1;
//             }
//         }
//         return mini;
//     }
// };
class Solution {
public:
    int maxii(vector<int>& bloomDay) {
        int max = INT_MIN;
        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i] > max) {
                max = bloomDay[i];
            }
        }
        return max; 
    }
    
    long long FindFlowers(vector<int>& bloom, int m, int k ,int day){
    int ans = 0;
    for(int i=0 ; i<bloom.size() ; i++){
        int count=0;
        while(i<bloom.size() && bloom[i]<=day && count<k){
            count++;
            i++;
        }
         if(count==k){
            ans++;
            i--;
        }
    
    }
    return ans;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
       if(bloomDay.size()/k < m) return -1;
        int l = 1;
        int r = maxii(bloomDay);
        long long flowers; int ans = 0;
        int mid;
        while(l <= r) {
           mid = l + (r-l)/2;
           flowers = FindFlowers(bloomDay, m, k, mid);
           if(flowers < m) {
             l = mid + 1;
           }
           else if(flowers >= m){
            ans = mid;
            r = mid - 1;
           }
        }
        return ans;
    }
};