import java.util.Scanner;

public class App {
    public static void quickSort(int[] nums,int l,int r){
        if(l>=r) return;
        int i,j,x;
        i=l-1;
        j=r+1;
        x=nums[l];
        while(i<j){
            do{i++;}while(nums[i]<x);
            do{j--;}while(nums[j]>x);
            if(i<j){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            else break;
        }
        quickSort(nums,l,j);
        quickSort(nums,j+1,r);
    }
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            nums[i] = sc.nextInt();
        }
        quickSort(nums,0,nums.length-1);
        for(int i=0;i<nums.length;i++){
            System.out.print(nums[i]+" ");
        }
    }
}
