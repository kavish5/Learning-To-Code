import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 14-05-2017.
 */
public class dutchFlagPartition {

    public static enum Color { RED , WHITE , BLUE }

    public static List<Color> dutchFlagPartition(int pivotIndex, List<Color> A){
        Color pivot = A.get(pivotIndex);
        int smaller = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A.get(i).ordinal() < pivot.ordinal())
                    Collections.swap(A, smaller++, i);
        }
        int larger = A.size() - 1;
        for (int i = A.size() - 1; i >= 0 && A.get(i).ordinal() >= pivot.ordinal();--i) {
            if (A.get(i).ordinal() > pivot.ordinal())
                Collections.swap(A, larger--, i);
        }
        return A;
    }

    public static void main(String[] args) {
        List<Color> A = new ArrayList<>();
        A.add(Color.RED);
        A.add(Color.WHITE);
        A.add(Color.RED);
        A.add(Color.RED);
        A.add(Color.BLUE);
        A.add(Color.WHITE);
        System.out.println(dutchFlagPartition(2, A));
    }

}
