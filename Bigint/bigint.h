#include <string>
using namespace std;

class Bigint
{
    bool negative;
    string digits;

    public:
    // constructors
    Bigint();
    Bigint(int);
    Bigint(string);

    // member functions
    string to_string() const;
    Bigint operator+(Bigint const& obj);
    string addition_loop(int i , int j, Bigint const& obj);

};