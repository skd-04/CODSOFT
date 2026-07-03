
//CALCULTOR
#include <iostream>
using namespace std;

int main()
{
    int choice;
    float num1, num2, result;

    cout << "===== SIMPLE CALCULATOR =====" << endl;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "\nChoose an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;

    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            result = num1 + num2;
            cout << "Result = " << result;
            break;

        case 2:
            result = num1 - num2;
            cout << "Result = " << result;
            break;

        case 3:
            result = num1 * num2;
            cout << "Result = " << result;
            break;

        case 4:
            if(num2 == 0)
            {
                cout << "Division by zero is not possible.";
            }
            else
            {
                result = num1 / num2;
                cout << "Result = " << result;
            }
            break;

        default:
            cout << "Invalid Choice!";
    }

    return 0;
}