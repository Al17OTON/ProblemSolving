import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N, R;
    static Map<String, Integer> map = new HashMap<>();
    static int[] featureCount;
    static List<String> features = new ArrayList<>(); 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st, st2;
        StringBuilder sb = new StringBuilder();
        featureCount = new int[(int)Math.pow(2, 9)];
        N = Integer.parseInt(br.readLine());

        for(int n = 0; n < N; ++n) {
            map.put(br.readLine(), 0);
        }
        featureCount[0] = N;

        R = Integer.parseInt(br.readLine());

        for(int r = 0; r < R; ++r) {
            st = new StringTokenizer(br.readLine());

            char command = st.nextToken().charAt(0);

            if(command == 'U') {
                String target = st.nextToken();
                st2 = new StringTokenizer(st.nextToken(), ",");
                int feat = 0;
                while(st2.hasMoreTokens()) {
                    feat |= (1 << feat2Integer(st2.nextToken()));
                }
                --featureCount[map.replace(target, feat)];
                ++featureCount[feat];
                

            } else {
                st2 = new StringTokenizer(st.nextToken(), ",");
                int feat = 0;
                boolean flag = false;
                while(st2.hasMoreTokens()) {
                    int idx = getFeatureIdx(st2.nextToken());
                    if(idx == -1) {
                        flag = true;
                        break;
                    }
                    feat |= (1 << idx);
                }
                int sum = 0;
                if(!flag) {
                    for(int i = feat; i < featureCount.length; ++i) {
                        if((i & feat) == feat) sum += featureCount[i];
                    }   
                } 
                
                sb.append(sum).append("\n");
            }
        }

        System.out.println(sb);
    }

    static int feat2Integer(String feature) {
        for(int i = 0; i < features.size(); ++i) {
            if(features.get(i).equals(feature)) return i;
        }
        features.add(feature);
        return features.size() - 1;
    }
    static int getFeatureIdx(String feature) {
        for(int i = 0; i < features.size(); ++i) {
            if(features.get(i).equals(feature)) return i;
        }
        return -1;
    }
}