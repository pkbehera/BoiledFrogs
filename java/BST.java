//Binary trees
public class BST {
  static class Node {
    int data;
    Node left = null;
    Node right = null;
    Node(int data) {
      this.data = data;
    }
  }

  //Find height of the tree
  static int height(Node root) {
    if (root == null) {
      return -1;
    }
    int l = height(root.left);
    int r = height(root.right);
    return l > r ? l + 1 : r + 1;
  }

  private static boolean print(Node root, int level) {
    if (root == null) {
      return false;
    }
    if (level == 0) {
      System.out.print(root.data + " ");
      return true;
    }
    boolean l = print(root.left, level - 1);
    boolean r = print(root.right, level - 1);
    return l || r;
  }

  private static boolean printSpiral(Node root, int level, boolean l2r) {
    if (root == null) {
      return false;
    }
    if (level == 0) {
      System.out.print(root.data + " ");
      return true;
    }
    if (l2r) {
      boolean l = printSpiral(root.left, level - 1, l2r);
      boolean r = printSpiral(root.right, level - 1, l2r);
      return l || r;
    } else {
      boolean r = printSpiral(root.right, level - 1, l2r);
      boolean l = printSpiral(root.left, level - 1, l2r);
      return l || r;
    }
  }

  static void spiralOrder(Node root) {
    int i = 0;
    while (printSpiral(root, i++, i % 2 == 0)) {
      System.out.println();
    }
  }

  //Level order traversal, breadth first
  static void levelOrder(Node root) {
    /*int h = height(root);
    for (int i = 0; i <= h; i++) {
      print(root, i);
      System.out.println("");
    }*/
    int i = 0;
    while (print(root, i++)) {
      System.out.println();
    }
  }

  //Mirror a binary tree
  static void mirror(Node root) {
    if (root == null) {
      return;
    }
    Node t = root.left;
    root.left = root.right;
    root.right = t;
    mirror(root.left);
    mirror(root.right);
  }
  
  public static void main(String[] args) {
    Node root = new Node(4);
    root.left = new Node(2);
    root.right = new Node(6);
    root.left.left = new Node(1);
    root.left.right = new Node(3);
    root.right.left = new Node(5);
    root.right.right = new Node(7);
    System.out.println("Level Order");
    levelOrder(root);
    mirror(root);
    System.out.println("Level Order after mirror");
    levelOrder(root);
    mirror(root);
    System.out.println("Level Order after another mirror");
    levelOrder(root);
    System.out.println("Spiral Order");
    spiralOrder(root); 
  }
}
