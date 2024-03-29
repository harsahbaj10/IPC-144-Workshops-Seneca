/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include"w8p2.h"


// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* int_ptr) 
{
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

double getDoublePositive(double* double_ptr) 
{
	double userInput;
	int flag = 1;

	do 
	{
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

void openingMessage(const int seq_number) 
{

	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", NUMBER_OF_GRAMS);
	printf("\n");
}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int seq_number) 
{
	struct CatFoodInfo cfi;
	int flag;
	printf("Cat Food Product #%d\n", seq_number + 1);
	printf("--------------------\n");
	flag = 1;

	// SKU number

	printf("SKU           : ");
	flag = 1;
	do 
	{
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
	do 
	{
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
	do 
	{
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
	do 
	{
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* conversionToKgResult) 
{

	double poundsToKg = (*pounds) / LBsTOKG;

	if (conversionToKgResult != NULL)
	{
		*conversionToKgResult = poundsToKg;
	}

	return poundsToKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* conversionToGResult) 
{

	int poundsToG = ((*pounds) / LBsTOKG) * 1000;

	if (conversionToGResult != NULL)
	{
		*conversionToGResult = poundsToG;
	}

	return poundsToG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* conversionToKgResult, int* conversionToGResult) 
{

	double poundsToKg = (*pounds) / LBsTOKG;
	int poundsToG = ((*pounds) / LBsTOKG) * 1000;

	if (conversionToGResult != NULL && conversionToKgResult != NULL)
	{
		*conversionToGResult = poundsToG;
		*conversionToKgResult = poundsToKg;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeinGrams, const int totalGrams, double* numberOfServings)
{

	double total_servings = ((double)totalGrams) / servingSizeinGrams;

	if (numberOfServings != NULL)
	{
		*numberOfServings = total_servings;
	}

	return total_servings;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double* product_price, const double* total_numberOfServings, double* resultCostperServe) {

	double costPerServing = (*product_price) / (*total_numberOfServings);

	if (resultCostperServe != NULL)
	{
		*resultCostperServe = costPerServing;
	}

	return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* product_price, const double* totalCalories, double* resultCostperCalorie) {

	double costPerCal = (*product_price) / (*totalCalories);

	if (resultCostperCalorie != NULL)
	{
		*resultCostperCalorie = costPerCal;
	}

	return costPerCal;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cfi) {

	struct ReportData rd;

	// Assigning Values
	rd.skuNumber = cfi.skuNumber;
	rd.productPrice = cfi.productPrice;
	rd.product_weightPounds = cfi.product_weightPounds;
	rd.caloriesPer_serve = cfi.caloriesPer_serve;

	// Assigning calculated values
	rd.product_weightKilos = convertLbsKg(&rd.product_weightPounds, &rd.product_weightKilos);
	rd.product_weightGrams = convertLbsG(&rd.product_weightPounds, &rd.product_weightGrams);
	rd.total_servings = calculateServings(NUMBER_OF_GRAMS, rd.product_weightGrams, &rd.total_servings);

	// Total calories
	double totalCalories = rd.caloriesPer_serve * rd.total_servings;

	rd.costPerServing = calculateCostPerServing(&rd.productPrice, &rd.total_servings, &rd.costPerServing);
	rd.costCaloriesPerServing = calculateCostPerCal(&rd.productPrice, &totalCalories, &rd.costCaloriesPerServing);


	// Returning the struct
	return rd;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUMBER_OF_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int cheapestProductCheck) {

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.skuNumber, rd.productPrice, rd.product_weightPounds, rd.product_weightKilos, rd.product_weightGrams, rd.caloriesPer_serve, rd.total_servings, rd.costPerServing, rd.costCaloriesPerServing);
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cfi) 
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cfi.skuNumber, cfi.productPrice);
	printf("\n");

	// Ending line
	printf("Happy shopping!\n");
	printf("\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point

void start(void)
{
	// Struct Arrays
	struct ReportData rd[MAX_PRODUCTS] = { {0} };
	struct CatFoodInfo cfi[MAX_PRODUCTS] = { {0} };

	// Declaring variables
	int i, cheapestIndex = 0;

	// Printing the opening message
	openingMessage(MAX_PRODUCTS);

	// Filling the cfi array
	for (i = 0; i < MAX_PRODUCTS; i++) {
		cfi[i] = getCatFoodInfo(i);
		rd[i] = calculateReportData(cfi[i]);
	}

	// Dsiplaying cat food header
	displayCatFoodHeader();

	// Displaying cat food data
	for (i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cfi[i].skuNumber, &cfi[i].productPrice, cfi[i].caloriesPer_serve, &cfi[i].product_weightPounds);
	}

	// Determining the cheapest product's sku and price
	double cheapestProductPrice = rd[0].costPerServing;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (rd[i].costPerServing <= cheapestProductPrice)
		{
			cheapestProductPrice = rd[i].costPerServing;
			cheapestIndex = i;
		}
	}
	printf("\n");

	// Displaying the report header
	displayReportHeader();

	// Displaying the report data
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(rd[i], cheapestIndex);

		if (cheapestIndex == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	// Displaying final analysis
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (i == cheapestIndex)
		{
			displayFinalAnalysis(cfi[i]);
		}
	}
}