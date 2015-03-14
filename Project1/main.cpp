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

int main()
{

	BulkClass bulkClub;

	// PRINT - Welcome screen
	cout <<
	"__          __  _                            _______            \n"
	"\\ \\        / / | |                          |__   __|         \n"
	" \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___     | | ___       \n"
	"  \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | |/ _ \\ \n"
	"   \\  /\\  /  __/ | (_| (_) | | | | | |  __/    | | (_) |      \n"
	"    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|    |_|\\___/  \n\n";

	do
	{
		choice = bulkClub.Menu();
		system("cls");

		switch (choice)
		{

		cout << endl;
		cin.ignore(1000, '\n');

	case ADD_INITIAL_MEMBERS:

		if (initMemCount == 0)
		{
			//adds members
			bulkClub.AddMembers(infile);
			infile.clear();
			cout << endl;
			cout << bulkClub.GetMemberArraySize() << " members added...\n\n";

			initMemCount++;
		}
		else
		{
			cout << "\n\nDo you want to re-initialize the list?... : ";
			cin >> Option;

			if (Option == 'Y')
			{
				cout << "\n Okay, please hit 1 to-initialize the list.\n\n";
				initMemCount = 0;
				bulkClub.DeleteMemberList();
			}
			else
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
				bulkClub.FillItemArray(infile, 1);
				infile.clear();

				//fills the array with the second file
				bulkClub.FillItemArray(infile, 2);
				infile.clear();

				//fills the array with the third file
				bulkClub.FillItemArray(infile, 3);
				infile.clear();

				//fills the array with the fourth file
				bulkClub.FillItemArray(infile, 4);
				infile.clear();

				//fills the array with the fifth file
				bulkClub.FillItemArray(infile, 5);
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
			cout << "\n\nDo you want to re-initialize the list?...: ";
			cin >> Option;

			if (Option == 'Y')
			{
				cout << "\n Okay, please hit 2 to-initialize the list.\n\n";
				initTranCount = 0;
				bulkClub.DeleteTransactionList();
			}
			else
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

			cin.ignore(1000, '\n');
			do
			{
				//function call - menu
				cout << endl;
				cout << "Please enter a day(1-5)";
				cout << endl;
				cout << "Choice: ";
				//function call - check int input
				intTemp = -1;
				intTemp = GetAndCheckInt(1, 5);

			} while (intTemp == -1);

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

			cout << "Please enter a name or ID: ";
			//option number 2 with a name passed in
			cin.ignore(1000, '\n');
			getline(cin, stringTemp);

			found = bulkClub.SearchNameOrId(stringTemp);
			if (!found)
			{
				cout << "\n\nName or ID not found...\n";

			}

		} else
		{
			cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
		}

		break;

	case PRINT_TOTAL_PURCHASES:

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
			cin.ignore(1000, '\n');
			do
			{
				//function call - menu
				cout << endl;
				cout << "Please enter a day(1-5)";
				cout << endl;
				cout << "Choice: ";
				//function call - check int input
				intTemp = -1;
				intTemp = GetAndCheckInt(1, 5);

			} while (intTemp == -1);

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

		}

		//outputs with all the changed data
		//bulkClub.OutputMembers();

		cout << endl << endl;

	} while (choice != EXIT);

}

