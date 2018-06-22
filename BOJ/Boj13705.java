import java.math.BigDecimal;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.math.MathContext;

public class Boj13705{
	public static BigDecimal go(BigDecimal x, BigDecimal a, BigDecimal b, BigDecimal c){
		BigDecimal result;
		result = x.multiply(a).add(b.multiply(new BigDecimal(Math.sin(x.doubleValue())))).add(c);
		return result;
	}

	public static void main(String[] args){
		BufferedReader bf = new BufferedReader( new InputStreamReader( System.in ) );
		StringTokenizer st = null;
		BigDecimal a = null, b = null, c = null;
		BigDecimal x = null, val = null, dx = null, two = new BigDecimal("2.0", new MathContext(10));
		BigDecimal boundary1 = new BigDecimal("0.0000000001", new MathContext(10));
		BigDecimal boundary2 = new BigDecimal("-0.0000000001", new MathContext(10));

		try {
			st = new StringTokenizer( bf.readLine(), " " );
			a = new BigDecimal(Integer.parseInt(st.nextToken()), new MathContext(10));
			b = new BigDecimal(Integer.parseInt(st.nextToken()), new MathContext(10));
			c = new BigDecimal(Integer.parseInt(st.nextToken()), new MathContext(10));
			System.out.println(a+ " " + b + " " + c);
			x = c.divide(a);
			dx = b.divide(a);
			System.out.println(x + " " + dx);
			while(true){
				dx.divide(two);
				val = go(x, a, b, c);

				if( val.compareTo(boundary2) > 0 && val.compareTo(boundary1) < 0 ) break;
				else if( val.compareTo(boundary1) >= 0 ) x.subtract(dx);
				else x.add(dx);
			}

		} catch(IOException e){
			e.printStackTrace();
		}

		System.out.println(x);
	}
}