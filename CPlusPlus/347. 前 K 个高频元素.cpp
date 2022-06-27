/*
 * 解法 1： 优先队列
 * 解法 2： 快速选择
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class PQSolution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> keyToFrequency;
        vector<int> result;
        for(const auto& elem : nums){
            auto iter = keyToFrequency.find(elem);
            if(iter == keyToFrequency.end()){
                keyToFrequency.insert(std::make_pair(elem,1));
            }
            else{
                iter->second = iter->second + 1;
            }
        }
        auto cmp = [&keyToFrequency](const int& first, const int& second){
            return keyToFrequency[first] > keyToFrequency[second];
        };
        for(const auto& elem:keyToFrequency){
            if(result.size() < k-1){
                result.push_back(elem.first);
            }
            else if(result.size() == k-1){
                result.push_back(elem.first);
                std::make_heap(result.begin(), result.end(), cmp);
            }else{
                if(keyToFrequency[elem.first] > keyToFrequency[result[0]]){
                    std::pop_heap(result.begin(), result.end(),cmp);
                    result.pop_back();
                    result.push_back(elem.first);
                    std::push_heap(result.begin(), result.end(),cmp);
                }
            }
        }
        return result;
    }
};
class PartitionSolution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> part;
        for(const auto& e:nums){
            cnt[e]++;
            if(cnt[e] == 1){
                part.push_back(e);
            }
        }
        int low = 0; int high = part.size()-1;
        int mid = partition(part, low, high);
        while(mid!=k-1){
            if(mid > k-1) high = mid-1;
            else low = mid+1;
            mid = partition(part, low, high);
        }
        return vector<int>(part.begin(), part.begin()+k);
    }
private:
    unordered_map<int, int> cnt;
    int partition(vector<int>& part, int low, int high){
        int povit = part[low];
        while(low < high){
            while(low < high && cnt[part[high]] <= cnt[povit]){
                --high;
            }
            swap(part[low], part[high]);
            while(low < high && cnt[part[low]] >= cnt[povit]){
                ++low;
            }
            swap(part[low], part[high]);
        }
        part[low] = povit;
        return low;
    }
};
