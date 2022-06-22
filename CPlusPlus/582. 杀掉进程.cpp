/*
 * 解决这个问题的思路有点像查并集
 */
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
        vector<int> res {};
        unordered_map<int, int> to_parent {};
        for (int i = 0; i < pid.size(); ++i) {
            to_parent[pid[i]] = ppid[i];
        }
        if (kill == 0)
            return pid;
        for (int i = 0; i < pid.size(); ++i) {
            int curr = pid[i];
            while (curr != 0) {
                if (curr == kill) {
                    res.push_back(pid[i]);
                    break;

                } else {
                    curr = to_parent[curr];
                }
            }
        }
        return res;
    }
};
