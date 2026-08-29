#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class LibraryItem
{
private:
    string title;
    string author;
    string duedate;

public:
    bool isavailable = true;
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    static int LibraryItemCount;
    LibraryItem(string title, string author, string duedate)
    {
        this->title = title;
        this->author = author;
        this->duedate = duedate;
        LibraryItemCount++;
    }
    string settitle(string newtitle)
    {
        title = newtitle;
    }
    string setauthor(string newauthor)
    {
        author = newauthor;
    }
    string setduedate(string newduedate)
    {
        duedate = newduedate;
    }
    string gettitle()
    {
        return title;
    }
    string getauthor()
    {
        return author;
    }
    string getduedate()
    {
        return duedate;
    }
};

class Books : public LibraryItem
{
public:
    string pages;
    Books(string title, string author, string duedate, string pages) : LibraryItem(title, author, duedate)
    {
        this->pages = pages;
    }
    void checkOut()
    {
        if (isavailable)
        {
            isavailable = false;
            cout << "Check out successfully" << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
    void returnItem()
    {
        if (!isavailable)
        {
            isavailable = true;
            cout << "return item successfully" << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
    void displayDetails()
    {
        cout << "Book Title :" << gettitle() << endl;
        cout << "Book Author :" << getauthor() << endl;
        cout << "Book Duedate :" << getduedate() << endl;
        cout << "Book Pages :" << pages << endl;
    }
    ~Books()
    {
        cout << "Book Remove Successfully" << endl;
    }
};

class DVDs : public LibraryItem
{
public:
    string duration;
    DVDs(string title, string author, string duedate, string duration) : LibraryItem(title, author, duedate)
    {
        this->duration = duration;
    }
    void checkOut()
    {
        if (isavailable)
        {
            isavailable = false;
            cout << "Check out successfully" << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
    void returnItem()
    {
        if (!isavailable)
        {
            isavailable = true;
            cout << "return item successfully" << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
    void displayDetails()
    {
        cout << "DVDs Title :" << gettitle() << endl;
        cout << "DVDs Author :" << getauthor() << endl;
        cout << "DVDs Duedate :" << getduedate() << endl;
        cout << "DVDs duration :" << duration << endl;
    }
    ~DVDs()
    {
        cout << "DVDs destructor called" << endl;
    }
};

class magazines : public LibraryItem
{
public:
    string issueNumber;
    magazines(string title, string author, string duedate, string issueNumber) : LibraryItem(title, author, duedate)
    {
        this->issueNumber = issueNumber;
    }
    void checkOut()
    {
        if (isavailable)
        {
            isavailable = false;
            cout << "Check out successfully" << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
    void returnItem()
    {
        if (!isavailable)
        {
            isavailable = true;
            cout << "return item successfully" << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
    void displayDetails()
    {
        cout << "Magazines Title :" << gettitle() << endl;
        cout << "Magazines Author :" << getauthor() << endl;
        cout << "Magazines Duedate :" << getduedate() << endl;
        cout << "Magazines issueNumber :" << issueNumber << endl;
    }
    ~magazines()
    {
        cout << "magazines destructor called" << endl;
    }
};
int LibraryItem::LibraryItemCount = 0;

int main()
{
    LibraryItem *l[100];
    Books b1("algo", "F. Scott Fitzgerald", "2026-09-15", "180");
    l[0] = &b1;
    Books b2("To-Kill-a-Mockingbird", "Harper Lee", "2026-10-01", "281");
    l[1] = &b2;

    DVDs d1("Project-HailMary", "Andy Weir", "2026-09-12", "16h 10m");
    l[2] = &d1;
    DVDs d2("OurPlanet", "David Attenborough", "2026-09-05", "50m");
    l[3] = &d2;

    magazines m1("TheAmazingSpider-Man", "Stan Lee", "2026-09-15", "300");
    l[4] = &m1;
    magazines m2("NationalGeographic", "Various", "2026-10-01", "142");
    l[5] = &m2;

    int choice;
    while (true)
    {
        cout << "===============Library Management System==============" << endl;
        cout << "1. Search Items" << endl;
        cout << "2. check out" << endl;
        cout << "3. return" << endl;
        cout << "4. Exit" << endl;
        cout << "Please Enter Your Choice : ";
        cin >> choice;

        string bname;
        switch (choice)
        {
        case 1:
            cout << "Enter title :";
            cin >> bname;
            for (int i = 0; i < LibraryItem::LibraryItemCount; i++)
            {
                if (bname == l[i]->gettitle())
                {
                    l[i]->displayDetails();
                }
            }
            break;
        case 2:
            cout << "Enter title :";
            cin >> bname;
            for (int i = 0; i < LibraryItem::LibraryItemCount; i++)
            {
                if (bname == l[i]->gettitle())
                {
                    l[i]->checkOut();
                }
            }
            break;
        case 3:
            cout << "Enter title :";
            cin >> bname;
            for (int i = 0; i < LibraryItem::LibraryItemCount; i++)
            {
                if (bname == l[i]->gettitle())
                {
                    l[i]->returnItem();
                }
            }

            break;

        case 4:
            exit(0);
        default:
            cout << "Please Enter Valid Choice !!" << endl;
            break;
        }
    }

    return 0;
}