#include "BulkClass.h"
#include "OtherFunctions.h"

namespace AustinsNameSpace
{
ifstream infile;
bool found = false;
int choice = 0;
int initMemCount = 0;
int initTranCount = 0;
char Option;
}

namespace zain
{
string stringTemp;
int intTemp;
}

using namespace AustinsNameSpace;
using namespace zain;

int main(int argc, char **argv)
{
	BulkClass bulkClub;

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
		choice = bulkClub.Menu();

		switch (choice) {

		cout << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	case ADD_INITIAL_MEMBERS:

		if (initMemCount == 0)
		{
			//adds members
			bulkClub.AddMembers(infile, argv);
			infile.clear();
			cout << endl;
			cout << bulkClub.GetMemberArraySize() << " members added...\n\n";

			initMemCount++;
		} else
		{
			do
			{
				cout << "\n\nDo you want to re-initialize the list?... : ";
				Option = GetAndCheck('Y', 'N');
			} while (Option == -1);

			if (Option == 'Y')
			{
				cout << "\n Okay, please hit 1 to-initialize the list.\n\n";
				initMemCount = 0;
				bulkClub.DeleteMemberList();
			} else
			{
				cout << "\n\nList not re-initialized...\n\n";
			}
		}

		break;

	case ADD_TRANSACTIONS:

		if (initTranCount == 0)
		{
			if (bulkClub.GetMemberArraySize() != 0)
			{
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
						<< " transactions added...\n\n";

				initTranCount = 1;

			} else
			{
				cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
			}
		} else
		{
			do
			{
				cout << "\n\nDo you want to re-initialize the list?... : ";
				Option = GetAndCheck('Y', 'N');
			} while (Option == -1);

			if (Option == 'Y')
			{
				cout << "\n Okay, please hit 2 to-initialize the list.\n\n";
				initTranCount = 0;
				bulkClub.DeleteTransactionList();
			} else
			{
				cout << "\n\nList not re-initialized...\n\n";
			}

		}

		break;

	case PRINT_SALES_REPORT:

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{

			//option #1, day is passed in by user input...

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

			cout << endl;

			bulkClub.PrintSalesReport(intTemp);

		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case SEARCH_NAME_OR_ID:

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{

			cin.ignore(1000, '\n');
			cout << "\nPlease enter a name or ID: ";
			//option number 2 with a name passed in
<<<<<<< HEAD
=======
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
>>>>>>> origin/Project-Details
			getline(cin, stringTemp);

			found = bulkClub.SearchNameOrId(stringTemp);
			if (!found)
			{
				cout << "\n\nName or ID has no transaction record\n\n";

			}

		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_TOTAL_PURCHASES:

		cout << endl;

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			//prints the total purchases by each member and a grand total.
			bulkClub.PrintTotalPurchases();
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_TOTAL_ITEMS_SOLD:

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			cin.ignore(1000, '\n');
			//searchs an item by user input and ouputs the amount sold and the
			//total price
			cout << "\nEnter item: ";
			getline(cin, stringTemp);
			bulkClub.PrintTotalSalesAndItemsSold(stringTemp);
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_ITEM_QUANTITY:

		cout << endl;

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			//prints the opverall quantity of each item
			bulkClub.PrintItemQuantity();
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_REBATE:

		cout << endl;

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			//prints the rebate for preferred members
			bulkClub.PrintPreferredRebate();
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_AMOUNT_PAID:

		cout << endl;

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			bulkClub.PrintAmountPaid();
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_EXPIRATION:

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

			bulkClub.PrintMemberExpiration(intTemp);
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case ADD_NEW_MEMBERS:

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			bulkClub.AddMembers();
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

	case DELETE_MEMBERS:

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

		if (bulkClub.GetMemberArraySize() != 0
				&& bulkClub.GetTransactionArraySize() != 0)
		{
			bulkClub.AddTransactions();
		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!";
		}

		break;

		}

		//outputs with all the changed data
		//bulkClub.OutputMembers();

		cout << endl << endl;

		if (choice != EXIT)
		{
<<<<<<< HEAD
=======
			cout << "Press Enter To Go Back" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
>>>>>>> origin/Project-Details
			system("cls");
		}

	} while (choice != EXIT);

}

