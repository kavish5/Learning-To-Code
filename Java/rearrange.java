import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 01-04-2017.
 */
public class rearrange {

    private static List<Integer> result_rearrange(List<Integer> data) {
        for(int i = 1; i < data.size(); i++){
            if((data.get(i-1) < data.get(i) && (i%2==0)) || (data.get(i-1) > data.get(i) && (i%2!=0)))
                Collections.swap(data, i, i-1);
        }
        return data;
    }

    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        data.add(1);
        data.add(2);
        data.add(10);
        data.add(4);
        data.add(12);
        data.add(15);
        System.out.println(result_rearrange(data));
    }

}
