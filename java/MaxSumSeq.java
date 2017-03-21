public class MaxSumSeq {
	public static void main (String[] args) {
		MaxSumSeq m = new MaxSumSeq(args);
		System.out.println("Max Sum: " + m.maxSumSeq());
		System.out.println("Start: " + m.start);
		System.out.println("End: " + m.end);
	}

	MaxSumSeq(String[] args) {
		input = new int[args.length];
		int i = 0;
		for (String s : args) {
			input[i++] = Integer.valueOf(s);
		}
		end = i;
	}
	int[] input;
	int start = 0;
	int end = 0;

	int maxSumSeq() {
		int max_so_far = input[0];
		int cur_max = input[0];
		int cur_s = 0;
		int cur_e = 0;
		for (int i = 1; i < input.length; i++) {
			int sum = cur_max + input[i];
			if (sum > input[i]) {
				cur_max = sum;
				cur_e = i;
			} else {
				cur_max = input[i];
				cur_s = i;
				cur_e = i;
			}
			if (cur_max > max_so_far) {
				max_so_far = cur_max;
				start = cur_s;
				end = cur_e;
			}
		}
		return max_so_far;
	}
}
