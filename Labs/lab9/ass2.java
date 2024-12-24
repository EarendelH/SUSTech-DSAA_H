import java.util.Scanner;

class Node {
    int key;
    int value;
    Node left;
    Node right;

    Node(int k, int v) {
        key = k;
        value = v;
        left = null;
        right = null;
    }
}

public class Main {
    public static Node insert(Node root, int key, int value) {
        if (root == null) return new Node(key, value);
        if (key < root.key) root.left = insert(root.left, key, value);
        else if (key > root.key) root.right = insert(root.right, key, value);
        return root;
    }

    public static Node find(Node root, int key) {
        if (root == null || root.key == key) return root;
        if (key < root.key) return find(root.left, key);
        return find(root.right, key);
    }

    public static void modify(Node root, int key, int newValue) {
        Node node = find(root, key);
        if (node != null) node.value = newValue;
    }

    public static int sumOfValue(Node root) {
        if (root == null) return 0;
        return root.value + sumOfValue(root.left) + sumOfValue(root.right);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int K = in.nextInt();
        Node root = null;
        for (int i = 0; i < K; ++i) {
            String s = in.next();
            if (s.equals("insert")) {
                int key = in.nextInt();
                int value = in.nextInt();
                root = insert(root, key, value);
            } else if (s.equals("modify")) {
                int key = in.nextInt();
                int newValue = in.nextInt();
                modify(root, key, newValue);
            } else if (s.equals("sum")) {
                int key = in.nextInt();
                Node node = find(root, key);
                if (node != null) System.out.println(sumOfValue(node));
            }
        }
    }
}