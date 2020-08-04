import java.util.Scanner;


public class Strong {

	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		StringBuffer challenge = new StringBuffer(in.nextLine()) ;
		char t;
		
		for(int i=0; i< challenge.length() / 2; i ++) {
			t = challenge.charAt( 2*i );
			challenge.setCharAt( 2*i, challenge.charAt(2*i+1));
			challenge.setCharAt( 2*i+1 , t);
		}
		
		System.out.println(challenge);
	}

	
	
	
	
}
