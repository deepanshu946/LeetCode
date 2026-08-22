class Trie {
public:
    class TrieNode{
        public:

        bool isEnd=0;
        TrieNode* children[26];
        TrieNode(){
            // isEnd = 0;
            for(int i=0 ; i<26 ; i++){
                children[i]=NULL;
            }
        } 
    };
    TrieNode* root;
    Trie() {
         root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawl = root;
        for(char ch : word){
            int idx = ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=new TrieNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->isEnd = 1;

    }
    
    bool search(string word) {
        TrieNode* crawl = root;
        for(char ch : word){
            int idx = ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl = crawl->children[idx];
        }
        if(crawl->isEnd){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawl = root;
        for(char ch : prefix){
            int idx = ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl = crawl->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */