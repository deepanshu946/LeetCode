class Solution {
public:
    vector<string> ans;
    class TrieNode{
        public:
        string word;
        bool isEnd;
        TrieNode* children[26];
        TrieNode(){
            word="";
            isEnd = 0;
            for(int i=0 ; i<26 ; i++){
                children[i]=NULL;
            }
        } 
    };
    // TrieNode* root;
    
    
    void insert(TrieNode* root , string word) {
        TrieNode* crawl = root;
        for(char ch : word){
            int idx = ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=new TrieNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->isEnd = 1;
        crawl->word = word;

    }
    
    // bool search(string word) {
    //     TrieNode* crawl = root;
    //     for(char ch : word){
    //         int idx = ch-'a';
    //         if(crawl->children[idx]==NULL){
    //             return false;
    //         }
    //         crawl = crawl->children[idx];
    //     }
    //     if(crawl->isEnd){
    //         return true;
    //     }
    //     return false;
    // }
    
    // bool startsWith(string prefix) {
    //     TrieNode* crawl = root;
    //     for(char ch : prefix){
    //         int idx = ch-'a';
    //         if(crawl->children[idx]==NULL){
    //             return false;
    //         }
    //         crawl = crawl->children[idx];
    //     }
    //     return true;
    // }
    void solve(vector<vector<char>> &board , int i , int j , TrieNode * root , int m , int n, vector<vector<bool>> &vis ){
        if(i>=m || i<0 || j>=n || j<0){
            return;
        }
        if(root->children[board[i][j]-'a']==NULL){
            return; 
        }
        root = root->children[board[i][j]-'a'];
        if(root->isEnd){
            ans.push_back(root->word);
            root->isEnd=0;
        }
        vis[i][j]=1;
        if(i+1<m && !vis[i+1][j]){
            solve(board,i+1,j,root,m,n,vis);
        }
        if(j+1<n && !vis[i][j+1]){
            solve(board,i,j+1,root,m,n,vis);
        }
        if(i-1>=0 && !vis[i-1][j]){
            solve(board,i-1,j,root,m,n,vis);
        }
        if(j-1>=0 && !vis[i][j-1]){
            solve(board,i,j-1,root,m,n,vis);
        }
        vis[i][j]=0;
    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode * root = new TrieNode();
        for(int i=0 ; i<words.size() ; i++){
            insert(root,words[i]);

        }
        int m = board.size() ;
        int n =  board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[i].size() ; j++){
                 if(root->children[board[i][j]-'a'] != NULL){
                    solve(board,i,j,root ,m , n,  vis);
                 }
            }
        }
        return ans;
    }
};