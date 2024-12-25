import java.util.*;
class Solution {
    // 2 ~ 9진법이므로 9는 수식에 존재 불가능
    
    // 불가능한 진법 표시
    boolean[] isNot = new boolean[10];
    // X가 존재하는 수식 표시
    boolean[] need2Fill;
    //수식의 최대 숫자를 찾아서 최소 가능 진법을 찾는다.
    int MAX_NUM = 1;
    int count = 0; // X 카운트
    public String[] solution(String[] expressions) {
        String[] result;
        need2Fill = new boolean[expressions.length];
        for(int i = 0; i < expressions.length; i++) {
            String tmp = expressions[i];
            for(int j = 0; j < tmp.length(); j++) {
                if(tmp.charAt(j) == 'X') {
                    count++;
                    need2Fill[i] = true;
                }
                
                if(tmp.charAt(j) >= '0' && tmp.charAt(j) <= '9')MAX_NUM = Math.max(MAX_NUM, tmp.charAt(j) - '0');
            }   
        }
        
        for(int i = 0; i < expressions.length; i++) {
            // 미지수가 존재하지 않는다면 진법을 찾아본다.
            if(!need2Fill[i]) findBase(expressions[i]);
        }
        result = new String[count];
        int idx = 0;
        
        // 가능한 진법들로 수식을 하나씩 채워본다.
        for(int i = 0; i < expressions.length; i++) {
            String prev = null;
            if(need2Fill[i]) {
                for(int j = MAX_NUM + 1; j < 10; j++) {
                    if(!isNot[j]) {
                        String res = guess(expressions[i], j);
                        //이전 진법과 결과가 다르다면 ? 넣기
                        if(prev != null && prev.compareTo(res) != 0) {
                            prev = "?";
                            break;
                        }
                        prev = res;
                    }
                }
                
                result[idx++] = expressions[i].substring(0, expressions[i].length() - 1) + prev;
                
            }
        }
        
        return result;
    }
    
    // 가능한 진법을 모두 해보고 불가능한 진법을 표시한다
    void findBase(String a) {
        StringTokenizer st = new StringTokenizer(a);
        String A = st.nextToken();
        char calc = st.nextToken().charAt(0);
        String B = st.nextToken();
        st.nextToken(); // '=' 지우기
        String C = st.nextToken();
        
        for(int i = MAX_NUM + 1; i < 10; i++) {
            if(!isNot[i] && calcuration(A, B, calc, i) != n210(C, i)) isNot[i] = true; 
        }
    }
    
    // 가능한 진법을 사용하여 정답 유추
    String guess(String a, int base) {
        StringTokenizer st = new StringTokenizer(a);
        String A = st.nextToken();
        char calc = st.nextToken().charAt(0);
        String B = st.nextToken();
        
        return ten2N(calcuration(A, B, calc, base), base);
    }
    
    //진법에 맞춰서 계산
    //머리아프니까 10진법으로 변환하고 다시 원래 진법으로 변환
    int calcuration(String A, String B, char calc, int base) {
        int a = n210(A, base);
        int b = n210(B, base);
        return calc == '+' ? a + b : a - b;
    }
    
    // 특정 숫자를 10진법으로 변환
    int n210(String a, int base) {
        int res = 0;
        for(int i = a.length() - 1; i >= 0; i--) {
            int num = a.charAt(i) - '0';
            res += num * Math.pow(base, a.length() - i - 1);
        }
        // System.out.println(res);
        return res;
    }
    
    // 10진법의 수를 특정 진법의 수로 변환
    String ten2N(int ten, int base) {
        return Integer.toString(ten, base);
    }
}