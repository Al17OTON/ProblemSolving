import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Lecture implements Comparable<Lecture> {
        int start, end;

        public Lecture(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Lecture o) {
            return Integer.compare(this.start, o.start);
        }
    }

    static int N, MAX = 0;
    static PriorityQueue<Lecture> pq = new PriorityQueue<>();
    static PriorityQueue<Integer> room = new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            pq.add(new Lecture(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        while(!pq.isEmpty()) {
            Lecture l = pq.poll();
            if(!room.isEmpty() && room.peek() <= l.start) room.poll();
            room.add(l.end);
            MAX = Math.max(MAX, room.size());
        }

        System.out.println(MAX);
    }
}