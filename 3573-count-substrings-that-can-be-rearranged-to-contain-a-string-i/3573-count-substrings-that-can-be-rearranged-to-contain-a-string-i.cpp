class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0 ; i<word2.size() ; i++){
            m1[word2[i]]++;
        }
        long long ans = 0;
        int start = 0;
        int end = 0;
        while(end < word1.length()){
            m2[word1[end]]++;
            bool check = 1;
            for(auto i:m1){
                if(m2.find(i.first) == m2.end()){
                    check=0;
                    break;
                }
                else if(m2[i.first] < i.second){
                    check = 0;
                    break;
                }

            }
            if(check==1){
                int temp = 1;
                while(temp==1){
                    ans = ans + word1.length()-end;
                    m2[word1[start]]--;
                    start++;
                    for(auto i:m1){
                        if(m2.find(i.first) == m2.end()){
                            temp=0;
                            break;
                        }
                        else if(m2[i.first] < i.second){
                            temp = 0;
                            break;
                        }
                    }
                }
            }
            end++;
        }
        return ans;


    }
};