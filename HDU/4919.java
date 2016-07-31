import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	BigInteger contribution(BigInteger n, BigInteger coefficient){
		BigInteger result;
		if(!n.testBit(0)) { // n%2 == 0
			result = n.shiftLeft(1).subtract(BigInteger.valueOf(4));
		} else {
			result = n.shiftRight(1).multiply(BigInteger.valueOf(6));
		}
		return result.multiply(coefficient);
	}

	BigInteger solve(BigInteger n) {
		BigInteger result = BigInteger.ZERO;
		BigInteger[] coefficient = new BigInteger[]{BigInteger.ONE,BigInteger.ZERO};
		while (n.signum() > 0) { // n >= 0
				System.out.print(coefficient[0]);System.out.print(" ");System.out.println(coefficient[1]);
				result = result.add(contribution(n,                     coefficient[0]));
				result = result.add(contribution(n.add(BigInteger.ONE), coefficient[1]));
				if (!n.testBit(0)) {
					n = (n.shiftRight(1)).subtract(BigInteger.ONE);
					coefficient = new BigInteger[]{coefficient[0].shiftLeft(1),
											       coefficient[0].shiftLeft(1).add(coefficient[1].shiftLeft(2))};
				} else {
					n = n.shiftRight(1);
					coefficient = new BigInteger[]{coefficient[0].shiftLeft(2).add(coefficient[1].shiftLeft(1)),
											   	   coefficient[1].shiftLeft(1)};
				}
		} 
		return result;
	}

	public void run() {
		try {
			while (true) {
				BigInteger n = reader.nextBigInteger();
				System.out.println(solve(n));
				//writer.println(solve(n));
			}
			} catch (InputMismatchException ex){			
			}
			writer.close();
	}

	Main() {
		reader = new InputReader(System.in);
		writer = new PrintWriter(System.out);
	}

	public static void main(String[] args) {
		new Main().run();
	}

	private static void debug(Object...os) {
		System.err.println(Arrays.deepToString(os));
	}

	private InputReader reader;
	private PrintWriter writer;
}

class InputReader {
	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int nextChar() {
		if (charCount == -1)
			throw new InputMismatchException();
		if (head >= charCount) {
			head = 0;
			try {
				charCount = stream.read(buffer);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (charCount <= 0)
				return -1;
		}
		return buffer[head++];
	}

	public BigInteger nextBigInteger() {
		int c = nextChar();
		while (isSpaceChar(c)) {
			c = nextChar();
		}
		StringBuffer buffer = new StringBuffer();
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			buffer.append(c - '0');
			c = nextChar();
		} while (!isSpaceChar(c));
		return new BigInteger(buffer.toString());
	}

	public boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private InputStream stream;
	private int head,charCount;
	private byte[] buffer = new byte[1024];
}
