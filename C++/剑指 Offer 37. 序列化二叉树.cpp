/*
执行用时：36 ms, 在所有 C++ 提交中击败了85.51% 的用户
内存消耗：30.5 MB, 在所有 C++ 提交中击败了64.57% 的用户
这个题目解决的时候有两个技巧：
    * 如果我们使用中序、后序便利， 数据从一个流出来要等很长的事件
    * 可以利用 C++ 中的 stringstream 的性质， 省去了很多繁琐的字符串操作
*/
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serizHelper(root);
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::istringstream stream(data); 
        return deserHelper(stream);
    }
private:
    string output{};
    void serizHelper(TreeNode* root){
        if(root == nullptr){
            output.append("* ");
            return;
        }
        output.append(std::to_string(root->val));
        output.append(" ");
        serizHelper(root->left);
        serizHelper(root->right);
    }
    TreeNode* deserHelper(std::istringstream& stream){
        string res;
        stream >> res;
        TreeNode* root{};
        if(res != "*"){
            root = new TreeNode(std::stoi(res));
            root->left = deserHelper(stream);
            root->right = deserHelper(stream);
        }
        return root;
    }
};