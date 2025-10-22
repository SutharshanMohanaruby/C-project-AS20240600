#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30


int main()
{
    int i;
}
;

void citymanagement()
{
    int choice,n,find,i,j;
    char cities[],name,newname;
    printf("1.Add city\n");
    printf("2.Rename city\n");
    printf("3.Remove city\n");
    printf("Enter your choice");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("How many cities do you want to add?");
        scanf("%d",&n);
        if(cityCount+n>MAX_CITIES)
        {
            printf("space not enough");
            citymanagement();
        }
        for (i=0;i<=n;n++)
        {
            printf("Enter city name:");
            scanf("%s"cities[cityCount]);
            cityCount++;
            printf("City added successfully!\n");
        }

    else if(choice==2)
    {
        printf("Enter city name to rename:");
        scanf("%s",name);
        printf("Enter new name for %s:",name);
        scanf("%s",newname);
        strcpy(name,newname);
        printf("City renamed successfully!\n");
    }

    else if(choice==3)
    {
        printf("Enter city name to remove:");
        scanf("%s",name);
        for(i=0;i<cityCount;i++)
        {
            if(strcmp(cities[i],name)==0)
            {
                find=1;
                for(j=i;j<cityCount-1;j++)
                {
                    strcpy(cities[j],cities[j+1]);
                }
                cityCount--;
                printf("City '%s' removed successfully!\n",name);
                break;
            }

        }
        if(find!=1)
            printf("City '%s' not found!\n",name);
    }

}
