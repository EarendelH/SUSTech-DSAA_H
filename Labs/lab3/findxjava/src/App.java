import java.math.BigDecimal;
import java.util.Scanner;

public class App {
    static double y;
    static double a;
    static double b;
    static double c;
    static double d;
    public static double f(double x) {
        return (a * x + b * Math.log(x) - c /x + d);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        y = sc.nextDouble();
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        d = sc.nextDouble();
        double x;
        double left = 1, right = 1e9;
        int L = -1, R = -1;
        boolean flag = false;
        if(a==0&&b==0&&c==0&&d==y){
            System.out.println("NOT UNIQUE");
            return;
        }
        if(f(1)>y||f(1e9)<y||(a==0&&b==0&&c==0&&y!=d)){
            System.out.println("NO ANSWER");
            return;
        }
        // System.out.println(two(2.005));
        while(true){
            double mid=left+(right-left)/2;
            if((f(mid)<=y && f(mid+0.01)>=y)){
                // System.out.println("the f is "+f(mid,a,b,c,d)+" when x is "+mid+" left is "+left+" right is "+right);
                System.out.println(String.format("%.0f", mid*100));
                return;
            }
            if(f(mid)>y){
                right=mid;
            }else{
                left=mid;
            }
        }
        // System.out.println(String.format("%.0f", two(left)*100));


    }
}
