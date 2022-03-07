class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        Node* result;
        if(key_to_node.find(node->val) == key_to_node.end()){
            result = new Node(node->val);
            key_to_node[node->val] = result;
        }else{
            result = key_to_node[node->val];
            return result;
        }
        for(const auto& elem : node->neighbors){
            result->neighbors.push_back(cloneGraph(elem));
        }
        return result;
    }
private:
    unordered_map<int, Node*> key_to_node{};
};