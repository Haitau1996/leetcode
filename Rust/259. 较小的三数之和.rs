// 需要注意下面两点
// 1. 别忘记对 vec 进行排序这个预处理动作
// 2. 确定 j 和 k 的时候， 其实发现两者是相关的， 如果对某个 j 和 k 结果大于 target, 那么对于大于j
//    的所有位置， 结果都是大的， 如果小于 target, 那么对于 j,k 之间的所有位置结果也都是小于的，
//    因此 j 和 k 之间 O(n^2) 的时间复杂度可以将为 O(n)， 要么右移 J， 要么左移 K。
pub fn three_sum_smaller(mut nums: Vec<i32>, target: i32) -> i32 {
    if nums.len() < 3 {
        return 0;
    }
    nums.sort();
    let mut i: usize = 0;
    let mut res: i32 = 0;
    while i < nums.len() - 2 {
        let mut j: usize = i + 1;
        let mut k = nums.len() - 1;
        while j < k {
            if nums[i] + nums[j] + nums[k] < target {
                res = res + ((k - j) as i32);
                j = j + 1;
            } else {
                k = k - 1;
            }
        }
        i = i + 1;
    }
    res
}
