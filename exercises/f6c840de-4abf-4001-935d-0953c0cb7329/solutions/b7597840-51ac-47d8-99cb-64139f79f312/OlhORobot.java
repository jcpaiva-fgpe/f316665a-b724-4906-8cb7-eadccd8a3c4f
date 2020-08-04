import java.util.Scanner;


public class OlhORobot {

	public static void main(String args[]) {
		
		Scanner stdin = new Scanner(System.in);
		int x,y, move, time, start = 0 , end = 0;
		
		for(int robot=1; robot<=2; robot++) {
			x = stdin.nextInt();
			y = stdin.nextInt();
			time = 0;
			while((move=stdin.nextInt()) != 0) {
				time ++;
				switch(move) {
				case 2: y -= 1; break;
				case 8: y += 1; break;
				case 4: x -= 1; break;
				case 6: x += 1; break;
				case 5: break;
				}
			    if( x==0 && y== 0) {
				 if(robot==1) {
					 if(start == 0)
						 start = time;
					 end = time;
				 } else {
					 /* robot == 2 */
					 if(time >= start && time <= end) {
						 System.out.println("KO");
						 System.exit(0);
					 }
						 
				 }
			    }
			 }
		}
		System.out.println("OK");
	}
}
