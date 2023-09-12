package part2.ch5.boj16987;

import java.util.Scanner;

public class Main {


    public static int n;
    public static Egg[] eggs;
    public static int answer = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        eggs = new Egg[n];
        for(int i = 0; i < n; i++) {
            eggs[i] = new Egg(sc.nextInt(), sc.nextInt());
        }
        solve(0);
        System.out.println(answer);
    }
    public static void solve(int pick) {
        if(pick == n) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(eggs[i].durability <= 0) count++;
            }
            answer = Math.max(answer, count);
            return;
        }

        if(eggs[pick].durability > 0) {
            boolean targetExists = false;
            for(int target = 0; target < n; target++) {
                if(target == pick) continue;
                if(eggs[target].durability > 0) {
                    targetExists = true;
                    eggs[pick].fight(eggs[target]);
                    solve(pick + 1);
                    eggs[pick].restore(eggs[target]);
                }
            }
            if(!targetExists) solve(pick + 1);
        }
        else {
            solve(pick + 1);
        }
    }
}

class Egg {
    int durability;
    int weight;

    public Egg(int durability, int weight) {
        this.durability = durability;
        this.weight = weight;
    }

    public void fight(Egg other) {
        this.durability -= other.weight;
        other.durability -= this.weight;
    }

    public void restore(Egg other) {
        this.durability += other.weight;
        other.durability += this.weight;
    }
}
