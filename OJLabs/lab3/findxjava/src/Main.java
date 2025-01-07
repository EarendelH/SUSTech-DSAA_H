import java.util.Scanner;
public class Main {
    static long y ;
    static long a;
    static long b ;
    static long c ;
    static long d;
    public static void Main(String[] args) {
        Scanner in = new Scanner(System.in);
        y = in.nextLong();
        a = in.nextLong();
        b = in.nextLong();
        c = in.nextLong();
        d = in.nextLong();
        long x=find(100,(long)1e11);
        if(evaluateFunction(0.01)>y || evaluateFunction(1e11)<y||(a==0&&b==0&&c==0&&y!=d) || x<0){
            System.out.println("NO ANSWER");
        }else if((a==0&&b==0&&c==0&&d==y)){
            System.out.print("NOT UNIQUE");
        }else{
            System.out.print(x);
        }
    }

    private static double evaluateFunction(double x) {
        return (a*x + b*(Math.log(x)) - c/x + d);
    }
    private static long find(long left, long right){
        if(right>left){
            long min=(left+right)/2;
            if(  evaluateFunction(0.01*min) <=y && evaluateFunction((0.01*(min+1)))>=y){
                 return min;
            }else if(evaluateFunction(0.01*min)<y){
                return find(min+(left+right)%2,right);
            }else{
                return find(left,min);
            }
        }
        return -1;
    }

}