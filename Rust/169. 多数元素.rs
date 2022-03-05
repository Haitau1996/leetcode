impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut count:i32 = 0;
        let mut current:i32 = 0;
        for elem in nums{
            if count == 0 {
                current = elem;
                count = 1;
            }else if elem == current{
                count = count + 1;
            }else{
                count = count - 1;
            }
        }
        current
    }
}