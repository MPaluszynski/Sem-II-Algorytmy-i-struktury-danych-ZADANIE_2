#include <iostream>
#include <stdio.h>

using namespace std;

int clockWiseSelection (int circleOfPeople[], int numberOfPeople, int deadPeopleCounter, int reverseDeadPeopleCounter, int k){
    int counter = 0, dummyInteger = 0;
    for(int x = 0 ; x < numberOfPeople ; x++){
        if(x%2 == 0){
            counter++;
        }
    }

    int * newCircleOfPeople = new int[counter];

    for(int y = 0 ; y < numberOfPeople ; y++){
        if(y%2 == 0){
            newCircleOfPeople[dummyInteger] = circleOfPeople[y];
            dummyInteger++;
        } else {
            deadPeopleCounter++;
            reverseDeadPeopleCounter++;
            if(deadPeopleCounter == k || reverseDeadPeopleCounter == k){
                printf("%d\n", circleOfPeople[y]);
                break;
            }
        }
    }
    if(deadPeopleCounter == k || reverseDeadPeopleCounter == k){
        delete [] newCircleOfPeople;
    }
    else if((k == (deadPeopleCounter+1) || k == (reverseDeadPeopleCounter+1)) && numberOfPeople%2 != 0 ){
        printf("%d\n", circleOfPeople[0]);
        delete [] newCircleOfPeople;
    }
    else if(numberOfPeople%2 != 0) {
        int * nextCircleOfPeople = new int[counter-1];
        for (int z = 1 ; z < counter ; z++){
            nextCircleOfPeople[z-1]= newCircleOfPeople[z];
        }
        delete [] newCircleOfPeople;
        clockWiseSelection (nextCircleOfPeople, (counter-1), (deadPeopleCounter+1), (reverseDeadPeopleCounter+1), k);
        delete [] nextCircleOfPeople;
    } else {
        clockWiseSelection (newCircleOfPeople, counter, deadPeopleCounter, reverseDeadPeopleCounter, k);
        delete [] newCircleOfPeople;
    }
    return 0;
}

int main()
{
    int s;
    scanf("%d", &s);
    for(int a = 0 ; a < s ; a++) {
        long long int numberOfPeople, k;
        scanf("%d", &numberOfPeople);
        scanf("%d", &k);
        if(numberOfPeople == 1){
            printf("%d\n", numberOfPeople);
        } else if (numberOfPeople == k){

        } else {
            int* circleOfPeople = new int[static_cast<size_t>(numberOfPeople)];

            for(int b = 0 ; b < numberOfPeople ; b++){
                circleOfPeople[b] = b+1;
            }

            clockWiseSelection(circleOfPeople, numberOfPeople, 0, (((-1)*numberOfPeople)-1), k);
            delete [] circleOfPeople;
        }
    }
    return 0;
}
