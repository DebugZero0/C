#include<stdio.h>
#include<string.h>
int main(){
    struct student // Structure declaration
    {
        char name[20]; // Structure members
        char address[20];
        int rollno;
    }s1,s2,s3; // Structure variable declaration
    
    // Structure variable initialization
    s1.rollno=3;
    strcpy(s1.name,"Ankan");
    strcpy(s1.address,"Delhi");

    s2.rollno=2;
    strcpy(s2.name,"vikash");
    strcpy(s2.address,"Mumbai");

    // s3.rollno=1;
    // strcpy(s3.name,"Ravi");
    // strcpy(s3.address,"Banglore");
    struct student s3={1,"Ravi","Banglore"}; // Structure variable initialization using compound literal

    struct student stu[10]; // Array of structure
    stu[0]=s1; // Copying structure data to array of structure
    stu[1]=s2; 
    stu[2]=s3; 
    for(int i=0;i<3-1;i++){
        for(int j=0;j<3-i-1;j++){
            if(stu[j].rollno>stu[j+1].rollno){ // Sorting the array of structure based on roll number
                struct student temp=stu[j]; // Temporary structure to swap the data
                stu[j]=stu[j+1]; // Swapping the data
                stu[j+1]=temp; // Swapping the data
            }
        }
    }
    printf("Roll No\tName\tAddress\n"); // Printing the structure data
    for(int i=0;i<3;i++){
        printf("%d\t%s\t%s\n",stu[i].rollno,stu[i].name,stu[i].address); // Printing the structure data
    } 

}
// Output:
// Roll No	Name	Address
// 1		Ravi	Banglore
// 2		vikash	Mumbai  
// 3		Ankan	Delhi