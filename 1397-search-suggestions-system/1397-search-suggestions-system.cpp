class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        vector<vector<string>> ans;
        vector<vector<string>> finalans;
        for (int i = 0; i < searchWord.length(); i++) {
            vector<string> compare;
            if (ans.size() == 0) {
                compare = products;
            } else {
                compare = ans.back();
            }
            vector<string> temp;
            for (int j = 0; j < compare.size(); j++) {
                if (i < compare[j].length()) {
                    if (searchWord[i] == compare[j][i]) {
                        temp.push_back(compare[j]);
                    }
                }
            }
            priority_queue<string> pq;
            if(temp.size() > 3){
                for(int k=0 ; k<3 ; k++){
                    pq.push(temp[k]);
                }
                for(int l=3 ; l<temp.size() ; l++){
                    if(temp[l] < pq.top()){
                        pq.pop();
                        pq.push(temp[l]);
                    }
                }
                vector<string> finaltemp;
                while(!pq.empty()){
                    finaltemp.push_back(pq.top());
                    pq.pop();
                }
                sort(finaltemp.begin() , finaltemp.end());
                finalans.push_back(finaltemp);
            }
            else{
                sort(temp.begin() , temp.end());
                finalans.push_back(temp);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return finalans;
    }
};