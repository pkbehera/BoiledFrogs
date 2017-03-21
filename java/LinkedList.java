public class LinkedList {
  static class Node {
    int data;
    Node next;
    Node(int d) {
      data = d;
      next = null;
    }
  }

  //Traverse a linked list from the end
  static void rTraverse(Node head) {
    if (head == null) {
      return;
    }
    rTraverse(head.next);
    System.out.println(head.data);
  }

  //Reverse a linked list recursively
  static Node reverse(Node head) {
    if (head == null || head.next == null) {
      return head;
    }
    Node f = head;
    head = reverse(f.next);
    f.next.next = f;
    f.next = null;
    return head;
  }

  //Get kth node from end
  static int kthNode(Node head, int k) {
    Node c = head;
    Node t = head;
    while (k-- >= 0) {
      c = c.next;
    }
    while (c != null) {
      c = c.next;
      t = t.next;
    }
    return t.data;
  }

  static void print(Node head) {
    Node c = head;
    while (c != null) {
      System.out.println(c.data);
      c = c.next;
    }
  }

  public static void main(String[] args) {
    Node head = new Node(1);
    head.next = new Node(2);
    head.next.next = new Node(3);
    head.next.next.next = new Node(4);
    head.next.next.next.next = new Node(5);
    print(head);
    System.out.println();
    head = reverse(head);
    print(head);
    System.out.println();
    System.out.println(kthNode(head, 2));
    System.out.println();
    rTraverse(head);
  }
}
