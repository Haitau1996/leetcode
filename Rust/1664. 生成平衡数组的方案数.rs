/*
 * 将 i 以前（包含i） 的偶下标前缀和标记为 odd, 奇下标前缀和计为 even.
 * 那么 除掉 i 之后，  新的偶下标之和即为前面部分的偶下标之和加上后面部分的奇下标之和， 根据 i 是否为偶考虑要不要减去 nums[i]
 */
pub fn ways_to_make_fair(nums: Vec<i32>) -> i32 {
    let mut even = Vec::new();
    let mut odd = Vec::new();
    let mut i: usize = 1;
    even.push(0);
    odd.push(nums[0]);
    while i < nums.len() {
        if i % 2 == 0 {
            even.push(even[i - 1]);
            odd.push(odd[i - 1] + nums[i]);
        } else {
            even.push(even[i - 1] + nums[i]);
            odd.push(odd[i - 1]);
        }
        i = i + 1;
    }
    i = 0;
    let mut res = 0;
    let len = nums.len();
    while i < nums.len() {
        let left_even = if i % 2 == 0 {
            even[i]
        } else {
            even[i] - nums[i]
        };
        let left_odd = if i % 2 == 0 { odd[i] - nums[i] } else { odd[i] };
        if left_even + odd[len - 1] - odd[i] == left_odd + even[len - 1] - even[i] {
            res = res + 1;
        }
        i = i + 1;
    }
    res
}
