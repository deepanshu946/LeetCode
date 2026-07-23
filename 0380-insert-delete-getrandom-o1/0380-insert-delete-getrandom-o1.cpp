class RandomizedSet {
public:
    unordered_map<int, int> s;
    vector<int> arr;
    int n;
    // mt19937 gen;
    RandomizedSet() { n = 0; }

    bool insert(int val) {
        if (s.find(val) == s.end()) {
            s[val] = arr.size();
            arr.push_back(val);
            // n++;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (s.find(val) == s.end())
            return false;

        int idx = s[val];
        int lastVal = arr.back();
        if (idx != arr.size() - 1) {
            arr[idx] = lastVal;
            s[lastVal] = idx;
        }
        arr.pop_back();
        s.erase(val);
        return true;
    }

    int getRandom() {
        // cout<<n<<endl;
        // random_device rd;
        // mt19937 gen(rd());
        // uniform_int_distribution<> dist(0, arr.size() - 1);
        // cout<<dist(gen)<<endl;
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */