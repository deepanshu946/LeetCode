
class Solution {
private:
bool check(long long mid , int h , vector<int> &piles){
    long long temp = 0;
    for(int i=0 ; i<piles.size() ; i++){
        temp = temp + (piles[i]/mid);
        if(piles[i]%mid != 0){
            temp++;
        }
    }
    if(temp<=h){
        return true;
    }
    return 0;
}
int solve(long long lower , long long upper , vector<int> &piles , int h){
    long long ans = 0;
    while(lower<=upper){
        long long mid = (lower+upper)/2;
        if(check(mid,h,piles)){
            ans = mid;
            upper=mid-1;
        }
        else{
            lower=mid+1;
        }
    }   
    return ans; 
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long upper = INT_MIN;
        for(int i=0 ; i<piles.size() ; i++){
            if(piles[i]>upper){
                upper=piles[i];
            }
        }
        return solve(1,upper,piles,h);
    }
};