// NAME         :	YILMAZ ALPEREN
// STUDENT NO   :	1306190030
/* DESCRIPTION  :


**********************************************************************************************************************
									*S H O P - L I S T - P L A N N E R*
								   /			|			|		  \
								  /				|			|		   \
								 /				|			|		    \
								/				|			|			 \
							   /				|			|			  \
			1-)	CREATE A NEW SHOPPING LIST      |           |    4-)  EDIT A SHOPPING LIST*
												|			|
												|			|
	 2-) SHOW SHOPPING LISTS   <----------------|			|-------------------> 3-) DELETE SHOPPING LIST


************************************************************************************************************************

************************************************************************************************************************

										*EDIT A SHOPPING LIST
					(First you have to choose which list(as a number) do you want to edit)
									   /       |    |         \                 \
									  /		   |	|		   \                 \
									 /         |    |           \                 \---------> 5-) Undo product that deleted
									/          |    |            \
						1-)	add new product	   |	|		4-) edit product for its name
											   |    |
			   2-)	delete product <-----------|    |-------------> 3-)edit product for its amount
				   becasue already
				   taken.
************************************************************************************************************************
-------------------------------------------------------------------------------------------------------------------------
										U S E R - G U I D E
	(First when you execute this program,you have to choose a number which operation you want.)
----> 1-)Create a new shopping list (When you enter 1 ) :
		-First,you have to write "title" of product as a *string* .
		-Then, you have to enter amount of this product as a *integer*
		-So if you want to add new products in "this list" enter 1 and you will do again above these 2 instructions.
		-If not want to add new products in this list then you have to enter 2 and you will be in main menu.

----> 2-)Show shopping list (When you enter 2) :
		-All shopping list that you created will be on the console.

----> 3-)Delete shopping list (when you enter 3 )  :
		-All shopping list that you created will be on the console and it will question you
	"Which Shopping List(as a number) do you want to delete ? " so you have to enter as a *number*
	which shopping list you want to delete. FOR EXAMPLE.
	Let's assume that you create 3 shopping list then "in main" menu you enter 3
	***********************************
	LIST 1
	1-) Orange    12
	***********************************

	***********************************
	LIST 2
	1-) Apple   10
	***********************************

	***********************************
	LIST 3
	1-)Milk   2
	***********************************

	And let's suppose that you want to delete first list ...
	So after this question "Which Shopping List(as a number) do you want to delete ? ", you have to
	enter 1.

----> 4-) Edit a shopping list (when you enter 4 ) :
		-All shopping list that you created will be on the console and it will question you
	"Which Shopping List (as a number ) do you want to edit ? " so you have to enter as a *number* which shopping list
	do you want to edit. FOR EXAMPLE
	Let's assume that you created 3 shopping list then in main menu you enter 4
	***********************************
	LIST 1
	1-) Orange    12
	***********************************

	***********************************
	LIST 2
	1-) Apple   10
	2-) Lemon   4
	***********************************

	***********************************
	LIST 3
	1-)Milk   2
	***********************************
	And let's suppose that you want to edit second list..
	So after this question "Which Shopping List (as a number ) do you want to edit ? " you have to enter 2 .

	For second list that you choose , you can operation 5 things

	These 5 things...............

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	1. Add new product (when you enter 1)  :
		-You have to enter title of product as a *string*
		-Then you have to enter amount of product as a *number*
		-So if you want to add new products in "this list" enter 1 and you will do again above these 2 instructions.
		-If not want to add new products in this list then you have to enter 2 and you will be in main menu.

	2. Delete product because already taken (when you enter 2 )  :
		-Shopping list that you choose for edit, will on the console and....
		***********************************
		LIST 2
		1-) Apple   10
		2-) Lemon   4
		***********************************
		It ask "Please enter a *number* which product you want to delete" and let's suppose that you want to delete
		second product... So you have to enter 2
		After this ......
		-If you want to continue delete in this list enter 1
		-If not want to continue delete in this list enter 2 and you will be in main menu

	3. Edit product for its amount (when you enter 3) :
		-Shopping list that you choose for edit, will on the console and....
		***********************************
		LIST 2
		1-) Apple   10
		2-) Lemon   4
		***********************************
		It ask "Please enter a *number* which product you want to edit its amount " and let's suppose that you want
		to edit first product... So you have to enter 1
		After this you have to enter new amount as a *integer*.
		Then.....
		-If you want to continue edit another product's amount in this list enter 1
		-If not want to continue in this list enter 2 and you will be in main menu

	4. Edit product for its name (when you enter 4)
		-Shopping list that you choose for edit, will on the console and...
		***********************************
		LIST 2
		1-) Apple   10
		2-) Lemon   4
		***********************************
		It ask "Please enter a *string* which product you want to edit its name " and let's suppose that you want
		to edit first product... So you have to enter 1
		After this you have to enter new name as a *string*.
		Then.....
		-If you want to continue edit another product's name in this list enter 1
		-If not want to continue in this list enter 2 and you will be in main menu

	5. Undo product that deleted (when you enter 5 ) :
		-Let's assume that after delete one product (it can be Lemon) , your Shoppling list appear like this...
		***********************************
		LIST 2
		1-) Apple   10
		----------------------------------
			D E L E T E D - P R O D U C T
		1-) Lemon   4

		***********************************
		It ask "Please enter a *number* which "deleted" product you want to undo and let's suppose that you want to undo Lemon
		So..... you have to enter 1
		Then.....
		-If you want to continue undo deleted product in this list enter 1
		-If not want to continue in this list , enter 2 and you will be in main menu


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


----> 9-) quit this apps (when you enter 9)
	-You close this apps.

--------------------------------------------------------------------------------------------------------------------------------

*/

