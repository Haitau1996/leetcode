// 使用partition 不剪枝的话会超时
// ！！！ 原来不是 partition 的问题， 是因为传递参数时候没有使用 by -reference 导致vector 复制
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int low = 0; 
        int high = points.size() - 1;
        int pos = partition(points,low,high);
        while(pos != k){
            if(pos > k){
                high = pos - 1;
            }
            else{
                low = pos + 1;
            }
            pos = partition(points,low, high);
        }
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
private:
    int get_distance_square(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
    int partition(vector<vector<int>>& points, int beg, int end){
        if(beg >= end) return beg;
        int rand_pos = rand()%(end - beg) + beg;
        swap(points[beg],points[rand_pos]);
        auto povit_point = points[beg];
        int povit = get_distance_square(povit_point);
        while(beg < end){
            while(beg < end && get_distance_square(points[end]) >=povit){
                --end;
            }
            swap(points[beg],points[end]);
            while(beg < end && get_distance_square(points[beg]) <= povit){
                ++beg;
            }
            swap(points[beg],points[end]);
        }
        points[beg] = povit_point;
        return beg;
    }
};
