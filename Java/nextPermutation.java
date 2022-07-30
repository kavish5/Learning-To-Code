import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 17-05-2017.
 */
public class nextPermutation {

    public static List<Integer> nextPermutation(List<Integer> perm) {
        int k = perm.size() - 2;
        while (k >= 0 && perm.get(k) >= perm.get(k + 1))
            --k;
        if (k == -1)
            return Collections.emptyList();

        for (int i = perm.size() - 1; i > k; --i) {
            if (perm.get(i) > perm.get(k)) {
                Collections.swap(perm, k, i);
                break;
            }
        }
        Collections.reverse(perm.subList(k + 1, perm.size())) ;
        return perm;
    }

    public static void main(String[] args) {
        List<Integer> perm = new ArrayList<>();
        perm.add(6);
        perm.add(2);
        perm.add(1);
        perm.add(5);
        perm.add(4);
        perm.add(3);
        perm.add(0);
        System.out.println(nextPermutation(perm));
    }
}
