impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let mut result = Vec::new();
        let mut first:usize = 0;
        while nums.len() > 2 && first < (nums.len() - 2){
            if first > 0 && nums[first]==nums[first-1]{
                first = first + 1;
            }
            else{
                let mut second:usize = first + 1;
                let mut third: usize = nums.len()-1;
                while second < third{
                    if nums[first] + nums[second] + nums[third] == 0{
                        result.push(vec![nums[first],nums[second],nums[third]]);
                        while second < third && nums[second+1] == nums[second]{
                            second = second + 1;
                        }
                        while second < third && nums[third-1] == nums[third]{
                            third = third - 1;
                        }
                        second = second + 1;
                        third = third - 1;
                    } else if nums[first] + nums[second] + nums[third] < 0{
                        second = second+1;
                    }else{
                        third = third-1;
                    }
                }
                first = first + 1;
            }
        }
        result
    }
}