import java.util.Scanner;

public class BinaryTree {
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    Scanner in = new Scanner(System.in);
    private Node root;

    BinaryTree() {
        root = null;
    }

    public class Node {
        int data;
        Node left, right;

        Node (int data) {
            this.data = data;
            left = right = null;
        }
    }

    public Node buildTree() {
        int n = in.nextInt();
        if (n == -1)
            return null;
        
        root = new Node(n);
        root.left = buildTree();
        root.right = buildTree();

        System.out.println(root.data);
        return root;
    }

    public void preOrderTraversal(Node root) {
        if (root == null)
            return;
        
        // Root --> Left --> Right
        System.out.print(root.data + " -> ");
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);
    }

    public void inOrderTraversal(Node root) {
        if (root == null)
            return;
        
        // Left --> Root --> Right
        inOrderTraversal(root.left);
        System.out.print(root.data + " -> ");
        inOrderTraversal(root.right);
    }

    public void postOrderTraversal(Node root) {
        if (root == null)
            return;
        
        // Left --> Right --> Root
        postOrderTraversal(root.left);
        postOrderTraversal(root.right);
        System.out.print(root.data + " -> ");
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = tree.buildTree();
        System.out.println("PostOrder Traversal:");
        tree.preOrderTraversal(tree.root);
        System.out.println("\nPreOrder Traversal:");
        tree.postOrderTraversal(tree.root);
        System.out.println("\nInOrder Traversal:");
        tree.inOrderTraversal(tree.root);
        System.out.println();
    }
}