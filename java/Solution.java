public class Solution {
  static class Node {
    int data;
    Node next = null;
    Node(int d, Node p) {
      data = d;
      if (p != null) {
        p.next = this;
      }
    }
  }
  static Node rreverse(Node h) {
    if (h == null) {
      return null;
    }
    if (h.next == null) {
      return h;
    }
    Node f = h;
    Node r = reverse1(h.next);
    f.next.next = f;
    f.next = null;
    return r;
  }
  static Node reverse(Node head) {
    Node p = null;
    Node c = head;
    Node n = null;
    while (c != null) {
      n = c.next;
      c.next = p;
      p = c;
      c = n;
    }
    head = p;
    return head;
  }

  static void print(Node h) {
    Node c = h;
    while (c != null) {
      System.out.println(c.data);
      c = c.next;
    }
  }
  static void printr(Node h) {
    if (h == null) {
      return;
    }
    printr(h.next);
    System.out.println(h.data);
  }
  public static void main(String[] args) {
    Node h = new Node(1, null);
    Node n1 = new Node(2, h);
    Node n2 = new Node(3, n1);
    Node n3 = new Node(4, n2);
    print(h);
    //h = reverse(h);
    //System.out.println("--------");
    //print(h);
    //System.out.println("--------");
    //printr(h);
    //System.out.println("--------");
    h = rreverse(h);
    print(h);
  }
}
