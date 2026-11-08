impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {

        let mut l: isize = 0;
        let mut r: isize = (nums.len() - 1) as isize;

        while l <= r
        {
            let m: usize = (l + (r - l) / 2) as usize;
            if nums[m] < target {
                l = m as isize + 1;
            } else if nums[m] > target {
                r = m as isize - 1;
            }
            else {
                return m.try_into().unwrap();
            }
        }

        return -1;
    }
}
