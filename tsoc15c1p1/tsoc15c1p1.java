import java.util.*;
public class tsoc15c1p1 {
    public static void main(String[] args){ 
        Scanner sc = new Scanner(System.in);
        HashMap<String, Integer> hm = new HashMap<>();
        hm.put("Cl", 0); hm.put("Br", 0); hm.put("Xe", 0); hm.put("Kr", 0); hm.put("Si", 0); hm.put("As", 0); hm.put("Rn", 0); hm.put("Ne", 0); hm.put("He", 0);
        hm.put("H", 0); hm.put("C", 0); hm.put("N", 0); hm.put("O", 0); hm.put("F", 0); hm.put("P", 0); hm.put("S", 0); hm.put("I", 0);
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            boolean molecular = true;
            String[] st = sc.nextLine().split(" ");
            for (int j = 0; j < st.length; j++) {
                if (hm.get(st[j]) == null) {
                    molecular = false; break;
                }
            }
            System.out.println(molecular ? "Molecular!" : "Not molecular!");
        }
    }
}