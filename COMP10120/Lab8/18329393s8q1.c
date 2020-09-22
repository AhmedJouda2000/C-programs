/*
This is set 8 Question 1. Write a C Program which can fill and initialise the
structures with user data (read from the files towns.txt and counties.txt) and
then print out the name,  population,  county’s longName, county’s shortName
and the county’s population for each of the 5 town records by using struct
member reference notation.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 03/04/2019
*/

//include the libraries needed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//create a struct called County
//it includes: a pointer to a string that contains the long name of the county,
//another pointer to its short name, and unsigned int for its population
struct county
{
	char *longName;
	char *shortName;
	unsigned int population;
};

//creat a struct called town
//it includes: a pointer to a string to the town's name, an unsigned int for its
//population and a struct county that contains the town's county.
struct town
{
	char *name;
	unsigned int population;
	struct county aCounty;
};


//define the main function that returns nothing
int main (void)
{


	FILE *tPtr, *cPtr; //towns and conuties file pointers

	//a string to store the name of the town's county for comparsion
	char townCounty[80] = {0};

	//create arrays of structs counties and towns
	struct county Counties[4];
	struct town Towns[5];

	//open the file counties, if it cant be opened display an error message
	if ((cPtr = fopen("counties.txt", "r")) == NULL)
	{
		puts("Failed to open counties.txt");
	}
	//if the file opens:
	else
	{
		//declare a loop counter i and assign it to 0
		int i=0;
		//while the end of file is not reached
		while (!feof(cPtr))
		{
			//loop through the counties array and malloc then allocates a new area in
			//memory of the specified number of bytes (20 & 3) and stores the pointers
			//to the new locations in the variables on the left hand side
			Counties[i].longName = malloc(20);
			Counties[i].shortName = malloc(3);
			//scan from the file the counties long and short name and place them in
			//the new locations and also scan the population into its variable
			//This way we have the Counties array filled with the counties long and
			//short names and their populations
			fscanf(cPtr, "%s %s %u \n", Counties[i].longName, Counties[i].shortName, &Counties[i].population);

			//increment for the next county
			i++;
		}
		fclose(cPtr);	//close the file
	}

	//open the file towns, if it cant be opened display an error message
	if ((tPtr = fopen("towns.txt", "r")) == NULL)
		puts("Failed to open towns.txt");
	//if the file opens:
	else
	{
		//declare a variable i and assign it to 0 to be the loop counter
		int i=0;
		//loop until the end of file
		while (!feof(tPtr))
		{
			//loop through the towns array and malloc then allocates a new area in
			//memory of the specified number of bytes (20) for the name and stores the
			//pointer to the new location in the variables on the left hand side
			Towns[i].name = malloc(20);
			/*
				scan from the file the towns name and place it in the new location and
				scan the the population into the appropriate part of the struct
				and finally place the place the town's county in the temporary string
				"townCounty"
			*/
			fscanf(tPtr, "%s %u %s \n", Towns[i].name, &Towns[i].population, townCounty);

			/*
				loop over the entire counties array,
				we are trying to find the matching county in the array "counties" to the
				current town's county stored temporary in "townCounty", we do this using
				strcmp, once we match the county's names we assign the conuties details
				such as long & short name and population to the struct county inside the
				sturct town for that particular town.
				This way the struct aCounty inside the struct town has all the town's
				county information.
			*/
			for (int j=0; j<4; j++)
			{
				if (strcmp(townCounty, Counties[j].longName) == 0)
				{
					Towns[i].aCounty.longName = Counties[j].longName;
					Towns[i].aCounty.shortName = Counties[j].shortName;
					Towns[i].aCounty.population = Counties[j].population;
				}
			}
			//increment the counter to move to the next town
			i++;
		}
		fclose(tPtr);	//close the file
	}

	//Print the titles of each column and appropriatly space them
	printf("%12s | %15s | %12s | %12s | %20s \n", "Town", "Town Population", "County", "County Code", "County Population");

	//print the elements of the array "towns" required and appropriatly spaced
	for (int k=0; k<5; k++)
	{
		printf("%12s | %15u | %12s | %12s | %20u \n", Towns[k].name, Towns[k].population, Towns[k].aCounty.longName, Towns[k].aCounty.shortName, Towns[k].aCounty.population);
	}
	return 0;
}
