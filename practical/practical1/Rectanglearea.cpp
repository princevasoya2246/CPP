#include<iostream>
#include<string.h>


using namespace std;

class Rectangle{
    private:
    float length;
    float width;

    public:
   
    void setlength(float l){
        this->length=l;
    }
    void setwidth(float w){
        this->width=w;
    }
    float getlength(){
        return length;
    }
    float getwidth(){
        return width;
    }

    float area(){
        return length*width;
    }
};
int main(){
    Rectangle r;
    float l,w;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter width: ";
    cin >> w;
    r.setlength(l);
    r.setwidth(w);

    cout << "Rectangle area is : " << r.area() << endl;

    return 0;
}