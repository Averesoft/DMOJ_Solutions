import java.util.*;
import java.io.*;
public class oly18decp4 {
 
   static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
   public static void main(String[] args)throws IOException{
      Scanner in = new Scanner(System.in);
      long nums = in.nextLong();
      long[] input = new long[(int)nums];
      long target = in.nextLong();
      long answer = 0;
      for(long i = 0; i<nums;i++)
         input[(int)i] = in.nextLong();
      Arrays.sort(input);
      long index = 0;
      long lowR = input[input.length-1]+1;

      while(index<lowR&&index<input.length){
         lowR = bSearch(target, index, input);
         answer+= lowR-index;
         index++;
      }
      System.out.println(answer);
      
      
   }
   public static long bSearch(long t, long i, long[] arr){
      long max = arr.length-1;
      long min = 0;
      while(min<=max){ 
         long mid = (max+min)/2;
         if(arr[(int)mid]+arr[(int)i]<t)
             min = mid + 1;
         else if(arr[(int)mid]+arr[(int)i]>t)
             max = mid - 1;    
         if((arr[(int)mid]+arr[(int)i]<=t)&&(mid+1==arr.length||(arr[(int)mid+1]+arr[(int)i]>t)))
            return mid;

      } 
      return 0;
   }
}