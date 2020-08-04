/**
 * PadeiroViajante.java created on 2010/04/21
 * Copyright 2008 Computer Laboratory Univ Cambridge (CL). All rights reserved.
 * 
 * CL grants you ("Licensee") a non-exclusive, royalty free, license
 * to use, modify and redistribute this software in source and binary
 * code form, provided that i) this copyright notice and license appear
 * on all copies of the software; and ii) Licensee does not utilize the
 * software in a manner which is disparaging to CL.
 * 
 * This software is provided "AS IS," without a warranty of any kind.
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED. SUN AND
 * ITS LICENSORS SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
 * LICENSEE AS A RESULT OF USING, MODIFYING OR DISTRIBUTING THE
 * SOFTWARE OR ITS DERIVATIVES. IN NO EVENT WILL CL OR ITS LICENSORS
 * BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA, OR FOR DIRECT,
 * INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES,
 * HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING
 * OUT OF THE USE OF OR INABILITY TO USE SOFTWARE, EVEN IF SUN HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * 
 */

// package topas;

import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.Scanner;
import java.util.Stack;

/**
 * @author pbrandao
 *
 */
public class PadeiroViajante {
	/**
	 * Se as direcções a dar são relativas (esquerda, dta) ou absolutas (sempre N, S, E,
	 * W)
	 */
	public final static boolean DIR_REL = true;
//	public final static String START_PT = "(2,1)";
//	public final static String END_PT = START_PT;
	public final static short  DIR_N = 0;
	public final static short  DIR_S = 1;
	public final static short  DIR_E = 2;
	public final static short  DIR_W = 3;
	public final static short  DIR_STOP = 4;
	public final static short  DIR_CONT = 5;
	public final static int PADARIA_X = 4;
	public final static int PADARIA_Y = 5;

	public static final String SEP_DIR = "";
	public static final String SEP_PERC = "\n";

	public short dir_corr = 2;
	
	public final static String DIRECCOES[] = {"norte,", "sul,","este,","oeste,","S","F"};

	public final static String DIRECCOES_REL[][] = {
				{"F","I","D", "E"},
				{"I", "F","E","D"},
				{"E","D","F","I"},
				{"D", "E","I","F"}
				};

	public class Coordenadas {
		public int x;
		public int y;
		/**
		 * @param coord
		 */
		public Coordenadas(String coord) {
			coord = coord.substring(1, coord.length()-1);
			String xy[] = coord.split(",");
			x = Integer.valueOf(xy[0]);
			y = Integer.valueOf(xy[1]);
		}
		/**
		 * @param xCoord
		 * @param yCoord
		 */
		public Coordenadas(int xCoord, int yCoord) {
			x = xCoord;
			y = yCoord;

		}
		/**
		 * @param out
		 */
		public void print(PrintStream out) {
			out.print("("+x+","+y+")");
		}
		
	}
	public class Percurso {
		Coordenadas pontoFinal = null; 
		void adicPontoInicio(Coordenadas pontoInicio){
			pontos.addFirst(pontoInicio);
		}
		void adicPontoFinal(Coordenadas pontoFinal){
			pontos.addLast(pontoFinal);
			this.pontoFinal = pontoFinal;
		}
		
		ArrayDeque<Coordenadas> pontos = new ArrayDeque<Coordenadas>();
		/**
		 * @param linha 
		 * 
		 */
		public Percurso(String linha) {
			for (String coordSt : linha.split(";"))
			{
				Coordenadas coord= new Coordenadas(coordSt);
				pontos.add(coord);
				pontoFinal = coord;
			}
		}
		/**
		 * @param scan
		 */
		public Percurso(Scanner scan) {
			int nrDePontos = scan.nextInt();
			for (int i = 0; i <nrDePontos; i++){
				Coordenadas coord= new Coordenadas(scan.nextInt(),scan.nextInt());
				pontos.add(coord);
				pontoFinal = coord;
			}
			
		}
		public void printCourse(PrintStream out){
			for (Coordenadas coord : pontos)
			{
				coord.print(out);
			}
		}
		/**
		 * @return
		 */
		public Coordenadas pontoFinal() {
			return pontoFinal;
		}
		public StringBuffer printDireccoesRel() {
			Coordenadas posCor = pontos.removeFirst();
			Coordenadas posSeg = null;
			StringBuffer direccoes = new StringBuffer();

			while (!pontos.isEmpty())
			{
				posSeg = pontos.removeFirst();
				direccoes.append(printPontoSegRel(posCor, posSeg));
				posCor = posSeg;
			}
			return direccoes;	
		}
		/**
		 * @param posCor
		 * @param posSeg
		 * @param direccoes
		 */
		private StringBuffer printPontoSegAbs(Coordenadas posCor, Coordenadas posSeg) {
			StringBuffer direccoes = new StringBuffer();
			int coord1=0,coord2=0;
			if(posCor.x == posSeg.x) //movimento no eixo y
			{
				if(posCor.y > posSeg.y) {
					coord1 = posSeg.y;
					coord2 = posCor.y;
					dir_corr = DIR_N;
				}					
				else{
					coord2 = posSeg.y;
					coord1 = posCor.y;
					dir_corr = DIR_S;
				}					
			}
			else if(posCor.y == posSeg.y) //movimento no eixo x
				if(posCor.x > posSeg.x){
					coord1 = posSeg.x;
					coord2 = posCor.x;
					dir_corr = DIR_W;
				}					
				else{
					coord2 = posSeg.x;
					coord1 = posCor.x;
					dir_corr = DIR_E;
				}					
			direccoes.append(printDir(coord1, coord2, DIRECCOES[dir_corr]));
			return direccoes;
		}
		
