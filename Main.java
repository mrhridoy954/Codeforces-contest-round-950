import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        StringBuilder result = new StringBuilder();

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int[] rows = new int[k];
            int[] cols = new int[k];

            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                rows[i] = Integer.parseInt(st.nextToken());
                cols[i] = Integer.parseInt(st.nextToken());
            }

            int minRow = n;
            int minCol = m;
            for (int i = 0; i < k; i++) {
                minRow = Math.min(minRow, rows[i]);
                minCol = Math.min(minCol, cols[i]);
            }

            int alpha = (minRow - 1) + (minCol - 1);
            result.append(alpha).append("\n");

            for (int i = 0; i < k; i++) {
                int newAlpha = Math.max(alpha, (rows[i] - 1) + (cols[i] - 1));
                if (newAlpha > alpha) {
                    result.append(1).append(" ");
                } else {
                    result.append(0).append(" ");
                }
            }
            result.append("\n");
        }
        System.out.print(result.toString());
    }
}
