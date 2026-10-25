impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let numCount = nums.len();
        let set: HashSet<i32> = HashSet::from_iter(nums);

        return set.len() != numCount;
    }
}
