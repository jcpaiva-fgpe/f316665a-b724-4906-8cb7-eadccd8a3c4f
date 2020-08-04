

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class KenKen {
	
	int size;
	List<Restriction> restrictions;
	int[][] board;
	
	public KenKen(int size, List<Restriction> restrictions) {
		this.size=size;
		this.restrictions = restrictions;
	}
	
	static class Restriction {
		int value;
		char operation;
		List<Cell> cells = new ArrayList<Cell>(); 
		
		public Restriction(int value, char operation) {
			this.value = value;
			this.operation = operation;
		}
		
		void addCell(int line, int column) {
			cells.add(new Cell(line,column));
		}
	}
	
	static class Cell {
		int line;
		int column;
		
		public Cell(int line, int column) {
			super();
			this.line = line;
			this.column = column;
		}	
	}
	
	boolean solved() {
		return validLines() && validColumns() && validRestrictions();
	}
	
	boolean validLines() {
		for(int line=0; line<size; line++) 
			for(int column=0; column<size; column++)
				for(int cursor=column+1; cursor<size; cursor++)
					if(board[line][column] == board[line][cursor])
						return false;
		return true;
	}
	
	boolean validColumns() {
		for(int column=0; column<size; column++)
			for(int line=0; line<size; line++) 
				for(int cursor=line+1; cursor<size; cursor++)
					if(board[line][column] == board[cursor][column])
						return false;
		return true;
	}
	
	boolean validRestrictions() {				
		for(Restriction restriction: restrictions) {
			List<Integer> arguments = getArguments(board, restriction.cells);
			int value = operate(restriction.operation,arguments);
			
			if(restriction.value != value)
				return false;
		}
		return true;	
	}
	
	List<Integer> getArguments(int[][] board, List<Cell> cells) {
		ArrayList<Integer> arguments = new ArrayList<Integer>(cells.size());
		
		for(Cell cell:cells)
			arguments.add(board[cell.line][cell.column]);
		return arguments;
	}
	
	private int operate(char operation, List<Integer> arguments) {
		int value = -1;
		
		switch (operation) {
		case '*':
			value = 1;
			for(int arg: arguments)
				value *= arg;
			break;
		case '+':
			value = 0;
			for(int arg: arguments)
				value += arg;
			break;
		case '-':
			Collections.sort(arguments);
			value = arguments.get(1) - arguments.get(0);
			break;
		case '/':
			Collections.sort(arguments);
			value = arguments.get(1) / arguments.get(0);
			break;
		default:
			break;
		}
		
		return value;
	}


	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		
		int size = in.nextInt();
		int regions = in.nextInt();
		
		
		List<Restriction> restrictions= new ArrayList<Restriction>();

		for(int rn=0; rn < regions; rn++) {
			int cells = in.nextInt();
			int value = in.nextInt();
			char operation = in.next().charAt(0);
			
			Restriction restriction = new Restriction(value,operation);
			
			for(int cn=0; cn < cells; cn++) {
				int line = in.nextInt();
				int column = in.nextInt();
				
				restriction.addCell(line, column);
			}
			restrictions.add(restriction);
		}
		KenKen kenKen = new KenKen(size,restrictions);
	 
		int attempts = in.nextInt();
		for(int an=0; an < attempts; an++) {
			String name = in.next();
			int board[][] = new int[size][size];
			for(int row = size-1; row >=0; row--)
				for(int column=0; column<size; column++) 
					board[row][column] = in.nextInt();

			kenKen.board = board;
			
			System.out.print(name+": ");
			if(kenKen.solved())
				System.out.println("OK");
			else
				System.out.println("KO");
		}
			
		
	}

}
