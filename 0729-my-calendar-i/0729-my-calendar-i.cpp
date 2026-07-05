class MyCalendar {
public:
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    unordered_set<pair<int,int>,pair_hash> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(s.find({start,end}) != s.end()){
            return false;
        }
        for(auto i:s){
            if((i.first <= start && i.second>start )|| (i.first < end && i.second>=end)||(start<=i.first && end>=i.second) ){
                return false;
            }
        }
        s.insert({start,end});

        return true;
    }

};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */