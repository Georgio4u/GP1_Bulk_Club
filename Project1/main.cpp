/*
 * main.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: aenglish3
 */

#include "BulkClass.h"

int main()
{

	ifstream infile;
	BulkClass bulkClub;

	//adds members
	bulkClub.AddMembers(infile);

	//outputs all members with default values
	bulkClub.OutputMembers();
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
	cout << endl << endl;

	//outputs with all the changed data
	bulkClub.OutputMembers();

}

