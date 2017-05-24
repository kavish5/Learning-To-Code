/**
 * Created by Kavish Kapadia on 13-05-2017.
 */
public class numberPalindrome {

    public static boolean isNumberPalindrome(long x){
        int numOfDigit = (int) Math.floor((Math.log10(x)+1));
        int msdMask = (int)Math.pow(10, numOfDigit - 1);
        for(int i = 0; i < (numOfDigit/2); i++){
            if(x%10 != x/msdMask)
                return false;
            x %= msdMask;
            x /= 10;
            msdMask /= 100;
        }
        return true;
    }

    public static void main(String[] args) {
        long x = 1221;
        System.out.println(isNumberPalindrome(x));
    }
}
