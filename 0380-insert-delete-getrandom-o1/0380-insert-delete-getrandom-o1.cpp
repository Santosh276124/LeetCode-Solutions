class RandomizedSet {
public:
    unordered_map<int,int> m;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val) == false)
        {
            m[val]++;
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        
        if(m.count(val))
        {
            m.erase(val);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
       int ind = rand()%m.size();
        auto it = m.begin();
        for(int i = 0; i < ind; i++)
        {
            it++;
        }
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */