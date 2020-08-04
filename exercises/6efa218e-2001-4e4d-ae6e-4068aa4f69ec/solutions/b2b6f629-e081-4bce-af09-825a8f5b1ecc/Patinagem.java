import java.util.Scanner;


public class Patinagem {
	
	Scanner in = new Scanner(System.in);
	
	Patinagem() {
		
		int n = in.nextInt();
		
		int max = 0;
		int min = 100;
		
		int countMax = 0;
		int countMin = 0;
		
		int sum = 0;
		
		for(int i=0; i<n; i++) {
			int v = in.nextInt();
			sum += v;
			if(v > max) {
				max = v;
				countMax = 0;
			}
			if(v == max)
				countMax++;
			
			if(v < min) {
				min = v;
				countMin = 0;
			}
			if(v == min)
				countMin++;
		}
		
		if(countMax == 1) {
			sum -= max;
			n--;
		}
		if(countMin == 1) {
			sum -= min;
			n--;
		}

		int average = sum / n;
		System.out.println(average);
	}
	
	
	public static void main(String... strings) {
		new Patinagem();
	}

}
