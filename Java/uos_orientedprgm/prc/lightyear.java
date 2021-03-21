public class lightyear 
{
    public static void main(String[] args) throws Exception 
    {
        final double light_speed = 30e4;
        double distance = 40e12;

        double secs;

        secs = distance / light_speed;

        double lightyear = secs / (60.0 * 60.0 * 24.0 * 365.0);
        System.out.println("걸리는 시간은"+lightyear+"광년입니다.");
    }
}