//Development Enviroment : Microsoft Visual Studio 2019

#include <iostream>
#include <string>
#include <vector>


class Product {
private:
	std::string title;
	int amount;


public:
	bool beSeen = true;

	void setTitle(std::string title) {
		this->title = title;
	}
	//-----------------------------------------------------
	std::string getTitle() {
		return title;
	}
	//////////////////////////////////////////////////////////////////
	void setAmount(int amount) {
		this->amount = amount;

	}
	//------------------------------------------------------
	int getAmount() {
		return amount;
	}


};

std::vector <std::vector <Product> > shopList;


int interaction();
void detection(int keeper);
void createShopList();
bool checkerGoingOn();
void showShopingList();
void deleteShopingList();
void editSection();
void specificPrint(int number);
void scanForDelete(int whichList, int  whichProduct);
bool checkerGoingOnDelete();
void scanForEdit(int whichList, int whichAmount);
bool checkerGoingOnEdit();
void printAllOfProducts(int number);
bool checkerGoingOnUndo();
void recycleBin(int whichList, int whichProduct);
void scanforName(int whichListToEdit, int whichName);
bool checkerGoingOnName();


int main() {
	int keeper;
	std::cout << "				S H O P - L I S T - P L A N N E R " << std::endl;
	while (true) {

		keeper = interaction();
		if (keeper == 9) break;
		detection(keeper);

	}
	system("cls");
	std::cout << "Closing apps.............";
	return 0;
}

