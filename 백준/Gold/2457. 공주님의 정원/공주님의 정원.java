import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 그리디
public class Main {

    // 개화 시기 순서로 오름차순 정렬한다.
    static class Flower implements Comparable<Flower> {
        int start_date, end_date;

        public Flower(int start_date, int end_date) {
            this.start_date = start_date;
            this.end_date = end_date;
        }

        @Override
        public int compareTo(Flower o) {
            return Integer.compare(this.start_date, o.start_date);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Flower> start = new PriorityQueue<>();
        StringTokenizer st;
        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            int start_m = Integer.parseInt(st.nextToken());
            int start_d = Integer.parseInt(st.nextToken());
            int end_m = Integer.parseInt(st.nextToken());
            int end_d = Integer.parseInt(st.nextToken());

            start.offer(new Flower(makeDate(start_m, start_d), makeDate(end_m, end_d)));
        }

        // 3월 1일 = 301 부터 시작
        int current_time = 301, count = 0;
        // 12월이 되면 종료
        while(!start.isEmpty() && current_time < 1200) {
            int max_end_time = -1;

            // 개화시기가 current_time보다 이르면서 current_time보다 뒤에 꽃이 지는 것 중 가장 늦게 지는 꽃 찾기
            while(!start.isEmpty() && start.peek().start_date <= current_time) {
                if(isInside(start.peek(), current_time)) max_end_time = Math.max(max_end_time, start.peek().end_date);
                start.poll();
            }

            // 조건에 맞는 꽃을 못 찾았다면 탈출
            if(max_end_time == -1) break;
            
            // 가장 늦게 지는 꽃을 심는다.
            count++;
            current_time = max_end_time;
        }
        // 12월을 넘기지 못했다면 0 출력
        if(current_time < 1200) count = 0;

        System.out.println(count);
    }
    // 시기 비교를 쉽게 하기 위한 변환
    static int makeDate(int m, int d) {
        return m * 100 + d; 
    }
    // 시기가 포함되는지 검사
    static boolean isInside(Flower f, int date) {
        return f.start_date <= date && f.end_date > date;
    }
}