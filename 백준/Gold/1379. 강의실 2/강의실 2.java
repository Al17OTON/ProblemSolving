import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Room implements Comparable<Room> {
        int num, end;
        public Room(int num, int end) {
            this.num = num;
            this.end = end;
        }

        @Override
        public int compareTo(Room o) {
            return this.end - o.end;
        }
    }
    static class Lecture implements Comparable<Lecture> {
        int num, start, end;

        public Lecture(int num, int start, int end) {
            this.num = num;
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Lecture o) {
            return this.start - o.start;
        }
    }

    static int N;
    static PriorityQueue<Lecture> lectures = new PriorityQueue<>();
    static int[] lecturesResult;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        lecturesResult = new int[N + 1];

        for(int n = 0; n < N; ++n) {
            st = new StringTokenizer(br.readLine());
            int num, start, end;

            num = Integer.parseInt(st.nextToken());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());

            lectures.offer(new Lecture(num, start, end));
        }
        
        PriorityQueue<Room> rooms = new PriorityQueue<>();
        Queue<Integer> q = new LinkedList<>(); 
        int max = 0;
        while(!lectures.isEmpty()) {
            Lecture lec = lectures.poll();

            while(!rooms.isEmpty() && rooms.peek().end <= lec.start) {
                q.offer(rooms.poll().num);
            }

            if(q.isEmpty()) {
                ++max;
                lecturesResult[lec.num] = max;
                rooms.offer(new Room(max, lec.end));
            } else {
                lecturesResult[lec.num] = q.peek();
                rooms.offer(new Room(q.poll(), lec.end));
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(max).append("\n");
        for(int n = 1; n <= N; ++n) {
            sb.append(lecturesResult[n]).append("\n");
        }
        System.out.println(sb);
    }
}