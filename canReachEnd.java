import java.util.ArrayList;
import java.util.List;

/**
 * Created by Kavish Kapadia on 15-05-2017.
 */
public class canReachEnd {

    public static boolean canReachEnd(List<Integer> maxAdvanceSteps){

        int furthestReached = 0, lastIndex = maxAdvanceSteps.size()-1;
        for(int i = 0; i <= furthestReached && furthestReached < lastIndex; i++)
            furthestReached = Math.max(furthestReached, i + maxAdvanceSteps.get(i));
        return furthestReached >= lastIndex;
    }

    public static void main(String[] args) {
        List<Integer> A = new ArrayList<>();
        A.add(3);
        A.add(2);
        A.add(0);
        A.add(0);
        A.add(2);
        A.add(0);
        A.add(1);
        System.out.println(canReachEnd(A));
    }
}
