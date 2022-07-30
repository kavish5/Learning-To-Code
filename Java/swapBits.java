/**
 * Created by Kavish Kapadia on 10-05-2017.
 */
public class swapBits {

    private static long result_swapBits(long x, int i, int j){
        if(((x >>> i) & 1) != ((x >>> j) & 1)){
            long bitMask = (1L << i) | (1L << j);
            x ^= bitMask;
        }
        return x;
    }

    public static void main(String[] args) {
        long x = 1234;
        System.out.println(result_swapBits(x, 4, 5));
    }
}
