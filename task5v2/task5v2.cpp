#include <iostream>
using namespace std;

struct Clients
{
    char Case;
    union
    {
        struct {
            char Name[10]; int Phone; int Age; } Female;
        struct {
            char Name[10]; int NumPhone; int Growth; } Male;
    };
    char Address[40];
};

Clients InpClientInfo(Clients client)
{
    char gender;
    cout << "Пол клиента: ";
    cin >> gender;

    client.Case = gender;
    

    if (client.Case == 'f')
    {
        cout << "Заполнение БД для клиентов женского пола." << endl;
        cout << "Имя: ";
        cin >> client.Female.Name;
        cout << "Номер телефона: ";
        cin >> client.Female.Phone;
        cout << "Возраст: ";
        cin >> client.Female.Age;
    }
    else
    {
        cout << "Заполнение БД для клиентов мужского пола." << endl;
        cout << "Имя: ";
        cin >> client.Male.Name;
        cout << "Телефон: ";
        cin >> client.Male.NumPhone;
        cout << "Рост: ";
        cin >> client.Male.Growth;
    }
    cout << "Адрес: ";
    cin >> client.Address;
    return client;
}

void OutSubscriberInfo(Clients client)
{
    if (client.Case == 'f')
    {
        cout << client.Female.Name << " | ";
        cout << client.Female.Phone << " | ";
        cout << client.Female.Age << " | ";
        cout << client.Address;
    }
    else
    {
        cout << client.Male.Name << " | ";
        cout << client.Male.NumPhone << " | ";
        cout << client.Male.Growth << " | ";
        cout << client.Address << endl;
    }
}

Clients& ChangeAdress(Clients& scb)
{
    cout << "Новый адрес клиента: ";
    cin >> scb.Address;
    return scb;
}

void main()
{
    setlocale(LC_ALL, "Russian");
    Clients DataBase[10];                  //   База данных.
    Clients client = { 0, {"", 0, 0}, ""}; // Пустая структура для очистки
    Clients newClient = { 0, {"", 0, 0}, "" };
    int i;
    char j;                                  // Очистка базы данных.
    //for (i = 0; i < sizeof(DataBase) / sizeof(Clients); i++)
    //    DataBase[i] = client;
    while (1)
    {
        cout << "    Меню СУБД:" << endl
            << "1. Ввод данных." << endl
            << "2. Вывод информации об клиенте." << endl
            << "3. Вывод всей информации." << endl
            << "4. Удаление клиента." << endl
            << "5. Изменить адрес клиента." << endl
            << "6. Закончить работу." << endl
            << ">";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            //Clients newClient = { 0, {"", 0, 0}, "" };
            cout << "Номер абонента: ";
            cin >> i;
            //cout << "Вариант (m-мужчина, f-женщина): ";
            //cin >> j;
            DataBase[i] = InpClientInfo(newClient);
        }
            break;
        case 2:
        {
            cout << "Номер абонента: ";
            cin >> i;
            OutSubscriberInfo(DataBase[i]);
        }
            break;
        case 3:
        {
            for (i = 0; i < sizeof(DataBase) / sizeof(Clients); i++)
                if (DataBase[i].Address[0])
                {
                    cout << "Клиент номер " << i << ':' << endl;
                    OutSubscriberInfo(DataBase[i]);
                }
        }
              break;
        case 4:
        {
            cout << "Номер клиента: ";

            cin >> i;
            DataBase[i] = client;
        }
            break;
        case 5:
        {
            cout << "Номер клиента в базе: ";
            cin >> i;
            cout << "Новый адрес: ";
            cin >> j;
            ChangeAdress(DataBase[i]);
        }
            break;
        //case 6: for (i = 0; i < sizeof(DataBase) / sizeof(Clients); i++)
        //    if ((DataBase + i)->Time > 0)
        //        OutSubscriberInfo(DataBase[i]);
        //    break;
        case 6: return;
        default: cout << "Поторите ввод!" << endl;
        }
    }
}