int interaction() {

	std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "1-create a new shoping list   2-show shoping lists   3-delete shoping list  4-edit a shoping list"
		<< std::endl << "9-quit this app " << std::endl;
	int keeper;
	std::cout << "Please enter \"number\" which operation you want : ";
	std::cin >> keeper;
	return keeper;
}
void detection(int keeper) {
	system("cls");
	if (keeper == 1) {
		createShopList();
	}
	else if (keeper == 2) {
		showShopingList();
	}
	else if (keeper == 3) {
		deleteShopingList();
	}
	else if (keeper == 4) {
		editSection();
	}

}
void createShopList() {

	std::vector <Product> tempVector;
	Product tempProduct;
	std::string tempString;
	int tempAmount;
	do {
		system("cls");
		std::cout << "Please enter title of product : ";
		std::cin.ignore(256, '\n');
		std::getline(std::cin, tempString);
		std::cout << "Please enter amount of product : ";
		std::cin >> tempAmount;
		tempProduct.setAmount(tempAmount);
		tempProduct.setTitle(tempString);
		tempVector.push_back(tempProduct);

	} while (checkerGoingOn());
	shopList.push_back(tempVector);
	system("cls");
}
bool checkerGoingOn() {		// continue for add items.
	system("cls");

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "1-Continue for adding new product in this list   	2-It's enough for this list" << std::endl;
	int keeper;
	std::cout << "Please enter \"number\"  which operation do you want : ";
	std::cin >> keeper;
	system("cls");
	if (keeper == 1)return true;
	else return false;

}
void showShopingList() {
	system("cls");
	std::cout << std::endl;
	int k;
	int price;

	for (int i = 1; i <= shopList.size(); ++i) {
		k = 1;
		price = 0;
		std::cout << "*****************************************************************" << std::endl;
		std::cout << "LIST  " << i << std::endl;
		for (int j = 1; j <= shopList[i - 1].size(); ++j) {
			if (shopList[i - 1][j - 1].beSeen) {
				price += shopList[i - 1][j - 1].getAmount();
				std::cout << k << "-)  " << shopList[i - 1][j - 1].getTitle();
				for (int b = shopList[i - 1][j - 1].getTitle().size(); b < 50; ++b) {
					std::cout << ' ';
				}
				std::cout << shopList[i - 1][j - 1].getAmount() << "     " << std::endl;
				k++;
			}
		}
		std::cout << "+" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "\t\t\t\t\t" << "total amount:  " << price << "     " << std::endl;
		std::cout << "*****************************************************************" << std::endl;
	}
}
void deleteShopingList() {
	system("cls");
	showShopingList();
	std::cout << std::endl << std::endl;
	std::cout << "Which Shopping List (as a number) do you want to delete : ";
	int wantToDelete;
	std::cin >> wantToDelete;
	shopList.erase(shopList.begin() + wantToDelete - 1);
	system("cls");

}
void editSection() {
	system("cls");
	showShopingList();
	std::cout << "Which Shopping List (as a number) do you want to edit : ";
	int whichListToEdit;
	std::cin >> whichListToEdit;
	system("cls");
	specificPrint(whichListToEdit);
	std::cout << "1-add new product    2-delete product because already taken    3-edit product for its amount    4-edit product for its name " << std::endl;
	std::cout << "5-undo product that deleted." << std::endl << std::endl;
	std::cout << "Please enter \"number\" which operation do you want : ";
	int numberOperation;
	std::cin >> numberOperation;
	std::string tempString;
	int tempAmount;
	Product tempProduct;
	if (numberOperation == 1) {
		do {
			system("cls");
			specificPrint(whichListToEdit);
			std::cout << "Please enter title of product :";
			std::cin.ignore(256, '\n');
			std::getline(std::cin, tempString);
			std::cout << "Please enter amount of product :";
			std::cin >> tempAmount;
			tempProduct.setAmount(tempAmount);
			tempProduct.setTitle(tempString);
			shopList[whichListToEdit - 1].push_back(tempProduct);


		} while (checkerGoingOn());
	}
	else if (numberOperation == 2) {
		do {
			system("cls");
			specificPrint(whichListToEdit);
			std::cout << "Please enter \"number\" which product do you want to delete : ";
			int whichProduct;
			std::cin >> whichProduct;
			scanForDelete(whichListToEdit, whichProduct);

		} while (checkerGoingOnDelete());
	}
	else if (numberOperation == 3) {
		do {
			system("cls");
			specificPrint(whichListToEdit);
			std::cout << "Please enter \"number\" which product do you want to edit its amount : ";
			int whichAmount;
			std::cin >> whichAmount;
			system("cls");
			specificPrint(whichListToEdit);
			scanForEdit(whichListToEdit, whichAmount);
		} while (checkerGoingOnEdit());
	}
	else  if (numberOperation == 5) {
		do {
			system("cls");
			printAllOfProducts(whichListToEdit);
			std::cout << "Please enter \"number\" which deleted product do you want to undo : ";
			int whichUndo;
			std::cin >> whichUndo;
			recycleBin(whichListToEdit, whichUndo);


		} while (checkerGoingOnUndo());
	}
	else if (numberOperation == 4) {
		do {
			system("cls");
			specificPrint(whichListToEdit);
			std::cout << "Please enter \"number\" which product do you want to edit its name : ";
			int whichName;
			std::cin >> whichName;
			system("cls");
			specificPrint(whichListToEdit);
			scanforName(whichListToEdit, whichName);
		} while (checkerGoingOnName());
	}


}
void specificPrint(int number) {
	int k = 1;
	int price = 0;
	std::cout << "*****************************************************************" << std::endl;
	std::cout << "LIST  " << number << std::endl;
	for (int i = 1; i <= shopList[number - 1].size(); ++i) {
		if (shopList[number - 1][i - 1].beSeen) {
			price += shopList[number - 1][i - 1].getAmount();
			std::cout << k << "-)  " << shopList[number - 1][i - 1].getTitle();
			for (int b = shopList[number - 1][i - 1].getTitle().size(); b < 50; ++b) {
				std::cout << ' ';
			}
			std::cout << shopList[number - 1][i - 1].getAmount() << "     " << std::endl;
			k++;
		}
	}
	std::cout << "+" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "\t\t\t\t\t" << "total amounts:  " << price << "     " << std::endl;
	std::cout << "*****************************************************************" << std::endl;

}

