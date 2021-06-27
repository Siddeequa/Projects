// header files
#include <iostream>
using namespace std;

//Global variable
int no;

// Main Menu function
void mainMenu() {
	cout << "*** Main Menu ***" << endl;
	cout << "Enter " << endl;
	cout << "1 for Inventory Menu" << endl;
	cout << "2 for Transaction Menu" << endl;
	cout << "3 to Exit" << endl;
}

// Inventory Menu function
void inventoryMenu()
{
	cout << "*** Inventory Menu ***" << endl;
	cout << "Enter " << endl;
	cout << "1 to Add Book" << endl;
	cout << "2 to Display All Books" << endl;
	cout << "3 to Search for a Book" << endl;
	cout << "4 to Filter Book based on Category" << endl;
	cout << "5 to Update Book Information" << endl;
	cout << "6 to Sort Book based on available quantity" << endl;
	cout << "7 to Delete Book" << endl;
	cout << "8 to return to Main Menu" << endl;
}

// Transaction Menu function
void transactionMenu() {
	cout << "*** Transaction Menu ***" << endl;
	cout << "Enter " << endl;
	cout << "1 to Add Purchase" << endl;
	cout << "2 to View All Purchase Transactions" << endl;
	cout << "3 to Sort Purchase Transactions based on total price" << endl;
	cout << "4 to View List of Products from a particular purchase transaction" << endl;
	cout << "5 to return to Main Menu" << endl;
}

//Inventory singly linked list node structure
struct book {
	string bookName, bookCategory;
	int bookQuantity;
	float bookPrice;
	book* next;
};

struct book* headBook = NULL;

//Transaction singly linked list node structure
struct purchase {
	int purchaseID, bookPurchasedQuantity[15];
	string bookPurchasedName[15];
	float total;
	purchase* next;
};

struct purchase* headPurchase = NULL;

//function call
void updateBookInfo();

void addBook() {
	// creating new node for new book
	struct book* new_book = new book;

	cout << "Enter book name: " << endl;
	cin >> new_book->bookName;
	// flag to check								
	bool found = false;								
	//creating temporary pointer
	struct book* ptr;
	//pointing to 1st node
	ptr = headBook;										
	//checking if book exists
	while (ptr != NULL) {								
		if (ptr->bookName == new_book->bookName) {						
			cout << "Book already exists!" << endl;
			updateBookInfo();
			found = true;
			break;
		}
		else {
			//linked list traversal
			ptr = ptr->next;							
		}
	}
	if (found == false) {
		//book quantity validation
		do {
			cout << "Enter book quantity: " << endl;
			cin >> new_book->bookQuantity;
			if (new_book->bookQuantity < 1) {
				cout << "Invalid Quantity Entered!" << endl;
			}
		} while (new_book->bookQuantity < 1);
		cout << "Enter book category: " << endl;
		cin >> new_book->bookCategory;
		cout << "Enter book price: " << endl;
		cin >> new_book->bookPrice;
		cout << "Book Successfully Added!" << endl << endl;
	}
	new_book->next = headBook;
	//point head to the memory address of the new created node, inserting the node at the beginning
	headBook = new_book;
}

void displayAllBooks() {
	struct book* ptr;									
	ptr = headBook;										
	// checking if linked list is empty
	if (ptr == NULL) {									
		cout << "No Record Exists!" << endl;
	}
	//linked list traversal to the end
	while (ptr != NULL) {								

		cout << "Book Name: " << ptr->bookName << endl;
		cout << "Book Category: " << ptr->bookCategory << endl;
		cout << "Book Price: " << ptr->bookPrice << endl;
		cout << "Book Quantity: " << ptr->bookQuantity << endl << endl;
		ptr = ptr->next;								
	}
}

