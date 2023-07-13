func buildTree(inorder []int, postorder []int) *TreeNode {
    length := len(inorder)

    if length == 0 {
        return nil
    }

    root := postorder[length-1]
    i := 0
    for ; i < length; i++ {
        if inorder[i] == root {
            break
        }
    }

    return &TreeNode {
        Val: root,
        Left : buildTree(inorder[:i], postorder[:i]),
        Right : buildTree(inorder[i+1:], postorder[i:length-1]),
    }
}
