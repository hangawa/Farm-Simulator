#include <stdio.h>
#include <stdlib.h>

void printstory(){
    printf("\nYou inherited a farm and in order to keep the property, you must pay its bills. You have no experience or funds to invest, so you will dedicate your time over this next week gathering funds to save this farm.");
    printf("\n\nYou need to make $750 by the end of day 7. You will work for 12 hours each day. Each task you choose to do will take one hour of your time.");
    printf("\n\nImportant Notes:");
    printf("\n1. Collecting eggs will give you 12 eggs. A dozen eggs is worth $6\n2. Milking cows will give your 2 gallons of milk, each worth $3\n3. Making butter will take 1 gallon of milk and will make 3 wide sticks of butter, each worth $3.");
    printf("\nAll your goods will be added up and sold at the end of each day. ");
}
void getmilk(int *milk){
    *milk += 2;
}
void geteggs(int *eggs){
    *eggs += 12;
}
void makebutter(int *milk, int *butter){
    *milk -= 1;
    *butter += 3;
}
void makecheese(int *milk, int *cheese){
    *milk -= 2;
    *cheese += 1;
}
void makeyogurt(int *milk, int *yogurt){
    *milk -= 1;
    *yogurt += 1;
}
void makemayo(int *eggs, int *mayo){
    *eggs -= 6;
    *mayo += 1;
}
void printhour(int *hour, int *adjustedhour){
    if(*hour==12){
        printf("\nIt is 12 pm.");
    }
    else if(*hour>11){
        *adjustedhour = (*hour - 12);
        printf("\nIt is %d pm.", *adjustedhour);
    }
    else if(*hour<12){
        printf("\nIt is %d am.", *hour);
    }
}
void printoptions(int *cheesepress, int *yogurtmaker, int *mayoblender){
    if(*cheesepress == 1 && *yogurtmaker == 0 && *mayoblender == 0){
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\n4. Press cheese\nChoice: ");
    }
    else if(*cheesepress == 1 && *yogurtmaker == 1 && *mayoblender == 0){
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\n4. Press cheese\n5. Make yogurt\nChoice: ");
    }
    else if(*cheesepress == 0 && *yogurtmaker == 1 && *mayoblender == 0){
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\n4. Make yogurt\nChoice: ");
    }
    else if(*cheesepress == 1 && *yogurtmaker == 0 && *mayoblender == 1){
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\n4. Blend mayo\n5. Press cheese\nChoice: ");
    }
    else if(*cheesepress == 1 && *yogurtmaker == 1 && *mayoblender == 1){
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\n4 Blend mayo\n5. Press cheese\n6. Make yogurt\nChoice: ");
    }
    else if(*cheesepress == 0 && *yogurtmaker == 1 && *mayoblender == 1){
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\n4. Blend mayo\n5. Make yogurt\nChoice: ");
    }
    else if(*cheesepress == 0 && *yogurtmaker == 0 && *mayoblender == 1){
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\n4. Blend mayo\nChoice: ");
    }
    else{
        printf("\nWhat do you want to do?\n1. Milk cows\n2. Collect eggs\n3. Churn butter\nChoice: ");
    }
}
void checkwallet(int *wallet){
    if(*wallet >= 750){
        printf("Success! You did it! You get to keep the farm!");
    }
    else{
        printf("You Failed to collect the funds in time! You lost the farm!");
    }
}

