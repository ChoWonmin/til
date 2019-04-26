public class Solution {

	public static String solution(String s) {
	      String answer = "";
	      
	      int len = s.length();
	      
	      if ( len%2 == 0) {
	    	  	answer += s.substring(len/2 -1, len/2+1);
	      } else {
	    	  	answer += s.substring(len/2);
	      }
	      
	      return answer;
	  }
	
	public static void main(String[] args) {
		
	}

}
