/*
 * PreferredMember.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: aenglish3
 */

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
