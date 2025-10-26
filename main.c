#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

char cities[MAX_CITIES][50];
int distance[MAX_CITIES][MAX_CITIES];
int cityCount = 0;


void menu();
void citymanagement();
void distancemanagement();
void vehiclemanagement();
void requesthandling();
void calculations();
void deliveryrecords();
void performancereport();




int main()
{
    int choice;
do
{
    menu();
    printf("Enter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
          citymanagement();
          break;
      case 2:
          distancemanagement();
          break;
      case 3:
           vehiclemanagement();
           break;
     case 4:
          requesthandling();
          break;
     case 5:
          calculations();
          break;
     case 6:
          deliveryrecords();
          break;
     case 7:
         performancereport();
         break;
     case 8:
         printf("Exiting program..\n");
         break;
     default:
         printf("Invalid choice!\n");
    }
}
while(choice!=8);

return 0;


}

void menu()
{

    printf("\n\t\t LOGISTICS MANAGEMENT\t\t\n");
    printf("1.Citymanagement\n");
    printf("2.Distancemanagement\n");
    printf("3.Vehiclemanagement\n");
    printf("4.Requesthandling\n");
    printf("5.Calculations\n");
    printf("6.Deliveryrecords\n");
    printf("7.Performancereport\n");
    printf("8.Exit\n");

}

void citymanagement()
{
    int choice,n,find,i,j;
    char cities[],name[50],newname[50];
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
        for (i=0;i<n;n++)
        {
            printf("Enter city name:");
            scanf("%s" ,cities[cityCount]);
            cityCount++;
            printf("City added successfully!\n");
        }
    }

    else if(choice==2)
    {
        printf("Enter city name to rename:");
        scanf("%s",name );
        printf("Enter new name for %s:",name);
        scanf("%s",newname);
        for (i = 0; i < cityCount; i++)
        {
          if (strcmp(cities[i], name) == 0)
          {
            strcpy(cities[i], newname);
            printf("City renamed successfully!\n");
            return;
          }
          else
          {
             printf("City not found!\n");
          }
        }


    }

    else if(choice==3)
    {
        printf("Enter city index to remove:");
        scanf("%d",&i);
        if (i >= 0 && i < cityCount)
        {
            for (int j = i; j < cityCount - 1; j++)
            {
                strcpy(cities[j], cities[j + 1]);
            }
            cityCount--;
            printf("City removed!\n");
        }
        else
        {
          printf("Invalid index!\n");
        }
        break;
    }

}


void distancemanagement()
{
    if(cityCount<2)
    {
        printf("Not enough Cities Add min 2 cities");
        return;
    }
    int choice,i,j;
    do
    {
        printf("1. Enter or Edit Distances\n");
        printf("2. View Distance Table\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

    switch(choice)
    {
      case 1:
           printf("\nEnter distances between cities (in km)\n");
           for(i=0; i<cityCount; i++)
           {
              for(j=i+1; j<cityCount; j++)
              {
                 printf("Distance from %s to %s : ",cities[i],cities[j]);
                 scanf("%d",&distance[i][j]);
                 distance[j][i] = distance[i][j];


              }
           }
           printf("\nAll distances saved\n");
           break;
      case 2:
          printf("\nDistance Table:\n");
          for (i = 0; i < cityCount; i++)
          {
             for (j = 0; j < cityCount; j++)
             {
               printf("%4d ", distance[i][j]);
             }
             printf("\n");
          }
          break;



      default:
        printf("Invalid choice!\n");



    }

    }
    while(choice!=0);
}

void vehiclemanagement()
{
    printf("Type\tCapacity(kg)\tRate per km(LKR)\tAvg Speed(km/h)\Fuel Efficiency(km/l)\n"),
    printf("Van\t1000\t\t30\t\t60\t\t12\n");
    printf("Truck\t5000\t\t40\t\t50\t\t6\n");
    printf("Lorry\t10000\t\t80\t\t45\t\t4\n");

}


void requesthandling()
{
    int weight,vehicleType,city1,city2;
    if (cityCount < 2)
    {
       printf("\nAdd at least 2 cities and distances first!\n");
       return;
    }

    printf("\nEnter source city index: ");
    scanf("%d", &city1);
    printf("Enter destination city index: ");
    scanf("%d", &city2);

    if(city1==city2)
    {
        printf("Distance not set between these cities\n");
        return;
    }
    printf("Enter weight (kg):");
    scanf("%d", &weight);
    printf("Select Vehicle:\n");
    printf("1.Van(100kg)\n2.Truck(5000kg)\n3Lorry(10000kg)\n");
    printf("Enter vehicle type(1-3):");
    scanf("%d",&vehicleType);

    if (weight > vehicleCapacity[vehicleType])
    {
      printf("Weight exceeds vehicle capacity!\n");
      return;
    }
}

void calculations()
{
    int dist,vehicleRate[vehicleType],city1,city2;
    float baseCost,fuelUsed,fuelCost,totalCost,profit,customerCharge,time;

    baseCost = dist * vehicleRate[vType] * (1 + (float)weight / 10000);
    fuelUsed = (float)dist / vehicleEfficiency[vehicleType];
    fuelCost = fuelUsed * FUEL_PRICE;
    totalCost = baseCost + fuelCost;
    profit = baseCost * 0.25;
    customerCharge = totalCost + profit;
    time = (float)dist / vehicleSpeed[vehicleType];

}

int deliveryrecords()
{
    printf("\n========== DELIVERY COST ESTIMATION ==========\n");
    printf("From: %s\nTo: %s\n", cities[city1], cities[city2]);
    printf("Distance: %d km\n", dist);
    printf("Vehicle: %s\n", vehicleNames[vehicleType]);
    printf("Weight: %d kg\n", weight);
    printf("----------------------------------------------\n");
    printf("Base Cost: %.2f LKR\n", baseCost);
    printf("Fuel Used: %.2f L\n", fuelUsed);
    printf("Fuel Cost: %.2f LKR\n", fuelCost);
    printf("Operational Cost: %.2f LKR\n", totalCost);
    printf("Profit (25%%): %.2f LKR\n", profit);
    printf("Customer Charge: %.2f LKR\n", customerCharge);
    printf("Estimated Time: %.2f hours\n", time);
    printf("==============================================\n");


}

void performancereport()
{
  if (totalDeliveries == 0)
  {
     printf("No deliveries completed yet!\n");
     return;
  }
  printf("Total Deliveries Completed : %d\n", totalDeliveries);
  printf("Total Distance Covered     : %.2f km\n", totalDistance);
  printf("Average Distance/Delivery  : %.2f km\n", totalDistance / totalDeliveries);
  printf("Total Revenue              : %.2f LKR\n", totalRevenue);
  printf("Total Profit               : %.2f LKR\n", totalProfit);
}











