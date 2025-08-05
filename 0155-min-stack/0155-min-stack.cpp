class MinStack {
public:
    // stack<int,int> s;
    vector<pair<int,int>> s;
    int i=0;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.size()==0){
            s.push_back({val,val});
            // i++;
        }
        else{
            int get = getMin();
            cout<<get<<endl;
            s.push_back({val,min(val,get)});
            // i++;
        }
    }
    
    void pop() {
        s.pop_back();

        // i--;
    }
    
    int top() {
        return s[s.size()-1].first;
    }
    
    int getMin() {
        return s[s.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */