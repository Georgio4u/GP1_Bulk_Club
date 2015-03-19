/**********************************************************
 * AUTHOR 		 : Austin English, Zane, Georgio
 * STUDENT ID 	 : 364965
 * Project #1    : Bulk Club
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 3/19/15
 **********************************************************/

#include "BulkClass.h"
#include "OtherFunctions.h"

/*************************************************************************
 *
 *                  BULK CLUB(PROJECT #1)
 *________________________________________________________________________
 *  Hello users. Ever wondered how much time and money members spend at
 *  the bulk club? Well the wait is over. Anyone who is curious can gain
 *  access to a number of features when viewing spent data at the
 *  bulk club. So many features that they are not even going to be listed
 *  in this abstract. Enjoy using this program, and if any questions
 *  arrise, be sure to click item #15 in the list to view contributions.
 * _______________________________________________________________________
 * INPUTS:
 * 		infile    : access to all files
 * 		choice    : user menu option
 * 		stringTemp: User input for data
 * 		Option    : user re initialize list
 *
 *
 * PROCESSING:
 *
 * 		intTemp     : temp holder for user entered data(error check)
 * 		initMemCount: will not allow option 1 to be entered again
 * 		found       : data returns true or false, container variable
 *
 *
 * OUTPUTS:
 * 		The list ultimately outputs the list... not in main though
 *
 ************************************************************************/



// Austins namespace variables
namespace AustinsNameSpace
{
ifstream infile;      // file data
bool found = false;   // error checking bool
int choice = 0;       // user input data
int initMemCount = 0; // errror checking tool
char Option;          // user input for yes/no questions
}

// zains namespace variables
namespace zain
{
string stringTemp;  // tempstring for inputs
int intTemp;        // int for holding user input for error checks
}

//using both namespaces in main...
using namespace AustinsNameSpace;
using namespace zain;

