//https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150/
//380. Insert Delete GetRandom O(1)
class RandomizedSet {
public:
    unordered_map<int, int> um;
    vector<int> array;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(um.find(val) == um.end()) {
            array.push_back(val);
            int lastindex = array.size()-1;
            um[val] = lastindex;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {

        if(um.find(val) != um.end()) {
            int index = um[val];
            int le = array.back();
            array[index] = le;

            um[le] = index;
            array.pop_back();
            um.erase(val);

            return true;
        }

        return false;
        
    }
    
    int getRandom() {
        int index = array.size();
        int rv = array[rand() % index];

        return rv;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */