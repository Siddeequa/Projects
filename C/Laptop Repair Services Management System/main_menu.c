#include <stdio.h>;
#include <string.h>;
#include <math.h>;

//Declaring variables
char name[20], date[15], phone_number[20], pword[20];;
int id, new_id, service_type, service_choice, option, new_service_type, new_service_choice;
float service_fee, payment_made, unpaid, new_service_fee, additional_payment, total_payment, sum_all_payments, sum_all_unpaid_balances, amount_to_be_returned, sum_all_amount_to_be_returned;

// Functions
void welcomeMessage();
void adminLogin();
void menu();
void services();
void newRecordVisit();
void updateVisit();
void updatePayment();
void searchVisit();
void viewSpecificPayment();
void viewAll_payment_unpaid_balance();
void all_records();
void cancel();

//Main function
int main(void)
{
	//Print welcome message
	welcomeMessage();
	//Ask for password
	adminLogin();
}

//List of all functions:


//Welcome message function
void welcomeMessage()
{
	printf("\n\n\n\t\t\t\t\tWelcome to our laptop repair shop system!\n\n");
}

//Admin login function
void adminLogin()
{
	//Declaring constant string value for password
	const char password[20] = "12LaptopRepair34";

	//Loop to re ask password if not correct
	do{
		printf("\nTo access the system, enter password: ");
		scanf("%s", &pword);

		if (strcmp(pword, password) == 0){
			//If password correct, proceed to menu function
			menu();
		}
		else{
			printf("\n\tIncorrect password!\n\n");
		}
	} while (strcmp(pword, password) != 0);
}

//Menu function
void menu()
{
	//Start loop
	do{
		//Display available options
		printf("\n\n****************************************************** MENU ******************************************************\n\n");
		printf("-----                  To display services                                         Press[1]                  -----\n");
		printf("-----                  To record a visit                                           Press[2]                  -----\n");
		printf("-----                  To update existing visit                                    Press[3]                  -----\n");
		printf("-----                  To update payment made                                      Press[4]                  -----\n");
		printf("-----                  To search for a recorded visit                              Press[5]                  -----\n");
		printf("-----                  To view specific payment and unpaid balance                 Press[6]                  -----\n");
		printf("-----                  To view total payments and unpaid balances                  Press[7]                  -----\n");
		printf("-----                  To view all records                                         Press[8]                  -----\n");
		printf("-----                  For cancellation                                            Press[9]                  -----\n");
		printf("-----                  To exit                                                     Press[0]                  -----\n");

		//read option
		scanf("%d", &option);

		switch (option){
		case 1:
			services();
			break;

		case 2:
			newRecordVisit();
			break;

		case 3:
			updateVisit();
			break;

		case 4:
			updatePayment();
			break;

		case 5:
			searchVisit();
			break;

		case 6:
			viewSpecificPayment();
			break;

		case 7:
			viewAll_payment_unpaid_balance();
			break;

		case 8:
			all_records();
			break;

		case 9:
			cancel();
			break;

		case 0:
			exit(0);

		default:
			printf("Invalid option");
		}
	} while (option != 0);
}

//Services function
void services()
{
	// Display services provided
	printf("\n\n\n               SERVICE TYPE                               NEEDED DAYS                              SERVICE FEE   \n");
	printf("                                                                                               NORMAL      URGENT\n\n");
	printf("1. Remove virus, malware or spyware -------------------------- 2 ------------------------------ 30 RM ----- 50 RM \n");
	printf("2. Troubleshoot and fix computer running slow ---------------- 2 ------------------------------ 40 RM ----- 70 RM \n");
	printf("3. Laptop screen replacement --------------------------------- 3 ----------------------------- 380 RM ---- 430 RM \n");
	printf("4. Laptop keyboard replacement ------------------------------- 2 ----------------------------- 160 RM ---- 200 RM \n");
	printf("5. Laptop battery replacement -------------------------------- 1 ----------------------------- 180 RM ---- 210 RM \n");
	printf("6. Operating system format and installation ------------------ 2 ------------------------------ 50 RM ----- 80 RM \n");
	printf("7. Data backup and recovery ---------------------------------- 2 ----------------------------- 100 RM ---- 150 RM \n");
	printf("8. Internet connectivity issues ------------------------------ 1 ------------------------------ 50 RM ----- 75 RM \n");
}

//Record visit function
void newRecordVisit()
{
	//File pointer
	FILE* visits;

	//Opening file
	visits = fopen("visits.txt", "a");

	//Validate whether file can be opened
	if (!visits){
		printf("\nCould not create/open file\n");
		exit(0);
	}

	//Getting data
	printf("\nEnter visit ID: ");
	scanf("%d", &id);
	printf("\nEnter name: ");
	scanf("%s", &name);
	printf("\nEnter date: ");
	scanf("%s", &date);
	printf("\nEnter phone number: ");
	scanf("%s", &phone_number);

	//Loop to re print command if limits not respected
	do {
		//Display urgency options
		printf("\n\nFor normal service: Press [0]\nFor urgent service: Press [1]\n");
		scanf("%d", &service_type);
	} while (service_type < 0 || service_type > 1);

	//Loop to re print command if limits not respected
	do {
		//Display services options
		printf("\n\n\t\t\t\t\tEnter service choice:\n\n\t\t\tRemove virus, malware or spyware\t\tPress[1]\n\t\t\tTroubleshoot and fix computer running slow\tPress[2]\n\t\t\tLaptop screen replacement\t\t\tPress[3]\n\t\t\tLaptop keyboard replacement\t\t\tPress[4]\n\t\t\tLaptop battery replacement\t\t\tPress[5]\n\t\t\tOperating system format and installation\tPress[6]\n\t\t\tData backup and recovery\t\t\tPress[7]\n\t\t\tInternet connectivity issues\t\t\tPress[8]\n\n");
		scanf("%d", &service_choice);
	} while (service_choice < 1 || service_choice > 8);

	//switch options
	switch (service_choice){
	case 1:
		printf("\nRemove virus, malware or spyware");
		if (service_type == 0) {
			service_fee = 30;
		}
		else {
			service_fee = 50;
		}
		break;

	case 2:
		printf("\nTroubleshoot and fix computer running slow");
		if (service_type == 0) {
			service_fee = 40;
		}
		else {
			service_fee = 70;
		}
		break;

	case 3:
		printf("\nLaptop screen replacement");
		if (service_type == 0) {
			service_fee = 380;
		}
		else {
			service_fee = 430;
		}
		break;

	case 4:
		printf("\nLaptop keyboard replacement");
		if (service_type == 0) {
			service_fee = 160;
		}
		else {
			service_fee = 200;
		}
		break;

	case 5:
		printf("\nLaptop battery replacement");
		if (service_type == 0) {
			service_fee = 180;
		}
		else {
			service_fee = 210;
		}
		break;

	case 6:
		printf("\nOperating System Format and Installation");
		if (service_type == 0) {
			service_fee = 50;
		}
		else {
			service_fee = 80;
		}
		break;

	case 7:
		printf("\nData backup and recovery");
		if (service_type == 0) {
			service_fee = 100;
		}
		else {
			service_fee = 150;
		}
		break;

	case 8:
		printf("\nInternet connectivity issues");
		if (service_type == 0) {
			service_fee = 50;
		}
		else {
			service_fee = 75;
		}
		break;

	default:
		printf("\nInvalid choice");
	}

	//Display service fee on console
	printf("\nService fee: Rm %.2f", service_fee);

	//Payment made
	printf("\nEnter payment made: ");
	scanf("%f", &payment_made);

	//Calculate unpaid balance
	unpaid = service_fee - payment_made;

	if (unpaid < 0){
		amount_to_be_returned = fabs(unpaid);
	}
	else{
		amount_to_be_returned = 0;
	}

	//Display payment details
	printf("\nUnpaid balance: Rm %.2f", unpaid);
	printf("\nAmount to be returned: Rm %.2f", amount_to_be_returned);

	//Write data into file
	fprintf(visits, "Visit ID: ");
	fprintf(visits, "%d\n", id);
	fprintf(visits, "Name: ");
	fprintf(visits, "%s\n", name);
	fprintf(visits, "Date: ");
	fprintf(visits, "%s\n", date);
	fprintf(visits, "Phone number: ");
	fprintf(visits, "%s\n", phone_number);
	fprintf(visits, "Service type: ");
	fprintf(visits, "%d\n", service_type);
	fprintf(visits, "Service choice: ");
	fprintf(visits, "%d\n", service_choice);
	fprintf(visits, "Service fee: Rm ");
	fprintf(visits, "%.2f\n", service_fee);
	fprintf(visits, "Payment made: Rm ");
	fprintf(visits, "%.2f\n", payment_made);
	fprintf(visits, "Unpaid balance: Rm ");
	fprintf(visits, "%.2f\n", unpaid);
	fprintf(visits, "Amount to be returned: Rm ");
	fprintf(visits, "%.2f\n", amount_to_be_returned);
	fprintf(visits, ".....................................\n");

	//Close file
	fclose(visits);
}

//Update visit function
void updateVisit()
{
	//File pointers
	FILE* visits;
	FILE* updateVisits;

	//Open existing visits file
	visits = fopen("visits.txt", "r");

	//Validate if file can be opened
	if (!visits){
		printf("\nCould not create/open file\n");
		exit(0);
	}

	//Open temporary file
	updateVisits = fopen("updateVisits.txt", "w");

	//Validate whether file can be opened
	if (!updateVisits){
		printf("\nCould not create/open temporary file\n");
		exit(0);
	}

	//Get value of ID needing service update
	printf("\n\nEnter visit ID for service update: ");
	scanf("%d", &new_id);

	//Read data from existing visit file
	while (fscanf(visits, "%d\n", &id) != EOF) {
		fscanf(visits, "Visit ID: ");
		fscanf(visits, "%d\n", &id);
		fscanf(visits, "Name: ");
		fscanf(visits, "%s\n", &name);
		fscanf(visits, "Date: ");
		fscanf(visits, "%s\n", &date);
		fscanf(visits, "Phone number: ");
		fscanf(visits, "%s\n", &phone_number);
		fscanf(visits, "Service type: ");
		fscanf(visits, "%d\n", &service_type);
		fscanf(visits, "Service choice: ");
		fscanf(visits, "%d\n", &service_choice);
		fscanf(visits, "Service fee: Rm ");
		fscanf(visits, "%f\n", &service_fee);
		fscanf(visits, "Payment made: Rm ");
		fscanf(visits, "%f\n", &payment_made);
		fscanf(visits, "Unpaid balance: Rm ");
		fscanf(visits, "%f\n", &unpaid);
		fscanf(visits, "Amount to be returned: Rm ");
		fscanf(visits, "%f\n", &amount_to_be_returned);
		fscanf(visits, ".....................................\n");

		//Check whether ID entered for update matches any existing ID
		if (new_id == id) {
			//Loop to re print command if limits not respected
			do {
				//Display urgency options
				printf("\n\nFor normal service: Press [0]\nFor urgent service: Press [1]\n");
				scanf("%d", &new_service_type);
			} while (new_service_type < 0 || new_service_type > 1);

			//Loop to re print command if limits not respected
			do {
				//Display services options
				printf("\n\n\t\t\t\t\tEnter service choice:\n\n\t\t\tRemove virus, malware or spyware\t\tPress[1]\n\t\t\tTroubleshoot and fix computer running slow\tPress[2]\n\t\t\tLaptop screen replacement\t\t\tPress[3]\n\t\t\tLaptop keyboard replacement\t\t\tPress[4]\n\t\t\tLaptop battery replacement\t\t\tPress[5]\n\t\t\tOperating system format and installation\tPress[6]\n\t\t\tData backup and recovery\t\t\tPress[7]\n\t\t\tInternet connectivity issues\t\t\tPress[8]\n\n");
				scanf("%d", &new_service_choice);
			} while (new_service_choice < 1 || new_service_choice > 8);

			//switch options
			switch (new_service_choice) {
			case 1:
				printf("\nRemove virus, malware or spyware");
				if (new_service_type == 0) {
					new_service_fee = 30;
				}
				else {
					new_service_fee = 50;
				}
				break;

			case 2:
				printf("\nTroubleshoot and fix computer running slow");
				if (new_service_type == 0) {
					new_service_fee = 40;
				}
				else {
					new_service_fee = 70;
				}
				break;

			case 3:
				printf("\nLaptop screen replacement");
				if (new_service_type == 0) {
					new_service_fee = 380;
				}
				else {
					new_service_fee = 430;
				}
				break;

			case 4:
				printf("\nLaptop keyboard replacement");
				if (new_service_type == 0) {
					new_service_fee = 160;
				}
				else {
					new_service_fee = 200;
				}
				break;

			case 5:
				printf("\nLaptop battery replacement");
				if (new_service_type == 0) {
					new_service_fee = 180;
				}
				else {
					new_service_fee = 210;
				}
				break;

			case 6:
				printf("\nOperating System Format and Installation");
				if (new_service_type == 0) {
					new_service_fee = 50;
				}
				else {
					new_service_fee = 80;
				}
				break;

			case 7:
				printf("\nData backup and recovery");
				if (new_service_type == 0) {
					new_service_fee = 100;
				}
				else {
					new_service_fee = 150;
				}
				break;

			case 8:
				printf("\nInternet connectivity issues");
				if (new_service_type == 0) {
					new_service_fee = 50;
				}
				else {
					new_service_fee = 75;
				}
				break;

			default:
				printf("\nInvalid choice");
			}

			service_type = new_service_type;
			service_choice = new_service_choice;
			service_fee = new_service_fee;
			unpaid = service_fee - payment_made;

			if (unpaid < 0) {
				amount_to_be_returned = fabs(unpaid);
			}
			else {
				amount_to_be_returned = 0;
			}
		}

		//Write data into temporary file
		fprintf(updateVisits, "Visit ID: ");
		fprintf(updateVisits, "%d\n", id);
		fprintf(updateVisits, "Name: ");
		fprintf(updateVisits, "%s\n", name);
		fprintf(updateVisits, "Date: ");
		fprintf(updateVisits, "%s\n", date);
		fprintf(updateVisits, "Phone number: ");
		fprintf(updateVisits, "%s\n", phone_number);
		fprintf(updateVisits, "Service type: ");
		fprintf(updateVisits, "%d\n", service_type);
		fprintf(updateVisits, "Service choice: ");
		fprintf(updateVisits, "%d\n", service_choice);
		fprintf(updateVisits, "Service fee: Rm ");
		fprintf(updateVisits, "%.2f\n", service_fee);
		fprintf(updateVisits, "Payment made: Rm ");
		fprintf(updateVisits, "%.2f\n", payment_made);
		fprintf(updateVisits, "Unpaid balance: Rm ");
		fprintf(updateVisits, "%.2f\n", unpaid);
		fprintf(updateVisits, "Amount to be returned: Rm ");
		fprintf(updateVisits, "%.2f\n", amount_to_be_returned);
		fprintf(updateVisits, ".....................................\n");

		if (id == new_id) {
			//Display service fee on console
			printf("\nService fee:Rm %.2f", service_fee);
			printf("\nPayment made:Rm %.2f", payment_made);
			printf("\nUnpaid balance:Rm %.2f", unpaid);
			printf("\nAmount to be returned to customer:Rm %.2f", amount_to_be_returned);
		}
	}

	//Close files
	fclose(visits);
	fclose(updateVisits);

	//Remove original file
	remove("visits.txt");

	//Rename updated file after original file
	rename("updateVisits.txt", "visits.txt");

	//Display update successful message on console
	printf("\n\nUpdate done!\n\n");

}

//Update payment function
void updatePayment()
{
	//File pointers
	FILE* visits;
	FILE* payments;

	//Opening files
	visits = fopen("visits.txt", "r");
	payments = fopen("new_payments.txt", "w");

	//Validate if files can be opened
	if (!visits){
		printf("\nCould not open visits file\n");
		exit(0);
	}

	if (!payments){
		printf("\nCould not create/open new_payments file\n");
		exit(0);
	}

	//Get value of ID needing payment update
	printf("\n\nEnter visit ID for payment update: ");
	scanf("%d", &new_id);

	//Read data from existing visit file
	while (fscanf(visits, "%d\n", &id) != EOF){
		fscanf(visits, "Visit ID: ");
		fscanf(visits, "%d\n", &id);
		fscanf(visits, "Name: ");
		fscanf(visits, "%s\n", &name);
		fscanf(visits, "Date: ");
		fscanf(visits, "%s\n", &date);
		fscanf(visits, "Phone number: ");
		fscanf(visits, "%s\n", &phone_number);
		fscanf(visits, "Service type: ");
		fscanf(visits, "%d\n", &service_type);
		fscanf(visits, "Service choice: ");
		fscanf(visits, "%d\n", &service_choice);
		fscanf(visits, "Service fee: Rm ");
		fscanf(visits, "%f\n", &service_fee);
		fscanf(visits, "Payment made: Rm ");
		fscanf(visits, "%f\n", &payment_made);
		fscanf(visits, "Unpaid balance: Rm ");
		fscanf(visits, "%f\n", &unpaid);
		fscanf(visits, "Amount to be returned: Rm ");
		fscanf(visits, "%f\n", &amount_to_be_returned);
		fscanf(visits, ".....................................\n");

		//Check whether ID entered for update matches any existing ID
		if (new_id == id){
			//Ask for new payment
			printf("Enter additional payment made: ");
			scanf("%f", &additional_payment);

			//New values of payment made and unpaid balance
			total_payment = payment_made + additional_payment;
			unpaid = service_fee - total_payment;
			payment_made = total_payment;

			if (unpaid < 0){
				amount_to_be_returned = fabs(unpaid);
			}
			else{
				amount_to_be_returned = 0;
			}

			//Display payment details on console
			printf("\nPayment made:Rm %.2f", payment_made);
			printf("\nUnpaid balance:Rm %.2f", unpaid);
			printf("\nAmount to be returned:Rm %.2f", amount_to_be_returned);
		}

		//Write data into temporary file
		fprintf(payments, "Visit ID: ");
		fprintf(payments, "%d\n", id);
		fprintf(payments, "Name: ");
		fprintf(payments, "%s\n", name);
		fprintf(payments, "Date: ");
		fprintf(payments, "%s\n", date);
		fprintf(payments, "Phone number: ");
		fprintf(payments, "%s\n", phone_number);
		fprintf(payments, "Service type: ");
		fprintf(payments, "%d\n", service_type);
		fprintf(payments, "Service choice: ");
		fprintf(payments, "%d\n", service_choice);
		fprintf(payments, "Service fee: Rm ");
		fprintf(payments, "%.2f\n", service_fee);
		fprintf(payments, "Payment made: Rm ");
		fprintf(payments, "%.2f\n", payment_made);
		fprintf(payments, "Unpaid balance: Rm ");
		fprintf(payments, "%.2f\n", unpaid);
		fprintf(payments, "Amount to be returned: Rm ");
		fprintf(payments, "%.2f\n", amount_to_be_returned);
		fprintf(payments, ".....................................\n");
	}

	//Close files
	fclose(visits);
	fclose(payments);

	//Remove original file
	remove("visits.txt");

	//Rename new file after original file
	rename("new_payments.txt", "visits.txt");

	//Display update successful message on console
	printf("\n\nUpdate done!\n\n");
}

