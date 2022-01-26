/*
* 随机访问要是 O(1), 应该是 array baseed 一个结构存放元素
* 插入、删除 都是 O(1), 我们就需要借助一个 hash_map， 将 val 映射到 array 中的位置
*/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(val_to_pos.find(val) != val_to_pos.end()) return false;
        else{
            val_to_pos.insert(std::pair<int,int>(val,val_vec.size()));
            val_vec.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto to_remove = val_to_pos.find(val);
        if(to_remove == val_to_pos.end()) return false;
        else{
            auto pos = (*to_remove).second;
            auto tail_val = val_vec.back();
            val_to_pos[tail_val] = pos;
            val_vec[pos] = tail_val;
            val_vec.pop_back();
            val_to_pos.erase(to_remove);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand()%(val_vec.size());
        return val_vec[pos];
    }
private:
    std::unordered_map<int, int> val_to_pos;
    std::vector<int> val_vec;
};