int main(){
    printstory();
    int choice = 0, choice2 = 0;
    int eggs = 0, milk = 0, butter = 0, cheese = 0, yogurt = 0, mayo = 0;
    int cheesepress = 0, yogurtmaker = 0, mayoblender = 0;
    int wallet = 0;
    int day = 0, hour = 0, adjustedhour = 0;
    // half a dozen eggs per 1 small mayo jar
    for(day=1; day<=7; day++){
        printf("\nToday is day %d.\n", day);
        // daily task cycle
        for(hour=6; hour<=18; hour++){
            printhour(&hour, &adjustedhour);
            printoptions(&cheesepress, & yogurtmaker, &mayoblender);
            scanf("%d", &choice);
            if(choice<1||choice>6){
                printf("No task initiated, 1 hour passes, no gain.");
            }
            else if(choice==1){
                getmilk(&milk);
            }
            else if(choice==2){
                geteggs(&eggs);
            }
            else if(choice==3){
                if(milk<1){
                    printf("You don't have enough milk to do this, 1 hour passes, no gain.\n");
                }
                else{
                    makebutter(&milk, &butter);
                }
            }
            else if(choice == 4){
                if(mayoblender == 1){
                    if(eggs >= 6){
                        eggs -= 6;
                        mayo += 1;
                    }
                    else{
                        printf("\n\nYou do not have the materials for this. The hour passes\n\n");
                    }
                }
                else if(cheesepress == 1){
                    if(milk >= 2){
                        milk -= 2;
                        cheese += 1;
                    }
                    else{
                        printf("\n\nYou do not have the materials for this. The hour passes\n\n");
                    }
                }
                else if(yogurtmaker == 1){
                    if(milk >= 1){
                        milk -= 1;
                        yogurt += 1;
                    }
                    else{
                        printf("\n\nYou do not have the materials for this. The hour passes\n\n");
                    }
                }
                else{
                    printf("No task initiated, 1 hour passes, no gain.");
                }
            }
            else if(choice == 5){
                if(cheesepress == 1){
                    if(milk >= 2){
                        milk -= 2;
                        cheese += 1;
                    }
                    else{
                        printf("\n\nYou do not have the materials for this. The hour passes\n\n");
                    }
                }
                else if(yogurtmaker == 1){
                    if(milk >= 1){
                        milk -= 1;
                        yogurt += 1;
                    }
                    else{
                        printf("\n\nYou do not have the materials for this. The hour passes\n\n");
                    }
                }
                else{
                    printf("No task initiated, 1 hour passes, no gain.");
                }
            }
            else if(choice == 6){
                if(yogurtmaker == 1){
                    if(milk >= 1){
                        milk -= 1;
                        yogurt += 1;
                    }
                    else{
                        printf("\n\nYou do not have the materials for this. The hour passes\n\n");
                    }
                }
                else{
                    printf("No task initiated, 1 hour passes, no gain.");
                }
            }
            else{
                printf("No task initiated, 1 hour passes, no gain.");
            }
        }
        // end of day summary
        printf("\nYou have\n%d gallons of milk,\n%d eggs,\n%d sticks of butter,\n%d wheels of cheese,\nand %d tubs of yogurt\n", milk, eggs, butter, cheese, yogurt);
        wallet = (milk * 3) + ((eggs * 6)/12) + (butter * 3) + (cheese * 20) + (yogurt * 15) + (mayo * 10);
        printf("That is worth: $%d\n", wallet);
        // daily shopping
        if(((mayoblender == 0) && (wallet >= 50))||((cheesepress == 0) && (wallet >= 100))||((yogurtmaker == 0) && (wallet >= 150))){
            printf("\nDo you want to buy an upgrade?\n1. ");
            if(mayoblender == 0){
            printf("Mayonnaise Blender for $50\n(6 eggs can be made into one small jar of mayo worth $10\n2. ");
        }
            if(cheesepress == 0){
            printf("Cheese Press for $100\n(2 gallons of milk can be made into 1 cheese wheel worth $20)\n");
            if(mayoblender == 1){
                printf("2. ");
            }
            else if(mayoblender == 0){
                printf("3. ");
            }
        }
            if(yogurtmaker == 0){
            printf("Yogurt Maker for $150\n(1 gallon of milk can be made into 1 tub of yogurt worth $15)\n");
            if((mayoblender == 1) && (cheesepress == 1)){
                printf("2. ");
            }
            else if((mayoblender == 1)||(cheesepress == 1)){
                printf("3. ");
            }
            else if((mayoblender == 0) && (cheesepress == 0)){
                printf("4. ");
            }
        }
            printf("No Upgrade\nChoice: ");
            scanf("%d", &choice2);
        }
        if(choice2 == 1){
        if(mayoblender == 0){
            mayoblender = 1;
            wallet -= 50;
        }
        else if(cheesepress == 0){
            cheesepress = 1;
            wallet -= 100;
        }
        else if(yogurtmaker == 0){
            yogurtmaker = 1;
            wallet -= 150;
        }
    }
        else if(choice2 == 2){
        if((mayoblender == 0) && (cheesepress == 0)){
            cheesepress = 1;
            wallet -= 100;
        }
        else if(((mayoblender == 0) && (cheesepress = 1) && (yogurtmaker == 0))||((mayoblender == 1) && (cheesepress == 0) && (yogurtmaker == 0))){
            yogurtmaker = 1;
            wallet -= 150;
        }
        else{
            printf("No item purchased. The day passes.");
        }
    }
        else if(choice2 == 3){
        if((yogurtmaker == 0) && (wallet >= 150)){
            yogurtmaker = 1;
            wallet -= 150;
        }
        else{
            printf("No item purchased. The day passes.");
        }
    }
        else{
        printf("No item purchased. The day passes.");
    }
    }
    checkwallet(&wallet);
    return 0;
}
