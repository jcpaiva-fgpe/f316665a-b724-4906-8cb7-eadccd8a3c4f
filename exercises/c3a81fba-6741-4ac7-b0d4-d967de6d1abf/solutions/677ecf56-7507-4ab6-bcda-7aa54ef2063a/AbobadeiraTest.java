import static org.junit.Assert.assertEquals;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Random;

import org.junit.Test;

public class AbobadeiraTest {

	private final TestCase testCase1 = new TestCase(
			"2 4\n0 0\n0 1\n1 0\n1 1\n","2\n2\n\n0\n1\n");
	private final TestCase testCase2 = new TestCase(
			"3 5\n0 1 2\n2 1 0\n0 0 0\n1 1 2\n0 2 0\n","3\n1\n1\n\n0\n");
			
			
	@Test
	public void simpleTests() {
		assertEquals(testCase1.output,process(testCase1.input));
		assertEquals(testCase2.output,process(testCase2.input));
	}
	
	@Test
	public void generatedTests() {
		
		for(int i=0; i< 10; i++) {
			TestCase testCase = generate();
			
			assertEquals(testCase.output,process(testCase.input));
		}
		
	}
	
	@Test
	public void generateTestCases() throws IOException {
		int t=1;
		
		testCase1.serialize(t++);
		testCase2.serialize(t++);
		
		for(; t<10; t++) {
			generate().serialize(t++);
		}
	}
	
	
	String process(String data) {
		InputStream in = new ByteArrayInputStream(data.getBytes());
		ByteArrayOutputStream stream = new ByteArrayOutputStream();
		PrintStream out = new PrintStream(stream);
		
		Abobadeira.process(in,out);
		
		return new String(stream.toByteArray());
	}
	
	
	class TestCase {
		String input;
		String output;
		
		public TestCase(String input, String output) {
			super();
			this.input = input;
			this.output = output;
		}
		
		void serialize(int n) throws IOException {
			Files.write(Paths.get("in"+n+".txt"),input.getBytes());
			Files.write(Paths.get("out"+n+".txt"),output.getBytes());
		}
	}
	
	private static final Random RANDOM = new Random();
	
	
	private TestCase generate() {
		StringBuilder input = new StringBuilder();
		StringBuilder output = new StringBuilder();
		
		int n = RANDOM.nextInt(100);
		int m = RANDOM.nextInt(100);
		
		input.append(n);
		input.append(' ');
		input.append(m);
		input.append('\n');
		
		int p[] = new int[n];
		for(int i=0; i<m; i++) {
			int s = 0;
			boolean first = true;
			
			for(int j=0; j<n; j++) {
				int e = RANDOM.nextInt(n);
	
				if(first)
					first = false;
				else
					input.append(' ');
				input.append(e);
				
				s += e;
			}
			int r = s % n;
			p[r]++;
			input.append('\n');
		}
		
		int max = 0;
		for(int j=0; j<n; j++) {
			if(p[j] > max)
				max = p[j];
			
			output.append(p[j]);
			output.append('\n');
		}
		output.append('\n');
		for(int j=0; j<n; j++) 
			if(p[j] == max) {
				output.append(j);
				output.append('\n');
			}
		
		return new TestCase(input.toString(),output.toString());
	}
	
}