//Search function
void searchVisit()
{
	//File pointer
	FILE* visits;

	//Open file
	visits = fopen("visits.txt", "r");

	//Validate if files can be opened
	if (!visits){
		printf("\nCould not open visits file\n");
		exit(0);
	}

	//Get value of ID to search
	printf("\n\nEnter visit ID to search: ");
	scanf("%d", &new_id);

	//Read data from visits file
	while (fscanf(visits, "%d\n", &id) != EOF){
		fscanf(visits, "Visit ID: ");
		fscanf(visits, "%d\n", &id);
		fscanf(visits, "Name: ");
		fscanf(visits, "%s\n", &name);
		fscanf(visits, "Date: ");
		fscanf(visits, "%s\n", &date);
		fscanf(visits, "Phone number: ");
		fscanf(visits, "%s\n", &phone_number);
		fscanf(visits, "Service type: ");
		fscanf(visits, "%d\n", &service_type);
		fscanf(visits, "Service choice: ");
		fscanf(visits, "%d\n", &service_choice);
		fscanf(visits, "Service fee: Rm ");
		fscanf(visits, "%f\n", &service_fee);
		fscanf(visits, "Payment made: Rm ");
		fscanf(visits, "%f\n", &payment_made);
		fscanf(visits, "Unpaid balance: Rm ");
		fscanf(visits, "%f\n", &unpaid);
		fscanf(visits, "Amount to be returned: Rm ");
		fscanf(visits, "%f\n", &amount_to_be_returned);
		fscanf(visits, ".....................................\n");

		//Check whether ID entered for update matches any existing ID
		if (id == new_id){
			printf("\n\nVisit ID: %d", id);
			printf("\n\nCustomer name: %s", name);
			printf("\n\nVisit date: %s", date);
			printf("\n\nPhone number: %s", phone_number);
			printf("\n\nService type: %d", service_type);
			printf("\n\nService choice: %d", service_choice);
			printf("\n\nService fee: Rm %.2f", service_fee);
			printf("\n\nPayment made: Rm %.2f", payment_made);
			printf("\n\nUnpaid balance: Rm %.2f", unpaid);
			printf("\n\nAmount to be returned to customer: Rm %.2f", amount_to_be_returned);
		}
	}

	//Close file
	fclose(visits);
}

