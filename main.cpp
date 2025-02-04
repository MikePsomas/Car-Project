#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>




#define MIN_AGE 18
#define MAX_AGE 30
#define DISCOUNT_PERCENTAGE 0.20f 
#define MAX_CARS 10
#define CSV_FILE "D:\\data.csv" 
#define MENU_OPTION_BUY_A_CAR 'a'
#define MENU_OPTION_VIEW_A_CAR_SALES 'b' 
#define MENU_OPTION_VIEW_CAR_SALES_BETWEEN 'c' 
#define MENU_OPTION_EXIT 'x' 
#define TRUE 1  
#define FALSE 0
#define bool unsigned char


unsigned short carsAvailable = 10;
unsigned short numberOfCarSales = 0;
unsigned short carAmountPerSale[MAX_CARS];
unsigned short carTypePerSale[MAX_CARS];
bool discountGivenPerSale[MAX_CARS];
char customerNames[MAX_CARS][201];
float carPrice[] = { 7.500f, 1.200f, 1.500f, 1.700f, 2.200f, 4.000f , 9.000f, 6.00f, 5.000f, 7.000f };
char carType[][10] = { "Ford", "Peugeot", "Opel", "Fiat", "Datsun" ,"Reunault","Kia","Ferrari","Dodge","Citroen" };
char carPr[][10] = { "7500", "1200", "1500", "1700", "2200", "4000", "9000", "6000", "5000", "7000"};




// file variables and constants
#define FILE_OPENED 0
#define FILE_CLOSED 1
#define FILE_ERROR 2

//hold the file stream open
FILE* file;
unsigned char fileStatus = FILE_CLOSED;


// functions that the program will be using 




//gives the command to clear the screen for the users benefit
void clearScreen() {

	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}


	printf("\n\nPress Enter to %s...", userChoice == MENU_OPTION_EXIT ? "Exit" : "return to the Menu");
	}
	else {
		printf("\n\nPress Enter to return to the Menu...");
	}


	if (userChoice != '_') {
	
		getchar();
	}

	if (userChoice != '_') {
		getchar();
	}

// promp user to use this value and to capture the message

char getCharFromConsole(char message[201]) {
	char userInput;

	printf("%s", message);

	if (scanf(" %c", &userInput) != 1) {
		fprintf(stderr, "Error reading input.\n");
		exit(EXIT_FAILURE);
	}

	return userInput;
}


//use this to store a capture name
unsigned short getUnsignedShortFromConsole(char message[201]) {

	unsigned short userInput;


	printf(message);
	if (scanf("%hd", &userInput) != 1) {
		fprintf(stderr, "Error reading input.\n");
		exit(EXIT_FAILURE);
	}

	printf("%s", message);
	scanf("%hd", &userInput);
}



// will allow this function to enstablish a connection between this str variable
// and the one that will exist at the time and place when the function is executed
//and it will also modifity the existing string variable
// and they will both be pointing to the same adress in memory
void getStringFromConsole(char message[201], char* str) {

	printf("%s", message);

	if (scanf(" %200[^\n]", str) != 1) {
		fprintf(stderr, "Error reading input.\n");
		exit(EXIT_FAILURE);
	}
}




//copy the value found at the pointer a adress and then to thew new create a temp variable
// then copy the value found at a pointer a adress and into the adress represented by the pointer b
// copy the value of the temp variable to the pointer b adress
void swapUnsignedShort(unsigned short* a, unsigned short* b) {
	unsigned short temp;

	temp = *a;

	*a = *b;

	*b = temp;
}





void swapBool(bool* a, bool* b) {
	bool temp;

	temp = *a;

	*a = *b;

	*b = temp;
}
	file = fopen(fileName, "w");

	if (file == NULL) {
		printf("Error creating file %s: %s\n", fileName, strerror(errno));
		return NULL;
	}

	fclose(file);
	return file;
