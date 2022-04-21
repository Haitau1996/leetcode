// 和剑指 Offer 的转为单链表类似， 不过这个更简单
#include<cstddef>
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* left, Node* right) {
        val = _val;
        left = left;
        right = right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        // base case has only one node or zero node
        if(root == NULL) return root;
        Node* left = root->left;
        Node* right = root->right;
        root->left = root;
        root->right = root;
        if(left){
            Node* leftHead = treeToDoublyList(left);
            Node* leftTail = leftHead->left;
            root->left = leftTail;
            root->right = leftHead;
            leftTail-> right = root;
            leftHead->left = root;
            root = leftHead;
        }
        if(right){
            Node* rightHead = treeToDoublyList(right);
            Node* rightTail = rightHead->left;
            Node* rootTail = root->left;
            rootTail->right = rightHead;
            rightHead->left = rootTail;
            root->left = rightTail;
            rightTail->right = root;
        }
        return root;
    }
};
