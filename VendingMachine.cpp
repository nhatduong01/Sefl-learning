#include<iostream>
#include<iomanip>
using namespace std;
class  dispenserRegister;
class cashRegister
{
private:
	int cashOnhand;
public:
	cashRegister()
	{
		cashOnhand = 500;
	}
	cashRegister(int cash)
	{
		cashOnhand = cash;
	}
	int getCurrentBalance()
	{
		return cashOnhand;
	}
	void acceptAmount(int deposit)
	{
		cashOnhand += deposit;
	}

};
class  dispenserRegister
{
private:
	int noOfItems;
	int cost;
	const int CostCoookies = 5;
	const int CostWater = 6;
	const int CostCoke = 7;
	const int CostChips = 8;
public:
	dispenserRegister()
	{
		noOfItems = 50;
		cost = 50;
	}
	dispenserRegister(int _noOfItems, int _cost)
	{
		noOfItems = _noOfItems;
		cost = _cost;
	}
	int getNoOfItems()
	{
		return noOfItems;
	 }
	int getCost()
	{
		return cost;
	}
	void makeSale()
	{
		noOfItems--;
	}
	

};
void showSelection()
{
	cout << "***Welcome to Nhat Duong's candy shop***\n";
	cout << "To select the product please enter the below botton\n";
	cout << "1 for Candy :)" << endl;
	cout << "2 for Chips :)" << endl;
	cout << "3 for gum :)" << endl;
	cout << "4 for cookies :)" << endl;
	cout << "5 for water " << endl;
}
void sellProduct(dispenserRegister& product, cashRegister& pCounter)
{
	int amount1 = 0; //variable the hold the amount enterd
	int amount2 = 0; //variable to hold the extra money needed
	if (product.getNoOfItems() > 0)
	{
		cout << "Please deposit " << product.getCost() << " $" << endl;
		cin >> amount1;
		if (amount1 < product.getCost())
		{
			cout << "Please deposit extra  " << product.getCost() - amount1 << " $" << endl;
			cin >> amount2;
			amount1 += amount2;
		}
		if (amount1 >= product.getCost())
		{
			pCounter.acceptAmount(amount1);
			product.makeSale();
			cout << "Collect your item at the bottom and enjoy !!" << endl;

		}
		else
		{
			cout << "The amount is not enough please collect your money back " << endl;
			cout << "***************************************************" << endl;
		}
	}
	else
	{
		cout << "Sorry this product is sole out !!!" << endl;
	}

}
int main()
{
	cashRegister cash(500);
	dispenserRegister coke(3, 10);
	dispenserRegister water(4, 7);
	dispenserRegister cookies(5, 15);
	dispenserRegister chips(0, 5);
	dispenserRegister candy(1, 1);
	dispenserRegister gum(3, 2);
	int choice;
	showSelection();
	do {
		cin >> choice;
		cout << "Doing transaction ......" << endl;
		switch (choice)
		{
		case 1:
			sellProduct(candy, cash);
			break;
		case 2 :
			sellProduct(chips, cash);
			break;
		case 3 :
			sellProduct(gum, cash);
			break;
		case 4:
			sellProduct(cookies, cash);
			break;
		case 5 :
			sellProduct(water, cash);
			break;
		}
	} while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
	cout << "The current balance is " << cash.getCurrentBalance() << endl;
	cout << "The amount of coke left " << coke.getNoOfItems() << endl;
	cout << "The amount of water left " << water.getNoOfItems() << endl;
	cout << "The amount of cookies left " << cookies.getNoOfItems() << endl;
	cout << "The amount of chips left " << chips.getNoOfItems() << endl;
	cout << "The amount of candy left " << candy.getNoOfItems() << endl;
	cout << "The amount of gum left " << gum.getNoOfItems() << endl;
}
//void showSelection(dispenserRegister &temp)
//{
//	cout << "---------------------Welcome to Duong's vending machine------------------------\n ";
//	cout << "THE MACHINE SELL THE BELOW " << endl;
//	cout << "Water(0) Coke(1) Chips(2) Cookies(3) " << endl;
//	cout << "The the procduct by pressing the corresponding number " << endl;
//	cout << "Please choose the product: ";
//	int product = 0;
//	cin >> product;
//	switch (product)
//	{
//	case water:
//		cout << "You choose water !" << endl;
//			break;
//	case coke:
//		cout << "You choose coke !" << endl;
//		break;
//	case chips:
//		cout << "You choose chip !" << endl;
//		break;
//	case cookies:
//		cout << "You choose cookies !" << endl;
//		break;
//	}
//	cout << "Please enter number of the that items you want to buy : " << endl;
//	int number = 0;
//	cin >> number;
//	cout << "please enter the price :";
//	int price = 0;
//	cin >> price;
//	tem
//}
//void sellProduct(cashRegister& a, dispenserRegister& b)
//{
//	int num = b.getNoOfItems();
//	for (int i = 0; i < num; i++)
//	{
//		a.acceptAmount(b.getCost());
//		b.makeSale();
//		cout << "Successsfully transcation" << endl;
//		cout << "the current balance is : " << endl;
//		cout << a.getCurrentBalance() << endl;
//		cout << "The current item is : " << endl;
//		cout << b.getNoOfItems() << endl;
//	}
//	
//}
//int main()
//{
//	int cash_ = 0;
//	cout << "Please enter the cash you have : ";
//	cin >> cash_;
//	cashRegister cash(cash_);
//	dispenserRegister dispense;
//	showSelection(dispense);
//	sellProduct(cash, dispense);
//	return 0;
//}
