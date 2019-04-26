import java.util.ArrayList;
import java.util.Collections;

public class Solution {

	public static int[] solution(int[] array, int[][] commands) {
		
		int res[] = new int[commands.length];
		
		for (int x=0; x<commands.length; x++) {
	        int i = commands[x][0];
	        int j = commands[x][1];
	        int k = commands[x][2];
	        
	        ArrayList<Integer> list = new ArrayList<Integer>();
	        
	        for (int l = i-1; l < j; l++) {
				list.add(array[l]);
			}
	        
	        Collections.sort(list);
	        
	        res[x] = list.get(k-1);
	        
	    }
		
		
		return res;
	}
	
	public static void main(String[] args) {
		int[] array = {1, 5, 2, 6, 3, 7, 4};
		int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
		
	
		solution(array, commands);
		
	}

}
