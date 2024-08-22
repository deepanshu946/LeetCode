class Solution {
private:
long long root(long long n){
    long long low = 1, high = n;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <=(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

public:
    int mySqrt(int x) {
        long long a= root(x);
        return a;
    }
};