void searchBook() {
	string searchBookName;
	//Flag to check if book exists
	bool found = false;									

	cout << "Enter Book Name to search: ";
	cin >> searchBookName;
	// temporary pointer
	struct book* ptr;									
	ptr = headBook;										
	if (ptr == NULL) {									
		cout << "No Record Exists!" << endl;
	}

	while (ptr != NULL) {								
		if (ptr->bookName == searchBookName) {						

			cout << "Book Name: " << ptr->bookName << endl;
			cout << "Book Category: " << ptr->bookCategory << endl;
			cout << "Book Price: " << ptr->bookPrice << endl;
			cout << "Book Quantity: " << ptr->bookQuantity << endl << endl;
			found = true;
			break;
		}
		else {
			//linked list traversal
			ptr = ptr->next;							
		}
	}

	if (found == false) {
		cout << "Book does not Exist!" << endl;
	}
}

void filterBook() {
	string searchBookCategory;	
	//flag to check
	bool found = false;									

	cout << "Enter Book Category: ";
	cin >> searchBookCategory;
	// temporary pointer
	struct book* ptr;									
	ptr = headBook;									

	if (ptr == NULL) {								
		cout << "No Record Exists!" << endl;
	}

	while (ptr != NULL) {								
		if (ptr->bookCategory == searchBookCategory) {						

			cout << "Book Name: " << ptr->bookName << endl;
			cout << "Book Category: " << ptr->bookCategory << endl;
			cout << "Book Price: " << ptr->bookPrice << endl;
			cout << "Book Quantity: " << ptr->bookQuantity << endl << endl;
			found = true;
			//linked list traversal
			ptr = ptr->next;							
		}
		else {
			//linked list traversal
			ptr = ptr->next;							
		}
	}

	if (found == false) {
		cout << "No Book of this Category Exists!" << endl;
	}
}

void updateBookInfo() {
	string updateBookName;
	cout << "Enter Book Name needing Update: ";										
	cin >> updateBookName;
	// flag to check
	bool found = false;	
	// temporary pointer
	struct book* ptr;									
	ptr = headBook;										

	if (ptr == NULL) {									
		cout << "No Record Exists!" << endl;
	}

	while (ptr != NULL) {								
		if (ptr->bookName == updateBookName) {						

			cout << endl << "Current Book Name: " << ptr->bookName << endl;
			cout << "New Book Name: ";
			cin >> ptr->bookName;
			cout << "\nCurrent Book Category: " << ptr->bookCategory << endl;
			cout << "New Book Category: ";
			cin >> ptr->bookCategory;
			cout << "\nCurrent book price: " << ptr->bookPrice << endl;
			cout << "New book price: ";
			cin >> ptr->bookPrice;
			cout << "\nCurrent book quantity: " << ptr->bookQuantity << endl;
			cout << "New book quantity: ";
			cin >> ptr->bookQuantity;
			cout << "\nBook Info Updated Successfully!" << endl << endl;
			// set flag to true
			found = true;
			break;
		}
		else {
			//linked list traversal
			ptr = ptr->next;								
		}
	}

	if (found == false) {
		cout << "\nBook does not exist!" << endl;
	}
}

void sortBook() {
	// temporary pointer
	struct book* ptr;
	ptr = headBook;

	struct book* index;
	index = NULL;

	string a, b;
	float c;
	int d;

	if (ptr == NULL) {
		cout << "No Record Exists!" << endl;
	}

	while (ptr != NULL) {
		//Node index will point to node next to current
		index = ptr->next;
		while (index != NULL) {
			//If current node data is greater than index node data, swap data between them
			if (ptr->bookQuantity > index->bookQuantity) {

				a = ptr->bookName;
				ptr->bookName = index->bookName;
				index->bookName = a;


				b = ptr->bookCategory;
				ptr->bookCategory = index->bookCategory;
				index->bookCategory = b;

				c = ptr->bookPrice;
				ptr->bookPrice = index->bookPrice;
				index->bookPrice = c;

				d = ptr->bookQuantity;
				ptr->bookQuantity = index->bookQuantity;
				index->bookQuantity = d;
			}
			index = index->next;
		}
		ptr = ptr->next;
	}
	//pointing to head
	ptr = headBook;	
	//linked list traversal
	while (ptr != NULL) {
		cout << "Book Name: " << ptr->bookName << endl;
		cout << "Book Category: " << ptr->bookCategory << endl;
		cout << "Book Price: " << ptr->bookPrice << endl;
		cout << "Book Quantity: " << ptr->bookQuantity << endl << endl;
		ptr = ptr->next;							
	}
}