//View specific payment details function
void viewSpecificPayment()
{
	//File pointer
	FILE* visits;

	//Open file
	visits = fopen("visits.txt", "r");

	//Validate if files can be opened
	if (!visits){
		printf("\nCould not open visits file\n");
		exit(0);
	}

	//Get value of ID to search for payment
	printf("\n\nEnter visit ID to search: ");
	scanf("%d", &new_id);

	//Read data from visits file
	while (fscanf(visits, "%d\n", &id) != EOF){
		fscanf(visits, "Visit ID: ");
		fscanf(visits, "%d\n", &id);
		fscanf(visits, "Name: ");
		fscanf(visits, "%s\n", &name);
		fscanf(visits, "Date: ");
		fscanf(visits, "%s\n", &date);
		fscanf(visits, "Phone number: ");
		fscanf(visits, "%s\n", &phone_number);
		fscanf(visits, "Service type: ");
		fscanf(visits, "%d\n", &service_type);
		fscanf(visits, "Service choice: ");
		fscanf(visits, "%d\n", &service_choice);
		fscanf(visits, "Service fee: Rm ");
		fscanf(visits, "%f\n", &service_fee);
		fscanf(visits, "Payment made: Rm ");
		fscanf(visits, "%f\n", &payment_made);
		fscanf(visits, "Unpaid balance: Rm ");
		fscanf(visits, "%f\n", &unpaid);
		fscanf(visits, "Amount to be returned: Rm ");
		fscanf(visits, "%f\n", &amount_to_be_returned);
		fscanf(visits, ".....................................\n");

		//Check whether ID entered for update matches any existing ID
		if (id == new_id){
			printf("\n\nVisit ID: %d", id);
			printf("\n\nCustomer name: %s", name);
			printf("\n\nVisit date: %s", date);
			printf("\n\nPayment made: Rm %.2f", payment_made);
			printf("\n\nUnpaid balance: Rm %.2f", unpaid);
			printf("\n\nAmount to be returned: Rm %.2f", amount_to_be_returned);
		}
	}

	//Close file
	fclose(visits);
}

