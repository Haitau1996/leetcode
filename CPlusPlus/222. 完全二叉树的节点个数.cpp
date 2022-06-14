#include "include/tree.hpp"
#include <cmath>
// 解法 1： 看是否是满树， 递归求解
// 解法 2： 求出深度 h, 最小值为 2^(h-1) ， 最大值为  2^h - 1, 二分法求解， 验证结果的时候需要用一些位运算
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        size_t deepOfRoot = getDeepth(root);
        // base case: 两边长度相等， 是满二叉树
        size_t rightDeepth = getRDeepth(root);
        if(deepOfRoot == rightDeepth)
            return pow(2,deepOfRoot) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
private:
    size_t getDeepth(TreeNode *root){
        size_t deepth = 0;
        while(root != nullptr){
            ++deepth;
            root=root->left;
        }
        return deepth;
    }
    size_t getRDeepth(TreeNode *root){
        size_t deepth = 0;
        while(root != nullptr){
            ++deepth;
            root = root->right;
        }
        return deepth;
    }
};
class BinarySearch_Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int h = deepth(root);
        int l = (1 <<(h-1));
        int r = (1 <<h) - 1;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(valid(root, mid, h)) l = mid;
            else r = mid-1;
        }
        return l;
    }
private:
    int deepth(TreeNode* root){
        int res = 0; 
        while(root!= nullptr){
            root = root->left;
            ++ res;
        }
        return res;
    }
    bool valid(TreeNode* root, int curr, int h){
        int diff = curr - (1<<(h-1));
        int hc = 1;
        while(hc < h){
            if(diff & (1 <<(h - hc-1))){
                root = root->right;
            }else{
                root = root->left;
            }
            ++hc;
        }
        return root != nullptr;
    }
};