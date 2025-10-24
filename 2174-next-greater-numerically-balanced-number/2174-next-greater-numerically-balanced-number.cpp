class Solution {
private:
bool check(int i){
    unordered_map<int,int> m;
    while(i != 0){
        int d = i%10;
        m[d]++;
        i = i/10;
    }
    for(auto i:m){
        if(i.first != i.second){
            return false;
        }
    }
    return true;
}
public:
    int nextBeautifulNumber(int n) {
        if(n >= 666666) return 1224444;
        int i=n+1;
        while(true){
            if(check(i)){
                return i;
                break;
            }
            i++;
        }
        return -1;
    }
};