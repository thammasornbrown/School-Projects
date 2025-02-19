
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main();
//Main at bottom

typedef struct DOG_struct {
    char dogName[20];
    int payOut; 
    float odds; 
}   DOG;

typedef struct Results_struct{
     char winnerNames[20];
     int num_rounds;
}Results;

typedef struct bankStorage_struct{
    int avalWager;
    int accountTotal ;
}bankStorage;

//Where the race begins
void Gamble() {     
    srand(time(0));
    //min and max for odds. randpayout for rng.
    int min;
    int max;  
    int randPayout;
    int i;
    //array sizes
    int num_dogs = 9;
    int store_count = 0;
    char dogChoice[20];
    // Structs
    Results Winner[store_count];
    DOG stats[num_dogs];
    bankStorage funds;
 
  
   
    printf("\nGreg's account: %d\nTotal avaliable to wager: %d\n", funds.accountTotal, funds.avalWager);
    printf("\nPick a dog\n");
   
    
    strcpy(stats[0].dogName , ("Dash"));       //Add all dog names and respective odds to struct
    stats[0].odds = 40;
    strcpy(stats[1].dogName , ("Baxter"));
    stats[1].odds = 10;
    strcpy(stats[2].dogName , ("Luna"));
    stats[2].odds = 8;
    strcpy(stats[3].dogName , ("Milo"));
    stats[3].odds = 6;
    strcpy(stats[4].dogName , ("Daisy"));
    stats[4].odds = 1;
    strcpy(stats[5].dogName , ("Duke"));
    stats[5].odds = 4;
    strcpy(stats[6].dogName , ("Olive"));
    stats[6].odds = 8;
    strcpy(stats[7].dogName , ("Winston"));
    stats[7].odds = 10;
    strcpy(stats[8].dogName , ("Bella"));
    stats[8].odds = 13;
    
    
    //  payout ranges
    for (i = 0; i < num_dogs; i++){
        
        switch(i){                                      
            case 0: max = 2; min = 1;  // Dash
            break;
            
            case 1: max = 5; min = 1; // Baxter
            break;
            
            case 2: max = 10; min = 1; // Luna
            break;
            
            case 3: max = 15; min = 1; // Milo
            break;
            
            case 4: max = 50; min = 1; // Daisy
            break;
            
            case 5: max = 20; min = 1; // Duke
            break;
            
            case 6: max = 10; min = 1; // Olive
            break;
            
            case 7: max = 5; min = 1; // Winston
            break;
            
            case 8: max = 3; min = 1; // Bella
            break;
            
        }
        
        randPayout = min + (rand() % (max - min + 1)); //generate a payout within a previously generated range. max and min values changer per case.
        
        stats[i].payOut = randPayout;   // Itterate through loop and give each dog the random payouts.
        
        printf("%s | Payout: %d | Odds: %.2f%%\n", stats[i].dogName, stats[i].payOut, stats[i].odds); // for testing | Display all dog stats
    }
    //select a dog
    printf("\nChoice: ");
    scanf("%s", dogChoice); 
    
    float total_odds = 0;
    for ( i = 0; i < num_dogs; i++) {
        total_odds += stats[i].odds;
    }
 
    
    float rand_dog = ((float) rand() / RAND_MAX) * total_odds;
  
    
    float cumulative_sum = 0;
    for (i = 0; i < num_dogs; i++) {
        cumulative_sum += stats[i].odds; //addition assignment of odds
        
         // store whoever wins, if Greg won and how much he won.
        if (rand_dog < cumulative_sum) {
            printf("\nThe winner is: %s\n", stats[i].dogName);
            strcpy(Winner[store_count].winnerNames, stats[i].dogName);
            
            if(dogChoice == stats[i].dogName){
                printf("Greg won!\n");
            }
            else{
                printf("Greg did not win\n\n");
            }
             
            store_count++; //increase amount of wins that can be stored affter a race.
            break;
        }
    }
    
    main(); //Return to menu
}


//Store funds here
void Bank(){
    
    int randTotal = 500 + (rand() % (10000 - 500 + 1)); // give greg a starting bankTotal between $100k and $500
    
    //int bankTotal = randTotal;
    int deposit;
    bankStorage gambleMoney = {0};
    
    char menuInput;
    
                                             // bank menu
    printf("[A] Greg's Account total\n[D] Deposit\n[W] Withdraw\n");
    scanf(" %c", &menuInput);
    
    if(menuInput == 'A'||menuInput == 'a'){
        printf("\nGreg's Account total: $%d\n", gambleMoney.accountTotal); // If user enters either upper or lowercase of the same char the same printf will occur.
       
   }
    else if (menuInput == 'D' || menuInput == 'd'){
        printf("\nHow much will Greg Deposit?\nAmount: $"); 
        scanf("%d", &deposit);
        gambleMoney.accountTotal += deposit;
        gambleMoney.avalWager -= deposit;     // however much you take from gambleMoney, you put back into bankTotal
    }   
    else if(menuInput == 'W' || menuInput == 'w'){
        printf("\nHow much will Greg withdraw so he can gamble?\nAmount: $"); 
        scanf("%d", &gambleMoney.avalWager);                   //withdraws to gambleMoney so he can wager however much of it he wants.
       // bankTotal -= gambleMoney.avalWager;                         // subtract ammount withdrawn from bankTotal to keep current.
    }
    main();  
}



int main() {
    int num_results = 1;
    Results Records[num_results];
    int Wager; 
    int i;
    char Input;
    //set avaliable wager amount to 0 so that user goes and withdraws funds from bank for greg to wager.
    bankStorage initFunds;
    initFunds.avalWager; 
    
    
    //Main menu
    printf("Gambling Greg\n-------------\n");
    printf("[G] Gamble\n[B] Banking\n[R] Results\n[L] Leave the dog track\n");
    scanf(" %c", &Input);
    
    
  
     switch (Input) {
           
            case 'g':
            if(initFunds.avalWager <= 0){
                printf("\nGreg needs to withdraw some money before he can gamble\nVisit the bank.\n");
                Bank();
            }
            else{
                Gamble();
                break;
            }
                
                
            case 'b':
            
                Bank();
                break;
                
            case 'r': 
               // for (i = 0; i < num_results; i++){
                //printf("Results: %s", Records[i].winnerNames);
              //  }
                break;
                
            case 'l':
                printf("\nGreg leaves the dog track.");
                //return 0;
                break;
                
            default:
                printf("Invalid choice. Please select a valid option.\n");
                main();
                break;
        }
   
   
 
    return 0;
}
