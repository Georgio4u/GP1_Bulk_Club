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
	 bool SearchNameOrId(string);
	 void PrintTotalPurchases();

private:

	//the arrays and their sizes

 int memberCount;
 int transactionCount;
 BasicMember ** memberArray;
 Transaction ** itemArray;


};
#endif /* BULKCLASS_H_ */
