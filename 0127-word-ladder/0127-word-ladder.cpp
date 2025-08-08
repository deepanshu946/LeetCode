class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> m;
        for(int i=0 ; i<wordList.size() ; i++){
            for(int j=0 ; j<wordList.size() ; j++){
                if(i==j){
                    continue;
                }
                int p=0;
                int q=0;
                int count=0;
                while(p<wordList[j].length()){
                    if(wordList[i][p] != wordList[j][q]){
                        count++;
                    }
                    if(count>=2){
                        break;
                    }
                    p++;
                    q++;
                }
                if(count==1){
                    m[wordList[i]].push_back(wordList[j]);
                }
            }
        }
        for(int j=0 ; j<wordList.size() ; j++){
                int p=0;
                int q=0;
                int count=0;
                while(p<wordList[j].length()){
                    if(wordList[j][p] != beginWord[q]){
                        count++;
                    }
                    if(count>=2){
                        break;
                    }
                    p++;
                    q++;
                }
                if(count==1){
                    m[beginWord].push_back(wordList[j]);
                }
            }
        queue<string> q;
        unordered_set<string> s;
        int count=0;
        q.push(beginWord);
        s.insert(beginWord);
        // count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;

            for(int i=0 ; i<size ; i++){
                string top = q.front();
                q.pop();
                if(top==endWord){
                    return count;
                }
                for(auto it : m[top]){
                    if(s.find(it) == s.end()){
                        s.insert(it);
                        q.push(it);
                    }
                }
            }
        }
        return 0;
    }
};