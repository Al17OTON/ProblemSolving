import java.util.*;

class Room implements Comparable<Room> {
//     int startHour, startMin, endHour, endMin;
//     public Room(int sh, int sm, int eh, int em) {
//         startHour = sh;
//         startMin = sm;
//         endHour = eh;
//         endMin = em;
//     }
    
//     public int compareTo(Room o) {
//         if(this.startHour == o.startHour) {
//             if(this.startMin == o.startMin) {
                
//             }
//             return this.startMin - o.startMin;
//         } 
//         return this.startHour - o.startHour;
//     }
    
    int start, end;
    public Room(String start, String end) {
        int hour = Integer.parseInt(start.substring(0, 2));
        int min = Integer.parseInt(start.substring(3, 5));
        this.start = hour * 100 + min;
        
        hour = Integer.parseInt(end.substring(0, 2));
        min = Integer.parseInt(end.substring(3, 5)) + 10;
        if(min >= 60) {
            min -= 60;
            hour += 1;
        }
        this.end = hour * 100 + min;
    }
    
    public int compareTo(Room o) {
        if(this.start == o.start) return this.end - o.end;
        return this.start - o.start;
    }
    
    // public int compareTo(Room o) {
    //     if(this.start.compareTo(o.start) == 0) return this.end.compareTo(o.end);
    //     return this.start.compareTo(o.start);
    // }
}

class Solution {
    PriorityQueue<Room> pq = new PriorityQueue();
    PriorityQueue<Integer> roomPq = new PriorityQueue();
    
    public int solution(String[][] book_time) {
        int answer = 0;
        
        for(String[] book : book_time) {
            pq.offer(new Room(book[0], book[1]));
        }
        
        while(!pq.isEmpty()) {
            Room room = pq.poll();
            // System.out.println(room.start + " " + room.end);
            while(!roomPq.isEmpty() && roomPq.peek() <= room.start) {
                roomPq.poll();
            }
            
            roomPq.offer(room.end);
            answer = Math.max(answer, roomPq.size());
        }
        
        return answer;
    }
}