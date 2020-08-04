import java.util.Scanner;


public class Lifts {


	private static Scanner stdin = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int ac = stdin.nextInt();
		int s1 = stdin.nextInt();
		int s2 = stdin.nextInt();
		
		System.out.println(chama(ac,s1,s2));
	}
	
	public static int chama(int ac, int s1, int s2) {
		int d1 = Math.abs(ac - s1);
		int d2 = Math.abs(ac - s2);
		
		if(s1 == 999) {
			if(s2 == 999)
				return 0;
			else
				return 2;
		} else {
			if(s2 == 999)
				return 1;
			else  {
				if(d1 == d2)  {
					if(s1 == s2)
						return 1;
					else if(s1 > s2)
						return 1;
					else 
						return 2;	
				} else if(d1 < d2)
					return 1;
				else 
					return 2;
			}
		}	
	}
}
