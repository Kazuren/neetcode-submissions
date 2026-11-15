// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//     pub val: i32,
//     pub left: Option<Rc<RefCell<TreeNode>>>,
//     pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         TreeNode {
//             val,
//             left: None,
//             right: None,
//         }
//     }
// }

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut levels: Vec<Vec<i32>> = vec![];

        let Some(root) = root else { return levels; };

        let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::from([root]);

        while !queue.is_empty() {
            let mut level = vec![];

            for _ in 0..queue.len() {
                let node: Option<Rc<RefCell<TreeNode>>> = queue.pop_front();

                match node {
                    None => {}
                    Some(n) => {
                        level.push(n.borrow().val);
                        match n.borrow().left.clone() {
                            None => {}
                            Some(l) => {
                                queue.push_back(l);
                            }
                        }

                        match n.borrow().right.clone() {
                            None => {}
                            Some(r) => {
                                queue.push_back(r);
                            }
                        }
                    }
                }
            }

            levels.push(level);
        }
        return levels;
    }
}
