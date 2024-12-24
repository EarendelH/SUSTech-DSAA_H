import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class main2 {
    static String S;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        S = scanner.nextLine();
        System.out.println(maximizeMinLength(S));
    }
    private static int maximizeMinLength(String S) {
        List<Integer> kPositions = new ArrayList<>();
        if(S.isEmpty()) return 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'K') {
                kPositions.add(i);
            }
        }
        if(kPositions.size()==0) return 0;
        int left = 0;
        int right = S.length();
        int result = 0;
        while (left <= right) {
            int mid =( left + right ) / 2;
            if (isValidLength(kPositions, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    private static boolean isValidLength(List<Integer> kPositions, int minLen) {
        int[] len=new int[kPositions.size()];
        if(minLen<=kPositions.get(0)+1){
            len[0]=kPositions.get(0);
        }else{
            len[0]=minLen-1;
        }
        for (int i=1;i<=kPositions.size()-1;i++) {
            int right;
            if(i==kPositions.size()-1){
                right=S.length();
            }else{
                right=kPositions.get(i+1);
            }
            if(len[i-1]+minLen<=kPositions.get(i)){
                len[i]=kPositions.get(i);
            }else if(len[i-1]+minLen>=right){
                return false;
            }else if(len[i-1]+minLen>kPositions.get(i)){
                len[i]=len[i-1]+minLen;
            }
        }
        return true;
    }
}