void deleteBook(string deleteBookName) {
	
	// flag to check
	bool found = false;
	// temporary pointer
	struct book* temp;
	struct book* ptr;
	ptr = headBook;

	if (ptr == NULL) {
		cout << "No Record Exists!" << endl;
	}
	// If node is first in list
	else if (ptr->bookName == deleteBookName) {
		temp = ptr;
		// points to next
		headBook = ptr->next;
		// freeing memory
		delete(temp);
		found = true;
		cout << "\nBook Record Successfully Deleted!" << endl;
	}
	else {
		// Check for book
		while (ptr->next != NULL && found == false) {
			// if book found
			if (ptr->next->bookName == deleteBookName) {
				temp = ptr->next;
				ptr->next = ptr->next->next;
				// freeing memory space
				delete(temp);
				found = true;
				cout << "\nBook Record Successfully Deleted!" << endl;
			}
			else {
				// linked list traversal
				ptr = ptr->next;
			}
		}
	}

	if (found == false) {
		cout << "\nBook does not exist!" << endl;
	}
}


void addPurchase() {
	
	// creating new node for new purchase
	struct purchase* new_purchase = new purchase;

	cout << "Enter Purchase ID: " << endl;
	cin >> new_purchase->purchaseID;
	
	//creating temporary pointer
	struct purchase* ptr;
	//pointing to 1st node
	ptr = headPurchase;
	//checking if book exists
	while (ptr != NULL) {
		if (ptr->purchaseID == new_purchase->purchaseID) {
			do {
				cout << "Duplicate ID" << endl;
				cout << "Enter a unique Purchase ID: " << endl;
				cin >> new_purchase->purchaseID;
			} while (ptr->purchaseID == new_purchase->purchaseID);
		}
		else {
			//linked list traversal
			ptr = ptr->next;
		}
	}
	cout << "Enter Number of Different Books Purchased: " << endl;
	cin >> no;
	for (int i = 0; i < no; i++) {
		cout << "Enter 1 Book Name: " << endl;
		cin >> new_purchase->bookPurchasedName[i];

		struct book* current;										
		current = headBook;
		//flag to check if book exists in inventory
		bool found = false;
		while (current != NULL) {	
			//searching for book in inventory
			if (current->bookName == new_purchase->bookPurchasedName[i]) {
				//validating if there are enough books in stock
				do {
					cout << "Enter Book Quantity: " << endl;
					cin >> new_purchase->bookPurchasedQuantity[i];
					if (new_purchase->bookPurchasedQuantity[i] > current->bookQuantity) {
						cout << "Only " << current->bookQuantity << " books are available!" << endl;
					}
				} while (new_purchase->bookPurchasedQuantity[i] > current->bookQuantity);
				cout << "Update Book Quantity in Inventory: " << endl;
				updateBookInfo();
				if (current->bookQuantity == 0) {
					deleteBook(current->bookName);
				}
				found = true;
				break;
			}
			else {
				//linked list traversal
				current = current->next;								
			}
		}
		if (found == false) {
			cout << "Book Out of Stock!" << endl;
		}
	}
	cout << "Enter Total Amount Paid: " << endl;
	cin >> new_purchase->total;
	cout << "Purchase Successfully Added!" << endl << endl;
	
	new_purchase->next = headPurchase;
	//point head to the memory address of the new created node, inserting the node at the beginning
	headPurchase = new_purchase;
}

void viewAllPurchases() {
	struct purchase* ptr;										
	ptr = headPurchase;											

	if (ptr == NULL) {										
		cout << "No Record Exists!";
	}

	while (ptr != NULL) {									

		cout << "Purchase ID: " << ptr->purchaseID << endl;
		for (int i = 0; i < no; i++) {
			cout << "Book Purchased Name: " << ptr->bookPurchasedName[i] << endl;
			cout << "Book Purchased Quantity: " << ptr->bookPurchasedQuantity[i] << endl;
		}
		cout << "Total Amount Paid: " << ptr->total << endl << endl;
		ptr = ptr->next;									
	}
}

