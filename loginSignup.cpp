#include<stdio.h>
#include <stdlib.h>

void Home();
void signup(int universityID,int password,int phoneNumber);
void login(int universityID,int password);
int getEmptyPosition();

int sizeArray = 100;
int universityIDArray[100],passwordArray[100],phoneNumberArray[100];
///here it is a global variable and can usable from any function;


int main(){

    system("color 0A");

    for(int i=0; i<sizeArray;i++){
        universityIDArray[i]=0;
        passwordArray[i]=0;
        phoneNumberArray[i]=0;
    }

   /// universityIDArray[0]= 171155643;
   /// printf("%d",getEmptyPosition());

    Home();

}

void Home(){

    startPoint:
    printf("\nWelcome To FunBook\n");
    printf("1. Login to FunBook\n");
    printf("2. Sign Up to FunBook\n");

    int choseOption =0;
    printf("Please enter your choice: ");
    scanf("%d",&choseOption);

    if(choseOption==1){

            int universityID,password=0;
        printf("Enter Your University ID: ");
        scanf("%d",&universityID);
        printf("\nEnter Your Password: ");
        scanf("%d",&password);

        if(universityID!=0 || password!=0){

            login(universityID,password);

        }else{
            system("cls");
            printf("\nError input");
            goto startPoint;
        }

    } ///choseOption 1 is end here;
    else if(choseOption==2){

        int signUpUniversityID,signUpPassword,signUpPhoneNumber=0;
         printf("Enter Your University ID: ");
        scanf("%d",&signUpUniversityID);
        printf("\nEnter Your Password: ");
        scanf("%d",&signUpPassword);
      printf("\nEnter Your PhoneNumber: ");
        scanf("%d",&signUpPhoneNumber);

        if(signUpUniversityID!=0 || signUpPassword!=0 || signUpPhoneNumber!=0 ){

            signup(signUpUniversityID,signUpPassword,signUpPhoneNumber);

        }else{

            system("cls");
            printf("\nError input");
            goto startPoint;

        }

    }
}


void login(int universityID,int password){

    bool loginStatus = false;

        for(int i=0;i<sizeArray;i++){

              ///  printf("%d %d %d\n", universityIDArray[i],passwordArray[i],i);

            if(universityID==universityIDArray[i] && password==passwordArray[i] ){


                printf("Login Success\n");
                printf("Your ID: %d \n",universityIDArray[i]);
                printf("Your Phone Number: %d \n",phoneNumberArray[i]);

                loginStatus = true;

                break;

            }
        }

        if(loginStatus==false){
            printf("\n User ID Password Does not matched!!!");
            system("cls");
            Home();

        }else{
            Home();
        }

}

void signup(int universityID,int password,int phoneNumber){

    //printf("\n SignUp Function");
    int index_Of_universityID;
    bool result = false;
    for(index_Of_universityID=0;index_Of_universityID<sizeof(universityIDArray);index_Of_universityID++){

    /// checking that if ID is exist anymore;
        if(universityID==universityIDArray[index_Of_universityID]){

            result = false;
            break;
        }else{
            result = true;
        }

        ///now here i will save ID in Array;
        if(result == true){

        int emptyIndex = getEmptyPosition();
            universityIDArray[emptyIndex] = universityID;
            passwordArray[emptyIndex] = password;
            phoneNumberArray[emptyIndex] = phoneNumber;

           // printf("%d %d %d\n", universityIDArray[emptyIndex],passwordArray[emptyIndex],emptyIndex);

            Home();

        }else{
            printf("\n ID already Exist :D ");
            system("cls");
            Home();
        }

    }

}

int getEmptyPosition(){

    for(int i=0;i<sizeArray;i++){

        if(universityIDArray[i]==0){
            return i;

        }

    }

    return 0;
}
