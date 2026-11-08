impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {

        let mut l: i32 = 0;
        let mut r: i32 = (nums.len() - 1) as i32;

        while l <= r
        {
            let m: usize = (l + (r - l) / 2) as usize;
            if nums[m] < target {
                l = m as i32 + 1;
            } else if nums[m] > target {
                r = m as i32 - 1;
            }
            else {
                return m.try_into().unwrap();
            }
        }

        return -1;
    }
}
