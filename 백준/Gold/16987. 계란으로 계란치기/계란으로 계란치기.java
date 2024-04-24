import java.util.Scanner;

class EGG {
    int s, w;

    public EGG(int s, int w) {
        this.s = s;
        this.w = w;
    }
}

public class Main {
    static EGG[] eggs;
    static int N, maxCount = -1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        eggs = new EGG[N];

        for(int i = 0; i < N; i++) {
            eggs[i] = new EGG(sc.nextInt(), sc.nextInt());
        }

        dfsEgg(0, eggs);

        System.out.println(maxCount);

    }

    static void dfsEgg(int idx, EGG[] egg) {
        if(idx == N) {
            int hit = 0;
            for(int i = 0; i < egg.length; i++) {
                if(egg[i].w == -1) hit++;
            }
            maxCount = Math.max(maxCount, hit);
            return;
        }
        if(egg[idx].w == -1) {
            dfsEgg(idx + 1, egg);
            return;
        }

        boolean flag = false;
        for(int i = 0; i < egg.length; i++) {
            if(egg[i].w != -1 && idx != i) {
                EGG[] copy = copyEgg(egg);
                hitEgg(copy, idx, i);
                dfsEgg(idx + 1, copy);
                flag = true;
            }
        }
        
        if(!flag) dfsEgg(idx + 1, egg);

    }

    static EGG[] copyEgg(EGG[] origin) {
        EGG[] copy = new EGG[origin.length];
        for(int i = 0; i < origin.length; i++) {
            copy[i] = new EGG(origin[i].s, origin[i].w);
        }
        return copy;
    }
    
    static void hitEgg(EGG[] egg, int held, int target) {
        egg[held].s -= egg[target].w;
        egg[target].s -= egg[held].w;

        if(egg[held].s <= 0) {
            egg[held].w = -1;
        }
        if(egg[target].s <= 0) {
            egg[target].w = -1;
        }
    }
}
