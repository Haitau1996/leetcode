impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut dp:Vec<bool> = vec![false; nums.len()+1];
        let mut index: usize = 0;
        dp[index] = true;
        while index < nums.len(){
            if dp[index]{
                let local_len = nums[index] as usize;
                let mut inner_index:usize = 0;
                while inner_index < local_len{
                    if index+inner_index+1 > nums.len(){
                        break;
                    }else{
                        dp[index+inner_index+1] = true;
                        inner_index = inner_index + 1;
                    }
                }
            }
            index = index + 1;
        }
        dp[nums.len()-1]
    }
}