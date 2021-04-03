import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class ccc05s1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   
        int n = Integer.parseInt(br.readLine());
        String st;
        String nums = "", next = "";
        
        
        for (int i = 0; i < n; i++) {
            st = br.readLine();
            nums = "";
            next = "";
            for (int j = 0; j < st.length(); j++) {
                for (int b = 0; b < st.length(); b++) {
                    switch(st.charAt(b)) {
                        case 'A': nums += '2';
                        break;
                        case 'B': nums += "2";
                        break;
                        case 'C': nums += "2";
                        break;
                        case 'D': nums += '3';
                        break;
                        case 'E': nums += "3";
                        break;
                        case 'F': nums += "3";
                        break;
                        case 'G': nums += '4';
                        break;
                        case 'H': nums += "4";
                        break;
                        case 'I': nums += "4";
                        break;
                        case 'J': nums += '5';
                        break;
                        case 'K': nums += "5";
                        break;
                        case 'L': nums += "5";
                        break;
                        case 'M': nums += '6';
                        break;
                        case 'N': nums += "6";
                        break;
                        case 'O': nums += "6";
                        break;
                        case 'P': nums += '7';
                        break;
                        case 'Q': nums += "7";
                        break;
                        case 'R': nums += "7";
                        break;
                        case 'S': nums += "7";
                        break;
                        case 'T': nums += '8';
                        break;
                        case 'U': nums += "8";
                        break;
                        case 'V': nums += "8";
                        break;
                        case 'W': nums += '9';
                        break;
                        case 'X': nums += "9";
                        break;
                        case 'Y': nums += "9";
                        break;
                        case 'Z': nums += "9";
                        break;
                        case '-': break;
                        default: nums+=st.charAt(b);
                        break;
                    }
                    if (nums.length() >= 10) {
                        break;
                    }
                }
                if (nums.length() >= 10) {
                    break;
                }
                
            }
            next += nums.substring(0, 3) + '-' + nums.substring(3, 6) + '-' + nums.substring(6);
            System.out.println(next);
        }
    }

}