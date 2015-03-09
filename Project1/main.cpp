#include "BulkClass.h"

namespace AustinsNameSpace
{
ifstream infile;
bool found = false;
int choice = 0;
int initMemCount = 0;
int initTranCount = 0;
}

using namespace AustinsNameSpace;

int main()
{

	BulkClass bulkClub;

	cout << endl << endl;

	do
	{

		choice = bulkClub.Menu();

		switch (choice)
		{

		cout << endl;
		cin.ignore(1000,'\n');

		case ADD_INITIAL_MEMBERS:

			if (initMemCount == 0)
			{
				//adds members
				bulkClub.AddMembers(infile);
				infile.clear();
				cout << endl;
				cout << bulkClub.GetMemberArraySize()
						<< " members added...\n\n";

				initMemCount++;
			} else
			{
				cout << "\n\ncannot re-initialize list...\n\n";
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


				}
				else
				{
					cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
				}
			}
			else
			{
				cout << "\n\ncannot re-initialize list...\n\n";
			}
			break;

		case PRINT_SALES_REPORT:

			if (bulkClub.GetMemberArraySize() != 0
					&& bulkClub.GetTransactionArraySize() != 0)
			{

				//option #1, day is passed in by user input...
				bulkClub.PrintSalesReport(4);

			} else
			{
				cout << "\nNEED TO ADD MEMBERS FIRST!\n\n";
			}

			break;

		case SEARCH_NAME_OR_ID:

			if (bulkClub.GetMemberArraySize() != 0
					&& bulkClub.GetTransactionArraySize() != 0)
			{

				//option number 2 with a name passed in
				found = bulkClub.SearchNameOrId("Sally Shopper");
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
				bulkClub.PrintTotalSalesAndItemsSold("Coke");
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
				bulkClub.PrintMemberExpiration(11);
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

		}

		//outputs with all the changed data
		//bulkClub.OutputMembers();

		cout << endl << endl;

	} while (choice != EXIT);

}

