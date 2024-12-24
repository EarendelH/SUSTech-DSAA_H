import java.util.Scanner;

public class Main {
    public static void quickSort1(int[] nums,int l,int r){
        if(l>=r) return;
        int base = partition(nums,l,r);
        quickSort1(nums,l,base-1);
        quickSort1(nums,base+1,r);
    }
    public static int partition(int[] nums,int l,int r){
        int base = nums[l];
        while(l<r){
            while(l<r && nums[r]>=base) r--;
            nums[l] = nums[r];
            while(l<r && nums[l]<=base) l++;
            nums[r] = nums[l];
        }
        nums[l] = base;
        return l;
    }
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            nums[i] = sc.nextInt();
        }
        quickSort1(nums,0,nums.length-1);
        for(int i=0;i<nums.length;i++){
            System.out.print(nums[i]+" ");
        }
    }
    
}
