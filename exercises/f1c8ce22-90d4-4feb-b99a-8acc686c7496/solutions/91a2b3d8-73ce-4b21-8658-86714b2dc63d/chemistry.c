#include<stdio.h>


/*
 * @author Margarida Mamede
 */


void writeAndGoForward( char *character )
{
    printf("%c", *character);
    scanf("%c", character);
}


void decompose( )
{
    char symbol;

    scanf("%c", &symbol);
    do 
        {
	    // An element begins with an upper-case letter.
	    writeAndGoForward(&symbol);

	    // There may be lower-case letters.
	    while ( symbol >= 'a' && symbol <= 'z' )
	        writeAndGoForward(&symbol);
                    
	    printf(" ");  

	    if ( symbol >= '1' && symbol <= '9' )
	        // The number of atoms is given.
	        do
		    writeAndGoForward(&symbol);
		while ( symbol >= '0' && symbol <= '9' );
	    else
	        // The number of atoms is 1.
                printf("1");  

	    printf("\n");  
	}
    while ( symbol != '.' );
}


int main( )
{
    decompose();
    return 0;
}