void scanForDelete(int whichList, int  whichProduct) {
	int k = 1;
	for (int j = 1; j <= shopList[whichList - 1].size(); ++j) {

		if (shopList[whichList - 1][j - 1].beSeen) {
			if (k == whichProduct) {
				shopList[whichList - 1][j - 1].beSeen = false;
				return;
			}
			else k++;
		}
	}
}
bool checkerGoingOnDelete() {		// continue for delete items.
	system("cls");

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "1-Continue for deleting  products in this list   	2-It's enough for this list" << std::endl;
	int keeper;
	std::cout << "Please enter \"number\"  which operation you want : ";
	std::cin >> keeper;
	system("cls");
	if (keeper == 1)return true;
	else return false;

}
void scanForEdit(int whichList, int whichAmount) {
	int amount = 0;
	int k = 1;
	for (int j = 1; j <= shopList[whichList - 1].size(); ++j) {
		if (shopList[whichList - 1][j - 1].beSeen) {
			if (k == whichAmount) {
				std::cout << "Please enter new amounts as a integer  : ";
				std::cin >> amount;
				shopList[whichList - 1][j - 1].setAmount(amount);
				return;
			}
			else k++;
		}
	}
}
bool checkerGoingOnEdit() {
	system("cls");

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "1-Continue for editing another product's amount in this list   	2-It's enough for this list" << std::endl;
	int keeper;
	std::cout << "Please enter \"number\"  which operation you want : ";
	std::cin >> keeper;
	system("cls");

	if (keeper == 1)return true;
	else return false;
}
void scanforName(int whichList, int whichName) {
	std::string newName;
	int k = 1;
	for (int j = 1; j <= shopList[whichList - 1].size(); ++j) {
		if (shopList[whichList - 1][j - 1].beSeen) {
			if (k == whichName) {
				std::cout << "Please enter new name as a string : ";
				std::cin.ignore(256, '\n');
				std::getline(std::cin, newName);
				shopList[whichList - 1][j - 1].setTitle(newName);
				return;
			}
			else k++;
		}
	}
}
bool checkerGoingOnName() {
	system("cls");

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "1-Continue for editing another product's name in this list   	2-It's enough for this list" << std::endl;
	int keeper;
	std::cout << "Please enter \"number\"  which operation you want : ";
	std::cin >> keeper;
	system("cls");

	if (keeper == 1)return true;
	else return false;

}
void printAllOfProducts(int number) {
	int tk = 1;
	int tprice = 0;
	int fk = 1;
	int fprice = 0;

	std::cout << "*****************************************************************" << std::endl;
	std::cout << "LIST  " << number << std::endl;
	for (int i = 1; i <= shopList[number - 1].size(); ++i) {
		if (shopList[number - 1][i - 1].beSeen) {
			tprice += shopList[number - 1][i - 1].getAmount();
			std::cout << tk << "-)  " << shopList[number - 1][i - 1].getTitle();
			for (int b = shopList[number - 1][i - 1].getTitle().size(); b < 50; ++b) {
				std::cout << ' ';
			}
			std::cout << shopList[number - 1][i - 1].getAmount() << "     " << std::endl;
			tk++;
		}
	}
	std::cout << "+" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "\t\t\t\t\t" << "total amounts:  " << tprice << "     " << std::endl;
	std::cout << "///////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "                   D E L E T E D -- P R O D U C T	 " << std::endl;
	for (int i = 1; i <= shopList[number - 1].size(); ++i) {
		if (!(shopList[number - 1][i - 1].beSeen)) {
			fprice += shopList[number - 1][i - 1].getAmount();
			std::cout << fk << "-)  " << shopList[number - 1][i - 1].getTitle();
			for (int b = shopList[number - 1][i - 1].getTitle().size(); b < 50; ++b) {
				std::cout << ' ';
			}
			std::cout << shopList[number - 1][i - 1].getAmount() << "     " << std::endl;
			fk++;

		}
	}

	std::cout << "*****************************************************************" << std::endl;

}
bool checkerGoingOnUndo() {
	system("cls");

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "1-Continue for undo another product that deleted   	2-It's enough for this list" << std::endl;
	int keeper;
	std::cout << "Please enter \"number\"  which operation you want : ";
	std::cin >> keeper;
	system("cls");

	if (keeper == 1)return true;
	else return false;
}
void recycleBin(int whichList, int whichProduct) {
	int k = 1;
	for (int i = 1; i <= shopList[whichList - 1].size(); ++i) {
		if (!shopList[whichList - 1][i - 1].beSeen) {
			if (k == whichProduct) {
				shopList[whichList - 1][i - 1].beSeen = true;
				return;
			}
			else k++;
		}
	}
}
