/*
* 记得通过相对路径找到 is_palindrome
*/
impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let str:Vec<_> = s.chars().collect();
        let mut low = 0;
        let mut high = str.len() -1;
        loop{
            if low >= high{
                break;
            }
            if str[low] == str[high]{
                low = low + 1;
                high = high - 1;
            }
            else{
                return Self::is_palindrome(&str[low+1..high+1]) || Self::is_palindrome(&str[low..high]);
            }
        }
        true
    }
    pub fn is_palindrome(str:&[char])->bool{
        let mut low = 0;
        let mut high = str.len()-1;
        loop{
            if low >= high{
                break;
            }
            if str[low] == str[high]{
                low = low + 1;
                high = high - 1;
            }
            else{
                return false;
            }
        }
        true
    }
}