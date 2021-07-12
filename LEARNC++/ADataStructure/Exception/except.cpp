#include <iostream>
#include <exception>

using namespace std;

class BadLengthException
{
public:
    int n;
    BadLengthException(int len)
    {
        n = len;
        throw n;
    }
    const int what() throw()
    {
        return n;
    }
};

bool checkUsername(string name)
{
    bool isValid = true;
    int n = name.length();
    if (n < 5)
    {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (name[i] == 'w' && name[i + 1] == 'w')
        {
            isValid = false;
        }
    }
    return isValid;
}

int main()
{
    int n;

    while (n--)
    {
        string name;
        cin >> name;

        try
        {
            int n = name.length();
            bool isValid = checkUsername(name);
            if (isValid)
            {
                cout << " Valid User" << endl;
            }
            else
            {
                cout << " Invalid User" << endl;
            }
        }
        catch (BadLengthException e)
        {
            cout << " Too Short :" << e.what() << " length" << endl;
        }
    }
}