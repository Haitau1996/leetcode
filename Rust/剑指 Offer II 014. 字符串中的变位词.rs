/*
* 100% time, 27.27% men
* 纯属是复习 Rust 了：
    1. String 的元素无法直接使用下标去访问， 要 调用 .as_bytes*()
    2. &i32 和 integer 之间不能直接做比较
    3. array 的 index 是 usize, 不能直接用 i32
*/
impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        if s1.len() > s2.len() {
            return false;
        }
        let mut hash_arr:[i32;26] = [0;26];
        for item in s1.chars(){
            let index = item as usize - 'a' as usize;
            hash_arr[index] = hash_arr[index] + 1;
        }
        let str2 = s2.as_bytes();
        for i in 0..s1.len() {
            let index = str2[i] as usize - 'a' as usize;
            hash_arr[index] = hash_arr[index] - 1; 
        }
        let mut beg = 0;
        let mut end = s1.len();
        loop{
            if Self::all_zeros(&hash_arr) {
                return true;
            }
            if end == s2.len() {
                break;
            }
            let index = str2[beg] as usize - 'a' as usize;
            hash_arr[index] = hash_arr[index]+ 1;
            let index = str2[end] as usize - 'a' as usize;
            hash_arr[index] = hash_arr[index] - 1;
            beg = beg + 1;
            end = end + 1;
        }
        false
    }
    pub fn all_zeros(arr:&[i32;26])->bool{
        let compare : i32 = 0;
        for item in arr{
            if item != &compare {
                return false;
            }
        }
        true
    }
}