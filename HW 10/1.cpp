#include <iostream>
#include <string>
#include <cmath>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"
#include <vector>
#define PI 3.1415926

using namespace Graph_lib;

class Binary_Tree : public Shape {
    private:
        int level;
        double x, y;
    public:
        Binary_Tree(int x1, int y1, int n)
        {
            x = x1;
            y = y1;
            level = n;
        }
        Binary_Tree()
        {
            x = 150;
            y = 200;
            level = 3;
        }
        void draw_lines() const {
            Arc root_circle(Point(x, y), 10, 10, 0, 360);
            root_circle.draw();
            Text root_text(Point(x-10, y+4), "root");
            root_text.set_font_size(14);
            root_text.draw();
            draw_(x, y, 1);
        }
        virtual void draw_(double x1, double y1, int n) const {
            if(n == level) return;
            double angle = PI / (3.0 * n * std::sqrt(n));
            double offset = 70;
            double x2 = x1 - offset * sin(angle);
            double y2 = y1 + offset * cos(angle);
            double x3 = x1 + offset * sin(angle);
            double y3 = y1 + offset * cos(angle);
            Line line_left(Point(x1, y1 + 10), Point(x2, y2));
            Line line_right(Point(x1, y1 + 10), Point(x3, y3));
            if (color().visibility()){
                line_left.draw();
                line_right.draw();
                Arc left_circle(Point(x2, y2+10), 10, 10, 0, 360);
                Arc right_circle(Point(x3, y3+10), 10, 10, 0, 360);
                left_circle.draw();
                right_circle.draw();
                Text left_text(Point(x2-6, y2+10+4), "L");
                left_text.set_font_size(14);
                left_text.draw();
                Text right_text(Point(x3-6, y3+10+4), "R");
                right_text.set_font_size(14);
                right_text.draw();
            }
            draw_(x2, y2+10, n + 1);
            draw_(x3, y3+10, n + 1);
        }
};
class Triangle_Tree : public Binary_Tree {
    private:
        int level;
        double x, y;
    public:
        Triangle_Tree(double x1, double y1, int n)
        {
            x = x1;
            y = y1;
            level = n;
        }
        void draw_lines() const {
            Line l1(Point(x, y), Point(x+10, y+20));
            Line l2(Point(x, y), Point(x-10, y+20));
            Line l3(Point(x+10, y+20), Point(x-10, y+20));
            l1.draw(); l2.draw(); l3.draw();
            Text root_text(Point(x-15, y+10), "root");
            root_text.set_font_size(14);
            root_text.draw();
            draw_(x, y+20, 1);
        }
        void draw_(double x1, double y1, int n) const {
            if(n == level) return;
            double angle = PI / (3.0 * n * std::sqrt(n));
            double offset = 70;
            double x2 = x1 - offset * sin(angle);
            double y2 = y1 + offset * cos(angle);
            double x3 = x1 + offset * sin(angle);
            double y3 = y1 + offset * cos(angle);
            Line line_left(Point(x1, y1), Point(x2, y2));
            Line line_right(Point(x1, y1), Point(x3, y3));
            line_left.draw();
            line_right.draw();
            Line t1_left(Point(x2, y2), Point(x2+10, y2+20));
            Line t2_left(Point(x2, y2), Point(x2-10, y2+20));
            Line t3_left(Point(x2+10, y2+20), Point(x2-10, y2+20));
            t1_left.draw(); t2_left.draw(); t3_left.draw();
            
            Line t1_right(Point(x3, y3), Point(x3+10, y3+20));
            Line t2_right(Point(x3, y3), Point(x3-10, y3+20));
            Line t3_right(Point(x3+10, y3+20), Point(x3-10, y3+20));
            t1_right.draw(); t2_right.draw(); t3_right.draw();
            Text left_text(Point(x2-10, y2+20), "L");
            left_text.set_font_size(14);
            left_text.draw();
            Text right_text(Point(x3-10, y3+20), "R");
            right_text.set_font_size(14);
            right_text.draw();
            
            draw_(x2, y2+20, n + 1);
            draw_(x3, y3+20, n + 1);
        }
};

int main()
{
    Simple_window win(Point(100, 100), 500, 500, "Triangle Tree");
    Triangle_Tree t1(250, 100, 4);
    t1.set_color(Color::red);
    t1.set_style(Line_style(Line_style::solid, 2));
    win.attach(t1);
    win.wait_for_button();
    Simple_window win1(Point(100, 100), 500, 500, "Binary Tree");
    Binary_Tree t2(250, 100, 3);
    t2.set_color(Color::yellow);
    t2.set_style(Line_style(Line_style::solid, 2));
    win1.attach(t2);
    win1.wait_for_button();
    return 0;
}
