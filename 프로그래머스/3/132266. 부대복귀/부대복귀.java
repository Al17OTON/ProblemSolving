import java.util.*;

class Solution {

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        Arrays.fill(answer, -1);
        
        List<List<Integer>> adj = new ArrayList();
        for(int i = 0; i <= n; ++i) adj.add(new ArrayList());
        
        for(int i = 0; i < roads.length; ++i) {
            adj.get(roads[i][0]).add(roads[i][1]);
            adj.get(roads[i][1]).add(roads[i][0]);
        }
        
        bfs(n, destination, answer, sources, adj);
        
        return answer;
    }
    
    void bfs(int n, int dest, int[] answer, int[] source, List<List<Integer>> adj) {
        int[] sourceIdx = new int[n + 1];
        Arrays.fill(sourceIdx, -1);
        for(int i = 0; i < source.length; ++i) {
            sourceIdx[source[i]] = i;
        }
        
        boolean[] v = new boolean[n + 1];
        v[dest] = true;
        Queue<Integer> q = new LinkedList();
        q.offer(dest);
        
        int time = 0;
        while(!q.isEmpty()) {
            int size = q.size();
            for(int s = 0; s < size; ++s) {
                int pos = q.poll();
                
                if(sourceIdx[pos] != -1) {
                    answer[sourceIdx[pos]] = time;
                }
                
                for(int i = 0; i < adj.get(pos).size(); ++i) {
                    int next = adj.get(pos).get(i);
                    if(v[next]) continue;
                    v[next] = true;
                    q.offer(next);
                }
                
            }
            ++time;
        }
        
    }
}