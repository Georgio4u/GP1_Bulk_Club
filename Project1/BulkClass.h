/*
 * BulkClass.h
 *
 *  Created on: Feb 12, 2015
 *      Author: aenglish3
 */

#ifndef BULKCLASS_H_
#define BULKCLASS_H_

#include "PreferredMember.h"
#include "BasicMember.h"

//struct for 5 days of transactions
struct Transaction
{
	Date date;
	int memberId;
	double itemPrice;
	int itemQuantity;
	string itemName;
	int day;

	void ConvertStringDate(string);

};


class BulkClass
{
public:

	BulkClass();
	//constructor

	void AddMembers(ifstream &infile);
	//add members from file

	void OutputMembers();
	//basic output

	void FillItemArray(ifstream&,int);
	//used to fill item/transactions array

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

private:

	//the arrays and their sizes

 int memberCount;
 int transactionCount;
 BasicMember ** memberArray;
 Transaction ** itemArray;


};
#endif /* BULKCLASS_H_ */
