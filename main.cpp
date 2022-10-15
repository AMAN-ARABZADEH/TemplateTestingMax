#include <iostream>
// Practicng templates


#include <string>
#include <cstring>



/////////////////////////////////

// Maximum of two values
template <typename T>

inline T const &Max(T const &a, T const &b){
    return (a < b) ? b : a;
}

// Mazximum of two pointers
template <typename T>

inline  T* const Max(T* const &a, T* const &b){
    return (*a < *b) ? b : a;
}


// Maximum of two c string
inline char const* Max(char const* const &a, char const* const &b){
    return std::strcmp(a,b) < 0 ? b : a;
}


/////////////////////////////////////////////


// maximum of two values of any type (call-by-reference)
template <typename T>
inline T const& max(T const& a, T const& b)
{
    return  a < b  ?  b : a;
}

// maximum of two C-strings (call-by-value)
inline char const* max(char const* a, char const* b)
{
    return  std::strcmp(a,b) < 0  ?  b : a;
}

// maximum of three values of any type (call-by-reference)
template <typename T>
inline T const& max(T const& a, T const& b, T const& c)
{
    return max (max(a,b), c);  // error, if max(a,b) uses call-by-value
}


/*
    "Note that in all overloaded implementations, we pass all arguments by reference. In general, it is a good idea not to
    change more than necessary when overloading function templates. You should limit your changes to the number of
    parameters or to specifying template parameters explicitly. Otherwise, unexpected effects may happen. For example,
    if you overload the max() template, which passes the arguments by reference, for two C-strings passed by value, you
    can't use the three-argument version to compute the maximum of three C-strings":  Nicolai M. Josuttis
    Example from book C++ Template by Nicolai M. Josuttis.

 *
 */



/*
    /////////////////////////////////////////
    // maximum of two int values
    inline int const& max (int const& a, int const& b)
    {
        return  a < b ? b : a;
    }

    // maximum of two values of any type
    template <typename T>
    inline T const& Max(T const& a, T const& b)
    {
        return  a < b ? b : a;
    }

    // maximum of three values of any type
    template <typename T>
    inline T const& Max(T const& a, T const& b, T const& c)
    {
        return ::max (::max(a,b), c);
    }
*/





int main() {
    auto waiting = [](){std::cout << "Waiting......"; std::cin.get();
        std::cout << "\n=====================================================================================\n";};
    waiting();
    int a=7;
    int b=42;
    std::cout << Max(a,b) << '\n';      // max() for two values of type int

    std::string s="hey";
    std::string t="you";
    std::cout << Max(s,t)<< '\n';      // max() for two values of type std::string

    int* p1 = &b;
    int* p2 = &a;
    std::cout << Max(*p1,*p2)<< '\n';     // max() for two pointers

    char const* s1 = "David";
    char const* s2 = "Nico";
    std::cout << Max(s1,s2) << '\n';     // max() for two C-strings

    waiting();

    /*
     * Fibonacci numbers, just a simple program, but powerfullone using loop to count the n of fib number
     *  Programming is awesome (=
     */
      long prevFib = 1; // Pre fibonacci
      long currentFib = 1; // current fibonacci
      std::cout.width(2);  // output in a space of 2 chars
      std::cout << "n";
      std::cout.width(27); // output of the space
      std::cout << "Fibonacci number";
      std::cout.width(30);
      std::cout << "Fibonacci Quotient\n\n";
      std::cout.precision(20); // Precision for fib quotient

      // Loop over the n element
      std::size_t fibOf = 40;
      for(auto fib{1};fib <= fibOf; ++fib){
          std::cout.width(2);  // output in a space of 2 chars
          std::cout << fib;
          std::cout.width(27); // output of the space
          std::cout << prevFib;    // Output Fib numbers
          std::cout.width(30);
          std::cout << (long double)currentFib / prevFib << '\n'; // Fib Quotient
          std::cout.precision(20); // Precision for fib quotient

          // Exchange values and add with the previous value
          long temp = currentFib;
          currentFib += prevFib;
          prevFib = temp;
      }




















    return 0;
}
