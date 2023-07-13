/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func listToNode(head *ListNode, cnt int) *TreeNode {
    switch(cnt) {
    case 0:
        return nil
    case 1:
        return &TreeNode {
            Val: head.Val,
            Left: nil,
            Right: nil,
        }
    }

    m := cnt / 2
    tmp := head
    for i := 0; i < m-1; i++ {
        tmp = tmp.Next
    }

    mid := tmp.Next
    root := mid.Val

    tmp.Next = nil
    tmp = mid.Next
    mid.Next = nil

    return &TreeNode {
        Val: root,
        Left: listToNode(head, m),
        Right: listToNode(tmp, cnt-m-1),
    }
}

func sortedListToBST(head *ListNode) *TreeNode {
    cnt := 0
    for tmp := head; tmp != nil; tmp = tmp.Next {
        cnt += 1
    }
    return listToNode(head, cnt)
}
