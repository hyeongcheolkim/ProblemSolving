public class StringTest {
    public static void main(String[] args) throws Exception {
        String s1 = new String("Java");
        String s2 = new String("Java");
        String s3 = "Java";
        String s4 = "Java";

        // System.out.println(s1==s2);
        // System.out.println(s3==s4);
        // System.out.println(s1==s3);
        // System.out.println(s1.equals(s3));



        System.out.println(s1.toLowerCase());
        System.out.println(s3.toLowerCase()==s1.toLowerCase());
    }
}
