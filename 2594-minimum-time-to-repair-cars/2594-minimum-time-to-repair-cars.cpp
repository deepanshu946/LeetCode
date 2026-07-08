class Solution {
private:
bool ispossible(long long time , vector<int> &ranks , int cars){
    long long count = 0;
    for(int i=0 ; i<ranks.size() ; i++){
        long long temp = time/ranks[i];
        long long n = sqrt(temp);
        count=count+n;
    }
    if(count>=cars){
        return true;
    }
    return false;
}
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long maxi = 0;
        for(int i=0 ; i<ranks.size() ; i++){
            maxi = max(  maxi , 1LL *ranks[i]);
        }
        long long start = 0;
        long long ans = -1;

        long long end =1LL* maxi*(1LL* cars*cars);
        while(start<=end){
            long long mid = (start+end)/2;
            if(ispossible(mid,ranks,cars)){
                ans = mid;
                end=mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;

    }
};