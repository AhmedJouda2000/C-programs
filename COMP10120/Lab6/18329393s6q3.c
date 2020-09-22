/*
This is set 6 Question 3. Write a sequence of C functions which will allow you
to set up a system to record/catalogue the computer games that you have in a
file. It should be possible to record details such as, the title, the platform,
the developer and the year, but also detail if the computer game has been
borrowed and by whom and when. One function should provide functionality to
update these borrower details. Use Structs and Random Access Files to achieve
this.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 07/03/2019
*/

//include the libraries needed
#include <stdio.h>
//define MAX to 50, to be used an array size
#define MAX 50

//define a struct called 'record', it will store the required data for each entry
struct record
{
  unsigned int gameNum;   //unsigned integer to record the game number(1-1000)
  char title[MAX];       //char array(String) to store the title
  char platform[MAX];   //char array(String) to store the platfrom the game is played on
  char developer[MAX];  //char array(String) to store the name of the developer
  unsigned int year;    //unsigned int to store the year of the game
  char borrowed[4];     //Char array to store if the game is borrowed or not (Yes/No)
  char name[MAX];       //char array to store the name of the borrower
  char date[MAX];       //char array to store the date of borrowing
};



//declare the function "reset file" that takes in and returns nothing
//It will clear the file as its called when its a user's 1st time
//Its also called if the user choose the option to format the file
void resetFile(void)
{
  //declare a file pointer
  FILE *filePtr;

  //fopen opens the file, if a problem occurs it exists and print an error message
  if ((filePtr = fopen("GamesRecord.txt", "wb")) == NULL)
  {
    printf("\nFile could not be opened\n");
  }

  //if the file opens:
  else
  {
    //declare and intialize a "struct record" to empty strings and zeros (reset)
    struct record blankData = {0, "", "", "", 0, "", "", ""};

    //then loop a 1000 times (all the entries) and write the empty struct to them
    //This will reset the entire file
    for (unsigned int i = 1; i < 1000; i++)
    {
      fwrite(&blankData, sizeof(struct record), 1, filePtr);
    }

    //close the file
    fclose(filePtr);
  }
}



//declare the function "edit file" that takes in and returns nothing
//This function is called if the user chooses the option to edit the file
void editFile(void)
{
  //file pointer
  FILE *filePtr;

  //fopen opens the file, if a problem occurs it exists and print an error message
  if ((filePtr = fopen("GamesRecord.txt", "rb+")) == NULL)
  {
    printf("\nFile could not be opened\n");
  }

  //if the file does open:
  else
  {
    //declare and intialize a new struct record called "game", make it empty
    struct record game = {0, "", "", "", 0, "", "", ""};
    //Ask the user to input the games number from 1 - 1000
    //Store the user input into the gameNum varibale in the struct record "game"
    printf("Enter the game's number (1 - 1000)\nTo end input enter 0:\n");
    scanf("%d", &game.gameNum);

    //while the user didnt input 0 to end, enter the loop
    while (game.gameNum != 0)
    {
      //prompt the user to input the required details
      printf("Enter (***REPLACE SPACES WITH '_'***):\n1) Title\n2) Platform\n3) Developer\n4) Year of the game\n");
      printf("5) Was it borrowed? Enter Yes or No\n6) If Yes enter Name of the person and the date (DD/MM/YY) it was borrowed\n");
      printf("If not enter '-' for person and date\n");

      //store the inputed data into the corresponding variables in the struct
      fscanf(stdin, "%s %s %s %d %s %s %s", game.title, game.platform, game.developer, &game.year, game.borrowed, game.name, game.date);

      /*
        position the file position pointer for the file referenced by filePtr
        to the byte location calculated by (game.gameNum-1)*sizeof(struct record).
        SEEK_SET is the offset from the start of file
        we take away 1 from gameNum as positions in file start from 0 not 1
      */
      fseek(filePtr, (game.gameNum-1)*sizeof(struct record), SEEK_SET);

      //write the infromation into the file
      fwrite(&game, sizeof(struct record), 1, filePtr);

      //ask the user to input the next game's number he wants to edit or exit
      printf("Enter the next game's number (1 - 1000)\nTo end input enter 0:\n");
      //store the answer into gameNum and loop again
      scanf("%d", &game.gameNum);
    }
    //close the file
    fclose(filePtr);
  }
}



