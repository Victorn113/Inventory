#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int DESC_SIZE=31;
const int DATE_SIZE=11;

struct inventoryFile
{
    char des[DESC_SIZE];
int qty;
double wholeSale;
double retail;
char date[DATE_SIZE];
};
void viewRecord(fstream&);
void changeRecord(fstream&);
void addRecord(fstream&);

int main()
{
    int select;
    int again;
    cout << "Enter 1 to begin" << endl;
    cin >> again;
    int again2;
    while (again==1)
    {
    cout << "Enter 1 to view record, 2 to add, and 3 to change" << endl;
    cin >> select;
    fstream File;
    inventoryFile record;

    switch (select)
    {
    case 1:
        {viewRecord(File);


        break;}
    case 2:
        addRecord(File);

        break;
    case 3:
        {changeRecord(File);

        break;
        cout << "Enter 1 to continue or any other key to quit" << endl;
        cin >> again2;
        again2=again;
    }}}



return 0;
}

void viewRecord(fstream& invFile)
{
inventoryFile record;
long recNum;
invFile.open("invtry.dat",ios::out|ios::binary);

if (invFile.fail())
{
cout << "Error entering file" << endl;
exit(EXIT_FAILURE);
}
cout << "Enter the record number of the item: ";

    cin >> recNum;




    invFile.seekg(recNum * sizeof(record), ios::beg);

    if (invFile.fail())

    {

        cout << "\nError locating record.\n";

        invFile.close();

        return;

    }
invFile.read(reinterpret_cast<char*>(&record),sizeof(record));
invFile.close();
cout << "Description: ";

    cout << record.des << endl;

    cout << "Quantity: ";

    cout << record.qty << endl;

    cout <<"Wholesale cost: " << endl;

    cout << record.wholeSale << endl;

    cout << "Retail Price: " << endl;

    cout << record.retail;

    cout << "Date added to inventory: ";

    cout << record.date;
}
void changeRecord(fstream& invFile)
{
    inventoryFile record;

    long recNum;
    invFile.open("intry.dat",ios::in|ios::out|ios::binary);
    if (invFile.fail())
    {
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Description: " << endl;
    cin.getline(record.des,31);
    cout << "Quantity: ";
    cin >> record.qty;
    cout << "Wholesale cost: ";
    cin >> record.wholeSale;
    cout << "Retail price:";
    cin >> record.retail;
    cout << "Date added to inventory" << endl;
    cin >> record.date;

    invFile.seekp(recNum*sizeof(record),ios::beg);
    invFile.write(reinterpret_cast<char*>(&record),sizeof(record));
    invFile.close();
    cout << "Press any key to continue" << endl;
    cin.get();
}
void addRecord(fstream& invFile)
{
    inventoryFile record;

    invFile.open("invtry.dat",ios::out|ios::app|ios::binary);
    if (invFile.fail())
    {
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }
    cin.get();
    cout << "Enter the following inventory data" << endl;
    cout << "Description:" << endl;
    cin.getline(record.des,31);
    cout << "Quantity: ";
    cin >> record.qty;
    while(record.qty<0)
    {
        cout << "Enter a positive value, please:";
        cin >> record.wholeSale;
    }
    cout << "retail price: ";
    cin >> record.retail;
    while(record.retail<0)
    {
        cout << "Enter a positive value, please" << endl;
        cin >> record.retail;
    }
    cout << "Date added to inventory: ";
    cin >> record.date;

    invFile.write(reinterpret_cast<char*>(&record),sizeof(record));

    if (invFile.fail())
    {
        cout << "Error writing record to file" << endl;
    }
    else
    {
        cout << "record written to file" << endl;
    }
    invFile.close();
}
