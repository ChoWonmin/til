import java.util.ArrayList;

public class Solution {
	
	public static int[] solution(int[] arr) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		int previous = arr[0];
		list.add(arr[0]);
		for (int i = 1; i < arr.length; i++) {
			int val = arr[i];
			
			if (val != previous) { 
				list.add(val);
			}
			previous = val;
			
		}
		
		int res[] = new int[list.size()];
		
		for (int i = 0; i < list.size(); i++) {
			res[i] = list.get(i);
		}
		
		return res;
	}

	public static void main(String[] args) {
		
		
		int arr[] = {1,1,3,3,0,1,1};
		
		System.out.println(solution(arr));

	}

}
