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
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut values: Vec<i32> = vec![];
        Self::inorder_traversal_inner(root, &mut values);
        values
    }

    pub fn inorder_traversal_inner(root: Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
        let Some(root) = root else {return};

        Self::inorder_traversal_inner(root.borrow_mut().left.take(), v);
        v.push(root.borrow().val);
        Self::inorder_traversal_inner(root.borrow_mut().right.take(), v);
    }
}
