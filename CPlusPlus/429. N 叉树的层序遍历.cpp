// Definition for a Node.
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> curr_que;
        queue<Node*> next_que;
        vector<vector<int>> result;
        if(root == nullptr) return result;
        else{
            result.push_back(vector<int>());
            curr_que.push(root);
        }
        while(!curr_que.empty()){
            auto front = curr_que.front();
            curr_que.pop();
            result.back().push_back(front->val);
            for(auto &elem: front->children){
                if(elem != nullptr) 
                    next_que.push(elem);
            }
            if(curr_que.empty() && !next_que.empty()){
                result.push_back(vector<int>());
                swap(curr_que, next_que);
            }
        }
        return result;
    }
};
