
/**********************************************************
 * AUTHOR 		 : Austin English, Zane, Georgio
 * STUDENT ID 	 : 364965
 * Project #1    : Bulk Club
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 3/19/15
 **********************************************************/
#ifndef BULKCLASS_H_
#define BULKCLASS_H_

#include "PreferredMember.h"
#include "BasicMember.h"
#include <stdlib.h>

//struct for 5 days of transactions
struct Transaction
{
	Date date;        // compositon of date class
	int memberId;     // id of transaction
	double itemPrice; // price of item bought
	int itemQuantity; // quantity of item bought
	string itemName;  // name of item bought
	int day;          // day for input files and adding transactions

	void ConvertStringDate(string);
	//will convert the date into ints from a string
	//member function of struct

	void AddData(int tempId, int day, string itemName, double itemPrice,
				 int itemQuantity);
	//adds data when transaction data is added for a member.
	// all variables are initialized

};

// menu options for user
enum MenuOptions
{
	EXIT,
	ADD_DATA,
	RE_INIZALIZE,
	PRINT_SALES_REPORT,
	SEARCH_NAME_OR_ID,
	PRINT_TOTAL_PURCHASES,
	PRINT_TOTAL_ITEMS_SOLD,
	PRINT_ITEM_QUANTITY,
	PRINT_REBATE,
	PRINT_AMOUNT_PAID,
	PRINT_EXPIRATION,
	ADD_NEW_MEMBERS,
	ADD_NEW_TRANSACTIONS,
	DELETE_MEMBERS,
	BASIC_CONVERT_OR_NOT,
	PREFERRED_CONVERT_OR_NOT,
	ABOUT

};

// enum to display type of member.
enum DisplayCertainMember
{
	BASIC,
	PREFERRED,
	ALL_MEMBERS

};

//main class of whole project
class BulkClass
{
public:

	BulkClass();
	//constructor

	~BulkClass();

	BulkClass( const BulkClass& otherArr);
	//copy constructor for bulk class arrays

	int GetMemberArraySize();
	//will return the size of the array to see if it is empty or not
	//used in main to make sure options cannot be executed unless array<0

	int GetTransactionArraySize();
	//will return the size of the array to see if it is empty or not
	//used in main to make sure options cannot be executed unless array<0

	void AddMembers(ifstream &infile, char **path);
	//add members from file and path for the files

	int Menu();
	//menu for user to follow when choosing options

	string SubMenu();
	//menu for chosing certain member types

	void FillItemArray(ifstream&, int, char **path);
	//used to fill item/transactions array

	void UpdateRebateAndCost();

	string to_string(int number);
	//converts ints to a string

	void PrintSalesReport(int Day);
	//prints the report for a single day

	bool SearchNameOrId(string);
	//	A user should be able to enter a membership number or name and
	//get a list of the total purchases per that member.

	void PrintTotalPurchases();
	//A report that prints the total purchases by all the members sorted
	//by membership number.  It should also include a grand total of the
	//purchases.

	void PrintTotalSalesAndItemsSold(string);
	//A user should be able to enter an item name and get the quantity of
	//that item sold as well as the total sales price.

	void PrintItemQuantity();
	//A report that prints out the quantity of each item sold sorted by
	//item name.

	void PrintPreferredRebate();
	//prints the rebate for the preferred members

	void PrintAmountPaid();
	//prints the member fees for all members

	void PrintMemberExpiration(int);
	// will print the expiration based on a month entered

	void AddMembers();
	// will add members to the list

	void deleteMember();
	// will delete members from the list

	void DeleteMemberList();
	//will destroy the list, called in desructor

	void DeleteTransactionList();
	// will delete all transactions added

	void AddTransaction();
	//will add trnasactions to the program

	void ShouldBasicMembersConvert();
	//outputs the basic members who should convert as well as a hypothetical
	//rebate

	void ShouldPreferredMembersConvert();
	//outputs the preferred members who should convert

	void OverWriteMemberFile();
	// will allow the member file to be overwritten if new members are
	// added



private:

	//the arrays and their sizes

	int memberCount;            // size of member array
	int transactionCount;       // size of transaction array
	BasicMember ** memberArray; // array holding all members
	Transaction ** itemArray;   // array holding all transactions

};
#endif /* BULKCLASS_H_ */
