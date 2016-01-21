#include <iostream>
using namespace std;

int main()
{
	int plants=0, people=0, fruit=0, weeks=1;
    
    cout << "Entire the desired population: ";
    cin >> people;
    cout << "Entire the amount of starting plants: ";
    cin >> plants;
    while (fruit < people)
    {
        ++weeks;
        plants += fruit;
        fruit += plants;
    }
    
    cout << "It would take " << weeks << " weeks until you had enough plants." << endl;
	return 0;
}
