#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct pokemon 
{
    char name[20];
    int level;
    int hp;
    int attack;
    int defense;
}pokemon;
void print(pokemon p) // function to print the values of structure members
{
    printf("Name: %s\n",p.name); 
    printf("Level: %d\n",p.level);
    printf("HP: %d\n",p.hp);
    printf("Attack: %d\n",p.attack);
    printf("Defense: %d\n",p.defense);
}
void change(pokemon* p) // function to change the values of structure members using pointer
{
    strcpy(p->name,"Charizard"); // using pointer to access structure members 
    p->level=10;
    p->hp=200;
    p->attack=80;
    p->defense=50;
}
void main()
{
    pokemon a; // declaring a structure variable of type pokemon
    pokemon* p1=&a; // declaring a pointer to a structure variable of type pokemon

    strcpy(a.name,"Pikachu"); 
    a.level=5;
    a.hp=100;
    a.attack=50;
    a.defense=30;
    print(a);
    
    (*p1).level=10; // using pointer to access structure members 
    change(p1);
    print(a);
} 
