#include<stdio.h>
#include<string.h>
void main(){
    struct pokemon
    {
        char name[10];
        int speed;
        int attack;
        char tier;
    }a,b,c; 

    strcpy(a.name,"Pikachu");
    a.attack=100;
    a.speed=200;
    a.tier='A'; 

    b=a; // Copying structure a to b
    strcpy(b.name,"Charizrad"); // Modifying member of structure b 

    printf("Name of a: %s\n", a.name); // Accessing member of structure a
    printf("Attack of a: %d\n", a.attack);    
    printf("Speed of a: %d\n", a.speed); 
    printf("Tier of a: %c\n", a.tier); 

    printf("Name of b: %s\n", b.name); // Accessing member of structure b
    printf("Attack of b: %d\n", b.attack); 
    printf("Speed of b: %d\n", b.speed); 
    printf("Tier of b: %c\n", b.tier); 
}
// Output:
// Name of a: Pikachu
// Attack of a: 100
// Speed of a: 200
// Tier of a: A
// Name of b: Charizrad
// Attack of b: 300
// Speed of b: 200
// Tier of b: A
// The output shows that modifying b does not affect a, demonstrating deep copying.