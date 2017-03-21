public class Fact {
	public static void main(String[] args) {
		int n = Integer.valueOf(args[0]);
		long start = System.nanoTime();
		long fd = fact_d(n);
		long td = System.nanoTime() - start;
		System.out.print("fact_d(" + n + "): " + fd + " Time: " + td);
		start = System.nanoTime();
		long fr = fact_r(n);
		long tr = System.nanoTime() - start;
		System.out.println(" fact_r(" + n + "): " + fr + " Time: " + tr);
	}

	static long fact_r(int n) {
		if (n == 0) {
			return 1;
		}
		return n * fact_r(n - 1);
	}

	static long fact_d(int n) {
		if (n == 0) {
			return 1;
		}
		long fact = 1;
		for (int i = 1; i <= n; i++) {
			fact *= i;
		}
		return fact;
	}
}