//View total payments, unpaid balances and amount owed to customers functions
void viewAll_payment_unpaid_balance()
{
	//File pointer
	FILE* visits;

	//Open file
	visits = fopen("visits.txt", "r");

	//Validate if file can be opened
	if (!visits){
		printf("\nCould not open visits file\n");
		exit(0);
	}

	//Initialise value of sums
	sum_all_payments = 0;
	sum_all_unpaid_balances = 0;
	sum_all_amount_to_be_returned = 0;

	//Read data from visits file
	while (fscanf(visits, "%d\n", &id) != EOF){
		fscanf(visits, "Visit ID: ");
		fscanf(visits, "%d\n", &id);
		fscanf(visits, "Name: ");
		fscanf(visits, "%s\n", &name);
		fscanf(visits, "Date: ");
		fscanf(visits, "%s\n", &date);
		fscanf(visits, "Phone number: ");
		fscanf(visits, "%s\n", &phone_number);
		fscanf(visits, "Service type: ");
		fscanf(visits, "%d\n", &service_type);
		fscanf(visits, "Service choice: ");
		fscanf(visits, "%d\n", &service_choice);
		fscanf(visits, "Service fee: Rm ");
		fscanf(visits, "%f\n", &service_fee);
		fscanf(visits, "Payment made: Rm ");
		fscanf(visits, "%f\n", &payment_made);
		fscanf(visits, "Unpaid balance: Rm ");
		fscanf(visits, "%f\n", &unpaid);
		fscanf(visits, "Amount to be returned: Rm ");
		fscanf(visits, "%f\n", &amount_to_be_returned);
		fscanf(visits, ".....................................\n");

		sum_all_payments = sum_all_payments + payment_made;
		sum_all_unpaid_balances = sum_all_unpaid_balances + unpaid;
		sum_all_amount_to_be_returned = sum_all_amount_to_be_returned + amount_to_be_returned;
	}

	//Display value of sums on console
	printf("\n\nTotal payments for all visits: Rm %.2f", sum_all_payments);
	printf("\n\nTotal amount owed by customers: Rm %.2f", sum_all_unpaid_balances);
	printf("\n\nTotal amount owed to customers: Rm %.2f", sum_all_amount_to_be_returned);

	//Close file
	fclose(visits);
}

//View all records function
void all_records()
{
	//File pointer
	FILE* visits;

	//Open file
	visits = fopen("visits.txt", "r");

	//Validate if file can be opened
	if (!visits) {
		printf("\nCould not open visits file\n");
		exit(0);
	}

	//Print on console
	printf("\nVisit ID");
	printf("\tName");
	printf("\t\tDate");
	printf("\t\tPhone number");
	printf("\t\tType");
	printf("\tService");
	printf("\t\tFee(Rm)");
	printf("\t\tPaid(Rm)");
	printf("\t\tUnpaid(Rm)");
	printf("\tAmount to be returned(Rm)");
	printf("\n__________________________________________________________________________________________________________________________________________________________________________");

	//Read data from visits file
	while (fscanf(visits, "%d\n", &id) != EOF) {
		fscanf(visits, "Visit ID: ");
		fscanf(visits, "%d\n", &id);
		fscanf(visits, "Name: ");
		fscanf(visits, "%s\n", &name);
		fscanf(visits, "Date: ");
		fscanf(visits, "%s\n", &date);
		fscanf(visits, "Phone number: ");
		fscanf(visits, "%s\n", &phone_number);
		fscanf(visits, "Service type: ");
		fscanf(visits, "%d\n", &service_type);
		fscanf(visits, "Service choice: ");
		fscanf(visits, "%d\n", &service_choice);
		fscanf(visits, "Service fee: Rm ");
		fscanf(visits, "%f\n", &service_fee);
		fscanf(visits, "Payment made: Rm ");
		fscanf(visits, "%f\n", &payment_made);
		fscanf(visits, "Unpaid balance: Rm ");
		fscanf(visits, "%f\n", &unpaid);
		fscanf(visits, "Amount to be returned: Rm ");
		fscanf(visits, "%f\n", &amount_to_be_returned);
		fscanf(visits, ".....................................\n");

		//Print data on console
		printf("\n\n  %d", id);
		printf("\t\t%s", name);

		//To align data
		for (int i = 0; i < 15 - strlen(name); i++)
		{
			printf(" ");
		}
		//Continue printing aligned data
		printf("%s", date);
		printf("\t %s", phone_number);
		printf("\t\t %d", service_type);
		printf("\t  %d", service_choice);
		printf("\t\t%.2f", service_fee);
		printf("\t\t%.2f", payment_made);
		printf("\t          %.2f", unpaid);
		printf("\t                 %.2f\n\n", amount_to_be_returned);
	}

	//Close file
	fclose(visits);
}

