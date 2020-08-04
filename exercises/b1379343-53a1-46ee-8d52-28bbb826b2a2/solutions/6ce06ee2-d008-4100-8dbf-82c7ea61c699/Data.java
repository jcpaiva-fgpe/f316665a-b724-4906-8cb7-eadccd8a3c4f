import java.util.Scanner;


public class Data {
	
	int table[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	
	
	public int dayOfWeek(int year, int month, int day) {
		
		if (month < 3)
			year--;
		
		return ( year + year/4 - year/100 + year/400 + table[month-1] + day ) % 7;
		
	}
	
	public int dayOfWeekInMay(int year, int day) {
		int sum = year + year/4 - year/100 + year/400 + day;
		
		return sum % 7;
	}
	
	public int dayOfTopas(int year) {
		
		int week = dayOfWeekInMay(year,1);
		
		if(week == 0)
			return 6;
		else
			return (7-week) + 6;
	}
	
	
	public static void main(String...strings) {
		Data data = new Data();
		
		Scanner in = new Scanner(System.in);
		int year = in.nextInt();
		System.out.println(data.dayOfTopas(year));
	}

}
