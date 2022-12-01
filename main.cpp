#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployement)
{
    if(wages < 0)
    {
        wages = -1*wages;
    }    
    if(interest < 0)
    {
        interest = -1*interest;
    }
    if(unemployement < 0)
    {
        unemployement = -1*unemployement;
    }   
    return wages+interest+unemployement;
}

int GetDeduction(int status)
{
    if(status == 2)
      return 24000;
    else if(status == 1)
      return 12000;
    else 
      return 6000;
}

//Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction)
{
    int taxable = agi - deduction;
    if(taxable < 0)
      
    return taxable;
}

// Calculate tax for single or dependent or married
int CalcTax(int status, int taxable)
{
  int tax;
  if(status == 0 || status == 1)
    {
      if(taxable <= 10000)
      {
         tax = (int)round(taxable*0.10);
      }
      else if(taxable <= 40000)
      {
        tax = 1000 + (int) round((taxable - 10000)*0.12);
      }
      else if(taxable <= 85000)
      {
        tax = 4600 + (int) round((taxable - 40000)*0.22);
      }
      else
      {
         tax = 14500 + (int)round((taxable - 85000)*0.24);
      }
        
    }
    else
    {
      if(taxable <= 20000)
      {
        tax = (int)round(taxable*0.10);
      }
      else if(taxable <= 80000)
      {
        tax = 2000 + (int)round((taxable - 20000)*0.12);
      }
      else
      {
        tax = 9200 + (int)round((taxable - 80000)*0.22);
      }
      }
  return tax;
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld)
{
  int taxdue;
  if(withheld < 0)
    taxdue = 0;
  else 
    taxdue = tax - withheld;
  return taxdue;
}

// Main function
int main()
{
    // Variable declaration
    int wages, interest, unemployement, status, withheld;
    int tax, agi, due, deduction, taxable;
  
    // Step #1: Input information
  cin >> wages;
  cin >> interest;
  cin >> unemployement;
  cin >> status;
  cin >> withheld;
  
    // Step #2: Calculate AGI
    agi = CalcAGI(wages, interest, unemployement);
    cout << "AGI: $" << agi << endl;
  
    deduction = GetDeduction(status);
    cout << "Deduction: $" << deduction << endl;

    taxable = CalcTaxable(agi, deduction);
    cout << "Taxable income: $" << taxable << endl;

    tax = CalcTax(status,taxable);
    cout << "Federal tax: $" << tax << endl;

    due = CalcTaxDue(tax, withheld);
    cout << "Tax due: $" << due << endl;

    return 0;
}