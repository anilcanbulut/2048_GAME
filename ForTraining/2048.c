#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void upward();
void downward();
void left();
void right();

int score=0;
int main(){

int game_map[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

srand(time(NULL));
int random1 = rand()%4;
int random2 = rand()%4;
int random3 = rand()%8;

game_map[random1][random2]=2;

random1 = rand()%4;
random2 = rand()%4;

if(random3==0 || random3==1 || random3==2 || random3==3 || random3==4 ){
game_map[random1][random2]=2;
}else
game_map[random1][random2]=4;

int i, j;

printf("\n\n\n\n");
    for(i=0; i<4; i++){
            printf("\n");
            printf("\t\t");
        for(j=0; j<4; j++){
            if(game_map[i][j]==0){
                printf("            -    ", game_map[i][j]);
            }else
            printf("            %d    ", game_map[i][j]);
        }
        printf("\n\n");
    }

while(1){

char direction;
printf("Enter a direction: ");
scanf("%c", &direction);

    if(direction=='w'){
    printf("Enter a direction: ");
    upward(game_map);
    }else if(direction=='s'){
    printf("Enter a direction: ");
    downward(game_map);
    }else if(direction=='a'){
    printf("Enter a direction: ");
    left(game_map);
    }else if(direction=='d'){
    printf("Enter a direction: ");
    right(game_map);
    }
}
return 0;
}

void upward(int arr[4][4]){

int i, j, count=0, sum=0, rand1, rand2, rand3;
srand(time(NULL));
rand1 = rand()%4;
rand2 = rand()%4;
rand3 = rand()%8;

    for(j=0; j<4; j++){
        for(i=0; i<4; i++){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(i==0){
                system("cls");
                    continue;
                }
                arr[i-count][j]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;
                }else
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(j=0; j<4; j++){
        for(i=0; i<1; i++){
            if(arr[i][j]==arr[i+1][j]){
                arr[i][j]=(arr[i][j]+arr[i+1][j]);
                arr[i+1][j]=0;
                score += arr[i][j];
            }
        }
    }

    for(j=0; j<4; j++){
        for(i=0; i<4; i++){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(i==0){
                    system("cls");
                    continue;
                }
                arr[i-count][j]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;
                }else
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(j=0; j<4; j++){
        for(i=1; i<3; i++){
            if(arr[i][j]==arr[i+1][j]){
                arr[i][j]=(arr[i][j]+arr[i+1][j]);
                arr[i+1][j]=0;
                score += arr[i][j];
            }
        }
    }

    if(rand3==0 || rand3==1 || rand3==2 || rand3==3 || rand3==4){
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=2;
        }
    }else{
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=4;
        }
    }

printf("\n\n\n\n");
        for(i=0; i<4; i++){
            printf("\n");
            printf("\t\t");
            for(j=0; j<4; j++){
                if(arr[i][j]==0){
                printf("            -    ", arr[i][j]);
            }else
                printf("            %d    ", arr[i][j]);
        }
        printf("\n\n");
    }

      printf("\tscore: %d\n\n", score);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(arr[i][j]==2048)
                printf("\nYou've won! Congratulations!\n");
        }
    }
}

void downward(int arr[4][4]){

int i, j, count=0, rand1, rand2, rand3;
srand(time(NULL));
rand1 = rand()%4;
rand2 = rand()%4;
rand3 = rand()%8;

    for(j=3; j>=0; j--){
        for(i=3; i>=0; i--){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(i==3){
                    system("cls");
                    continue;
                }
                arr[count+i][j]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;

                }else
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(j=3; j>=0; j--){

        for(i=3; i>2; i--){
            if(arr[i][j]==arr[i-1][j]){
                arr[i][j]=(arr[i][j]+arr[i-1][j]);
                arr[i-1][j]=0;
                 score += arr[i][j];
            }
        }
    }

    for(j=3; j>=0; j--){
        for(i=3; i>=0; i--){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(i==3){
                    system("cls");
                    continue;
                }
                arr[count+i][j]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;

                }else
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(j=3; j>=0; j--){
        for(i=2; i>0; i--){
            if(arr[i][j]==arr[i-1][j]){
                arr[i][j]=(arr[i][j]+arr[i-1][j]);
                arr[i-1][j]=0;
                 score += arr[i][j];
            }
        }
    }

    if(rand3==0 || rand3==1 || rand3==2 || rand3==3 || rand3==4){
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=2;
        }
    }else{
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=4;
        }
    }

printf("\n\n\n\n");
    for(i=0; i<4; i++){
            printf("\n");
            printf("\t\t");
        for(j=0; j<4; j++){
            if(arr[i][j]==0){
                printf("            -    ", arr[i][j]);
            }else
                printf("            %d    ", arr[i][j]);
        }
        printf("\n\n");
    }

      printf("\tscore: %d\n\n", score);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(arr[i][j]==2048)
                printf("\nYou've won! Congratulations!\n");
        }
    }
}

