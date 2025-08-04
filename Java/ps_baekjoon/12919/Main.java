import java.io.*;

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    String readLine(){
        try {
            return br.readLine();
        } catch (Exception e) {
            return null;
        }
    }

    String s, t;

    boolean answer = false;

    void fnc(String str){
        if(answer){
            return;
        }
        if(str.length() == s.length()){
            answer = str.equals(s);
            return;
        }

        if(str.charAt(str.length() - 1) == 'A')
            fnc(str.substring(0, str.length() - 1));
        if(str.charAt(0) == 'B')
            fnc(new StringBuilder(str.substring(1, str.length())).reverse().toString());
    }

    public void solve() {
        s = readLine().strip();
        t = readLine().strip();
        
        fnc(t);
        System.out.print(answer?1:0);
    }

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}
