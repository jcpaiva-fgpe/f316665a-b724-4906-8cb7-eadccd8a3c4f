import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;

/**
 * @author Margarida Mamede
 */


public class Chemistry
{

    private BufferedReader formula;

    private char symbol;


    public Chemistry( BufferedReader theFormula )
    {
        formula = theFormula;
    }


    private void writeAndGoForward( PrintStream out ) throws IOException
    {
        out.print(symbol);
        symbol = (char) formula.read();
    }


    public void decompose( PrintStream out ) throws IOException
    {
        symbol = (char) formula.read();
        do 
            {
                // An element begins with an upper-case letter.
                this.writeAndGoForward(out);

                // There may be lower-case letters.
                while ( symbol >= 'a' && symbol <= 'z' )
                    this.writeAndGoForward(out);
                    
                out.print(" ");  

                if ( symbol >= '1' && symbol <= '9' )
                    // The number of atoms is given.
                    do
                        this.writeAndGoForward(out);
                    while ( symbol >= '0' && symbol <= '9' );
                else
                    // The number of atoms is 1.
                    out.print(1);  

                out.println();  
            }
        while ( symbol != '.' );
    }


    public static void main( String[] args ) throws IOException
    {
        BufferedReader input = 
            new BufferedReader( new InputStreamReader(System.in) );

        new Chemistry(input).decompose(System.out);

        input.close();
    }


}
