import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class ransomNotes {

    // Complete the checkMagazine function below.
    static void checkMagazine(String[] magazine, String[] note) {
    		HashMap<String, Integer> mag=new HashMap();
    		int i;
    		if (magazine.length<note.length)
    			{System.out.println("No"); return;}

    		
    			for(i=0;i<magazine.length;++i){
    				mag.put( magazine[i], i);
    			
    			
    			}
    			for(i=0;i<note.length;++i){
    				if (mag.get(note[i])!=null)
    				{
    						mag.remove(note[i]);
    						continue;
    				}
    				else
    				{
    					System.out.println("No");
    					return;
    				}
    			}

    			System.out.println("Yes");
    		
    		


    }

 

    public static void main(String[] args) {
       
    	Scanner s = new Scanner(System.in);
       	 String m=s.nextLine();
       	 String n=s.nextLine();
       	 String[]magazine=m.split(" ");
       	 String[] note=n.split(" ");

        checkMagazine(magazine, note);

        s.close();
    }
}
