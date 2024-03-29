import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 19-05-2017.
 */
public class sudokuValidityChecker {

    public static boolean isValidSudoku(List<List<Integer>> partialAssignment){
        for (int i = 0; i < partialAssignment.size(); ++i) {
            if (hasDuplicate(partialAssignment , i, i + 1, 0, partialAssignment.size()))
                return false;
        }

        for (int j = 0; j < partialAssignment.size(); ++j) {
            if (hasDuplicate(partialAssignment , 0, partialAssignment.size(), j, j + 1))
                return false;
        }

        int regionSize = (int)Math.sqrt(partialAssignment.size());
        for (int I = 0 ; I < regionSize; ++I) {
            for (int J = 0 ; J < regionSize; ++J) {
                if (hasDuplicate(partialAssignment , regionSize * I,
                        regionSize * (I + 1), regionSize * J,
                        regionSize * (J + 1))) {
                    return false;
                }
            }
        }
        return true ;
    }

    private static boolean hasDuplicate (List <List<Integer>> partialAssignment,
                                         int startRow, int endRow, int startCol,
                                         int endCol ) {
        List<Boolean> isPresent = new ArrayList<>(
                Collections. nCopies (partialAssignment . size () + 1, false));
        for (int i = startRow; i < endRow; ++i) {
            for (int j = startCol; j < endCol; ++j) {
                if (partialAssignment.get(i).get(j) != 0 && isPresent.get(partialAssignment.get(i).get(j)))
                    return true;
                isPresent.set(partialAssignment.get(i).get(j), true);
            }
        }
        return false;
    }

}
