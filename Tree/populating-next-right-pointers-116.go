/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connectNode(node *Node, parent *Node) {
    if node == nil {
        return
    }

    if node == parent.Left {
        node.Next = parent.Right
    } else {
        uncle := parent.Next
        if uncle != nil {
            node.Next = uncle.Left
        }
    }
    connectNode(node.Left, node)
    connectNode(node.Right, node)
}

func connect(root *Node) *Node {
    if root == nil {
        return nil
    }

	root.Next = nil
    connectNode(root.Left, root)
    connectNode(root.Right, root)
    return root
}
