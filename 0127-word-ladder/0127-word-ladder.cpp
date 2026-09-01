class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> m;
        for(int i=0 ; i< wordList.size() ; i++){
            string word = wordList[i];
            for(int j=0 ; j<wordList.size() ; j++){
                string word2 = wordList[j];
                int change = 0;
                for(int k=0;k<word.length() ; k++){
                    if(word[k] != word2[k]){
                        change++;
                    }
                    if(change>1){
                        break;
                    }
                }
                if(change == 1){
                    m[word].push_back(word2);
                    m[word2].push_back(word);

                }
            }
        }
        string word = beginWord;
        for(int j=0 ; j<wordList.size() ; j++){
            string word2 = wordList[j];
            int change = 0;
            for(int k=0;k<word.length() ; k++){
                if(word[k] != word2[k]){
                    change++;
                }
                if(change>1){
                    break;
                }
            }
            if(change == 1){
                m[word].push_back(word2);
                // m[word2].push_back(word);

            }
        }
        unordered_set<string> vis;
        queue<string> pq;
        pq.push(beginWord);
        vis.insert(beginWord);
        int steps = 1;
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                string s = pq.front();
                pq.pop();
                if(s == endWord){
                    return steps;
                }
                for(auto i:m[s]){
                    if(vis.find(i) == vis.end()){
                        pq.push(i);
                        vis.insert(i);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};