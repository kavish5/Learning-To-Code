/**
 * Created by Kavish Kapadia on 13-05-2017.
 */
public class oldSchoolDivision {

    public static long divide(long x, long y) {
        long result = 0;
        int power = 32;
        long yPower = y << power;
        while (x >= y) {
            while (yPower > x) {
                yPower >>>= 1;
                --power;
            }
            result += 1L << power;
            x -= yPower;
        }
        return result;
    }

    public static void main(String[] args) {
        long x=11, y =2;
        System.out.println(divide(x,y));
    }
}
