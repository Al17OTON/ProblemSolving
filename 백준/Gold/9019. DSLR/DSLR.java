import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/*
D : n*2 -> 값이 9999보다 크면 10000 떼고 나머지 4자리 저장
S : n-1 -> 값이 0이면 9999 저장
L : 왼편으로 -> 1234이면 2341
 -> 1234*10%10000 + 1234*10/10000
R : 오른편으로 -> 1234이면 4123
 -> 1234/10 + 1234%10*1000
 -> 0123/10 + 0123%10*1000
 */
class Map {
    int num;
    String ans;
    Map (int num, String ans) {
        this.num = num;
        this.ans = ans;
    }
}
public class Main {
    static int answerN, inputN;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());


        for(int t=0; t<T; t++) {
            st = new StringTokenizer(br.readLine());
            inputN = Integer.parseInt(st.nextToken());
            answerN = Integer.parseInt(st.nextToken());

            String out = BFS(inputN);

            System.out.println(out);
        }

    }

    static String BFS(int n) {

        Deque<Map> q = new ArrayDeque<>();
        boolean[] visit = new boolean[10000];
        q.add(new Map(n, ""));
        visit[n] = true;
        String out = "";

        while (!q.isEmpty()) {
            int nNum;

            Map map = q.pollFirst();
            int num = map.num;
            String answer = map.ans;

            nNum = num*2%10000;
            if(nNum == answerN) {
                out= answer+"D";
                break;
            }
            else {
                if(!visit[nNum]) {
                    visit[nNum] = true;
                    q.add(new Map(nNum, answer+"D") );
                }
            }

            nNum = num-1;
            if(num==0) nNum=9999;
            if(nNum ==answerN) {
                out= answer+"S";
                break;
            }
            else {
                if(!visit[nNum]) {
                    visit[nNum] = true;
                    q.add(new Map(nNum, answer+"S") );
                }
            }

            //12340%10000 + 1234*10/10000
            nNum = (num*10) %10000 + num/1000;
            if(nNum ==answerN) {
                out= answer+"L";
                break;
            }
            else {
                if(!visit[nNum]) {
                    visit[nNum] = true;
                    q.add(new Map(nNum, answer+"L") );
                }
            }
            //1234/10 + 1234%10*1000
            nNum = num/10 + (num%10)*1000;
            if(nNum ==answerN) {
                out= answer+"R";
                break;
            }
            else {
                if(!visit[nNum]) {
                    visit[nNum] = true;
                    q.add(new Map(nNum, answer+"R") );
                }

            }
        }

        return out;
    }

}