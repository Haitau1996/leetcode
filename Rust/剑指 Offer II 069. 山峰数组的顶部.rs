impl Solution {
    pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
        let mut low:usize = 1;
        let mut high = arr.len() - 2;
        while low < high{
            let mid = (low + high)/2;
            if arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]{
                return mid as i32;
            }
            else if arr[mid] > arr[mid-1]{
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        low as i32
    }
}