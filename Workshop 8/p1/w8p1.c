/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Harsahbaj Singh
Student ID#: 146457221
Email      : hsna27@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include<stdio.h>

// User Libraries
#include"w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* int_ptr) {
	int userInput;
	int flag = 1;

	do {
		scanf("%d", &userInput);
		if (userInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (int_ptr != NULL)
	{
		*int_ptr = userInput;
	}
	return userInput;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* double_ptr) {
	double userInput;
	int flag = 1;

	do {
		scanf("%lf", &userInput);
		if (userInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (double_ptr != NULL)
	{
		*double_ptr = userInput;
	}
	return userInput;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int seq_number) {

	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", NUMBER_OF_GRAMS);
	printf("\n");
}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int seq_number) {
	struct CatFoodInfo cfi;
	int flag;
	printf("Cat Food Product #%d\n", seq_number + 1);
	printf("--------------------\n");
	flag = 1;

	// SKU number

	printf("SKU           : ");
	flag = 1;
	do {
		scanf("%d", &cfi.skuNumber);
		if (cfi.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	// Price of the product

	printf("PRICE         : $");
	flag = 1;
	do {
		scanf("%lf", &cfi.productPrice);
		if (cfi.productPrice <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	// Weight of the product

	printf("WEIGHT (LBS)  : ");
	flag = 1;
	do {
		scanf("%lf", &cfi.product_weightPounds);
		if (cfi.product_weightPounds <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	// Calories per serve in the product 

	printf("CALORIES/SERV.: ");
	flag = 1;
	do {
		scanf("%d", &cfi.caloriesPer_serve);
		if (cfi.caloriesPer_serve <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("\n");

	// Returning the struct
	return cfi;

}

// 5. Display the formatted table header

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku_number, double* product_price, int calorie_per_serving, double* product_weight_lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *product_price, *product_weight_lbs, calorie_per_serving);
}

// 7. Logic entry point

void start(void)
{
	int i;
	struct CatFoodInfo cfi[MAX_PRODUCTS] = { {0} };
	openingMessage(MAX_PRODUCTS);

	for (i = 0; i < MAX_PRODUCTS; i++) {
		cfi[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cfi[i].skuNumber, &cfi[i].productPrice, cfi[i].caloriesPer_serve, &cfi[i].product_weightPounds);
	}

}