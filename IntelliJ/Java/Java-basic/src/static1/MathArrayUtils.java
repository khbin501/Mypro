package static1;

public class MathArrayUtils {

    static public int sum(int[] array){
         int total=0;
        for (int i = 0; i < array.length; i++) {
            total += array[i];
        }
        return total;
    }

    static public double average(int[] array){
        int total=0;
        for (int i = 0; i < array.length; i++) {
            total += array[i];
        }
        return total / array.length;
    }

    static public int min(int[] array){
        int min = array[0];
        for (int i = 0; i < array.length; i++) {
            if(min >= array[i]){
                min = array[i];
            }
        }
        return min;
    }

    static public int max(int[] array){
        int max = array[0];
        for (int i = 0; i < array.length; i++) {
            if (max <= array[i]) {
                max = array[i];
            }
        }
        return max;
    }
}
