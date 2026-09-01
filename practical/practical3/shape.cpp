#include<iostream>
#include<string>

using namespace std;

class Shape{
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


};
class Circle:public Shape{
    private:
    float radius;

    public:
    void setradius(float r){
        this->radius=r;
    }


    float Circlearea(){
        return 3.14*radius*radius;
    }

};
class Rectangle:public Shape{
    private:
    float length,width;

    public:
    
    void setlength(float l){
        this->length=l;
    }
    void setwidth(float w){
        this->width=w;
    }

    float Rectanglearea(){
        return length*width;
    }
    
};
int main(){
    Circle c;
    c.setColor("red");
    c.setradius(5);
    c.setArea(c.Circlearea());

    Rectangle r;
    r.setColor("blue");
    r.setlength(10);
    r.setwidth(5);
    r.setArea(r.Rectanglearea());

    cout << "Circle  Color: " << c.getColor() << endl;
    cout << "Circle  Area: " << c.getArea() << endl;
    cout << "Rectangle Color: " << r.getColor() <<endl;
    cout << "Rectangle Area: " << r.getArea() << endl;

    return 0;
}
