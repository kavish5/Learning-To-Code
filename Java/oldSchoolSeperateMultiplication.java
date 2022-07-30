import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 15-05-2017.
 */
public class oldSchoolSeperateMultiplication {

    public static List<Integer> multiply(List<Integer> num1, List<Integer> num2){
        final int sign = num1.get(0) < 0^num2.get(0) < 0 ? -1 : 1;
        num1.set(0, Math.abs(num1.get(0)));
        num2.set(0, Math.abs(num2.get(0)));

        List<Integer> result = new ArrayList<>(Collections.nCopies(num1.size() + num2.size(), 0));

        for (int i = num1.size() - 1; i >= 0; --i){
            for (int j = num2.size() - 1; j >= 0; --j){
                result.set(i + j + 1, result.get(i + j + 1) + num1.get(i) * num2.get(j));
                result.set(i + j, result.get(i + j) + result.get(i + j + 1) / 10);
                result.set(i + j + 1, result.get(i + j + 1) % 10);
            }
        }

        int first_not_zero = 0;
        while (first_not_zero < result.size() && result.get(first_not_zero) == 0)
            ++first_not_zero ;
        result = result.subList(first_not_zero , result.size()) ;
        if (result.isEmpty () ) {
            return Arrays.asList(0) ;
        }
        result.set(0 , result.get(0) * sign);

        return result;
    }

    public static void main(String[] args) {

        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();

        a.add(1);
        a.add(9);
        a.add(5);

        b.add(5);
        b.add(9);
        b.add(1);

        System.out.println(multiply(a, b));
    }
}
