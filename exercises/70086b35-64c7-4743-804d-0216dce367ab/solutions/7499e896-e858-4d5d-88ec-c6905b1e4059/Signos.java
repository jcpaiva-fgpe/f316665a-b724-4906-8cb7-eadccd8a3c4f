import java.util.Scanner;


public class Signos {

	static String[] signos = { "rato", "boi", "tigre", "coelho", "dragão", "serpente", "cavalo", "carneiro",
			 "macaco", "galo", "cão", "porco"};
	
	static int offset = 4; 
	
	public static String signoDoAno(int ano) {
		int signo;
		
		if(ano <0) ano++;
		
		ano -= offset;
		
		signo = ano % 12;
		
		if(signo < 0)
			signo += 12;
		
		return signos[signo];
	}
	
	public static void main(String args []) {		
		
		Scanner stdin = new Scanner(System.in);
		
		int ano = stdin.nextInt();
		
		System.out.println(signoDoAno(ano));
		
	}
	
}
