import java.util.Hashtable;
import java.util.Scanner;

public class MotorWaySensors {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int length = in.nextInt();
		long time, lastTime = -100L;
		String type;
		Hashtable<String, Integer> count = new Hashtable<String, Integer>();
		Hashtable<String, Long> last = new Hashtable<String, Long>();

		count.put("P", 0);
		count.put("L", 0);
		count.put("I", 0);
		last.put("P", -100L);
		last.put("L", -100L);
		for (int i = 0; i < length; i++) {
			time = in.nextLong();
				type = in.next();		
			if (time - last.get(type) < 10) {
				if (lastTime != time) {
					count.put("I", count.get("I") + 1);
				}
			} else {
				count.put(type, count.get(type) + 1);
				if (lastTime == time )
					count.put("I", count.get("I") - 1);
			} 
			lastTime = time;
			last.put(type, time);
		}

		System.out.println(count.get("L"));
		System.out.println(count.get("P"));
		System.out.println(count.get("I"));
	}
}
