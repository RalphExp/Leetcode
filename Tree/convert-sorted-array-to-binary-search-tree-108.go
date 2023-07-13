/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
    length := len(nums)
    if length == 0 {
        return nil
    }

    return &TreeNode {
        Val: nums[length/2],
        Left: sortedArrayToBST(nums[:length/2]),
        Right: sortedArrayToBST(nums[length/2+1:]),
    }
}
