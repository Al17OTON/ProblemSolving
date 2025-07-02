import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Arduino {
        int r, c;
        boolean isDead;
        public Arduino(int r, int c) {
            this.r = r;
            this.c = c;
            isDead = false;
        }
        
    }

    static int R, C;
    static char[][] map;
    static int[][] collision;
    static String command;
    static Arduino player;
    static List<Arduino> mad = new ArrayList();
    static Queue<Integer> collideQ = new LinkedList<>();

    static int[] dr = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
    static int[] dc = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        map = new char[R][];
        collision = new int[R][C];
        for(int r = 0; r < R; ++r) Arrays.fill(collision[r], -1);

        int idx = 0;
        for(int r = 0; r < R; ++r) {
            map[r] = br.readLine().toCharArray();
            for(int c = 0; c < C; ++c) {
                if(map[r][c] == 'I') {
                    player = new Arduino(r, c);
                    map[r][c] = '.';
                } else if(map[r][c] == 'R') {
                    mad.add(new Arduino(r, c));
                    map[r][c] = '.';
                    collision[r][c] = idx++;
                }
            }
        }
        
        command = br.readLine();

        sim();
    }

    static void sim() {
        
        for(int i = 0; i < command.length(); ++i) {
            int dir = command.charAt(i) - '0';

            player.r += dr[dir];
            player.c += dc[dir];

            if(checkPlayerCollide()) {
                System.out.println("kraj " + (i + 1));
                return;
            }

            for(int j = 0; j < mad.size(); ++j) {
                move(j);
            }

            for(int j = 0; j < mad.size(); ++j) {
                setPos(j);
            }

            if(checkPlayerCollide()) {
                System.out.println("kraj " + (i + 1));
                return;
            }

            while(!collideQ.isEmpty()) {
                Arduino ard = mad.get(collideQ.poll());
                ard.isDead = true;
                collision[ard.r][ard.c] = -1;
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if(collision[r][c] != -1) sb.append('R');
                else if(player.r == r && player.c == c) sb.append('I');
                else sb.append('.');
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    static void setPos(int idx) {
        Arduino ard = mad.get(idx);
        if(ard.isDead) return;

        if(collision[ard.r][ard.c] != -1) {
            if(collision[ard.r][ard.c] != -10) {
                collideQ.offer(collision[ard.r][ard.c]);
                collision[ard.r][ard.c] = -10;

            }
            collideQ.offer(idx);
            return;
        }

        collision[ard.r][ard.c] = idx;
    }

    static void move(int idx) {
        Arduino ard = mad.get(idx);
        if(ard.isDead) return;

        collision[ard.r][ard.c] = -1;

        int r = player.r - ard.r;
        int c = player.c - ard.c;
        
        if(r != 0) r /= Math.abs(r);
        if(c != 0) c /= Math.abs(c);

        ard.r += r;
        ard.c += c;
    }

    static boolean checkPlayerCollide() {
        return collision[player.r][player.c] != -1;
    }
}