		private StringBuffer printPontoSegRel(Coordenadas posCor, Coordenadas posSeg) {
			StringBuffer direccoes = new StringBuffer();
			int coord1=0,coord2=0;
			int dir_anterior = dir_corr;
			if(posCor.x == posSeg.x) //movimento no eixo y
			{
				if(posCor.y > posSeg.y) {
					coord1 = posSeg.y;
					coord2 = posCor.y;
					dir_corr = DIR_N;
				}					
				else{
					coord2 = posSeg.y;
					coord1 = posCor.y;
					dir_corr = DIR_S;
				}					
			}
			else if(posCor.y == posSeg.y) //movimento no eixo x
				if(posCor.x > posSeg.x){
					coord1 = posSeg.x;
					coord2 = posCor.x;
					dir_corr = DIR_W;
				}					
				else{
					coord2 = posSeg.x;
					coord1 = posCor.x;
					dir_corr = DIR_E;
				}					
			direccoes.append(printDir(coord1, coord2, DIRECCOES_REL[dir_anterior][dir_corr]));
			return direccoes;
		}
		public StringBuffer printDireccoes() {
			if(DIR_REL)
				return printDireccoesRel();
			else
				return printDireccoesAbsol();
		}
		/**
		 * @return 
		 * 
		 */
		public StringBuffer printDireccoesAbsol() {
			Coordenadas posCor = pontos.removeFirst();
			Coordenadas posSeg;
			StringBuffer direccoes = new StringBuffer(); 
			while (!pontos.isEmpty())
			{
				posSeg = pontos.removeFirst();
				direccoes.append(printPontoSegAbs(posCor, posSeg));
				posCor = posSeg;
			}	
			return direccoes;
		}
		/**
		 * @param x
		 * @param x2
		 * @param string
		 * @return
		 */
		private StringBuffer printDir(int x, int x2, String dir) {
			int vezes = (x2-x)/2 - 1;
			StringBuffer aux = new StringBuffer();
			aux.append(dir+SEP_DIR);
			for (int i = 0; i < vezes; i++)
			{
				aux.append(DIRECCOES[DIR_CONT]+SEP_DIR);
			}
			return aux;
		}
		/**
		 * @return
		 */
		public Coordenadas removerInicio() {
			return pontos.removeFirst();
		}
	}
	/**
	 * @param args
	 */
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		PadeiroViajante padeiro = new PadeiroViajante();
		
		Scanner scan = new Scanner(System.in);
		Stack<Percurso> percursos = new Stack<Percurso>();

		int nrDePercursos = scan.nextInt();
		int percursoNr = 0;
		for (;percursoNr < nrDePercursos;percursoNr++) {
			percursos.add(padeiro.new Percurso(scan));
		}

		//tratar os percursos
//		Coordenadas start = padeiro.new Coordenadas(START_PT);
		Coordenadas start =  padeiro.new Coordenadas(PADARIA_X,PADARIA_Y);
//		Coordenadas end = padeiro.new Coordenadas(END_PT);
//		percursos.get(percursos.size()-1).adPontoFinal(end);
		for (Percurso percurso : percursos)
		{
			percurso.adicPontoInicio(start);
			System.out.print(percurso.printDireccoes()+DIRECCOES[DIR_STOP]+SEP_PERC);
			start = percurso.pontoFinal();
		}
	}

}
