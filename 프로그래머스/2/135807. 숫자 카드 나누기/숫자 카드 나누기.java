import java.util.*;

class Solution {
    // 모든 숫자를 나눌수있어야 하므로 각 배열의 가장 작은값의 약수 중 하나다.
    // 가장 작은 값의 약수들 중 모든 카드를 나눌 수 있는 값만 찾는다.
    // 그러한 약수들 중 가장 큰 값 부터 상대 카드를 나눌 수 없는 값을 찾는다.
    public int solution(int[] arrayA, int[] arrayB) {

        Arrays.sort(arrayA);
        Arrays.sort(arrayB);
        
        int minA = arrayA[0];
        int minB = arrayB[0];
        
        List<Integer> listA = getCommonDivisor(arrayA, getDivisor(minA));
        List<Integer> listB = getCommonDivisor(arrayB, getDivisor(minB));
        
        int mostA = foundMostNotCommon(arrayB, listA);
        int mostB = foundMostNotCommon(arrayA, listB);
        
        return Math.max(mostA, mostB);
    }
    
    int foundMostNotCommon(int[] arr, List<Integer> list) {
        for(int i = list.size() - 1; i >= 0; --i) {
            int div = list.get(i);
            boolean flag = true;
            for(int j = 0; j < arr.length; ++j) {
                if(arr[j] % div == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) return div;
        }
        return 0;
    }
    
    List<Integer> getDivisor(int num) {
        List<Integer> list = new ArrayList();
        
        for(int i = 2; i < num; ++i) {
            if(num % i == 0) list.add(i);
        }
        list.add(num);
        return list;
    }
    
    List<Integer> getCommonDivisor(int[] arr, List<Integer> list) {
        List<Integer> common = new ArrayList();
        
        for(int div : list) {
            boolean flag = true;
            for(int i = 1; i < arr.length; ++i) {
                if(arr[i] % div != 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) common.add(div);
        }
        
        return common;
    }
}