FILE* createFile(char fileName[201]) {

	file = fopen(fileName, "w");

	if (file != NULL) {
		fclose(file);
	}

	return file;
}
	file = fopen(fileName, mode);

	if (file == NULL) {
		if (createFile(fileName) == NULL) {
			fileStatus = FILE_ERROR;
void openFile(char fileName[201], char mode[4]) {
	while (1) {
		file = fopen(fileName, mode);

		if (file != NULL) {
			fileStatus = FILE_OPENED;
			break;
		}

		if (createFile(fileName) == NULL) {
			fileStatus = FILE_ERROR;
			printf("Error opening %s: %s", fileName, strerror(errno));
			break;
		}
	}
}




//close the file when the operation finished when it is already open

void closeFile() {

	if (fileStatus == FILE_OPENED) {
		fclose(file);
		fileStatus = FILE_CLOSED;
	}
}






// it will read the representing customers names store in the file
void readDataFromFile() {

	int lineCounter = 0;


	while (1) {

		unsigned short carAmountPerSaleValue = 0, carTypePerSaleValue = 0, discountGivenPerSaleValue = 0;
		char customerNameValue[201] = "";

		int scanResult = fscanf(
			file,
			"%hd,%hd,%hd,%200[^\n]",
			&carAmountPerSaleValue,
			&carTypePerSaleValue,
			&discountGivenPerSaleValue,
		unsigned short carAmountPerSaleValue = 0, carTypePerSaleValue = 0, discountGivenPerSaleValue = 0;
		char customerNameValue[201] = "";

		int scanResult = fscanf(
			file,
			"%hd,%hd,%hd,%200[^\n]",
			&carAmountPerSaleValue,
			&carTypePerSaleValue,
			&discountGivenPerSaleValue,
			customerNameValue
		);

		if (scanResult == EOF) {
			break;
		} else if (scanResult != 4) {
			fprintf(stderr, "Error reading data from file.\n");
			exit(EXIT_FAILURE);
		}

		lineCounter++;
	}


	numberOfCarSales = lineCounter;
}





//checking if the data from the file is char or if not we give it an error

void getDataFromFile() {
	openFile(CSV_FILE, "r");

	if (fileStatus == FILE_OPENED) {
		readDataFromFile();
	}
	else if (fileStatus == FILE_ERROR) {
		printf("There was an error trying to read from the file %s.", CSV_FILE);

		pauseProgram('_');
	}

	closeFile();
}






//calculating and converting the number of cars someone bought
//the amounts of how many cars they bought
//if they deserve a discount
// what is their name 
// and what is the cost
void writeDataToFile() {

		if (fprintf(file, "%hd,%hd,%hd,%s\n",
			carAmountPerSale[i],
			carTypePerSale[i],
			discountGivenPerSale[i],
			customerNames[i]) < 0) {
			fprintf(stderr, "Error writing to file.\n");
			exit(EXIT_FAILURE);
		}
		);
	}
}







void saveDataToFile() {
	openFile(CSV_FILE, "w");

	if (fileStatus == FILE_OPENED) {
		writeDataToFile();
	}
	else if (fileStatus == FILE_ERROR) {
		printf("There was an error trying to write to the file %s.", CSV_FILE);
		
		pauseProgram('_');
	}

	closeFile();
}







// greet the customer

void menu_greetCustomer() {

	printf("Welcome to the Awesome Car Sales office!\n\n");
}






// thats our menu so the client can decide what he wants to do

void menu_showMenu() {

	printf("Menu:\n");
	printf("%c. Buy Cars\n", MENU_OPTION_BUY_A_CAR);
	printf("%c. View Car Sales Stats\n", MENU_OPTION_VIEW_A_CAR_SALES);
	printf("%c. A subset of Car Sales Stats\n", MENU_OPTION_VIEW_CAR_SALES_BETWEEN);
	printf("%c. Exit\n\n", MENU_OPTION_EXIT);
}






//calculate the number of cars we have and the prices
void menu_showCarTypes() {

	int numberOfCars = sizeof(carPrice) / sizeof(float);


	printf("\nCar Types:\n");

	for (int i = 0; i < numberOfCars; i++) {
		printf("%d - %s - %s\n", i, carType[i], carPr[i]);
	}
}






// we calculate the discount 20%

float menu_applyDiscount(float currentPrice) {

	return currentPrice * (1 - DISCOUNT_PERCENTAGE);
}





// and after that we check if he is eligible for that depending one the age and if he had an customer card
bool menu_checkIfDiscountIsNeeded(unsigned short userAge) {

	if (userAge >= MIN_AGE && userAge <= MAX_AGE) {

		return TRUE;
	}
	else {

		char customerCard = getCharFromConsole("\nDo you have a Customer card ? Answer 'y' or 'n' : ");

		if (customerCard == 'y') {

			return TRUE;
		}
	}


	return FALSE;
}






//here we inform the user it he gets a discount  or not
void menu_printDiscountOutcome(bool giveDiscount) {

	switch (giveDiscount) {

	case TRUE:
		printf("\nYou get a discount!");
		break;

	case FALSE:
		printf("\nNo discount given.");
		break;
	}
}



// here we ask the user what car he wants we calculate the prices and we show him the cars
//we uptade how many cars left
//we calculate the discount if he got one in the price
//and we record the outcome 
void menu_buyCars() {
	printf("Buy Cars:\n\n");


	if (carsAvailable > 0) {
		printf("There are %hd cars available.\n\n", carsAvailable);
	}
	else {
		printf("Sorry, there are no more Cars available.");

		return;
	}


	unsigned short carsNeeded = 0, userAge = 0, carsTypes = 0;
	bool giveDiscount = FALSE;
	float totalPrice = 0;


	getStringFromConsole("What is your name? Name: ", &customerNames[numberOfCarSales]);

	carsNeeded = getUnsignedShortFromConsole("How many cars do you need? Amount: ");


	if (carsAvailable < carsNeeded) {
		printf("Sorry, there are fewer cars remaining than you require.");

		return;
	}








	carAmountPerSale[numberOfCarSales] = carsNeeded;


	menu_showCarTypes();

	carsTypes = getUnsignedShortFromConsole("\nWhat type of Cars do you need? Choose from above: ");


	carTypePerSale[numberOfCarSales] = carsTypes;


	totalPrice = carsNeeded * carPrice[carsTypes];


	carsAvailable -= carsNeeded;


	userAge = getUnsignedShortFromConsole("How old are you? Age: ");


	giveDiscount = menu_checkIfDiscountIsNeeded(userAge);


	if (giveDiscount == TRUE) {
		totalPrice = menu_applyDiscount(totalPrice);
	}


	discountGivenPerSale[numberOfCarSales] = giveDiscount;


	menu_printDiscountOutcome(giveDiscount);


	printf("\n\nThank you.\n");
	printf("You have bought %hd cars.\n", carsNeeded);
	printf("Total price is %.3f GBP.\n", totalPrice);
	printf("\nThere are %hd cars remaining.", carsAvailable);


	numberOfCarSales++;
}









void sortArraysByNumberOfCarsSoldPerSale() {


	for (int i = 0; i < numberOfCarSales - 1; i++) {


		for (int j = i + 1; j < numberOfCarSales; j++) {

			if (carAmountPerSale[i] > carAmountPerSale[j]) {


				swapUnsignedShort(&carAmountPerSale[i], &carAmountPerSale[j]);


				swapUnsignedShort(&carTypePerSale[i], &carTypePerSale[j]);


				swapBool(&discountGivenPerSale[i], &discountGivenPerSale[j]);


				char temp[201];

				strcpy(temp, customerNames[i]);

				strcpy(customerNames[i], customerNames[j]);

				strcpy(customerNames[j], temp);

			}

		}

	}

}







// this here will show the user the sales data


void printSalesDataAtPosition(int position) {

	
	int typeOfCarData = carTypePerSale[position];
	
	float price = carAmountPerSale[position] * carPrice[typeOfCarData];

	
	char discountGivenText[4];
	
	if (discountGivenPerSale[position] == TRUE) {
		
		strcpy(discountGivenText, "Yes");
		
		price *= (1 - DISCOUNT_PERCENTAGE);
	}
	else {
		
		strcpy(discountGivenText, "No");
	}

	
	printf("Sale Index    :   %d        |Sale Amount   : %.3f\n"
		   "Type of Cars  :   %s     |Car Sale      : %.3f\n"
		   "Number of Cars:   %hd        |Discount Given:  %s \n"
		   "Customer Name :   %s",
		position, price, carType[typeOfCarData],
		carPrice[typeOfCarData], carAmountPerSale[position],
		discountGivenText, customerNames[position]);

}











//this is calculating how many cars sold and the price given and how many cars left so we can print it  to the client
void menu_viewSales() {

	sortArraysByNumberOfCarsSoldPerSale();


	float totalSalesValue = 0;
	unsigned int carsSold = 0;

	printf("All Sales Data:\n\n");


	for (int i = 0; i < numberOfCarSales; i++) {



		int typeOfCarData = carTypePerSale[i];

		float price = carAmountPerSale[i] * carPrice[typeOfCarData];


		printSalesDataAtPosition(i);


		totalSalesValue += price;
		carsSold += carAmountPerSale[i];

	}
	
	printf("\n%hd Cars have been sold with a total value of %.3f GBP. There are %hd Cars unsold.\n",
		carsSold, totalSalesValue, carsAvailable);
}










//printing the sales data between min and max
void printSalesDataBasedOnCarsSoldBetweenMinMax(unsigned short min, unsigned short max) {

	printf("Sales Data containing between %hd and %hd Cars sold:\n\n", min, max);


	for (int i = 0; i < numberOfCarSales; i++) {


		if (min <= carAmountPerSale[i] && carAmountPerSale[i] <= max) {


			printSalesDataAtPosition(i);

		}

	}

}






//asking the client how many cars is the maximum he wants and the minimum

void menu_viewSalesBetween() {


	sortArraysByNumberOfCarsSoldPerSale();


	unsigned short minCarsSold = getUnsignedShortFromConsole("What's the minimum number of Cars  you're interested in? Number = ");
	unsigned short maxCarsSold = getUnsignedShortFromConsole("What's the maximum number of Cars  you're interested in? Number = ");

	printSalesDataBasedOnCarsSoldBetweenMinMax(minCarsSold, maxCarsSold);
}







// we ensure no data is lot and we save to files and we say bye bye to our costumer
void menu_exit() {
	printf("Thank you for using Awesome Car Sales Store! Bye-bye!");


	saveDataToFile();
}









//starting point of the program
//check if there is any data in the file
//ask the user for a choice of cars
// and in the end of the program print a have a good day

int main() { // Changed return type to int
	getDataFromFile();

	char userChoice;

	do {
		clearScreen();

		menu_greetCustomer();
		menu_showMenu();

		userChoice = getCharFromConsole("Please choose a Car from the above : ");

		clearScreen();

		switch (userChoice) {
		case MENU_OPTION_BUY_A_CAR:
			menu_buyCars();
			break;

		case MENU_OPTION_VIEW_A_CAR_SALES:
			menu_viewSales();
			break;

		case MENU_OPTION_VIEW_CAR_SALES_BETWEEN:
			menu_viewSalesBetween();
			break;

		case MENU_OPTION_EXIT:
			menu_exit();
			break;
		}

		pauseProgram(userChoice);

	} while (userChoice != MENU_OPTION_EXIT);

	clearScreen();

	printf("\n\nHave a good day!\n\n");

	return 0; // Added return statement
}

