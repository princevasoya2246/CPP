#include <iostream>
#include <string>

using namespace std;

class Shape
{
private:
    string color;
    float area;

public:
    
    void setColor(string c)
    {
        color = c;
    }

    string getColor()
    {
        return color;
    }

    void setArea(float a)
    {
        area = a;
    }

    float getArea()
    {
        return area;
    }
    virtual void display()
    {
        cout << "Shape" << endl;
    }
};
class Circle : public Shape
{
private:
    float radius;

public:
    void setradius(float r)
    {
        this->radius = r;
    }

    float Circlearea()
    {
        return 3.14 * radius * radius;
    }
    void display() 
    {   
        cout << "Circle "<<endl;
        cout << "Circle  Color: " << getColor() << endl;
        cout << "Circle radius: " << radius<< endl;
        cout << "Circle  Area: " << getArea() << endl;
    }
};
class Rectangle : public Shape
{
private:
    float length, width;

public:
    void setlength(float l)
    {
        this->length = l;
    }
    void setwidth(float w)
    {
        this->width = w;
    }

    float Rectanglearea()
    {
        return length * width;
    }
    void display() 
    {   cout << "\n" <<"Rectangle"<<endl;
        cout << "Rectangle Color: " << getColor() << endl;
        cout << "Rectangle length:" <<length <<endl;
        cout << "Rectangle width:" <<width <<endl;
        cout << "Rectangle Area: " << getArea() << endl;
    }
};
int main()
{
    Circle c;
    c.setColor("red");
    c.setradius(5);
    c.setArea(c.Circlearea());

    Rectangle r;
    r.setColor("blue");
    r.setlength(10);
    r.setwidth(5);
    r.setArea(r.Rectanglearea());

    Shape *s[2];
    s[0]=&c;
    s[1]=&r;

    for(int i=0;i<2;i++){
        s[i]->display();
    }
    return 0;
}