//declare the function "Print table" that takes in and returns nothing
//This function is called if the user chooses the option to view the file
//It printd out the table of data in the file
void printTable(void)
{
  //file pointer
  FILE *filePtr;

  //fopen opens the file, if a problem occurs it exists and print an error message
  if ((filePtr = fopen("GamesRecord.txt", "rb")) == NULL)
  {
    printf("\nFile could not be opened\n");
  }

  //if it opens:
  else
  {
    //print the titles with appropriate spacing
    printf("%-21s%-15s%-17s%-19s%-14s%-18s%-20s%s\n", "Game Number", "Title", "Platform", "Developer", "Year", "Borrowed", "Name", "Date");

    //While the end of file is not reached:
    while (!feof(filePtr))
    {
      //declare and intialize an empty struct record called game
      struct record game = {0, "", "", "", 0, "", "", ""};

      //read the data from the file into the record struct "game"
      //store the value returned from fread into the integer "x"
      int x = fread(&game, sizeof(struct record), 1, filePtr);
      /*
        fread returns the number of items successfully read, therefore as long
        as its not 0 as well as game id is not 0, then print all the infromation
        in that struct (row). Make sure its well spaced and aligns with the titles
      */
      if (x != 0 && game.gameNum != 0)
      {
        printf("%-21d%-15s%-17s%-19s%-14d%-18s%-20s%s\n", game.gameNum, game.title, game.platform, game.developer, game.year, game.borrowed, game.name, game.date);
      }
    }
    fclose(filePtr); //close the file
  }
}




//declare the function "actions" that takes in and returns nothing
//This function is called to allow the user pick an action
//It acts as an operator that calls the other functins
void actions(void)
{
  //declare an integer variable to store the user's choice in
  int x;
  //Print out the menu of actions and take user input
  printf("\nHow can we help you today?\n");
  printf("Enter 1 to format (delete) games record\n");
  printf("Enter 2 to edit games record\n");
  printf("Enter 3 to view games record\n");
  printf("Enter 0 to exit\n");
  scanf("%d", &x); // store the user input in "x"

  //as long as the user doesn't enter 0 (exit)
  while (x != 0)
  {
    //if the user enters 1 (format)
    if (x == 1)
    {
      //declare a integer variable that will store the user's input
      int z;
      //ask the user if they are sure about deleting their data
      printf("This will format Games Record, all your data will be lost!\n");
      printf("1 for YES or 0 for NO.\n");
      //store their choice in z
      scanf("%d", &z);

      //if they choose 0 (delete) then call the resetFile function
      while (z != 0)
      {
        resetFile();
        break;
      }
    }

    //if the user enters 2 (edit)
    else if (x == 2)
    {
      //call the function "editFile"
      editFile();
    }

    //if the user enters 3 (view)
    else if (x == 3)
    {
      //call the funtion "printTable"
      printTable();
    }

    //Then offer the choices again and store the choice in "x"
    //This will keep repeating until the user inputs 0 to exit
    printf("\nHow can we help you today?\n");
    printf("Enter 1 to format (delete) games record\n");
    printf("Enter 2 to edit games record\n");
    printf("Enter 3 to view games record\n");
    printf("Enter 0 to exit\n");
    scanf("%d", &x);
  }
}


//define the main function that returns nothing
int main(void)
{
  int y;  //Declare an integer variable 'y'

  //Promote the user to input if they have used the game before or not
  //Store their answer in 'y'
  printf("Enter 1 if it is your first time using the program, if not 0\n");
  scanf("%d", &y);

  //if they havent used the game before
  if (y == 1)
	  {
      //delete all data to empty the file by calling the function "reset file"
	    resetFile();
      //Make sure the user knows in what file their records will be held
	    printf("The file GamesRecord.txt will hold your records\n");
      //Call the funtion actions
	    actions();
	  }

  //if they have used it before, then we want to keep the data so we dont reset
  else
	  {
      //we only call the function actions
	    actions();
	  }

  //once actions is finished, print a message to indicate execuetion is over
  printf("\nSee you soon!\n");
}
