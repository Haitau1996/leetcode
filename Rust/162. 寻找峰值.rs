impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        let mut low:usize = 0;
        let mut high = nums.len() - 1;
        while low < high{
            let mid = (low + high)/2;
            if nums[mid] > nums[mid + 1]{
                if mid == 0 {
                    return mid as i32;
                }
                else if nums[mid] > nums[mid - 1]{
                    return mid as i32;
                }
                else {
                    high = mid - 1;
                }
            }
            else{
                low = mid + 1;
            }
        }
        low as i32
    }
}