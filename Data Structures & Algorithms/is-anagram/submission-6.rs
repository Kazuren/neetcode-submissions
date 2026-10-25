impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {

        if s.len() != t.len() {
            return false;
        }

        let mut charFrequencyS: [u32; 26] = [0; 26];
        let mut charFrequencyT: [u32; 26] = [0; 26];

        for (sc, tc) in s.chars().zip(t.chars())
        {
            charFrequencyS[sc as usize - 'a' as usize] += 1;
            charFrequencyT[tc as usize - 'a' as usize] += 1;
        }

        
        for i in 0..26
        {
            if charFrequencyS[i] != charFrequencyT[i]
            {
                return false;
            }
        }

        return true;

    }
}
