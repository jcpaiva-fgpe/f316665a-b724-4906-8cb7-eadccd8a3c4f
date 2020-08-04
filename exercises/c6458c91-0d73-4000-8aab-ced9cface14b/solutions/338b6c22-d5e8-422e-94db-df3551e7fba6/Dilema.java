import java.util.Scanner;

public class Dilema {

	static final int[] oneZero = { 1, 0 };
	static final int[] zeroOne = { 0, 1 };
	private static Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {
		int gain[][][] = new int[2][2][2];
		int total[] = new int[2];
		
		// read in gain matrix and initialize totals
		for(int line:oneZero) {
			for(int column:oneZero)
				for(int part:zeroOne)
					gain[line][column][part] = stdin.nextInt();
		    total[line] = 0;
		}
		//read in number of matches
		int n = stdin.nextInt();
		// read in matches and accumulate totals
		for(int c=0; c<n; c++) {
			int j0 = stdin.nextInt();
			int j1 = stdin.nextInt();
			
			for(int part:zeroOne)
				total[part] += gain[j0][j1][part];
		}
		// print results
		if(total[0] == total[1]) 
			System.out.println("AB "+total[0]);
		else {
			if(total[0] > total[1]) { // A > B
				System.out.println("A "+total[0]);
				System.out.println("B "+total[1]);
			} else { // B > A 
				System.out.println("B "+total[1]);
				System.out.println("A "+total[0]);
				
			}
		}
		
	}

}
