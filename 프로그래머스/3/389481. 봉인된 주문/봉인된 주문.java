import java.util.*;
class Solution {
    //26진수
    public String solution(long n, String[] bans) {
        
        PriorityQueue<Long> pq = new PriorityQueue();
        for(String ban : bans) {
            pq.offer(getIndex(ban));
        }
        
        while(!pq.isEmpty() && pq.peek() <= n) {
            pq.poll();
            n++;
        }
        return getSpell(n);
    }
    
    long getIndex(String a) {
        long index = 0;
        for(int i = 0; i < a.length(); i++) {
            long c = (a.charAt(i) - 'a') + 1;
            index += c * pow(a.length() - (i + 1));
        }
        return index;
    }
    
    long pow(int p) {
        long result = 1;
        for(int i = 0; i < p; i++) result *= 26;
        return result;
    }
    
    String getSpell(long n) {
        ArrayList<Character> list = new ArrayList();
        while(n > 26) {
            int tmp = (int)(n % 26) - 1;
            if(tmp == -1) {
                n--;
                tmp = 25;
            }
            char a = (char)(tmp + 'a');
            list.add(a);
            n /= 26L;
        }
        list.add((char)((int)(n - 1) + 'a'));
        
        String res = "";
        for(int i = list.size() - 1; i >= 0; i--) {
            res += list.get(i);
        }
        
        return res;
    }
}