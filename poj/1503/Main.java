import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger ans = BigInteger.ZERO;
		while (cin.hasNextBigInteger()) {
			ans = ans.add(cin.nextBigInteger());
		}			
		System.out.println(ans);
	}
}
