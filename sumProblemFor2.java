import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 10-05-2017.
 */
public class sumProblemFor2 {

    private static boolean result_2SumProblem(List<Integer> data, int k) {
        Collections.sort(data);
        int i = 0, j = data.size()-1;
        while(i<j){
            if(data.get(i) + data.get(j) == k)
                return true;
            else if(data.get(i) + data.get(j) > k)
                j--;
            else
                i++;
        }
        return false;
    }

    public static void main(String[] args) {
        int k = 6;
        List<Integer> data = new ArrayList<>();
        data.add(1);
        data.add(2);
        data.add(10);
        data.add(4);
        data.add(12);
        data.add(15);
        System.out.println(result_2SumProblem(data, k));
    }

}
