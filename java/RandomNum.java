import java.util.Random;

public class RandomNum {
	public static void main(String[] args) {
		int num = 1000;
		int max = 1;
		int lucky = 0;
		for (int i = 0; i < num; i++) {
			int rand = getRandomNumberInRange(0, max);
			//System.out.print(rand + " ");
			if (rand == max) {
				lucky++;
			}
		}
		System.out.print("\n" + "Lucky: " + lucky + ":  ");
		if (lucky > num / 2) {
			System.out.println("Go ahead!!");
		} else {
			System.out.println("Dont Do!!");
		}
	}

	private static int getRandomNumberInRange(int min, int max) {
		if (min >= max) {
			throw new IllegalArgumentException("max must be greater than min");
		}
		Random r = new Random();
		return r.nextInt((max - min) + 1) + min;
	}
}

