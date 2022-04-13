#include<cstdlib>
#include<unordered_map>
#include<utility>
#include<vector>

using namespace std;
class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(val_to_pos.find(val) != val_to_pos.end()){
            return false;
        }else{
            auto pos = val_arr.size();
            val_arr.push_back(val);
            val_to_pos.insert(pair<int,int>(val, pos));
            return true;
        }
    }
    
    bool remove(int val) {
        if(val_to_pos.find(val) == val_to_pos.end()) return false;
        auto last_val = val_arr.back();
        auto last_pos = val_arr.size()-1;
        auto val_pos = val_to_pos[val];
        swap(val_arr[last_pos],val_arr[val_pos]);
        val_to_pos[last_val] = val_pos;
        val_arr.pop_back();
        val_to_pos.erase(val);
        return true;
    }
    
    int getRandom() {
        int pos = rand()%val_arr.size();
        return val_arr[pos];
    }
private:
    vector<int> val_arr;
    unordered_map<int, int> val_to_pos;
};
