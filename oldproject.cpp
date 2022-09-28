#include <iostream>          
#include <string>
#include <algorithm>
#include <vector>

std::string getWord(){
    std::string x{};
    std::cout << "Write the word you want to replace: ";
    std::getline(std::cin, x);
    return x;
}

char getReplacingChar(){
	std::cout << "What character should we replace with: ";
	char x{};
	std::cin >> x;
	return x;
}

int askInt(){
    int x{};
    std::cout << "How many characters do you want to replace(max 3): ";
    if(std::cin >> x && x <= 3 && x  >= 1)
    {
        return x;
    }
        std::cout << "ERROR: Invalid input!" << '\n';
        std::cin.clear(); 
        std::cin.ignore(1000000,'\n' );
        return askInt();
}

void entChar(std::vector<char>& ex){
    std::cout << "Enter the chracter you want to replace: ";
    char newchar0{};
    std::cin >> newchar0;
    ex.push_back(newchar0);
}

std::vector<char> whichChar(){
    int x{askInt()};
    std::vector<char> y{};
    switch(x)
    {
        case 1:
        {
            entChar(y);
            return y;
        }
        case 2:
        {
            entChar(y);
			entChar(y);
            return y;
        }
        case 3:
        {
			entChar(y);
			entChar(y);
			entChar(y);
            return y;
        }
        default:
        {
            std::cout << "You chose more than 3!";
        }
    }
}

void wordChanger(std::string &word, std::vector<char>& charss, char& rChar){
    std::string x{word};
    std::vector<char> y{charss};
	char z{rChar};

    for(int i{0}; i < y.size(); ++i)
    {
        std::replace(x.begin(), x.end(), y[i], z );
    }
    std::cout << "Your final word is: " << x << '\n';
}

int main(){
    std::string x{getWord()};
    std::vector<char> y{whichChar()};
    char z{getReplacingChar()};
    wordChanger(x,y,z);

}