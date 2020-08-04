import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Abobadeira {
	
	
	
	public static void main(String[] args) {
		process(System.in,System.out);
	}

	static void process(InputStream in, PrintStream out) {
		try(Scanner sin = new Scanner(in)) {
		
		int n = sin.nextInt();
		int m = sin.nextInt();
				int p[] = new int[n];
		int max = 0;
		
		for(int i=0; i< m; i++) {
			int s = 0;
			for(int j=0; j< n; j++) 
				s += sin.nextInt();
			
			int r = s % n;
			for(int j=0; j< n; j++)
				if(j == r) {
					p[j]++;
					if(p[j] > max)
						max = p[j];
				}
			
		}
		
		for(int j=0; j< n; j++)
			out.println(p[j]);
		out.println("");
		for(int j=0; j< n; j++)
			if(p[j] == max)
				out.println(j);
		}
	}

}
