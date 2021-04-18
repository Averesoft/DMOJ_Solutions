import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
public class ccc08j4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   
        String st = br.readLine();
        String s[];
        Stack stack = new Stack();
        String a, ob1, ob2;
        while(!st.equals("0")) {
            s = st.split(" ");
            
            for (int i = s.length-1; i >= 0; i--) {
                a = s[i];
                if (s[i].equals("+") || s[i].equals("*") || s[i].equals("/") || s[i].equals("-") || s[i].equals("%") || s[i].equals("^")) {
                    ob2 = (String) stack.pop();
                    ob1 = (String) stack.pop();
                    stack.push(ob2 + " " + ob1 + " " + a);
                } else {
                    stack.push(a + "");
                }
            }
            System.out.println(stack.pop());
            st = br.readLine();
            stack.clear();
        }
    }

}