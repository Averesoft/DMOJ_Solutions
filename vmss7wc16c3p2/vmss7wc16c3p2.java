import java.io.*;
import java.util.*;
 
public class vmss7wc16c3p2 {
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
 
        int n = in.nextInt();
        int m = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
 
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        int x;
        int y;
        for (int i=0; i<=n; i++)
        {
            adj.add(new ArrayList<Integer>());
        } 
        for (int i=0; i<m; i++)
        {
            x = in.nextInt();
            y = in.nextInt();
            adj.get(x).add(y);
            adj.get(y).add(x);
        }
 
        boolean [] visited = new boolean [n+1];
        Stack<Integer> stk = new Stack<Integer>();
        stk.push(a);
        visited[a] = true;
        while(!stk.empty()){
            int pointer = stk.pop();
            if (pointer == b)
            {
                visited[pointer] = true;
                break;
            }
            for (int i: adj.get(pointer))
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    stk.push(i);
                }
            }
        }
 
        if (visited[b])
        {
            System.out.println("GO SHAHIR!");
        }
        else{
            System.out.println("NO SHAHIR!");
        }
    }
}
