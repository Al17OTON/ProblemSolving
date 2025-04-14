import java.util.*;

class Solution {
    
    class State {
        int ar, ac, br, bc;
        boolean[][] av, bv;
        
        public State(int ar, int ac, int br, int bc, int N, int M) {
            this.ar = ar;
            this.ac = ac;
            this.br = br;
            this.bc = bc;
            
            av = new boolean[N][M];
            bv = new boolean[N][M];
        }
        
        public State(int ar, int ac, int br, int bc, boolean[][] av, boolean[][] bv) {
            this.ar = ar;
            this.ac = ac;
            this.br = br;
            this.bc = bc;
            
            this.av = av;
            this.bv = bv;
        }
        
        boolean[][] getAv() {
            boolean[][] v = new boolean[N][];
            for(int r = 0; r < N; ++r) v[r] = av[r].clone();
            return v;
        }
        boolean[][] getBv() {
            boolean[][] v = new boolean[N][];
            for(int r = 0; r < N; ++r) v[r] = bv[r].clone();
            return v;
        }
    }
    
    int N, M;
    boolean[][] map;
    State start;
    int[] aEnd, bEnd;
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    
    public int solution(int[][] maze) {
        int answer = 0;
        N = maze.length;
        M = maze[0].length;
        map = new boolean[N][M];
        
        start = new State(0,0,0,0, N, M);
        
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < M; ++c) {
                if(maze[r][c] == 1) {
                    start.ar = r;
                    start.ac = c;
                } else if(maze[r][c] == 2) {
                    start.br = r;
                    start.bc = c;
                } else if(maze[r][c] == 3) {
                    aEnd = new int[] {r, c};
                } else if(maze[r][c] == 4) {
                    bEnd = new int[] {r, c};
                } else if(maze[r][c] == 5) {
                    map[r][c] = true;
                }
            }
        }
        
        return bfs();
    }
    
    
    int bfs() {
        int turn = 0;
        Queue<State> q = new LinkedList();
        start.av[start.ar][start.ac] = true;
        start.bv[start.br][start.bc] = true;
        q.offer(start);
        
        while(!q.isEmpty()) {
            int size = q.size();
            for(int s = 0; s < size; ++s) {
                State state = q.poll();
                
                if(state.ar == aEnd[0] && state.ac == aEnd[1] && state.br == bEnd[0] && state.bc == bEnd[1]) return turn;
                // printMap(state);
                aFirst(q, state);
                bFirst(q, state);
            }
            
            ++turn;
        }
        
        return 0;
    }
    
    void aFirst(Queue<State> q, State state) {
        if(state.ar == aEnd[0] && state.ac == aEnd[1]) return;
        
        for(int d = 0; d < 4; ++d) {
            int nr = state.ar + dr[d];
            int nc = state.ac + dc[d];
            
            if(nr >= N || nr < 0 || nc >= M || nc < 0 || map[nr][nc] || state.av[nr][nc]) continue;
            
            if(state.br == bEnd[0] && state.bc == bEnd[1]) {
                if(nr == state.br && nc == state.bc) continue;
                boolean[][] nAv = state.getAv();
                nAv[nr][nc] = true;
                q.offer(new State(nr, nc, state.br, state.bc, nAv, state.bv));
                continue;
            }
            
            for(int dd = 0; dd < 4; ++dd) {
                int nbr = state.br + dr[dd];
                int nbc = state.bc + dc[dd];
                
                if(nbr >= N || nbr < 0 || nbc >= M || nbc < 0 || map[nbr][nbc] || state.bv[nbr][nbc] || (nbr == nr && nbc == nc) || (nr == state.br && nc == state.bc && nbr == state.ar && nbc == state.ac)) continue;
                boolean[][] nAv = state.getAv();
                boolean[][] nBv = state.getBv();
                nAv[nr][nc] = true;
                nBv[nbr][nbc] = true;
                
                q.offer(new State(nr, nc, nbr, nbc, nAv, nBv));
            }
            
        }
    }
    void bFirst(Queue<State> q, State state) {
        if(state.br == bEnd[0] && state.bc == bEnd[1]) return;
        
        for(int d = 0; d < 4; ++d) {
            int nr = state.br + dr[d];
            int nc = state.bc + dc[d];
            
            if(nr >= N || nr < 0 || nc >= M || nc < 0 || map[nr][nc] || state.bv[nr][nc]) continue;
            
            if(state.ar == aEnd[0] && state.ac == aEnd[1]) {
                if(nr == state.ar && nc == state.ac) continue;
                boolean[][] nBv = state.getBv();
                nBv[nr][nc] = true;
                q.offer(new State(state.ar, state.ac, nr, nc, state.av, nBv));
                continue;
            }
            
            for(int dd = 0; dd < 4; ++dd) {
                int nar = state.ar + dr[dd];
                int nac = state.ac + dc[dd];
                
                if(nar >= N || nar < 0 || nac >= M || nac < 0 || map[nar][nac] || state.av[nar][nac] || (nar == nr && nac == nc) || (nr == state.ar && nc == state.ac && nar == state.br && nac == state.bc)) continue;
                
                boolean[][] nAv = state.getAv();
                boolean[][] nBv = state.getBv();
                nAv[nar][nac] = true;
                nBv[nr][nc] = true;
                
                q.offer(new State(nar, nac, nr, nc, nAv, nBv));
            }
            
        }
    }
    
    void printMap(State state) {
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < M; ++c) {
                char i = ' ';
                if(state.ar == r && state.ac == c) i = 'a';
                else if(state.br == r && state.bc == c) i = 'b';
                else if(map[r][c]) i = 'X';
                System.out.print(i + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}