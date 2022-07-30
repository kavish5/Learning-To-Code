import java.util.ArrayList;
import java.util.List;

/**
 * Created by Kavish Kapadia on 16-05-2017.
 */
public class sellStockTwice {

    public static double buyAndSellStockTwice(List<Double> prices) {
        double maxTotalProfit = 0.0;
        List<Double> firstBuySellProfits = new ArrayList<>();
        double minPriceSoFar = Double.MAX_VALUE;

        for (int i = 0; i < prices.size(); ++i) {
            minPriceSoFar = Math.min(minPriceSoFar, prices.get(i));
            maxTotalProfit = Math.max(maxTotalProfit, prices.get(i) - minPriceSoFar);
            firstBuySellProfits.add(maxTotalProfit);
        }

        double maxPriceSoFar = Double.MIN_VALUE;

        for (int i = prices.size() - 1; i > 0; --i){
            maxPriceSoFar = Math.max(maxPriceSoFar, prices.get(i));
            maxTotalProfit = Math.max(maxTotalProfit, maxPriceSoFar - prices.get(i) + firstBuySellProfits.get(i - 1));
        }
        return maxTotalProfit;
    }

    public static void main(String[] args) {
        List<Double> A = new ArrayList<>();
        A.add(12.0);
        A.add(11.0);
        A.add(13.0);
        A.add(9.0);
        A.add(12.0);
        A.add(8.0);
        A.add(14.0);
        A.add(13.0);
        A.add(15.0);
        System.out.println(buyAndSellStockTwice(A));
    }
}
