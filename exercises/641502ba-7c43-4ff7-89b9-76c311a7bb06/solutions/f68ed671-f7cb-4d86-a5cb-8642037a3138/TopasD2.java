
import java.util.*;

class TopasD2 {
    public static void main(String args[]) {
	Scanner in= new Scanner(System.in);

	int n= in.nextInt();
	int minLoc, maxLoc, min, max, amp, ampMin,ampMax;
	int t0,t1,t2;
	boolean cresce=true;

	t0=t1=t2= in.nextInt();
	min=max=minLoc=maxLoc= t0;
	ampMax=-100;
	ampMin=100;
	int i= 1;
	while (i < n) {
	    // subidas ou patamares
	    while (i<n && (t1= in.nextInt())>=t0) {i++; t0= t1;}
	    if (i<n) {
		maxLoc= t0;
		if (maxLoc>max) max= maxLoc;
		i++;
		amp=maxLoc-minLoc;
		if (amp<ampMin)
		    ampMin= amp;
		if (amp>ampMax)
		    ampMax= amp;	    
		t0= t1;
		cresce= false;
	    }
	    // descidas ou patamares
	    while (i<n && (t1= in.nextInt())<=t0) {i++; t0= t1;}
	    if (i<n) {
		minLoc= t0;
		if (minLoc<min) min= minLoc;
		i++;
		amp=maxLoc-minLoc;
		if (amp<ampMin)
		    ampMin= amp;
		if (amp>ampMax)
		    ampMax= amp;
		cresce= true;
		t0= t1;
	    }
	}
	if (cresce==true)
	    maxLoc= t1;
	else
	    minLoc= t1;
	if (t1<min) {
	    min= t1;
	}
	else if (t1>max) {
	    max= t1;
	}
	amp=maxLoc-minLoc;
	if (amp<ampMin)
	    ampMin= amp;
	else if (amp>ampMax)
	    ampMax= amp;
	System.out.println(max+" "+min+" "+ampMax+" "+ampMin);
    }
}