import java.util.List;
import java.util.Scanner;
public class sharesMaxProfit {
    public static void main(String[] args) {
        float profit = 0,min = 999;
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i = 0; i < n; i++){
            float data;
            if(i == 0)
                min = in.nextFloat();
            else{
                data = in.nextFloat();
                if(profit < data - min)
                    profit = data - min;
                if(min > data)
                    min = data;
            }
        }
        System.out.println("Profit: " + profit); // Profit = 0 for descending order
    }

    public static double computeMaxProfit(List<Double> prices){
        double minPrice = Double.MAX_VALUE , maxProfit = 0.0;
        for (Double price : prices) {
            maxProfit = Math.max(maxProfit , price - minPrice);
            minPrice = Math.min(minPrice , price);
        }
        return maxProfit;
    }
}