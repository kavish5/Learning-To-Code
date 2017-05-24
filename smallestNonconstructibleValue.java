import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 31-03-2017.
 */
public class smallestNonconstructibleValue{

    public static int result_smallestNonconstructibleValue(List<Integer> A) {
        Collections.sort(A);
        int maxConstructibleValue = 0;
        for (int a : A){
            if (a > maxConstructibleValue + 1)
                break ;
            maxConstructibleValue += a;
        }
    return maxConstructibleValue + 1;
    }

    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        data.add(1);
        data.add(2);
        data.add(2);
        data.add(4);
        data.add(12);
        data.add(15);
        System.out.println(result_smallestNonconstructibleValue(data));
    }
}