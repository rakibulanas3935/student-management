#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Student
{
    int id;
    char name[50];
    char phone[50];
    int age;
    int year;
    char district[100];
    float cgpa;
    struct Student *next;

}* head;

void insert(int id, char* name, char* phone, float cgpa,char* district,int age,int year)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->id = id;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->cgpa = cgpa;
     
	strcpy(student->district, district);
	student->age=age;
	student->year=year;
    student->next = NULL;

    if(head==NULL)
    {
        head = student;
    }
    else
    {
        student->next = head;
        head = student;
       
          
    }

}
void search(int id,char* name)
{
    struct Student * temp = head;
    while(temp!=NULL)
    {
        if(temp->id==id || temp->id==name)
        {
        	
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t    ID: %d\n", temp->id);
        printf("\t\t\t\t 	Name: %s\n", temp->name);
        printf("\t\t\t\t 	Phone: %s\n", temp->phone);
        printf("\t\t\t\t 	District: %s\n", temp->district);
        printf("\t\t\t\t 	Age: %d\n", temp->age);
        printf("\t\t\t\t 	Admission year: %d\n", temp->year);
        printf("\t\t\t\t 	cgpa: %0.2f\n\n", temp->cgpa);
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");            
        return;
        }
        temp = temp->next;
    }
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   Student with id %d is not found !!!\n", id);
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n"); 
}
void update(int id)
{

    struct Student * temp = head;
    while(temp!=NULL)
    {

        if(temp->id==id)
        
        {
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   Record Found !!!\n", id);
       	printf("\t\t\t\t   Enter New name: ");
        scanf("%s", temp->name);
        fflush(stdin);
        printf("\t\t\t\t   Enter New phone number: ");
        scanf("%s", temp->phone);
        fflush(stdin);
		printf("\t\t\t\t   Enter New district: ");
        scanf("%s", temp->district);
        fflush(stdin);
        printf("\t\t\t\t   Enter New age: ");
        scanf("%d", &temp->age);
        printf("\t\t\t\t   Enter New Admitted year: ");
        scanf("%d", &temp->year);
        printf("\t\t\t\t   Enter New cgpa: ");
        scanf("%f", &temp->cgpa);
       
        printf("\t\t\t\t    Updation Successful!!!\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        return;
        }
        temp = temp->next;

    }
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   Student with ID number %d is not found !!!\n", id);
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");

}
void Delete(int id)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head;
    while(temp1!=NULL)
    {

        if(temp1->id==id)
        {
			printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    		printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   Record with id %d Found !!!\n", id);
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    		printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");

            if(temp1==temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }
			printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    		printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   Record Successfully Deleted !!!\n");
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    		printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   Student with id %d is not found !!!\n", id);
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");

}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL)
    {
		
		printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t    id: %d\n", temp->id);
        printf("\t\t\t\t 	Name: %s\n", temp->name);
        printf("\t\t\t\t 	Phone: %s\n", temp->phone);
        printf("\t\t\t\t 	District: %s\n", temp->district);
        printf("\t\t\t\t 	Age: %d\n", temp->age);
        printf("\t\t\t\t 	Admission year: %d\n", temp->year);
        printf("\t\t\t\t 	cgpa: %0.2f\n\n", temp->cgpa);
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
       
        temp = temp->next;

    }
}





int main()
{
    int ch,ch1;
    head = NULL;
    char name[100];
    char phone[100];
    int id;
    int age;
    int year;
    char district[100];
    float cgpa;

    do
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++      Student Mangement System           ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");


        printf("\n\n\n\n\t\t\t\t\t Enter a key to start ....");

        getch();
        system("cls");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++      Student Mangement System           ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\t\t\t\t   ---------------------------------------------");


        printf("\n\t\t\t\t   Enter >1< Insert student details");
        printf("\n\t\t\t\t   Enter >2< Search for student details");
        printf("\n\t\t\t\t   Enter >3< Delete student details");
        printf("\n\t\t\t\t   Enter >4< Update student details");
        printf("\n\t\t\t\t   Enter >5< To see student list");

        printf("\n\t\t\t\t   Enter >0< To Exit");
        printf("\n\t\t\t\t   ---------------------------------------------\n\n");
        printf("\n\t\t\t\t   Enter your Choice ::  ");
        fflush(stdin);
        scanf("%d",&ch);
        system("cls");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++      Student Mangement System           ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");




        switch (ch)
        {
        case 1:
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   Enter id: ");
            scanf("%d", &id);
            printf("\t\t\t\t   Enter name: ");
            scanf("%s", name);
            fflush(stdin);
            printf("\t\t\t\t   Enter phone number: ");
            scanf("%s", phone);
            fflush(stdin);
			printf("\t\t\t\t   Enter district: ");
            scanf("%s", district);
            fflush(stdin);
            printf("\t\t\t\t   Enter age: ");
            scanf("%d", &age);
            printf("\t\t\t\t   Enter Admitted year: ");
            scanf("%d", &year);
            printf("\t\t\t\t   Enter cgpa: ");
            scanf("%f", &cgpa);
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            insert(id, name, phone, cgpa,district,age,year);
            break;
        case 2:
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\n\t\t\t\t    Enter >1< to search by ID");
            printf("\n\t\t\t\t    Enter >2< to search by Name");
            printf("\n\t\t\t\t   ---------------------------------------------\n\n");
        	printf("\n\t\t\t\t  Enter your Choice ::  ");
        	fflush(stdin);
        	scanf("%d",&ch1);
        	
        	switch(ch1){
        		case 1:
        			printf("\n\t\t\t\t  Enter ID to search ::  ");
        			scanf("%d", &id);
        			search(id,name);
        			break;
        		
        		case 2:
        			printf("\n\t\t\t\t  Enter Name to search ::  ");
        			scanf("%s", name);
        			search(id,name);
        			break;
        			
			}
            
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            
            break;
        case 3:
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   Enter id to delete: ");
            scanf("%d", &id);
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            Delete(id);
            break;
        case 4:
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   Enter id to update: ");
            scanf("%d", &id);
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        	printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            update(id);
            break;
        case 5:
            display();
            break;
        case 0:
            exit(0);
            break;
		
		
		    
        }


    }
    while (ch!=0);

}

