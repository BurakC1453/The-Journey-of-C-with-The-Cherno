#include <iostream>
#include <string>

class bank_account
{
private:
	std::string accountHolderName = "Burak";
	int accountNumber = 123456789;
	std::string accountPassword = "1234";
	int accountBalance = 10000;
	double operationAmount = 0.0;
	int userChoice = 0;
	std::string userPasswordInput;
	std::string userNameInput;
	int passKey = 0;

	void display_menu()
	{
		std::cout << "Bank Account Management System" << std::endl;
		std::cout << "1. Deposit\n" << "2. Withdraw\n" << "3. Check Balance\n" << "4. Exit" << std::endl;
		std::cin >> userChoice;
	}

	void perform_operation()
	{
		switch (userChoice)
		{
		case 1:
			std::cout << "Enter amount to deposit: ";
			std::cin >> operationAmount;
			accountBalance += operationAmount;
			std::cout << "Deposit successful. Current balance: " << accountBalance << std::endl;
			break;
		case 2:
			std::cout << "Enter amount to withdraw: ";
			std::cin >> operationAmount;
			if (operationAmount > accountBalance)
			{
				std::cout << "Insufficient funds. Current balance: " << accountBalance << std::endl;
			}
			else
			{
				accountBalance -= operationAmount;
				std::cout << "Withdrawal successful. Current balance: " << accountBalance << std::endl;
			}
			break;
		case 3:
			std::cout << "Current balance: " << accountBalance << std::endl;
			break;
		case 4:
			std::cout << "Exiting. Thank you for using our services!" << std::endl;
			exit(0);
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}

	void user_authentication()
	{
		std::cout << "Enter account holder name: ";
		std::cin >> userNameInput;
		std::cout << "Enter account password: ";
		std::cin >> userPasswordInput;
		if (userNameInput == accountHolderName && userPasswordInput == accountPassword)
		{
			std::cout << "Authentication successful. Welcome, " << accountHolderName << "!" << std::endl;
			passKey = 1;
		}
		else
		{
			std::cout << "Authentication failed. Please try again." << std::endl;
		}
	}

public:
	void run()
	{

		for (int i = 0; i <= 2;i += 1)
		{
			user_authentication();
			if (passKey == 1)
			{
				break;
			}
			else if (i == 2)
			{
				std::cout << "Too many failed attempts. Exiting." << std::endl;
				exit(0);
			}
			else
			{
				std::cout << "Attempt " << i + 1 << " of 3 failed. Please try again." << std::endl;
			}
		}
			while (true)
			{
				display_menu();
				perform_operation();
			}
		}
};

int main()
{
	bank_account myAccount;
	myAccount.run();
	return 0;
}