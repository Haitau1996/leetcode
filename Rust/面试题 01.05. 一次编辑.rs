pub fn one_edit_away(first: String, second: String) -> bool {
    let a = first.as_bytes();
    let b = second.as_bytes();
    if (a.len() as i32 - b.len() as i32).abs() > 1 {
        return false;
    }
    let mut status = true;
    let mut ia: usize = 0;
    let mut ib: usize = 0;
    while ia < a.len() && ib < b.len() {
        if a[ia] == b[ib] {
            ia = ia + 1;
            ib = ib + 1;
        } else if status {
            if a.len() < b.len() {
                ib = ib + 1;
            } else if a.len() == b.len() {
                ia = ia + 1;
                ib = ib + 1;
            } else {
                ia = ia + 1;
            }
            status = false;
        } else {
            return false;
        }
    }
    if ia == a.len() && ib == b.len() {
        return true;
    }
    if status && a.len() - ia + b.len() - ib == 1 {
        return true;
    }
    false
}
