import java.util.*;
class RoverPos{
	static int Rover_x;
	static int Rover_y;
	static int Rover_z;
	static char Rover_orientation;
	static char []direction_array={'N','E','S','W'};

	RoverPos(int x, int y, int z, char o){
		Rover_x=x;
		Rover_y=y;
		Rover_orientation=o;
		Rover_z=z;
	}
	static void movement(String ins, int Plateau_x, int Plateau_y, int Plateau_z){
		int i;
		int len=ins.length();
			for(i=0;i<len;++i){

				if (ins.charAt(i)=='M'){ 
					Rover_x=moveInCurrentDirX(Rover_x,Rover_orientation);
					Rover_y=moveInCurrentDirY(Rover_y,Rover_orientation);
				}
						
				else if(ins.charAt(i)=='L' ){
					Rover_orientation=changeDirLeft(Rover_orientation); 
				}

				else if (ins.charAt(i)=='R'){
					Rover_orientation=changeDirRight(Rover_orientation); 
				}

				else if (ins.charAt(i)=='U' || ins.charAt(i)=='l'){
					Rover_orientation=ins.charAt(i);
					if (Rover_orientation=='U')
						Rover_z++;
					if (Rover_orientation=='l')
						Rover_z--;
				}

				else{
					System.out.println("error complining: wrong input. skipping the wrong variable "+ins.charAt(i));
				}

				Rover_x=checkLimit(Rover_x,Plateau_x);
				Rover_y=checkLimit(Rover_y,Plateau_y);
				Rover_z=checkLimit(Rover_z,Plateau_z);
			}
	}
	static int moveInCurrentDirX(int x, char o){
		switch(o){
			case 'E': 
				++x; 
				break;
			case 'W': 
				--x; 
				break;
		}
		return x;
	}
	static int moveInCurrentDirY(int y, char o){
		switch(o){
			case 'N': 
				++y;
				break;
			case 'S':
				--y;
				break;
		}
		return y;
	}
	static char changeDirLeft(char o){
		if (o=='U')
			o='W';
		else if (o=='l')
			o='E';
		else 
		{
			int i;
			for( i=0;i<3;++i)
				if (direction_array[i]==o)
					return direction_array[i+1];
			if (direction_array[i]==o)
				return direction_array[0];
		}
		return o;
	}
	static char changeDirRight(char o){
		if (o=='U')
			o='E';
		else if (o=='l')
			o='W';
		else
		{
			for(int i=1;i<4;++i)
				if (direction_array[i]==o)
					return direction_array[i-1];
			if (direction_array[0]==o)
				return direction_array[3];
		}
		return o;
	}
	static int checkLimit(int x, int limit){
		if (x<0)
			x=0;
		else if (x>limit)
			x=limit;

		return x;
	}

}

public class Rover{
	public static void main(String args[]){
		Scanner sc=new Scanner (System.in);

		int Plateau_x,Plateau_y,Plateau_z;
		Plateau_x=sc.nextInt();
		Plateau_y=sc.nextInt();
		Plateau_z=sc.nextInt();
		int no_of_rovers; 
		no_of_rovers=sc.nextInt();

		int res[][]=new int [no_of_rovers][3]; 
		char res_o[]=new char[no_of_rovers]; 

		int j;
		for(j=0;j<no_of_rovers;++j){
			
			int x,y,z;

			x=sc.nextInt();
			y=sc.nextInt();
			z=sc.nextInt();

			char o; 
			o=sc.next().charAt(0);

			RoverPos r=new RoverPos(x,y,z,o);

			String ins=sc.next();
			r.movement(ins, Plateau_x, Plateau_y, Plateau_z);
			
			res[j][0]=r.Rover_x;
			res[j][1]=r.Rover_y;
			res[j][2]=r.Rover_z;
			res_o[j]=r.Rover_orientation;
		}

		for(j=0;j<no_of_rovers;++j){
			System.out.print(res[j][0]+" "+res[j][1]+" "+res[j][2]+" "+res_o[j]+" ");
		}

	}
}
