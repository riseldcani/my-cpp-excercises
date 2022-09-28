#include <iostream>
#include <string>

struct Encryptor{

	std::string encrypt(const std::string &data) const noexcept {
	std::string encrypted;
    for(int i{0}; i < data.length(); ++i)
		{
			encrypted = data[i] + 5;
			std::cout << encrypted;
		}
	return encrypted;
    }

	std::string decrypt(const std::string &data) const noexcept {
	std::string decrypted;
	for(int i{0}; i < data.length(); ++i)
		{
			decrypted = data[i] - 5;
			std::cout << decrypted;
		}
	return decrypted;
	}

};

std::string getInput(){
	std::cout << "Enter the word: ";
	std::string x{};
	std::cin >> x;
	return x;
}

void askUser(){

	Encryptor a;
	std::cout << "1- encrypt" << ' ' << "2- decrypt: ";
	int x{};
	std::cin >> x;
	std::cin.ignore();
	switch(x)
	{
		case 1:{
		a.encrypt(getInput());
		break;
		}
		case 2:{
		a.decrypt(getInput());
		break;
		}
		default:{
		std::cout << "ERROR:INVALID INPUT";
		break;
		}
	}
}

int main(){
	askUser();
}