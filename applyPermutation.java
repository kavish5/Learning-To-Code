import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 17-05-2017.
 */
public class applyPermutation {

    public static List<Integer> applyPermutation(List<Integer> perm, List<Integer> A){
        for (int i = 0; i < A.size(); ++i){
            int next = i;
            while (perm.get(next) >= 0){
                Collections.swap(A, i, perm.get(next));
                int temp = perm.get(next);
                perm.set(next, perm.get(next) - perm.size());
                next = temp;
            }
        }
        for (int i = 0; i < perm.size(); i++)
            perm.set(i, perm.get(i) + perm.size());
        return A;
    }

    public static void main(String[] args) {
        List<Integer> perm = new ArrayList<>();
        perm.add(3);
        perm.add(2);
        perm.add(1);
        perm.add(0);

        List<Integer> A = new ArrayList<>();
        A.add(7);
        A.add(5);
        A.add(3);
        A.add(10);

        System.out.println(applyPermutation(perm, A));
    }

}
