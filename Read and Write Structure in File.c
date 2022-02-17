#include<stdio.h>
#include<stdlib.h>

struct student
{
int id;
char name[100];
int marks;
};

struct Admin
{
struct student std[10];
};
 void write(struct Admin *ptr)
{
    int n;
    FILE *wptr;
    fflush(stdin);
    wptr = fopen("student_file.txt", "w");

   printf("Enter number of student details to be recorded: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("\nEnter the student %d details:\n",(i+1));

        printf("\nID: ");
        scanf("%d",&ptr->std[i].id);

        printf("Name: ");
        scanf("%s",ptr->std[i].name);

        printf("Marks: ");
        scanf("%d",&ptr->std[i].marks);

        fprintf(wptr,"%d\t %s\t %d\n",ptr->std[i].id,ptr->std[i].name,ptr->std[i].marks);
    }
   fclose(wptr);
}

void read(struct Admin *ptr)
{

    FILE *rptr;
    int i, n;

    rptr=fopen("student_file.txt","r");
    if(rptr==NULL)
    {
        printf(stderr,"\nerror opening the file\n");
        exit(1);
    }

    printf("Enter the number of details to be displayed: ");
    scanf("%d",&n);

    printf("\n\nDetail of students:\n------------------------------------\nId\t\tName\t\tMarks\t");
    printf("\n------------------------------------\n");

    for(i=0;i<n;i++)
    {
        fscanf(rptr,"%d %s %d",&ptr->std[i].id,&ptr->std[i].name,&ptr->std[i].marks);
        printf("\n%d\t",ptr->std[i].id);
        printf("\t%s\t",ptr->std[i].name);
        printf("\t%d",ptr->std[i].marks);

    }

fclose(rptr);
}


int main()
{
    struct Admin a;
    struct Admin *ptr=NULL;
    ptr=&a;
    write(ptr);
    read(ptr);
    return(0);

}
