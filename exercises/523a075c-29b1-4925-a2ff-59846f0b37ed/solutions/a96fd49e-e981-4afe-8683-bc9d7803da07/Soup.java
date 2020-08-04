import java.util.Scanner;

public class Soup {

	public static void main(String[] args) {
		new Soup();
	}

	Scanner in = new Scanner(System.in);
	
	Soup() {
		int n = in.nextInt();
		int m = in.nextInt();
		
		char soup[][] = new char[n+1][m+1];
		
		for(int i=1; i<=n; i++) {
			String line = in.next();
			for(int j=1; j<=m; j++)
				soup[i][j] = line.charAt(j-1);
		}
		
		int k = in.nextInt();
		for(int c=0; c<k; c++) {
			String word = in.next();
			
			for(int i=1; i<=n; i++)
				for(int j=1; j<=m; j++)
					for(int di= -1; di<=1 ; di++)
						for(int dj= -1; dj <=1; dj++) {
							if(di == 0 && dj == 0)
								continue;
							int t, ri=0, rj=0;
							for(t=0; t<word.length(); t++) {
								ri = i+di*t;
								rj = j+dj*t;
								
								if(
									ri < 1 || ri > n ||
									rj < 1 || rj > m ||
									soup[ri][rj] != word.charAt(t)
								) break;
							}
							if(t == word.length()) {
								System.out.println(i+" "+j+" "+ri+" "+rj);
								break;
							}
						}
		}
	}
		
}
