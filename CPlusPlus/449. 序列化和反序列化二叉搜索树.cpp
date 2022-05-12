class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string temp{};
        seri_core(root, temp);
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp{};
        vector<int> buffer{};
        istringstream ss{data};
        while(getline(ss, temp, ' ')){
            buffer.push_back(stoi(temp));
        }
        return dese_core(buffer, 0, buffer.size()-1);
    }
private:
    void seri_core(TreeNode* root, string& in){
        if(root == nullptr)
            return;
        in += to_string(root->val);

        if(root->left) in.push_back(' ');
        seri_core(root->left, in);
        
        if(root->right) in.push_back(' ');
        seri_core(root->right, in);
    }
    TreeNode* dese_core(vector<int>& buffer, int low, int high){
        if(low > high) return nullptr;
        if(low == high) return new TreeNode(buffer[low]);
        else{
            int root_val = buffer[low];
            int temp = low+1;
            while(temp <= high && buffer[temp] < root_val){
                ++temp;
            }
            TreeNode* root = new TreeNode(root_val);
            root->left = dese_core(buffer,low+1,temp-1);
            root->right = dese_core(buffer, temp, high);
            return root;
        }
    }
};
