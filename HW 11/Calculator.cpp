#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"
#include <vector>

using namespace Graph_lib;
using namespace std;

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title );
private:
    Button next_button;        // add (next_x,next_y) to lines
    Button quit_button;
    In_box formula;
    Out_box result;

    static void cb_next(Address, Address);
    void next();
    static void cb_quit(Address, Address);
    void quit();
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    next_button(Point(x_max()-150,0), 70, 20, "Calculate", cb_next),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
    formula(Point(x_max()-310,0), 50, 20, "Formula:"),
    result(Point(100,0), 100, 20, "Result:")
{
    attach(next_button);
    attach(quit_button);
    attach(formula);
    attach(result);
}
void Lines_window::cb_quit(Address, Address pw)
{
       reference_to<Lines_window>(pw).quit();
}
void Lines_window::quit()
{
    hide();
}
void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}
void Lines_window::next()
{
    string s = formula.get_string();
    istringstream iss(s);
    double a, b;
    char op;
    double val = 0;
    if (!(iss >> a >> op >> b)) {
        result.put("Input error");
        return;
    }
    switch(op) {
        case '+':
            val = a + b;
            break;
        case '-':
            val = a - b;
            break;
        case '*':
            val = a * b;
            break;
        case '/':
            if(b == 0) {
                result.put("Div 0 error");
                return;
            }
            val = a / b;
            break;
        default:
            result.put("Unknown op");
            return;
    }
    ostringstream oss;
    oss << val;
    result.put(oss.str());
}
int main()
try {
    Lines_window win(Point(100,100),600,400,"Calculator");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}