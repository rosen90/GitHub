#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct List
{
    char id[50];
    char name[50], lastName[50];
    double sum;
    int months;
    struct List *next;
};
typedef struct List List;
void menu(char *fname, List *root);
List *InsertNewClient(FILE *fp)
{
    List *result = NULL;
    result = (List*)malloc(sizeof(List));
    fscanf(fp, "%s", result->id);
    fscanf(fp, "%s", result->name);
    fscanf(fp, "%s", result->lastName);
    fscanf(fp, "%lf", &result->sum);
    fscanf(fp, "%d", &result->months);
    result -> next =NULL;
    return result;
}
List *create_queue_list(char *fname)
{
    FILE *fp;
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Cannnot open the file!");
        exit(1);
    }
    List *res_root = NULL;
    List *end_item = NULL;
    while( !feof(fp) )
    {
        if (res_root == NULL)
        {
            res_root = InsertNewClient(fp);
            end_item = res_root;
        }
        else
        {
            end_item->next = InsertNewClient(fp);
            end_item = end_item->next;
        }
    }
    fclose(fp);
    return res_root;
}
void WriteToFile(char *fname, List *root, bool update)
{
    FILE *fp;
    char id[50];
    char name[50], lastName[50];
    double sum;
    int months;
    fp = fopen(fname, "a");
    if (fp == NULL)
    {
        printf("Cannot open the file!");
        menu(fname, NULL);
        return ;
    }
    if (root == NULL && !update)
    {
        printf("Enter a code of the client: ");
        scanf("%s",id);
        fprintf(fp,"%s",id);
        fprintf(fp,"\n");
        printf("Enter a first name of the client: ");
        scanf("%s", name);
        fprintf(fp,"%s",name);
        fprintf(fp,"\n");
        printf("Enter a last name of the client: ");
        scanf("%s", lastName);
        fprintf(fp,"%s",lastName);
        fprintf(fp,"\n");
        printf("Enter a sum of the client: ");
        scanf("%lf", &sum);
        fprintf(fp,"%lf",sum);
        fprintf(fp,"\n");
        printf("Enter months of the client: ");
        scanf("%d", &months);
        fprintf(fp,"%d",months);
        system("cls");
    }
    else
    {
        fclose(fp);
        fp = fopen(fname, "w");
        List *new_client = NULL;

        if(!update)
    {
        new_client = (List*)malloc(sizeof(List));
        printf("Enter a code of the client: ");
        scanf("%s",id);
        strcpy(new_client->id,id);
        printf("Enter a name of the client: ");
        scanf("%s", name);
        strcpy(new_client->name,name);
        printf("Enter a last name of the client: ");
        scanf("%s", lastName);
        strcpy(new_client->lastName,lastName);
        printf("Enter a sum of the client: ");
        scanf("%lf", &sum);
        new_client->sum = sum;
        printf("Enter months of the client: ");
        scanf("%d", &months);
        new_client->months = months;
        new_client->next = NULL;
    }
        do
        {
            fprintf(fp, "%s", root->id);
            fprintf(fp,"\n");
            fprintf(fp, "%s", root->name);
            fprintf(fp, "\n");
            fprintf(fp, "%s", root->lastName);
            fprintf(fp,"\n");
            fprintf(fp, "%lf", root->sum);
            fprintf(fp,"\n");
            fprintf(fp, "%d", root->months);
            root = root->next;
            if(root != NULL)
            {
                 fprintf(fp,"\n");
            }
        }
        while (root !=NULL);

        if (root == NULL && !update)
        {
            fprintf(fp,"\n");
            fprintf(fp,"%s",new_client->id);
            fprintf(fp,"\n");
            fprintf(fp,"%s",new_client->name);
            fprintf(fp,"\n");
            fprintf(fp,"%s", new_client->lastName);
            fprintf(fp, "\n");
            fprintf(fp,"%lf",new_client->sum);
            fprintf(fp,"\n");
            fprintf(fp,"%d",new_client->months);
            printf("The information was written in the file.\n");
        }
    }
    fclose(fp);
    root = create_queue_list(fname);
    menu(fname,root);
}
void ShowInformation(char* fname, List *root)
{
    if( root == NULL )
    {
        root = create_queue_list(fname);
    }
    List *curr_item = root;
    system("cls");
    printf("The clients of the bank list are: \n");
    while(curr_item != NULL)
    {
        printf("%s %s %s %lf %d\n", curr_item->id, curr_item->name,curr_item->lastName, curr_item->sum, curr_item->months);
        curr_item = curr_item->next;
    }
    menu(fname,root);
}
List *delete_client(char *fname, List *root)
{
    if( root == NULL )
    {
      root = create_queue_list(fname);
    }
    List *prev_item=root;
    List *current_item=root;
    char idNumber[20], coincidence;
    coincidence = 0;
    printf("Enter the id number of the client: ");
    scanf("%s",idNumber);
    while(current_item != NULL)
    {
        if(strcmp(idNumber, current_item->id)==0)
        {
            if(current_item == root)
            {
                root = root->next;
                prev_item = root;
                coincidence++;
            }
            else
            {
                prev_item->next = current_item->next;
            }
                free(current_item);
                current_item = prev_item;
                printf("The id number is deleted!\n");
        }
            prev_item = current_item;
            if (coincidence == 0)
            {
                current_item = current_item->next;
            }
            coincidence = 0;
    }
	    WriteToFile(fname,root,true);
        system("cls");
        return root;
}
void findClient(char *fname,List *root)
{
    if(root == NULL )
    {
        root = create_queue_list(fname);
    }
    List *current_item = root;
    int suma, match;
    match = 0;
    printf("Enter the sum: ");
    scanf("%d", &suma);
    while (current_item != NULL)
    {
        if(current_item->sum > suma)
        {
            printf("The clients with bigger sum are : \n");
            match++;
            printf("%s %s %s\n", current_item->name,current_item->lastName, current_item->id);
        }
        current_item=current_item->next;
    }
    if (match == 0)
    {
        printf("There are not clients with bigger sum.");
    }
     menu(fname,root);
}
void menu(char *fname, List *root)
{
    int choice;
    printf("MENU\n");
    printf("1. Read data from file.\n");
    printf("2. Write data to file.\n");
    printf("3. Show information on screen.\n");
    printf("4. Show clients with sum bigger then choosen one.\n");
    printf("5. Delete client.\n");
    printf("6. Exit.\n");
    printf("Please, make your choice : ");
    scanf("%d", &choice);
    system("cls");

    switch(choice)
    {
    case 1: root = create_queue_list(fname);
            menu(fname,root);
        break;
    case 2: WriteToFile(fname, root, false);
        break;
    case 3: ShowInformation(fname,root);
        break;
    case 4: findClient(fname,root);
        break;
    case 5: root = delete_client(fname,root);
            menu(fname,root);
        break;
    case 6: exit(0);
        break;
    }
}
int main() {
    List *root = NULL;
    char fname[20];
    printf("Enter the name of the file that you want to work with: ");
    gets(fname);
    menu(fname, root);
    return 0;
}

