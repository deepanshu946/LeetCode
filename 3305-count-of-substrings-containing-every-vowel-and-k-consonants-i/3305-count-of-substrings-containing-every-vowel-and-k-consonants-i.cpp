
class Solution {
private:
bool checkvovel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    return false;
}
public:
    int countOfSubstrings(string word, int k) {
        vector<int> temp(word.length(),0);
        // if(checkvovel(word[word.length()-1])){
        //     temp[word.length()-1]=1;
        // }
        for(int i=word.length()-2; i>=0 ; i--){
            if(checkvovel(word[i+1])){
                temp[i] = temp[i+1]+1;
            }
            else{
                temp[i]=0;
            }

        }
        unordered_map<int,int> vovels;
        int count = 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right<word.length()){
            if(checkvovel(word[right])){
                vovels[word[right]]++;
            }
            else{
                count++;
            }
            while(count>k){
                if(checkvovel(word[left])){
                    vovels[word[left]]--;
                    if(vovels[word[left]]==0){
                        vovels.erase(word[left]);
                    }
                }
                else{
                    count--;
                }
                left++;
            }
            while(vovels.size()==5 && count==k){
                ans = ans+ temp[right]+1;
                if(checkvovel(word[left])){
                    vovels[word[left]]--;
                    if(vovels[word[left]]==0){
                        vovels.erase(word[left]);
                    }
                }
                else{
                    count--;
                }
                left++;
            }
            right++;
        }
        return ans;

    }
};