//Cancel function
void cancel()
{
	//File pointers
	FILE* visits;
	FILE* cancellation;

	//Open file
	visits = fopen("visits.txt", "r");
	cancellation = fopen("cancellation.txt", "w");

	//Validate if files can be opened
	if (!visits){
		printf("\nCould not open visits file\n");
		exit(0);
	}

	if (!cancellation){
		printf("\nCould not open cancellation file\n");
		exit(0);
	}

	//Get value of ID to cancel
	printf("\n\nEnter visit ID to cancel service: ");
	scanf("%d", &new_id);

	//Read data from visits file
	while (fscanf(visits, "%d\n", &id) != EOF){
		fscanf(visits, "Visit ID: ");
		fscanf(visits, "%d\n", &id);
		fscanf(visits, "Name: ");
		fscanf(visits, "%s\n", &name);
		fscanf(visits, "Date: ");
		fscanf(visits, "%s\n", &date);
		fscanf(visits, "Phone number: ");
		fscanf(visits, "%s\n", &phone_number);
		fscanf(visits, "Service type: ");
		fscanf(visits, "%d\n", &service_type);
		fscanf(visits, "Service choice: ");
		fscanf(visits, "%d\n", &service_choice);
		fscanf(visits, "Service fee: Rm ");
		fscanf(visits, "%f\n", &service_fee);
		fscanf(visits, "Payment made: Rm ");
		fscanf(visits, "%f\n", &payment_made);
		fscanf(visits, "Unpaid balance: Rm ");
		fscanf(visits, "%f\n", &unpaid);
		fscanf(visits, "Amount to be returned: Rm ");
		fscanf(visits, "%f\n", &amount_to_be_returned);
		fscanf(visits, ".....................................\n");

		//Check whether ID entered for update matches any existing ID
		if (id != new_id){
			fprintf(cancellation, "Visit ID: ");
			fprintf(cancellation, "%d\n", id);
			fprintf(cancellation, "Name: ");
			fprintf(cancellation, "%s\n", name);
			fprintf(cancellation, "Date: ");
			fprintf(cancellation, "%s\n", date);
			fprintf(cancellation, "Phone number: ");
			fprintf(cancellation, "%s\n", phone_number);
			fprintf(cancellation, "Service type: ");
			fprintf(cancellation, "%d\n", service_type);
			fprintf(cancellation, "Service choice: ");
			fprintf(cancellation, "%d\n", service_choice);
			fprintf(cancellation, "Service fee: Rm ");
			fprintf(cancellation, "%.2f\n", service_fee);
			fprintf(cancellation, "Payment made: Rm ");
			fprintf(cancellation, "%.2f\n", payment_made);
			fprintf(cancellation, "Unpaid balance: Rm ");
			fprintf(cancellation, "%.2f\n", unpaid);
			fprintf(cancellation, "Amount to be returned: Rm ");
			fprintf(cancellation, "%.2f\n", amount_to_be_returned);
			fprintf(cancellation, ".....................................\n");
		}

		//Calculate amount to refund to customer
		if (id == new_id){
			amount_to_be_returned = payment_made;
			
			//Display amount to be returned to customer
			printf("\nAmount to be refunded: Rm %.2f", amount_to_be_returned);
		}
	}

	//Close file
	fclose(visits);
	fclose(cancellation);

	//Remove original file
	remove("visits.txt");

	//Rename updated file after original file
	rename("cancellation.txt", "visits.txt");

	//Display update successful message on console
	printf("\n\nService booking removed from file!\n\n");
}




