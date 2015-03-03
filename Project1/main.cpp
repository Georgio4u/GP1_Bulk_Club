
#include "BulkClass.h"

namespace AustinsNameSpace
	{
		ifstream infile;
		bool found = false;
	}


using namespace AustinsNameSpace;

int main()
{

	BulkClass bulkClub;

	//adds members
	bulkClub.AddMembers(infile);
	infile.clear();

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

	//outputs with all the changed data
	bulkClub.OutputMembers();

	//option #1, day is passed in by user input...
	bulkClub.PrintSalesReport(4);

	//option number 2 with an id passed in
	found = bulkClub.SearchNameOrId("88888");
	if (!found)
	{
		cout << "\n\nName or ID not found...\n";

	}

	//option number 2 with a name passed in
	found = bulkClub.SearchNameOrId("Sally Shopper");
	if (!found)
	{
		cout << "\n\nName or ID not found...\n";

	}

	cout << endl << endl;
	//prints the total purchases by each member and a grand total.
	bulkClub.PrintTotalPurchases();

	cout << endl << endl << endl;

	//searchs an item by user input and ouputs the amount sold and the
	//total price
	bulkClub.PrintTotalSalesAndItemsSold("Coke");

	cout << endl << endl << endl;

	bulkClub.PrintItemQuantity();

}