void left(int arr[4][4]){

int i, j, count=0, rand1, rand2, rand3;
srand(time(NULL));
rand1 = rand()%4;
rand2 = rand()%4;
rand3 = rand()%8;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(j==0){
                    system("cls");
                    continue;
                }
                arr[i][j-count]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;

                }else
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(i=0; i<4; i++){
        for(j=0; j<1; j++){
            if(arr[i][j]==arr[i][j+1]){
                arr[i][j]=(arr[i][j]+arr[i][j+1]);
                arr[i][j+1]=0;
                score += arr[i][j];
            }
        }
    }

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(j==0){
                    system("cls");
                    continue;
                }
                arr[i][j-count]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;
                }else
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(i=0; i<4; i++){
        for(j=1; j<3; j++){
            if(arr[i][j]==arr[i][j+1]){
                arr[i][j]=(arr[i][j]+arr[i][j+1]);
                arr[i][j+1]=0;
                score += arr[i][j];
            }
        }
    }

    if(rand3==0 || rand3==1 || rand3==2 || rand3==3 || rand3==4){
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=2;
        }
    }else{
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=4;
        }
    }

printf("\n\n\n\n");
    for(i=0; i<4; i++){
            printf("\n");
            printf("\t\t");
        for(j=0; j<4; j++){
            if(arr[i][j]==0){
                printf("            -    ", arr[i][j]);
            }else
                printf("            %d    ", arr[i][j]);
        }
        printf("\n\n");
    }

      printf("\tscore: %d\n\n", score);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(arr[i][j]==2048)
                printf("\nYou've won! Congratulations!\n");
        }
    }
}

void right(int arr[4][4]){

int i, j, count=0, rand1, rand2, rand3;
srand(time(NULL));
rand1 = rand()%4;
rand2 = rand()%4;
rand3 = rand()%8;

    for(i=3; i>=0; i--){
        for(j=3; j>=0; j--){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(j==3){
                    system("cls");
                    continue;
                }
                arr[i][j+count]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;
                }
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(i=3; i>=0; i--){

        for(j=3; j>2; j--){
            if(arr[i][j]==arr[i][j-1]){
                arr[i][j]=(arr[i][j]+arr[i][j-1]);
                arr[i][j-1]=0;
                score += arr[i][j];
            }
        }
    }

    for(i=3; i>=0; i--){
        for(j=3; j>=0; j--){
            if(arr[i][j]==0){
                count++;
            }else if(arr[i][j]!=0){
                if(j==3){
                    system("cls");
                    continue;
                }
                arr[i][j+count]=arr[i][j];
                if(count == 0){
                    system("cls");
                    continue;
                }
                arr[i][j]=0;
                    system("cls");
                continue;
            }
        }
        count=0;
    }

    for(i=3; i>=0; i--){
        for(j=2; j>0; j--){
            if(arr[i][j]==arr[i][j-1]){
                arr[i][j]=(arr[i][j]+arr[i][j-1]);
                arr[i][j-1]=0;
                score += arr[i][j];
            }
        }
    }

    if(rand3==0 || rand3==1 || rand3==2 || rand3==3 || rand3==4){
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=2;
        }
    }else{
        while(arr[rand1][rand2]==0){
            arr[rand1][rand2]=4;
           }
    }

printf("\n\n\n\n");
    for(i=0; i<4; i++){
            printf("\n");
            printf("\t\t");
        for(j=0; j<4; j++){
            if(arr[i][j]==0){
                printf("            -    ", arr[i][j]);
            }else
                printf("            %d    ", arr[i][j]);
        }
        printf("\n\n");
    }

      printf("\tscore: %d\n\n", score);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(arr[i][j]==2048)
                printf("\n\nYou've WON! CONGRATULATIONS!\n\n\n");
        }
    }
}
