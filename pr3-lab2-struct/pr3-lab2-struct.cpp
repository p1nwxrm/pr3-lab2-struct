#include <iostream>
#include <string>

using namespace std;

struct Car
{
    //fields
    string brand;
    string model;
    double engineVolume = 0;
    double mileage = 0;
    string bodyType;
    string category;
    double price = 0;

    //methods
    void SetInfo();
    void ShowInfo();
};

void showCatalog(Car* catalog, int size);
void findCar(Car* catalog, int size, string brand, string model);
int getHighMileageCars(Car* catalog, int size);
void sortCatalogByBrand(Car* catalog, int size);
void sortCatalogByBodyType(Car* catalog, int size);
void sortCatalogByPrice(Car* catalog, int size);

int main()
{
    int size = 0;
    cout << "Enter catalog size: ";
    cin >> size;
    Car* catalog = new Car[size];

    bool isWork = true;
    int pick1 = 0, pick2 = 0;
    string brand;
    string model;

    while(isWork)
    {
        system("pause");
        system("cls");

        cout << "==========MENU==========\n";
        cout << "1 - Fill out the catalog\n";
        cout << "2 - Display the catalog on the screen\n";
        cout << "3 - Find the right car\n";
        cout << "4 - Sort by...\n";
        cout << "5 - Exit the program\n";
        cout << "\n";
        cin >> pick1;

        switch(pick1)
        {
        case 1:
            for (int i = 0; i < size; ++i)
            {
                cout << "\n" << i + 1 << ".";
                catalog[i].SetInfo();
            }
            break;
        case 2:
            showCatalog(catalog, size);
            break;
        case 3: 
            cout << "\nEnter car brand + model: ";
            cin >> brand >> model;
            findCar(catalog, size, brand, model);
            break;
        case 4:
            cout << "\n";
            cout << "==========MENU==========\n";
            cout << "1 - Sort by brand\n";
            cout << "2 - Sort by body type\n";
            cout << "3 - Sort by price\n";
            cout << "\n";
            cin >> pick2;

            switch (pick2)
            {
            case 1:
                sortCatalogByBrand(catalog, size);
                break;
            case 2:
                sortCatalogByBodyType(catalog, size);
                break;
            case 3:
                sortCatalogByPrice(catalog, size);
                break;
            default:
                cout << "There is no such answer.\n";
                break;
            }

            cout << "\n";
            showCatalog(catalog, size);

            break;
        case 5:
            cout << "Bye!\n";
            isWork = false;
            break;
        default:
            cout << "There is no such answer.\n"; 
            break;
        }
    }
   
    delete[] catalog;

    return 0;
}

void Car::SetInfo()
{
    cout << "\tEnter car brand: ";
    cin >> brand;
    cout << "\tEnter car model: ";
    cin >> model;
    cout << "\tEnter engine volume: ";
    cin >> engineVolume;
    cout << "\tEnter mileage: ";
    cin >> mileage;
    cout << "\tEnter body type: ";
    cin >> bodyType;
    cout << "\tEnter category: ";
    cin >> category;
    cout << "\tEnter price: ";
    cin >> price;
}

void Car::ShowInfo()
{
    cout << "\tCar brand: " << brand << "\n";
    cout << "\tCar model: " << model << "\n";
    cout << "\tEngine volume: " << engineVolume << "\n";
    cout << "\tMileage: " << mileage << "\n";
    cout << "\tBody type: " << bodyType << "\n";
    cout << "\tCategory: " << category << "\n";
    cout << "\tPrice: " << price << "\n";
}

void showCatalog(Car* catalog, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << i + 1 << ".";
        catalog[i].ShowInfo();
    }
}

void findCar(Car* catalog, int size, string brand, string model)
{
    bool carExist = false;
    for (int i = 0; i < size; ++i)
    {
        if (catalog[i].brand == brand && catalog[i].model == model)
        {
            carExist = true;
            catalog[i].ShowInfo();
        }
    }
    if (!carExist)
    {
        cout<<"The car doesn`t exist.\n";
    }
}

int getHighMileageCars(Car* catalog, int size)
{
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (catalog[i].mileage > 5000)
        {
            ++count;
        }
    }

    return count;
}

void sortCatalogByBrand(Car* catalog, int size) {
    for (int i = 1; i < size; i++) {
        Car key = catalog[i];
        int j = i - 1;
        while (j >= 0 && catalog[j].brand > key.brand) {
            catalog[j + 1] = catalog[j];
            j--;
        }
        catalog[j + 1] = key;
    }
}

void sortCatalogByBodyType(Car* catalog, int size) {
    for (int i = 1; i < size; i++) {
        Car key = catalog[i];
        int j = i - 1;
        while (j >= 0 && catalog[j].bodyType > key.bodyType) {
            catalog[j + 1] = catalog[j];
            j--;
        }
        catalog[j + 1] = key;
    }
}

void sortCatalogByPrice(Car* catalog, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (catalog[j].price > catalog[j + 1].price)
            {
                swap(catalog[j], catalog[j + 1]);
            }
        }
    }
}