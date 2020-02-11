import java.util.*;
public class leaders_in_an_array{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int arr[]=new int [n];
		int res[]=new int [n];
		int itr=0;
		for(int i=0;i<n;++i)
			arr[i]=sc.nextInt();
		int leader=arr[n-1];
		for(int i=n-1;i>=0;--i){
			if (leader<=arr[i]){
				leader=arr[i];
				res[itr]=leader;
				itr++;
			}

		}
		while(itr>0){
			System.out.println(res[itr-1]);
			itr--;
		}
		
	}
}