class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1= nums1.size();
        int sz2 = nums2.size();
        int mid = (sz1+sz2 + 1)/2;
        int mid2 = (sz1 + sz2 + 2)/2;
        return (findKth(nums1,0,nums2,0,mid) + findKth(nums1,0,nums2,0,mid2))/2.0;
        
    }
private:
    int findKth(vector<int>& nums1, int beg1, vector<int>nums2, int beg2, int K){
        if(beg1 >= nums1.size()) return nums2[beg2 + K -1];
        if(beg2 >= nums2.size()) return nums1[beg1 + K -1];
        if(K == 1) return min(nums1[beg1],nums2[beg2]);
        else{
            int half1 = (beg1 + K/2 -1) < nums1.size() ? nums1[beg1 + K/2 -1] : numeric_limits<int>::max();
            int half2 = (beg2 + K/2 -1) < nums2.size() ? nums2[beg2 + K/2 -1] : numeric_limits<int>::max();
            if(half1 > half2){
                beg2 = beg2 + K/2;
                K = K - K/2;
            }
            else{
                beg1 = beg1 + K/2;
                K = K - K/2;
            }
            return findKth(nums1,beg1, nums2,beg2, K);
        }
    }
};