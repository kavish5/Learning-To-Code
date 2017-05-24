/**
 * Created by Kavish Kapadia on 02-04-2017.
 */
public class rotate {

    private static boolean result_rotate(String check1,String check2){
        String checkconcat = check2.concat(check2);
        return checkconcat.contains(check1);
    }

    public static void main(String[] args) {
        String a = "car";
        String b = "arc";
        System.out.println(result_rotate(a,b));
    }
}
