class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> index; // stores <value, index> pairs
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // If element is present return false 
        // or else add at end of list and store the index in the map
        if(index.count(val) == 1)
            return false;

        v.push_back(val);  
        index[val] = v.size()-1; 
        return true;
        
    }
    
    bool remove(int val) {
        // If element is not there return false
        // or swap the last element with val and pop back the last element
        if(index.count(val) == 0)
            return false;

        int last = v.back(); 
        v[index[val]] = last;   
        v.pop_back();	   
        index[last] = index[val];	     
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */