/**
 * Created by Kavish Kapadia on 11-05-2017.
 */
public class closestIntSameBitCount {

        static final int NUM_UNSIGN_BITS = 63;
        private static long result_closestIntSameBitCount(long x) {
            for (int i = 0; i < NUM_UNSIGN_BITS - 1; i++)
                if ((((x >>> i) & 1) != ((x >>> (i + 1)) & 1))) { // >>> removes i bits
                    x ^= (1L << i) | (1L << (i + 1));
                    break;
                }
            return x;
        }

        public static void main(String[] args) {
            long x = 27;
            System.out.println(result_closestIntSameBitCount(x));
        }

}
