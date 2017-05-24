import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by Kavish Kapadia on 12-05-2017.
 */
public class getPrimes {

    public static List<Long> getPrime(long n){
        List<Long> result = new ArrayList<>();
        if(n<2)
            return result;
        result.add((long) 2);
        for(long i = 3; i <= n; i+=2){
            boolean isPrime = true;
            for(int j = 0; result.get(j) * result.get(j) <= i; j++){
                if(i%result.get(j) == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime)
                result.add(i);
        }
        return result;
    }

    public static List<Integer> generatePrimes(int n){
        final int size = (int)Math.floor(0.5 * (n - 3)) + 1;
        List<Integer> primes = new ArrayList<>();
        primes.add(2);
        List<Boolean> isPrime = new ArrayList<>(Collections.nCopies(size , true));
        for (int i = 0; i < size; ++i) {
            if (isPrime.get(i)) {
                int p = ((i * 2) + 3);
                primes.add(p);
                for (long j = ((i * i) * 2) + 6 * i + 3; j < size; j += p)
                    isPrime.set((int) j, false);
            }
        }
        return primes;
    }

    public static void main(String[] args) {
        long n = 100;
        System.out.println(getPrime(n));
        System.out.println(generatePrimes((int) n));
    }

}
