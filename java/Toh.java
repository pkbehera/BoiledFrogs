public class Toh {
	public static void main(String[] args) {
		toh(Integer.valueOf(args[0]), "A", "B", "C");
	}
	static int step = 0;
	static void toh(int n, String from, String to, String temp) {
		if (n == 1) {
			System.out.println(++step + ": Move disk#" + n + " " + from + " -> " + to);
		} else {
			toh(n - 1, from, temp, to);
			System.out.println(++step + ": Move disk#" + n + " " + from + " -> " + to);
			toh(n - 1, temp, to, from);
		}
	}
}
