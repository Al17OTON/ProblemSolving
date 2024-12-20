import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Flower {
        int start_date, end_date;

        public Flower(int start_date, int end_date) {
            this.start_date = start_date;
            this.end_date = end_date;
        }
    }
    
    static class StartFlower implements Comparable<StartFlower> {
        Flower f;

        public StartFlower(Flower f) {
            this.f = f;
        }

        @Override
        public int compareTo(StartFlower o) {
            return Integer.compare(this.f.start_date, o.f.start_date);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        PriorityQueue<StartFlower> start = new PriorityQueue<>();
        StringTokenizer st;
        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            int start_m = Integer.parseInt(st.nextToken());
            int start_d = Integer.parseInt(st.nextToken());
            int end_m = Integer.parseInt(st.nextToken());
            int end_d = Integer.parseInt(st.nextToken());

            start.offer(new StartFlower(new Flower(makeDate(start_m, start_d), makeDate(end_m, end_d))));
        }

        // PriorityQueue<EndFlower> end = new PriorityQueue<>();
        int current_time = 301, count = 0;
        while(!start.isEmpty() && current_time < 1200) {
            int max_end_time = -1;
            while(!start.isEmpty() && start.peek().f.start_date <= current_time) {
                if(isInside(start.peek().f, current_time)) max_end_time = Math.max(max_end_time, start.peek().f.end_date);
                start.poll();
            }

            if(max_end_time == -1) break;

            count++;
            current_time = max_end_time;
        }

        if(current_time < 1200) count = 0;

        System.out.println(count);
    }

    static int makeDate(int m, int d) {
        return m * 100 + d; 
    }

    static boolean isInside(Flower f, int date) {
        return f.start_date <= date && f.end_date > date;
    }
}