int main(int argc, char **argv)
{
	BulkClass bulkClub; //bulkclub object

	// PRINT - Precision set to two decimal point for money
	cout << fixed << setprecision(2);

	// PRINT - Welcome screen
	cout
<< "__          __  _                            _______            \n"
"\\ \\        / / | |                          |__   __|         \n"
" \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___     | | ___       \n"
"  \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | |/ _ \\ \n"
"   \\  /\\  /  __/ | (_| (_) | | | | | |  __/    | | (_) |      \n"
"    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|    |_|\\___/  \n\n";

	do
	{
		// error check for menu
		choice = bulkClub.Menu();
		system("cls");
		//switch for 15 options
		switch (choice)
		{

		cout << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// adds data to member list and transaction list
	case ADD_DATA:

		// will only add once
		if (initMemCount == 0)
		{
			//adds members
			bulkClub.AddMembers(infile, argv);
			infile.clear();
			cout << endl;
			cout << bulkClub.GetMemberArraySize() << " members added...\n";

			initMemCount++;

			//fills the array with the first file
			bulkClub.FillItemArray(infile, 1, argv);
			infile.clear();

			//fills the array with the second file
			bulkClub.FillItemArray(infile, 2, argv);
			infile.clear();

			//fills the array with the third file
			bulkClub.FillItemArray(infile, 3, argv);
			infile.clear();

			//fills the array with the fourth file
			bulkClub.FillItemArray(infile, 4, argv);
			infile.clear();

			//fills the array with the fifth file
			bulkClub.FillItemArray(infile, 5, argv);
			cout << endl;

			cout << bulkClub.GetTransactionArraySize()
					<< " transactions added...\n";
		}
		else
		{
			//output
			cout << "\n\n CANNOT ADD AGAIN\n\n";
		}
		break;

		// will print the total sales reporty for a given day
	case PRINT_SALES_REPORT:

		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			do
			{
				//function call - menu
				cout << endl;
				cout << "Please enter a day (1-5)";
				cout << endl;
				cout << "Choice: ";
				//function call - check int input
				intTemp = -1;
				intTemp = GetAndCheckInt(1, 5);

			} while (intTemp == -1);

			cout << endl << endl;

			bulkClub.PrintSalesReport(intTemp);

		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

		//will search a name or id from user input
	case SEARCH_NAME_OR_ID:

		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{

			cin.ignore(1000, '\n');
			cout << "\nPlease enter a name or ID: ";
			//option number 2 with a name passed in

			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, stringTemp);

			found = bulkClub.SearchNameOrId(stringTemp);
			if (!found)
			{
				cout << "\n\nName or ID has no transaction record\n\n";
				cout << setfill('-') << setw(45) << '-'
					 << setfill(' ') << endl;
			}
		}
		else
		{
			//output
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	// will print the total purchases of all members
	case PRINT_TOTAL_PURCHASES:

		cout << endl;

		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			//prints the total purchases by each member and a grand total.
			bulkClub.PrintTotalPurchases();
		}
		else
		{
			//output
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_TOTAL_ITEMS_SOLD:

		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			cin.ignore(1000, '\n');
			//searchs an item by user input and ouputs the amount
			//sold and the total price
			cout << "\nEnter item: ";
			getline(cin, stringTemp);

			//function call
			bulkClub.PrintTotalSalesAndItemsSold(stringTemp);
		}
		else
		{
			//output
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	//prints the quantity of all items bought
	case PRINT_ITEM_QUANTITY:

		cout << endl;

		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			//prints the opverall quantity of each item
			bulkClub.PrintItemQuantity();
		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;
		//prints the rebate of preferred members
	case PRINT_REBATE:

		cout << endl;
		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			//prints the rebate for preferred members
			bulkClub.PrintPreferredRebate();
		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_AMOUNT_PAID:

		cout << endl;
		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			bulkClub.PrintAmountPaid();
		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_EXPIRATION:

		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			do
			{
				//function call - menu
				cout << endl;
				cout << "Please enter a month (1-12)";
				cout << endl;
				cout << "Choice: ";
				//function call - check int input
				intTemp = -1;
				intTemp = GetAndCheckInt(1, 12);

			} while (intTemp == -1);

			cout << endl;

			// function call
			bulkClub.PrintMemberExpiration(intTemp);
		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case ADD_NEW_MEMBERS:

		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			cout << endl;
			bulkClub.AddMembers();
		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case DELETE_MEMBERS:
		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			bulkClub.deleteMember();
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case ADD_NEW_TRANSACTIONS:
		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			bulkClub.AddTransaction();
		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case RE_INIZALIZE:
		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{

			do
			{
				cout << "\n\nDo you want to re-initialize the list?... : ";
				Option = GetAndCheck('Y', 'N');
			} while (Option == -1);

			if (Option == 'Y')
			{

				cout << "\n\nlist re- initialized";
				bulkClub.DeleteMemberList();
				bulkClub.DeleteTransactionList();

				//adds members
				infile.clear();
				bulkClub.AddMembers(infile, argv);
				infile.clear();
				cout << endl;

				initMemCount++;

				//fills the array with the first file
				bulkClub.FillItemArray(infile, 1, argv);
				infile.clear();

				//fills the array with the second file
				bulkClub.FillItemArray(infile, 2, argv);
				infile.clear();

				//fills the array with the third file
				bulkClub.FillItemArray(infile, 3, argv);
				infile.clear();

				//fills the array with the fourth file
				bulkClub.FillItemArray(infile, 4, argv);
				infile.clear();

				//fills the array with the fifth file
				bulkClub.FillItemArray(infile, 5, argv);
				cout << endl;

			}
			else
			{
				cout << "\n\nList not re-initialized...";
			}

		}
		else
		{
			cout << "\nCANNOT DELETE FROM AN EMPTY LIST!";
		}

		break;

	case BASIC_CONVERT_OR_NOT:
		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			cout << endl;
			bulkClub.ShouldBasicMembersConvert();
		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case PREFERRED_CONVERT_OR_NOT:
		// array cannot be empty
		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{

			cout << endl;
			bulkClub.ShouldPreferredMembersConvert();

		}
		else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case ABOUT:
		// Used to output all the programmers commitments
			cout << endl << setfill('*') << setw(59) << '*' << setfill(' ')
			     << endl;
			cout << setw(37) << right << "ABOUT THIS PROGRAM" << left;
			cout << endl << setfill('*') << setw(59) << '*' << setfill(' ')
			     << endl;

			cout << setw(19) << "PRODUCT OWNER:"
				             << "Austin English\n";
			cout << setw(19) << "SCRUM MASTER:"
				             << "Georgio Christodulou\n";
			cout << setw(19) << "NOBLE TEAM MEMBER:" << "Zain Haque\n\n";

			cout << setw(37) << right << "PROGRAMMING\n";

			cout << "Loading Members" << setfill('.') << setw(45)
				 << "Austin English\n";
			cout << "Loading Transactions" << setw(40) << "Zain Haque\n";
			cout << "Sales Report" << setw(48) << "Georgio Christodulou\n";
			cout << "Total Member Purchases" << setfill('.') << setw(38)
				 << "Austin English\n";
			cout << "Total Item Purchases" << setw(40) << "Zain Haque\n";
			cout << "Output Sales of Items" << setw(39) << "Georgio "
					                                       "Christodulou\n";
			cout << "Output Quantity of Items" << setw(36) << "Georgio "
					                                       "Christodulou\n";
			cout << "Rebates" << setw(53) << "Zain Haque\n";
			cout << "Member Dues" << setw(49) << "Austin English\n";
			cout << "Membership Expiration" << setw(39) << "Georgio "
					                                       "Christodulou\n";
			cout << "Add Members" << setw(49) << "Zain Haque\n";
			cout << "Remove Members" << setw(46) << "Georgio "
					                                "Christodulou\n";
			cout << "Change Membership Status" << setw(36) << "Austin "
					                                          "English\n\n";

			cout << right << setfill(' ') << setw(29) << "UML\n";

			cout << "Class Diagram" << setfill('.') << setw(47)
				 << "Georgio Christodulou\n";
			cout << "State Diagram" << setw(47) << "Austin English\n";
			cout << "Use Cases" << setw(50) << "Zain Haque";

			cout << endl << setfill('*') << setw(59) << '*' << setfill(' ')
			     << endl;
			break;

		}// end of switch

		cout << endl << endl;

		if (choice != EXIT)
		{
			//system("cls");
		}

		// end of main do while loop
	} while (choice != EXIT);

}

