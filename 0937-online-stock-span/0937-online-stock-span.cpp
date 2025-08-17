class StockSpanner {
public:
    stack<pair<int,int>> s;
    int count = 0;
    StockSpanner() {
        s.push({100000,-1});
        count=0;
    }
    
    int next(int price) {

        while(s.top().second != -1 && s.top().first <= price){
            s.pop();
        }
        int ans = 0;
        pair<int,int> t= s.top();
        if(t.second != -1){
            ans = count - t.second;
        }
        else{
            ans = count+1;
        }
        s.push({price,count});
        count++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */