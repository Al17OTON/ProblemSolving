import java.util.*;

class Solution {
    
    class Hand implements Comparable<Hand> {
        Pos left, right;
        int idx, cost;
        public Hand(Pos left, Pos right, int idx, int cost) {
            this.left = new Pos(left);
            this.right = new Pos(right);
            this.idx = idx;
            this.cost = cost;
        }
        
        public int compareTo(Hand o) {
            return this.cost - o.cost;
        }
    }
    
    class Pos {
        int r, c;
        public Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
        public Pos(Pos p) {
            this.r = p.r;
            this.c = p.c;
        }
    }
    
    char[][] map = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}
    };
    
    int[][][] dp = new int[10][10][100001];
    
    public int solution(String numbers) {
        // return dfs(numbers, 0, new Pos(1, 0), new Pos(1, 2));
        return bfs(numbers);
    }
    
    int bfs(String numbers) {
        PriorityQueue<Hand> q = new PriorityQueue();
        q.offer(new Hand(new Pos(1, 0), new Pos(1, 2), 0, 0));
        int result = Integer.MAX_VALUE;
        
        while(!q.isEmpty()) {
            Hand hand = q.poll();
            Pos left = hand.left;
            Pos right = hand.right;
            int idx = hand.idx;
            if(idx >= numbers.length()) {
                result = Math.min(result, hand.cost);
                continue;
            } 
            if(left.r == right.r && left.c == right.c) continue;
            
            int leftIdx = map[left.r][left.c] - '0';
            int rightIdx = map[right.r][right.c] - '0';

            if(dp[leftIdx][rightIdx][idx] != 0 && dp[leftIdx][rightIdx][idx] <= hand.cost) continue;
            dp[leftIdx][rightIdx][idx] = hand.cost;

            char number = numbers.charAt(idx);
            Pos target = getPos(number);

            int leftCost = getCost(left, target);
            int rightCost = getCost(right, target);
            
            q.offer(new Hand(target, right, idx + 1, hand.cost + leftCost));
            q.offer(new Hand(left, target, idx + 1, hand.cost + rightCost));

            // dp[leftIdx][rightIdx][idx] = Math.min(leftVal, rightVal);
        }
        
        return result;
    }
    
    int dfs(String numbers, int idx, Pos left, Pos right) {
        if(idx >= numbers.length()) return 0;

        if(left.r == right.r && left.c == right.c) return 9999999;
        
        int leftIdx = map[left.r][left.c] - '0';
        int rightIdx = map[right.r][right.c] - '0';
        
        if(dp[leftIdx][rightIdx][idx] != 0) return dp[leftIdx][rightIdx][idx];
        
        char number = numbers.charAt(idx);
        Pos target = getPos(number);
        
        int leftCost = getCost(left, target);
        int rightCost = getCost(right, target);
        
        int leftVal = leftCost + dfs(numbers, idx + 1, target, right);
        int rightVal = rightCost + dfs(numbers, idx + 1, left, target);
        
        return dp[leftIdx][rightIdx][idx] = Math.min(leftVal, rightVal);
    }
    
    int getCost(Pos finger, Pos target) {
        if(finger.r == target.r && finger.c == target.c) return 1;
        if(finger.r == target.r || finger.c == target.c) {
            return Math.abs(finger.r - target.r) * 2 + Math.abs(finger.c - target.c) * 2;
        }
        if(Math.abs(finger.r - target.r) == Math.abs(finger.c - target.c)) {
            return Math.abs(finger.r - target.r) * 3;
        }
        
        int r = Math.abs(finger.r - target.r);
        int c = Math.abs(finger.c - target.c);
        
        int min = Math.min(r, c);
        int max = Math.max(r, c);
        
        return (min * 3) + ((max - min) * 2); 
    }
    
    Pos getPos(char target) {
        for(int r = 0; r < 4; ++r) {
            for(int c = 0; c < 3; ++c) {
                if(map[r][c] == target) return new Pos(r, c);
            }
        }
        return null;
    }
}