void sortPurchase() {
	// temporary pointer
	struct purchase* ptr;
	ptr = headPurchase;

	struct purchase* index;
	index = NULL;

	string a[15];
	int b, c[15];
	float d;

	if (ptr == NULL) {
		cout << "No Record Exists!" << endl;
	}

	while (ptr != NULL) {
		//Node index will point to node next to current
		index = ptr->next;
		while (index != NULL) {
			//If current node data is greater than index node data, swap data between them
			if (ptr->total > index->total) {

				for (int i = 0; i < no; i++) {
					a[i] = ptr->bookPurchasedName[i];
					ptr->bookPurchasedName[i] = index->bookPurchasedName[i];
					index->bookPurchasedName[i] = a[i];

					c[i] = ptr->bookPurchasedQuantity[i];
					ptr->bookPurchasedQuantity[i] = index->bookPurchasedQuantity[i];
					index->bookPurchasedQuantity[i] = c[i];
				}

				b = ptr->purchaseID;
				ptr->purchaseID = index->purchaseID;
				index->purchaseID = b;


				d = ptr->total;
				ptr->total = index->total;
				index->total = d;
			}
			index = index->next;
		}
		ptr = ptr->next;
	}
	//pointing to head
	ptr = headPurchase;
	//linked list traversal
	while (ptr != NULL) {
		cout << "Purchase ID: " << ptr->purchaseID << endl;
		for (int i = 0; i < no; i++) {
			cout << "Book Purchased Name: " << ptr->bookPurchasedName[i] << endl;
			cout << "Book Purchased Quantity: " << ptr->bookPurchasedQuantity[i] << endl;
		}
		cout << "Total Amount Paid: " << ptr->total << endl << endl;
		ptr = ptr->next;
	}
}

void searchPurchase() {
	int searchPurchaseID;
	//Flag to check if book exists
	bool found = false;

	cout << "Enter Purchase ID to search: ";
	cin >> searchPurchaseID;
	// temporary pointer
	struct purchase* ptr;
	ptr = headPurchase;
	if (ptr == NULL) {
		cout << "No Record Exists!" << endl;
	}

	while (ptr != NULL) {
		if (ptr->purchaseID == searchPurchaseID) {

			cout << "Purchase ID: " << ptr->purchaseID << endl;
			for (int i = 0; i < no; i++) {
				cout << "Book Purchased Name: " << ptr->bookPurchasedName[i] << endl;
				cout << "Book Purchased Quantity: " << ptr->bookPurchasedQuantity[i] << endl;
			}
			cout << "Total Amount Paid: " << ptr->total << endl << endl;
			found = true;
			break;
		}
		else {
			//linked list traversal
			ptr = ptr->next;
		}
	}

	if (found == false) {
		cout << "Purchase ID does not Exist!" << endl;
	}
}

int main() {
	int choice, ch1, ch2;
	string deleteBookName;
	mainMenu();
	cin >> choice;
	while (choice != 3) {
		switch (choice)
		{
		case 1:
			inventoryMenu();
			cin >> ch1;
			while (ch1 != 8) {
				switch (ch1)
				{
				case 1:
					addBook();
					break;
				case 2:
					displayAllBooks();
					break;
				case 3:
					searchBook();
					break;
				case 4:
					filterBook();
					break;
				case 5:
					updateBookInfo();
					break;
				case 6:
					sortBook();
					break;
				case 7:
					cout << "Enter Book Name to delete: ";
					cin >> deleteBookName;
					deleteBook(deleteBookName);
					break;
				default:
					cout << "Invalid option!" << endl;
				}
				inventoryMenu();
				cin >> ch1;
			}
			break;
		case 2:
			transactionMenu();
			cin >> ch2;
			while (ch2 != 5) {
				switch (ch2)
				{
				case 1:
					addPurchase();
					break;
				case 2:
					viewAllPurchases();
					break;
				case 3:
					sortPurchase();
					break;
				case 4:
					searchPurchase();
					break;
				default:
					cout << "Invalid option!" << endl;
				}
				transactionMenu();
				cin >> ch2;
			}
			break;
		default:
			cout << "Invalid option!" << endl;
		}
		mainMenu();
		cin >> choice;
	}
}