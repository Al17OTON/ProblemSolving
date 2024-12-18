class Solution {
    int time = 0, stack = 0, currentHealth, health;
    int[] bandage;
    
    public int solution(int[] bandage, int health, int[][] attacks) {
        this.health = health;
        currentHealth = health;
        this.bandage = bandage;
        
        for(int i = 0; i < attacks.length; i++) {
            int[] attack = attacks[i];
            stack = 0;
        
            while(time++ < attack[0]) {
                heal();
            }
            
            currentHealth -= attack[1];
            if(isDead()) return -1;    
        } 
        
        return currentHealth;
    }
    
    void heal() {
        currentHealth += bandage[1];
        stack++;
        if (stack == bandage[0]) {
            currentHealth += bandage[2];
            stack = 0;
        }
        
        healthLimit();
    }
    
    void healthLimit() {
        currentHealth = Math.min(currentHealth, health);
    }
    
    boolean isDead() {
        return currentHealth <= 0;
    }
}   