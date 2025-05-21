import java.util.*;

class Solution {
    public int solution(int x, int y, int n) {
        return bfs(x, y, n);
    }
    
    
    int bfs(int x, int y, int n) {
        Queue<Integer> q = new LinkedList();
        boolean[] v = new boolean[y + 1];
        v[x] = true;
        q.offer(x);
        int turn = 0;
        
        while(!q.isEmpty()) {
            int size = q.size();
            for(int s = 0; s < size; ++s) {
                int num = q.poll();

                if(num == y) {
                    return turn;
                }

                if(num + n <= y && !v[num + n]) {
                    v[num + n] = true;
                    q.offer(num + n);
                }

                if(num * 2 <= y && !v[num * 2]) {
                    v[num * 2] = true;
                    q.offer(num * 2);
                }

                if(num * 3 <= y && !v[num * 3]) {
                    v[num * 3] = true;
                    q.offer(num * 3);
                }
            }
            ++turn;
        }
        
        
        
        return -1;
    }
}