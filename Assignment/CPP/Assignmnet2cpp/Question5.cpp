//============================================================================
// Name        : Question5.cpp
// Author      : Tanaya Gughane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

// Namespace 1
namespace Physics
{
    double clamp(double val, double min, double max)
    {
        if (val < min)
            return min;
        else if (val > max)
            return max;
        else
            return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


// Namespace 2
namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;
        else if (val > max)
            return max;
        else
            return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


int main5()
{
    // Call using full namespace path
    double velocity = Physics::clamp(120.5, 0.0, 100.0);
    int stat = GameMath::clamp(150, 0, 99);

    cout << "Physics Clamp Result  : " << velocity << endl;
    cout << "GameMath Clamp Result : " << stat << endl;

    double p = Physics::lerp(10, 20, 0.5);
    double g = GameMath::lerp(0, 100, 0.25);

    cout << "Physics Lerp Result   : " << p << endl;
    cout << "GameMath Lerp Result  : " << g << endl;

    // Limited block scope using namespace
    {
        using namespace Physics;

        double result = lerp(50, 100, 0.2);

        cout << "Using Physics Namespace Lerp : "
             << result << endl;
    }

    return 0;
}
