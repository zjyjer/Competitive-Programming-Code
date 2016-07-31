import java.math.*;
import java.util.*;
public class Solution
{
    public static void main(String[] args) {
        BigInteger two=BigInteger.valueOf(2),nn;
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
            BigInteger sum=BigInteger.ZERO,x;
            int n=cin.nextInt();
            nn=BigInteger.valueOf(n);
            for(int i=1;i<=n;i++)
            {
                int tmp=gcd(n,i);
                x=two.pow(tmp);
                sum=sum.add(x);
            }
            sum=sum.divide(nn);
            System.out.println(sum);
        }
    }
    public static int gcd(int x,int y)
    {
        if(x%y==0)
            return y;
        else return gcd(y,x%y);
    }
}