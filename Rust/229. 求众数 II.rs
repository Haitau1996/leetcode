// 学习了一下摩尔投票法
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();
        let mut elem1 = 0;
        let mut elem2 = 0;
        let mut vote1 = 0;
        let mut vote2 = 0;
        for i in nums.iter() {
            if vote1 > 0 && *i == elem1 {
                vote1 = vote1 + 1;
            } else if vote2 > 0 && *i == elem2 {
                vote2 = vote2 + 1;
            } else if vote1 == 0 {
                elem1 = *i;
                vote1 = 1;
            } else if vote2 == 0 {
                elem2 = *i;
                vote2 = 1;
            } else {
                vote1 = vote1 - 1;
                vote2 = vote2 - 1;
            }
        }
        let mut count1 = 0;
        let mut count2 = 0;
        for i in nums.iter() {
            if vote1 > 0 && *i == elem1 {
                count1 = count1 + 1;
            }
            if vote2 > 0 && *i == elem2 {
                count2 = count2 + 1;
            }
        }
        let mut sz = nums.len() as i32;
        if count1 > sz / 3 {
            res.push(elem1);
        }
        if count2 > sz / 3 {
            res.push(elem2);
        }
        res
    }
}
