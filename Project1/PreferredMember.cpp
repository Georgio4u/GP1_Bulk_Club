/**********************************************************
 * AUTHOR 		 : Austin English, Zane, Georgio
 * STUDENT ID 	 : 364965
 * Project #1    : Bulk Club
 * CLASS 		 : CS1C
 * SECTION 		 : T/TH 12:30a - 4:20p
 * DUE DATE 	 : 3/19/15
 **********************************************************/
#include "PreferredMember.h"

//default constructor
PreferredMember::PreferredMember()
{

	preferredDues = 0;
	rebate = 0;

}

//non default with a call to the basic member class to fill that data as
//well
PreferredMember::PreferredMember(string name, int id,
					string memberType,string memberExpiration)

				:BasicMember(name, id, memberType, memberExpiration)
{


	preferredDues = 95.00;


	rebate = 0;

}

//sets the rebate
void PreferredMember:: SetRebate( double amount)
{

	rebate = amount;

}

//gets the rebate.
float PreferredMember:: GetRebate()
{

	return rebate;
}


void PreferredMember:: PrintDues()
{

	cout << preferredDues;
	cout << endl;


}
