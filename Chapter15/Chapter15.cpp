#include <iostream>
#include "Simple_window.h"
#include "Graph.h"

//Functions for tasks
double one(double) { return 1; }

double slope(double x) { return x / 2; }

double square(double x) { return x * x; }

double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
    using namespace Graph_lib;
    try {
        //Create Window
        constexpr int xmax = 600;
        constexpr int ymax = 600;

        Simple_window win(Point{ 100, 100 }, xmax, ymax, "Function graphing");

        //Create Axis x and y
        constexpr int xlength = xmax - 200;
        constexpr int ylength = ymax - 200;

        constexpr int x_scale = 20; //Scale
        constexpr int y_scale = 20;

        constexpr int x_orig = xmax / 2; //Window center
        constexpr int y_orig = ymax / 2;

        Point orig { x_orig, y_orig };

        Axis x{ Axis::x, Point{100, y_orig},
            xlength, xlength / x_scale, "Axis X" };
        Axis y{ Axis::y, Point{x_orig, ylength+100},
           ylength, ylength / y_scale, "Axis Y" };

        x.set_color(Color::red);
        y.set_color(Color::red);

        win.attach(x);
        win.attach(y);
        win.wait_for_button();

        //Part 1 
        const int r_min = -10;//Range[-10,11]
        const int r_max = 11;
        const int n_points = 400;

        //Draw "Function graphing" one
         Function s(one, r_min, r_max, orig, n_points);
        win.attach(s);
        win.wait_for_button();

        //Part2 changes with scale
        /*Function s(one, r_min, r_max, orig, n_points, x_scale, y_scale);
        win.attach(s);
        win.wait_for_button();*/

        //Part 4 Draw "Function graphing" slope
        Function s2(slope, r_min, r_max, orig, n_points, x_scale, y_scale);
        //Part 5
        Text ts2(Point(100, y_orig + y_orig / 2-20), "x/2");
        win.attach(s2);
        win.attach(ts2);
        win.wait_for_button();

        //Part 6 Draw "Function graphing" square
        Function s3(square, r_min, r_max, orig, n_points, x_scale, y_scale);
        win.attach(s3);
        win.wait_for_button();

        //Part 7 Draw "Function graphing" cos with lambda function
        Function s4{ [](double x) {return cos(x); },
        r_min, r_max, orig, 400, 20, 20 };

        //Part 8 Create graphing cos in the blue color
        s4.set_color(Color::blue);
        win.attach(s4);
        win.wait_for_button();

        //Part 9 Draw "Function graphing" sloping_cos
        Function s5(sloping_cos, r_min, r_max, orig, 400, 20, 20);
        win.attach(s5);
        win.wait_for_button();
    }
    catch (exception& e) {
        return 1;
    }
    catch (...) {
        return 2;
    }
    return 0;
}
