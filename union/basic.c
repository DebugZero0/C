#include<stdio.h>
#include<string.h>
typedef struct pokemon{
    int attack;
    int hp;
    char name[15];
}pk;

typedef union beyblade
{
    int attack;
    char name[15];
    int hp;
}bd;

void main(){
    pk a={100,50,"Pikachu"}; 
    bd b={10,"pegasus",30};
    printf("Name:\t%s\nAttack:\t%d\nHp:\t%d\n",a.name,a.attack,a.hp);
    printf("Size of struct:%d\n",sizeof(pk)-1);

    printf("Name:\t%s\nAttack:\t%d\nHp:\t%d\n",b.name,b.attack,b.hp);
    printf("Size of union:%d",sizeof(bd)-1);
} 
