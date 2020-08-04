import java.util.Scanner;

public class Thermometer {

	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		float minT, maxT, minR, maxR, temp, corr;
		
		minT = in.nextFloat();
		maxT = in.nextFloat();
		
		minR = in.nextFloat();
		maxR = in.nextFloat();
		
		while((temp = in.nextFloat()) < 100.0) {
			corr = minR + (maxR-minR)/(maxT-minT)*(temp-minT);
			System.out.printf("%.1f\n",corr);
		}
	}
}
