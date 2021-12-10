#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mystruct
{
    int data;
    struct mystruct *next;
} mystruct;

mystruct *start;
mystruct *last;

void insertdatabegining(int input)
{
    mystruct *p = malloc(sizeof(mystruct));
    if (start == NULL)
    {
        start = p;
        last = p;
        p->data = input;
        p->next = NULL;
    }
    else
    {
        p->next = start;
        p->data = input;
        start = p;
    }
    printf("Data inserted \n");

}
void insertatend(int input)
{
    mystruct *p = malloc(sizeof(mystruct));
    if (start == NULL)
    {
        start = p;
        last = p;
        p->data = input;
        p->next = NULL;
    }
    else
    {
        last->next = p;
        last = p;
        p->data = input;
        p->next = NULL;
    }
    printf("Data inserted \n");
}
void display()
{
    if (start != NULL)
    {
        mystruct *temp = start;
        while (temp != NULL)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("Null ");
    }
    else
    {
        printf("\n list is empty ");
    }
    printf("\n");
}
void searchdata(int input){
    int a=1;
    if(start == NULL){
        printf("list is empty \n");
    }else{
        mystruct *temp_ = start;
        int x=0;
        while (temp_ != NULL)
        {
            x++;
            printf("%d -->", temp_->data);
            if(temp_->data==input){
                printf(" data  %d . sirada \n",x);
                a=2;
                break;              
            }
            temp_ = temp_->next;
        }
        if(a==1){
            printf("Data is not exist \n ");
        }
    }

}
int main()
{
    int answer;
    while (answer != 5)
    {

        int input;
        printf("---------------------------MENU-----------------------\n");
        printf("Insert the data : 1  \nDisplay : 2  \nSearch the data : 3  ");
        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            int where;
            printf("Dou you want where add to data - begin : 1 End : 2 \n ");
            scanf("%d", &where);
            printf("Enter a data =  ");
            scanf("%d", &input);
            if (where == 1)
            {
                insertdatabegining(input);
            }
            else
            {
                insertatend(input);
            }

            break;
        case 2 :
            display();
            break;
        
        case 3 :
            printf("Enter a Data ");
            scanf("%d",&input);
            searchdata(input);

        }
    }

    return 0;
}
