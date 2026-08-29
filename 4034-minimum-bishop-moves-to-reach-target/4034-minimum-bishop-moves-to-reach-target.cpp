class Solution {
public:
    int minBishopMoves(vector<int>& src, vector<int>& target) {
        if(((src[0]+src[1]) % 2) != ((target[0]+target[1])% 2)){
            return -1;
        }
        if(abs(target[0]-src[0]) == abs(target[1]-src[1])){
            return 1;
        }
        return 2;
    }
};