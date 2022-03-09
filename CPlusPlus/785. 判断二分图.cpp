/*
DFS 实现：
color 表示有三种状态 -1-> 未开始染色， 0 默认染色， 1 -> 0 的邻边
对某个点和它的所有邻居染色的过程如下：
1. 如果该点已经染色， 判断染的和传入的 flag 是否相等， 是的话就返回 true
2. 如果没有染色， 那么就先将它的颜色染上， 然后看能否对所有的子节点染色， 能的话返回 true

为什么可以有默认颜色而不用判断选择染 0 还是 1 ？ 在做 dfs 并且没有返回 false, 意味着过程中会将所有连在一起的点全部染上，剩下的就和前面已经染色的部分不相连了。 
为什么对已经染色的点可以直接下判断 ？ 因为给某点染上色之后就是对所有的邻居进行染色， 判断 false 已经存在递归过程中实现了， 如果不下判断， 可能的结果是相互调用直到无限循环。
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); ++i){
            if(color[i] == -1){
                if(!dfs(graph, color,i,0)) return false;
            }
        }
        return true;
    }
private: 
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int cursor, int flag){
        if(color[cursor] >= 0){
            return color[cursor] == flag;
        }
        color[cursor] = flag;
        for(const auto& elem : graph[cursor]){
            if(!dfs(graph,color,elem,1-flag)) return false;
        }
        return true;
    }
};