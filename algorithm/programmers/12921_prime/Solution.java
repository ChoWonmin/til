public class Main {
	
	public static int solution(int num) {
		int eratos[] = new int[1000001];
		int cnt = 0;
		
		for (int i = 2; i <= num; i++) {
			
			if (eratos[i]==0) {
				cnt++;
				
				for (int j = i; j <= num; j+=i) {	
					eratos[j] = 1;
				}
			}
		}
		
		return cnt;
	}

	public static void main(String[] args) {

		int num = 10;
		
		System.out.println( Main.solution(num) );
		
	}

}		
