package Three;

import java.util.Scanner;

class TreeNode{
	int value;
	TreeNode next;
	
	public TreeNode(int value) {
		this.value = value;
	}
}
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		TreeNode head = new TreeNode(-1);
		TreeNode head2 = head;
		while(n != 0) {
			TreeNode node = new TreeNode(n);
			head.next = node;
			head = node;
			n = sc.nextInt();
		}
		print(head2.next);
		reverse(head2);
		print(head2.next);
	}

	private static void reverse(TreeNode phead) {
		TreeNode first = phead.next;
		TreeNode next = first.next;
		while(first.next != null) {
			first.next = next.next;
			next.next = phead.next;
			phead.next = next;
			next = first.next;
		}
	}

	private static void print(TreeNode head) {
		while(head != null) {
			System.out.println(head.value);
			head = head.next;
		}
	}
}
