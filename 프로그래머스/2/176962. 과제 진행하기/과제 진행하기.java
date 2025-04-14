import java.util.*;

class Solution {
    
    class Plan implements Comparable<Plan> {
        String name;
        int startHour, startMin, cost;
        
        public Plan(String name, String start, String playtime) {
            this.name = name;
            StringTokenizer st = new StringTokenizer(start, ":");
            startHour = Integer.parseInt(st.nextToken());
            startMin = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(playtime);
        } 
        
        public int compareTo(Plan o) {
            if(startHour == o.startHour) return startMin - o.startMin;
            return startHour - o.startHour;
        }
        
        boolean isDone() {
//             int endHour = startHour + ((startMin + cost) / 60);
//             int endMin = (startMin + cost) % 60;
            
//             if(endHour == o.startHour) return endMin <= o.startMin;
//             return endHour < o.startHour;
            return cost <= 0;
        }
        
        int getBetween(Plan o) {
            return (o.startMin - startMin) + (o.startHour - startHour) * 60;
        }
    }
    
    PriorityQueue<Plan> pq = new PriorityQueue();
    ArrayDeque<Plan> stack = new ArrayDeque();
    
    public String[] solution(String[][] plans) {
        String[] answer = new String[plans.length];
        int idx = 0;
        
        for(String[] plan : plans) {
            pq.offer(new Plan(plan[0], plan[1], plan[2]));
        }
        
        while(!pq.isEmpty()) {
            // System.out.println(pq.poll().name);
            Plan plan = pq.poll();
            
            if(!stack.isEmpty()) {
                int past = stack.peekLast().getBetween(plan);
                stack.peekLast().cost -= past;
                
                while(!stack.isEmpty() && stack.peekLast().isDone()) {
                    Plan latest = stack.pollLast();
                    answer[idx++] = latest.name;
                    if(!stack.isEmpty()) stack.peekLast().cost += latest.cost;
                }
            }
            stack.offerLast(plan);
        }
        
        while(!stack.isEmpty()) answer[idx++] = stack.pollLast().name;
        
        return answer;
    }
}