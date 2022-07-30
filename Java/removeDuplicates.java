import java.util.ArrayList;
import java.util.List;

/**
 * Created by Kavish Kapadia on 15-05-2017.
 */
public class removeDuplicates {

    public static int uniqueElements(List<Integer> a){

        if(a.isEmpty())
            return 0;
        int writeIndex = 1;
        for(int i = 0; i < a.size() - 1; i++){
            if(!a.get(writeIndex - 1).equals(a.get(i)))
                a.set(writeIndex++, a.get(i));
        }
        return writeIndex;
    }

    public static void main(String[] args) {
        List<Integer> a = new ArrayList<>();
        a.add(2);
        a.add(3);
        a.add(5);
        a.add(7);
        a.add(7);
        a.add(11);
        a.add(11);
        a.add(11);
        a.add(13);
        a.add(13);
        System.out.println(uniqueElements(a));
    }

}
