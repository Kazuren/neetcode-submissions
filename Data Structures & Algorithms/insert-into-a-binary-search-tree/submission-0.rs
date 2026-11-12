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
    pub fn insert_into_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        let Some(root) = root else {
            return Some(Rc::new(RefCell::new(TreeNode::new(val))));
        };

        let binding = root.clone();
        let mut root = binding.borrow_mut();

        if val > root.val {
            root.right = Self::insert_into_bst(root.right.clone(), val);
        } else if val < root.val {
            root.left = Self::insert_into_bst(root.left.clone(), val);
        } 

        drop(root);
        Some(binding)
    }
}
