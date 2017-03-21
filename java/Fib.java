public class Fib {
	static long fib_r(int n) {
		if (n < 2) {
			return n;
		}
		return fib_r(n - 1) + fib_r(n - 2);
	}

	static long fib_d(int n) {
		if (n < 1) {
			return n;
		}
		long a = 0l;
		long b = 1l;
		long c = a + b;
		for (int i = 1; i < n; i++) {
			a = b;
			b = c;
			c = a + b;
		}
		return b;
	}

	public static void main(String[] args) {
		int c = Integer.valueOf(args[0]);
		for (int i = 0; i < c; i++) {
			long start = System.nanoTime();
			long fd = fib_d(i);
			long td = System.nanoTime() - start;
			System.out.print("fib_d(" + i + "): " + fd + " Time: " + td);
			start = System.nanoTime();
			long fr = fib_r(i);
			long tr = System.nanoTime() - start;
			System.out.println(" fib_r(" + i + "): " + fr + " Time: " + tr);
		}
	}
}
