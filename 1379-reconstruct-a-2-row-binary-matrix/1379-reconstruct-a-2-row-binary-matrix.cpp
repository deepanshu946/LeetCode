class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<int> first(colsum.size(),0);
        vector<int> second(colsum.size(),0);

        for(int i=0 ; i<colsum.size() ; i++){
            if(colsum[i]==0){
                continue;
            }
            if(colsum[i]==2){
                first[i]=1;
                second[i]=1;
                upper--;
                lower--;
                if(upper<0 || lower<0){
                    return {};
                }
            }
            else{
                if(upper>lower){
                    upper--;
                    first[i]=1;
                }
                else{
                    lower--;
                    second[i]=1;
                }
                if(lower<0 || upper<0){
                    return {};
                }
            }
        }
        if(upper != 0 || lower!=0){
            return {};
        }
        return {first,second};

    }
};