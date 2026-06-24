class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans= 0;
        for(int i=0 ; i<sentences.size() ; i++){
            int count = 0;
            for(int j=0 ; j<sentences[i].length() ; j++){
                if(sentences[i][j]== ' ' ){
                    count++;
                }
                
            }
            // if(count==0 && sentences[i].length() > 0){
            //     count = 1;
            // }
            // else{
                count += 1;
            // }
            ans = max(ans , count);
        }
        return ans;
    }
};