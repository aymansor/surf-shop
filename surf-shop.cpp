#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes
void ShowUsage();
void MakePurchase(int& iTotalX3samll,int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalX3samll, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTotalX3samll, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void TitleHeader();
void ClearInputStream();
void printOutput(const string itemSize, const int itemCount, const double itemTotalCost = 0);

int main()
{
	// Tracks how many surfboards sold of each size
	int iTotalX3samll = 0;
	int iTotalSmall = 0;
	int iTotalMedium = 0;
	int iTotalLarge = 0;

	// Output title header and show program usage
	TitleHeader();
	ShowUsage();

	char selection = ' ';
	while (selection != 'Q')
	{
		// Ask for input
		cout << endl;
		cout << "Please enter selection: ";
		cin >> selection;
		ClearInputStream();

		// Capitalize selection so the switch cases are evaluated accordingly
		selection = toupper(selection);

		switch (selection)
		{
		case 'S':
			cout << string(25, '\n');
			TitleHeader();
			// Call function to output how to use the program
			ShowUsage();
			break;
		case 'P':
			// Call function to sell surfboards - parameters are passed by reference 
			MakePurchase(iTotalX3samll, iTotalSmall, iTotalMedium, iTotalLarge);
			break;
		case 'C':
			// Call function to output the number of surfboards purchased
			DisplayPurchase(iTotalX3samll, iTotalSmall, iTotalMedium, iTotalLarge);
			break;
		case 'T':
			// Call function to show total amount due
			DisplayTotal(iTotalX3samll, iTotalSmall, iTotalMedium, iTotalLarge);
			break;
			// Quit the program
		case 'Q':
			cout << "Thank you";
			cout << "\nPress any key to continue. . . ";
			cin.get();
			return 0;
			// If user enters an invalid entry, notify user
		default:
			cout << "Invalid entry, try again!" << endl;
		}
	}

	return 0;
}

// Function to print the program usage
void ShowUsage()
{
	cout << "To show program usage \'S\'" << endl;
	cout << "To purchase a surfboard press \'P\'" << endl;
	cout << "To display current purchases press \'C\'" << endl;
	cout << "To display total amount due press \'T\'" << endl;
	cout << "To quit the program press \'Q\'" << endl;
}

// Responsible for selling surfboards to the user and gathering purchase quantity and type.
void MakePurchase(int& iTotalX3samll, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
	// Named constants - Surfboard sizes options
	const char X3_SMALL_SURFBOARD_TYPE = 'X';
	const char SMALL_SURFBOARD_TYPE = 'S';
	const char MEDIUM_SURFBOARD_TYPE = 'M';
	const char LARGE_SURFBOARD_TYPE = 'L';

	// Initialize variables - Tracks user choices
	int purchaseQuantity = 0;
	char purchaseType = ' ';

	// Get input
	cout << "Please enter the quantity and type (X=x3small, S=small, M=medium, L=large) "
		<< "of surfboard you would like to purchase: ";
	cin >> purchaseQuantity >> purchaseType;

	if (!cin || purchaseQuantity < 0)
	{
		cout << "[!] Invalid entry." << endl;
		ClearInputStream();
	}
	// Else the input is good for calculation
	else
	{
		ClearInputStream();

		// Capitalize the surfboard size option entered by the user
		purchaseType = toupper(purchaseType);
		// Checks what surfboard type was selected by the user
		if (purchaseType == X3_SMALL_SURFBOARD_TYPE)		// 'X'
			iTotalX3samll += purchaseQuantity;
		else if (purchaseType == SMALL_SURFBOARD_TYPE)		// 'S'
			iTotalSmall += purchaseQuantity;
		else if (purchaseType == MEDIUM_SURFBOARD_TYPE)		// 'M'
			iTotalMedium += purchaseQuantity;
		else if (purchaseType == LARGE_SURFBOARD_TYPE)		// 'L'
			iTotalLarge += purchaseQuantity;
		else
			cout << "[!] " << purchaseType << " is not a valid option" << endl;
	}
}

// This function outputs how many surfboards of each size purchased
void DisplayPurchase(const int iTotalX3samll, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	// If any surfboards were purchased by user print the size and total amount purchased
	printOutput("x3 small", iTotalX3samll);
	printOutput("small", iTotalSmall);
	printOutput("medium", iTotalMedium);
	printOutput("large", iTotalLarge);

	// If no surfboards of any size were purchased, print an appropriate message
	if (iTotalX3samll == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
		cout << "No purchases made yet." << endl;
}

// This function prints the total amount due
void DisplayTotal(const int iTotalX3samll, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	// Named constants - Prices of surfboards
	const double X3_SMALL_SURFBOARD_COST = 145.00;
	const double SMALL_SURFBOARD_COST = 175.00;
	const double MEDIUM_SURFBOARD_COST = 190.00;
	const double LARGE_SURFBOARD_COST = 200.00;

	double x3smallSurfboardTotal = X3_SMALL_SURFBOARD_COST * iTotalX3samll;
	double smallSurfboardTotal = SMALL_SURFBOARD_COST * iTotalSmall;
	double mediumSurfboardTotal = MEDIUM_SURFBOARD_COST * iTotalMedium;
	double largeSurfboardTotal = LARGE_SURFBOARD_COST * iTotalLarge;
	double totalAmountDue = x3smallSurfboardTotal + smallSurfboardTotal + mediumSurfboardTotal + largeSurfboardTotal;
	
	// If any surfboards were purchased by user print the size, total amount purchased, and cost of each surfboard size
	printOutput("x3 small", iTotalX3samll, x3smallSurfboardTotal);
	printOutput("small", iTotalSmall, smallSurfboardTotal);
	printOutput("medium", iTotalMedium, mediumSurfboardTotal);
	printOutput("large", iTotalLarge, largeSurfboardTotal);

	// If no surfboards of any size were purchased, print an appropriate message, else print total amount due
	if (iTotalX3samll == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
		cout << "No purchases made yet." << endl;
	else
		cout << "Amount due: $" << totalAmountDue << endl;
}

// This function outputs the title header
void TitleHeader()
{
	// Title header constants
	const string TITLE = " Welcome to my Surf Shop ";
	const char SYMBOLE = '*';
	const int LINE_LENGTH = 59;
	const int HALF_LINE_LENGTH = (LINE_LENGTH - TITLE.length()) / 2;

	const string FULL_LINE = string(LINE_LENGTH, SYMBOLE);
	const string HALF_LINE = string(HALF_LINE_LENGTH, SYMBOLE);

	// Title header output
	cout << FULL_LINE << endl;
	cout << HALF_LINE << TITLE << HALF_LINE << endl;
	cout << FULL_LINE << "\n\n" << endl;

}

// This function clears the input stream to avoid the program from going into a fail state, causing wrong results or errors.
void ClearInputStream()
{
	// Resets the input stream to a working state.
	cin.clear();
	// Ignore the rest of the input up until 10000 characters.
	cin.ignore(10000, '\n');
}

void printOutput(const string itemSize, const int itemCount, const double itemTotalCost)
{
	cout << fixed << showpoint << setprecision(2);
	if (itemCount > 0)
		cout << "The total number of " + itemSize + " surfboards is " << itemCount;
	if (itemCount > 0 && itemTotalCost != 0)
		cout << " at a total of $" << itemTotalCost;

	if (itemCount > 0)
		cout << endl;
}