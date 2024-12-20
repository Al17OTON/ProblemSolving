import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Date implements Comparable<Date> {
        int month, day;
        public Date(int month, int day) {
            this.month = month;
            this.day = day;
        }

        @Override
        public int compareTo(Date o) {
            if(this.month < o.month || (this.month == o.month && this.day < o.day)) return -1;
            else if(this.month == o.month && this.day == o.day) return 0;
            return 1;
        }

        @Override
        public String toString() {
            return "Date{" +
                    "month=" + month +
                    ", day=" + day +
                    '}';
        }

        public int date2Idx() {
            int idx = day;
            for(int i = 1; i < month; i++) {
                idx += months[i];
            }
            return idx;
        }
    }
    static class Flower implements Comparable<Flower> {
        Date start, end;

        public Flower(Date start, Date end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Flower o) {
            int res = this.start.compareTo(o.start);
            if(res == 0) return this.end.compareTo(o.end);
            return res;
        }

        @Override
        public String toString() {
            return "Flower{" +
                    "start=" + start +
                    ", end=" + end +
                    '}';
        }
    }
    static int[] yearDate = new int[366];
    static int[] months = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    static int N;
    static List<Flower> flowers;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        flowers = new ArrayList<>();
        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            flowers.add(new Flower(new Date(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())), new Date(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()))));
        }

        Collections.sort(flowers);

//        for(int i = 0; i < flowers.size(); i++) {
//            System.out.println(flowers.get(i));
//        }



        System.out.println(dp());
    }

    static int dp() {
        int curIdx = new Date(3,1).date2Idx();
        int endPoint = new Date(12, 1).date2Idx();
        for(int n = 0; n < flowers.size(); n++) {
            Flower f = flowers.get(n);
            int startIdx = f.start.date2Idx();
            int endIdx = f.end.date2Idx();

            if(startIdx > curIdx) return 0;
            if(endIdx <= curIdx) continue;

            for(; curIdx < endIdx; curIdx++) {
                yearDate[curIdx] = yearDate[startIdx - 1] + 1;
            }

            if(endPoint <= curIdx) break;
        }
        return yearDate[endPoint - 1];
    }
}
