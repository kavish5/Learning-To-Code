/**
 * Created by Kavish Kapadia on 13-05-2017.
 */
public class oldSchoolPower {

    public static double power(double x, int y){
        double result = 1.0;
        long power = y;
        if(y < 0){
            power = -power;
            x = 1.0/x;
        }
        while (power != 0){
            if((power & 1) != 0)
                result *= x;
            x *= x;
            power >>>= 1;
        }
        return result;
    }

    public static void main(String[] args) {
        double x = 3;
        int y = 10;
        System.out.println(power(x,y));
    }
}
