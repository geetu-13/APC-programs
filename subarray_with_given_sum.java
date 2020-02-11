import java.util.*;
public class subarray_with_given_sum{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int sum=sc.nextInt();
		int arr[]=new int [n];
		for(int i=0;i<n;++i)
			arr[i]=sc.nextInt();
		
		int posx=0;
		int posy=0;
		int sum_array=arr[0];
		while(posx<n && posy<n){
			if (sum==sum_array)
				break;
			if (sum_array<sum)
			{
				posy++;
				sum_array+=arr[posy];
				if (sum_array>sum)
				{
					sum_array-=arr[posx];
					posx++;
				}
			}
			if (sum_array>sum){
				posx=posy;
			}
		}
		/*according to computer index starts from zero. 
		we want it to start from index 1*/
		posx++;
		posy++;
		System.out.println("\n"+posx+" "+posy);
	}
}