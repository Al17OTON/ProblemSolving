import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static class Player {
        int money;
        public Player(int money) {
            this.money = money;
        }
    }

    static interface Room {
        boolean enter(Player p);
        
    }

    static class EmptyRoom extends RoomData implements Room{
        
        public EmptyRoom(int cost) {
            super(cost);
        }

        @Override
        public boolean enter(Player p) {
            // do nothing
            return true;
        }
    }
    static class TrollRoom extends RoomData implements Room {

        public TrollRoom(int cost) {
            super(cost);
        }

        @Override
        public boolean enter(Player p) {
            p.money -= cost;
            if(p.money < 0) return false;
            return true;
        }
    }
    static class LeprechaunRoom extends RoomData implements Room {

        public LeprechaunRoom(int cost) {
            super(cost);
        }

        @Override
        public boolean enter(Player p) {
            p.money = Math.max(p.money, cost);
            return true;
        }
    }
    static class RoomData {
        int cost;
        public RoomData(int cost) {
            this.cost = cost;
        }
    }

    static int N;
    static Room[] rooms;
    static int[][] adj;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        rooms = new Room[1001];
        adj = new int[1001][1002];
        // int[] v = new int[1001];
        while(true) {
            N = Integer.parseInt(br.readLine());
            if(N == 0) break;
            
            StringTokenizer st;
            for(int n = 1; n <= N; ++n) {
                st = new StringTokenizer(br.readLine());

                char code = st.nextToken().charAt(0);
                int cost = Integer.parseInt(st.nextToken());

                int idx = 0;
                while(st.hasMoreTokens()) {
                    int roomNum = Integer.parseInt(st.nextToken());
                    adj[n][idx++] = roomNum;
                }
                
                switch (code) {
                    case 'E':
                        rooms[n] = new EmptyRoom(cost);
                        break;
                    case 'L':
                        rooms[n] = new LeprechaunRoom(cost);
                        break;
                    case 'T':
                        rooms[n] = new TrollRoom(cost);
                        break;
                }
            }
            
            // Arrays.fill(v, -1);
            boolean[] v = new boolean[N + 1];
            sb.append(dfs(new Player(0), 1, v) ? "Yes\n" : "No\n");
        }
        System.out.println(sb);
    }

    static boolean dfs(Player p, int roomNum, boolean[] v) {
        if(!rooms[roomNum].enter(p)) return false;;

        if(roomNum == N) return true;
        
        int idx = 0;
        while(adj[roomNum][idx] != 0) {
            if(!v[adj[roomNum][idx]]) {
                v[adj[roomNum][idx]] = true;
                Player clone = new Player(p.money);
                if(dfs(clone, adj[roomNum][idx], v)) return true;
                v[adj[roomNum][idx]] = false;
            }
            ++idx;
        }
        return false;
    }
}