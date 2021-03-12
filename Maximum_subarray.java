//Justyna Gruba, 12.03. 2021

/* Porównanie trzech wyszukań sumy maksymalnej podtablicy w czasie O(n^2), O(n^3), O(n).*/
import java.util.Random;
public class Maximum_subarray{

    public static void square_complexity(int a[], int n){
        int start_index =0, end_index =0, max =0;

        long start = System.nanoTime();

        for(int i=0; i < n; i++){

            int sum = 0;
            for(int j = i; j < n; j++){

                sum = sum + a[j];
                if( sum > max) {
                    max = sum;
                    start_index = i;
                    end_index = j;
                }
            }
        }
        long end = System.nanoTime();
         display_data("n^2", start_index, end_index, max, (end-start));
    }

    public static void cubic_complexity(int a[], int n){
        int start_index=0, end_index=0, max=0;

        long start = System.nanoTime();

        for(int i=0; i < n; i++){
            for(int j= i; j < n; j++) {
                int sum = 0;
                for(int k = i; k <= j; k++)
                    sum = sum + a[k];

                if( sum > max ){
                    max = sum;
                    start_index = i;
                    end_index = j;
                }
            }
        }
        long end = System.nanoTime();
        display_data("n^3", start_index, end_index, max, (end-start));
    }
    public static void Kadane_algorithm(int a[], int n){
        int start_index=0, end_index=0, max=0;
        int curr_sum=0, curr_start=0;

        long start = System.nanoTime();
        for(int i=0; i<n; i++){
            curr_sum = curr_sum + a[i];
            if(curr_sum < 0){
                curr_sum=0;
                curr_start=i+1;
            }
            else if(curr_sum > max){
                max = curr_sum;
                start_index = curr_start;
                end_index = i;
            }
        }
        long end = System.nanoTime();

        display_data("n", start_index, end_index, max,(end-start));
    }
    public static void main(String[] args) {
        int n = 8;
        int[] a = new int[n];

        System.out.println("Tablica wejściowa");
        fill_array(a, n);
        square_complexity(a, n);
        cubic_complexity(a, n);
        Kadane_algorithm(a, n);
    }
    public static  void fill_array(int[] a, int n){
        Random rand = new Random();

        for(int i=0; i < n; i++)
            a[i] = -4 + rand.nextInt(10);

        display(a, 0, n);
    }
    public static void display(int[] arr, int i, int n){

        for(int k = i; k < n; k++)
            System.out.print("| " + arr[k] + " ");
            System.out.println("\n");

    }
    public static void display_data( String n, int start_index, int end_index, int max, long time){
        System.out.println("\nZłożoność: " + n + "\n" +
                "Maksymalana suma: " + max + "\n" +
                "Indeks początkowy: " + start_index + " \n" +
                "Indeks końcowy: " + end_index + "\n" +
                "Czas wykonania w nanosekundach: " + time);

    }

}

