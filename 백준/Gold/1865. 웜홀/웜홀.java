import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static class Edge {
        int from, to, cost;
        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    static int N, M, W;
    static ArrayList<ArrayList<Edge>> edge;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for(int tt = 0; tt < T; tt++) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            edge = new ArrayList<>();

            for(int n = 0; n <= N; n++) {
                edge.add(new ArrayList<>());
            }

            for(int m = 0; m < M; m++) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());

                edge.get(s).add(new Edge(s, e, t));
                edge.get(e).add(new Edge(e, s, t));
                
            }

            for(int w = 0; w < W; w++) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int t = -Integer.parseInt(st.nextToken());

                edge.get(s).add(new Edge(s, e, t));
            }

            boolean flag = false;
            for(int i = 1; i <= N; i++) {
                if(bellman(i)) {
                    flag = true;
                    break;
                }
            }

            sb.append(flag ? "YES\n" : "NO\n");
        }
        System.out.println(sb);
    }

    static boolean bellman(int idx) {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, 98765432);
        dist[idx] = 0;
        boolean update = false;
        
        for(int v = 1; v < N; v++) {
            update = false;
            for(int i = 1; i <= N; i++) {
                for(int e = 0; e < edge.get(i).size(); e++) {
                    Edge ed = edge.get(i).get(e);
    
                    if(dist[i] + ed.cost < dist[ed.to]) {
                        dist[ed.to] = dist[i] + ed.cost;
                        update = true;
                    }
                }
            }
            if(!update) break;
        }

        if(update) {
            for(int i = 1; i <= N; i++) {
                for(int e = 0; e < edge.get(i).size(); e++) {
                    Edge ed = edge.get(i).get(e);
    
                    if(dist[i] + ed.cost < dist[ed.to]) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    

}