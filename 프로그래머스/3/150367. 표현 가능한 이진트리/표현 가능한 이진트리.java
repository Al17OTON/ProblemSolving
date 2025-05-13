class Solution {
    
    // 중위순회
    // 주어진 10진수를 2진수로 변환
    // 리프노드가 아닌 곳이 0이면 불가능?
    // 비트가 0인 곳이 리프노드가 아니라면 불가능을 판별하기
    
    // 포화이진트리이기 때문에 리프노트든 무조건 짝수 인덱스를 가진다.
    // 그 외에는 전부 홀수
    // 짝수 노드가 1인 경우가 있다면 그 위에 있는 모든 노드는 홀수이여야만 한다.
    
    boolean[] possibleRoot = new boolean[64];
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];
        
        // possibleRoot[0] = true;
        possibleRoot[1] = true;
        possibleRoot[3] = true;
        possibleRoot[7] = true;
        possibleRoot[15] = true;
        possibleRoot[31] = true;
        
        int idx = 0;
        for(long tree : numbers) {
            
            if(tree == 1L) {
                answer[idx++] = 1;
                continue;
            }
            int lev = 1;
            int startIdx = 0;
            int idxGap = 2;
            boolean result = true;
            
            L:while(startIdx < 31) {
                boolean flag = false;
                int counter = 0;
                boolean tmp = false;
                int tmpIdx = -1;
                for(int i = startIdx; i < 64; i += idxGap) {
                    long bit = tree & (1L << i);
                    if(bit > 0) {
                        int parentIdx;
                        if(!flag) {
                            parentIdx = i + lev;
                        } else {
                            parentIdx = i - lev;
                        }
                        
                        if((tree & (1L << parentIdx)) == 0) {
                            if(!tmp) {
                                tmp = true;
                                tmpIdx = i;
                            } else {
                                result = false;
                                break L;
                            }
                        }
                        ++counter;
                    }
                    flag = !flag;
                }
                if(tmp && (counter > 1 || !possibleRoot[tmpIdx])) {
                    result = false;
                    break L;
                }
                startIdx += lev;
                idxGap *= 2;
                lev *= 2;
            }
            answer[idx++] = result ? 1 : 0;
        }
        
        return answer;
    }

}


/*
7
111
42
0101010
5
101 루트노드가 0이라 불가능
63
0111111
111
1101111
95
1011111

136
010001000

0101010101010101010101010101010

[1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1]
[1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1]
*/