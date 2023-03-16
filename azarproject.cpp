

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Orders{
    string order;
    int oquantity;
};
struct Azar{
    string name;
    string date;
};

int main()
{
    //Orders to search max and min
    Orders array1[6] = {
        {"Максым", 50},
        {"Аралаш", 40},
        {"Тан", 60},
        {"Чалап", 90},
        {"Жарма", 85},
        {"Бозо", 70}
    };
    
    //producst for searching
    Azar array[6] = {
        {"Максым", "01.11.2022"},
        {"Аралаш", "01.03.2023"},
        {"Тан", "11.02.2023"},
        {"Чалап", "30.01.2023"},
        {"Жарма", "09.01.2023"},
        {"Бозо", "10.03.2023"}
    };
        
    //Menu for saleman by array
    string salemenu[] = {
        "1. Показать весь список товаров для продажи",
        "2. Искать товар",
        "3. Показать отчет по продаже",
        "4. Сделать заказ отсутствующего товара",
        "5. Удалить заказ",
        "6. Выход"
    };
    
    
    //Menu for Deliveryman by array
    string deliveryMenu[] = {
        "1. Показать список товаров для доставки ",
        "2. Показать доставленные заказы",
        "3. Доставить заказ:",
        "4. Показать количество доставленных товаров",
        "5. Показать количество заказанных товаров",
        "6. Показать мой заработок ",
        "7. Выход"
    };
    
    //Menu for Provider by array
    string providermenu[] = {
        "1. Показать список товаров для поставки ",
        "2. Показать количество поставляемого товара",
        "3. Показать товар с самым большим количеством заказов для доставки",
        "4. Показать товар с самым меньшим количеством заказов для доставки",
        "5. Выход"
    };
    
    int a;
    int checking = 1;
    while (checking <= 1) {
        cout << "Типы аккаунтов: " << endl << "1. Saleman" << endl << "2. Deliveryman" << endl << "3. Provider" << endl << endl;
        cout << "Для запуска программы, пожалуйста выберите тип аккаунта (напишите порядковый номер): ";
        
        if (cin >> a) {
            switch (a) {
                case 1:
                case 2:
                case 3:
                    checking++;
                    break;
                default:
                    cout << "Извините, но у нас только 3 типа аккаунта выберите один из них! " << endl << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else { 
            cout << "Извините, введенное значение не является числом! " << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    //login page
    string login, password;
    switch (a) {
    case 1:
        cout << endl << "Вы выбрали первый тип аккаунта Saleman." << endl << endl;
        break;
    case 2:
        cout << endl << "Вы выбрали второй тип аккаунта Deliveryman." << endl << endl;
        break;
    case 3:
        cout << endl << "Вы выбрали третий тип аккаунта Provider." << endl << endl;
        break;
    default:
        cout << endl << "Неверный ввод." << endl << endl;
        break;
    }



    while (true) {
        cout << "Login: ";
        cin >> login;
        cout << "password: ";
        cin >> password;
        if (login == "saleshoro" and password == "shorosale123" and a == 1) {
            break;
        }
        else if (login == "deliveryshoro" and password == "shorodelivery123" and a == 2) {
            break;
        }
        else if (login == "providershoro" and password == "shoroprovider123" and a == 3) {
            break;
        }
        else {
            cout << "Извините, неверный login или password" << endl;
        }
    }
    
    
    int menunumber;
    
    //Menu for saleman
    if(a == 1){
        cout << endl << "Приветствую дорогой, Продавец!" << endl;
        while(true){
            cout << endl << "Menu:" << endl;
            for(auto now: salemenu){
                cout << now << endl;
            }
            
            cout << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 6: ";
            while (!(cin >> menunumber) || menunumber < 1 || menunumber > 6) {
                cout << "Ошибка: пожалуйста, введите число от 1 до 6: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Вы выбрали пункт: " << salemenu[menunumber - 1] << endl;
        
        
            if(menunumber == 6){
                cout << endl << "Программа завершена, мы будем рады вашему возвращению!";
                return 0;
            }
            
            
            if (menunumber == 1) {
                string sale;
                ifstream sales("sale.txt");
                if (!sales.is_open()) {
                    cout << "Нам еще не пришло список товаров!" << endl;
                } else {
                    while (getline(sales, sale)) {
                        cout << sale << endl;
                    }
                    sales.close();
                }
                cout << endl << endl;
            }
            
            
            if (menunumber == 2) {
                searching: 
                cout << "Выберите как вы хотите искать товар: " << endl;
                cout << "1. По названию " << endl << "2. По дате" << endl; 
                cout << "Для выбора напишите порядковый номер: ";
                int temp;
                while(!(cin >> temp)) { // check for invalid input (non-integer)
                    cin.clear(); // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
                    cout << "Некорректный ввод. Пожалуйста, введите целое число: "; // ask again for integer input
                }
                if (temp == 1) {
                    string search;
                    cout << endl << "Напишите название товара для поиска: ";
                    cin >> search;
                    bool checker = true;
                    for (auto now : array) {
                        if (search == now.name) {
                            checker = false;
                            cout << "Результаты поиска: " << now.name << " " << now.date << endl << endl;
                        }
                    }
                    if(checker = true){
                        cout << "Не удалось найти такой товар!" << endl << endl;
                    }
                }
                else if (temp == 2) {
                    string search;
                    cout << endl << "Напишите дату для поиска: ";
                    cin >> search;
                    bool checker = true;
                    for (auto now : array) {
                        if (search == now.date) {
                            cout << "Результаты поиска: " << now.name << " " << now.date << endl << endl;
                            checker = false;
                        }
                    }
                    if(checker = true){
                        cout << "Не удалось найти такой товар!" << endl << endl;
                    }
                }
                else {
                    cout << "У нас есть только 2 типа поиска выберите один из них!" << endl;
                    
                    goto searching;
                }
            }
            
            
            if (menunumber == 3) {
                string solt;
                ifstream solts("solt.txt");
                if (!solts.is_open()) {
                    cout << "Нам еще не пришло список проданных товаров!" << endl;
                } else {
                    while (getline(solts, solt)) {
                        cout << solt << endl;
                    }
                    solts.close();
                }
                cout << endl << endl;
            }
            
            
            if (menunumber == 4) {
              string missproduct;
              int count = 0;
              ifstream missings("missitem.txt");
              if (!missings.is_open()) {
                cout << "Отсутствующих товаров нет" << endl;
              } else {
                cout << endl << "Список отсутствующих товаров: " << endl;
                while (getline(missings, missproduct)) {
                  cout << ++count << ". " << missproduct << endl; // use prefix increment to start counting from 1
                }
                missings.close();
                int product, quantity; // reorder variable declarations
                productPoint:
                cout << "Пожалуйста, введите порядковый номер отсутствующего товара, который вы хотите заказать: ";
                while (!(cin >> product) || product <= 0 || product > count) { // add bounds check and use logical OR
                  cout << "Ошибка!! Введенное вами данные некорректны." << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  goto productPoint;
                }
                quantityPoint:
                cout << "Пожалуйста, введите количество товаров, которое вы хотите заказать: ";
                while (!(cin >> quantity) || quantity <= 0) { // add bounds check
                  cout << "Ошибка!! Введенное вами данные некорректны." << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  goto quantityPoint;
                }
                // update missitem.txt
                ifstream missings("missitem.txt");
                ofstream temps("tempmiss.txt");
                int missItemInt = 1;
                string kerek;
                while (getline(missings, missproduct)) {
                  if (missItemInt == product) {
                    kerek = missproduct;
                    missItemInt++;
                    continue;
                    
                  }
                  temps << missproduct << endl;
                  missItemInt++;
                }
                missings.close();
                temps.close();
                remove("missitem.txt");
                rename("tempmiss.txt", "missitem.txt");
                // update need_materials.txt
                ifstream need("need_material.txt");
                ofstream temps2("temp2.txt");
                while (getline(need, missproduct)) {
                  temps2 << missproduct << endl;
                }
                temps2 << kerek << " " << quantity << endl;
                need.close();
                temps2.close();
                remove("need_material.txt");
                rename("temp2.txt", "need_material.txt");
              }
              cout << endl << endl;
            }
            
            
            if(menunumber == 5){
                string solt;
                ifstream solts("solt.txt");
                
                if(!solts.is_open()) {
                    cout << "Нам еще не пришло список проданных товаров!" << endl;
                }else{
                    while (getline(solts, solt)) {
                        cout << solt << endl;
                    }
                    
                }
                solts.close();
                cout << "Какой заказ вы бы хотели удалить?(Напишите порядковый номер) : ";
                int deletenumber;
                cin >> deletenumber;
                int line_number = 1;
                ofstream tempsolts("temp.txt");
                ifstream solts2("solt.txt");
                while (getline(solts2, solt)) {
                    if(line_number == deletenumber){
                        line_number++;
                        continue;
                    }
                    tempsolts << solt << endl;
                    
                    line_number++;
                    
                }
                
                solts.close();
                tempsolts.close();
                remove("solt.txt");
                rename("temp.txt", "solt.txt");
            }
            
        }
    }
    
    //Menu for Deliveryman
    if(a == 2){
        
        cout << "Приветствую дорогой, Доставщик!";
        while(true){
            cout << endl << "Menu:" << endl;
            for(auto now: deliveryMenu){
                cout << now << endl;
            }
            cout << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7: ";
            while (!(cin >> menunumber) || menunumber < 1 || menunumber > 7) {
                cout << "Ошибка: пожалуйста, введите число от 1 до 7: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Вы выбрали пункт: " << deliveryMenu[menunumber - 1] << endl;
            
            
            if(menunumber == 7){
                cout << endl << "Программа завершена, мы будем рады вашему возвращению!";
                return 0;
            }
            
            
            if(menunumber == 1){
                string solt;
                ifstream solts("solt.txt");
                if (!solts.is_open()) {
                    cout << "Нам еще не пришло список оборудований для доставки !" << endl;
                } else {
                    cout << "Cписок товаров для доставки: " << endl;
                    while (getline(solts, solt)) {
                        cout << solt << endl;
                    }
                    solts.close();
                }
                cout << endl << endl;
            }
            
            
            if(menunumber == 2){
                string delivered;
                ifstream delivereds("delivered.txt");
                if (!delivereds.is_open()) {
                    cout << "Нет доставленных товаров !" << endl;
                } else {
                    cout << "Cписок доставленных товаров: " << endl;
                    while (getline(delivereds, delivered)) {
                        cout << delivered << endl;
                    }
                    delivereds.close();
                }
                cout << endl << endl;
            }
            
            
            if(menunumber == 3){
                string zakaz;
                cout << "Какой заказ был доставлен? : ";
                cin >> zakaz;
                string sale;
                ifstream sales("sale.txt");
                ofstream temps("temp.txt");
                while (getline(sales, sale)) {
                    if(zakaz == sale){
                        continue;
                    }
                    temps << sale << endl;
                }
                sales.close();
                temps.close();
                remove("sale.txt");
                rename("temp.txt", "sale.txt");
                ifstream delivereds("delivered.txt");
                ofstream tempes("tempes.txt");
                string tempus;
                while(getline(delivereds, tempus)){
                    tempes << tempus << endl;
                }
                tempes << zakaz << endl;
                delivereds.close();
                tempes.close();
                remove("delivered.txt");
                rename("tempes.txt", "delivered.txt");
                
                cout << endl << endl;
            }
            
            
            if(menunumber == 4){
                string delivered;
                int count = 0;
                ifstream delivereds("delivered.txt");
                if (!delivereds.is_open()) {
                    cout << "Нет доставленных товаров !" << endl;
                } else {
                    while (getline(delivereds, delivered)) {
                        count++;
                    }
                    cout << "Kоличество доставленных товаров: " << count;
                    delivereds.close();
                }
                cout << endl << endl;
            }
            
            
            if(menunumber == 5){
                string solt;
                int count = 0;
                ifstream solts("solt.txt");
                if (!solts.is_open()) {
                    cout << "Нам еще не пришло список оборудований для доставки !" << endl;
                } else {
                    while (getline(solts, solt)) {
                        count++;
                    }
                    cout << "Kоличество заказанных товаров: " << count;
                    solts.close();
                }
                cout << endl << endl;
            }
            
            
            if(menunumber == 6){
                string delivered;
                int count = 0, stavka;
                cout << "Сколько вы получаете за каждую доставку ?: ";
                cin >> stavka;
                ifstream delivereds("delivered.txt");
                if (!delivereds.is_open()) {
                    cout << "Нет доставленных товаров !" << endl;
                } else {
                    while (getline(delivereds, delivered)) {
                        count++;
                    }
                    cout << "Вы заработали: " << count * stavka  << "сомов";
                    delivereds.close();
                }
                cout << endl << endl;
            }
        }
    }
    if(a == 3){
        cout << "Приветствую дорогой, Поставщик!";
        while(true){
            cout << endl << "Menu:" << endl;
            for(auto now: providermenu){
                cout << now << endl;
            }
            cout << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 5: ";
            
            while (!(cin >> menunumber) || menunumber < 1 || menunumber > 5) {
                cout << "Ошибка: пожалуйста, введите число от 1 до 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Вы выбрали пункт: " << providermenu[menunumber - 1] << endl;
            
            
            if(menunumber == 1){
                string need;
                ifstream needs("need_material.txt");
                if (!needs.is_open()) {
                    cout << "Нам еще не пришло список товаров для поставки !" << endl;
                } else {
                    cout << "Список товаров для поставки : " << endl;
                    while (getline(needs, need)) {
                        cout << need << endl;
                    }
                    needs.close();
                }
                cout << endl << endl;
            }
            
            
            if(menunumber == 2){
                string need;
                int count = 0;
                ifstream needs("need_material.txt");
                if (!needs.is_open()) {
                    cout << "Нам еще не пришло список товаров для поставки !" << endl;
                } else {
                    
                    while (getline(needs, need)) {
                        count++;
                    }
                    needs.close();
                }
                cout << "Количество поставляемого товара : " << count << endl;
                cout << endl << endl;
            }
            
            
            if(menunumber == 3){
                int max = 0;
                for(auto now: array1){
                    if(now.oquantity > max){
                        max = now.oquantity;
                    }
                }
                for(auto now: array1){
                    if(now.oquantity == max){
                        cout << "Товар с самым большим количеством заказов для доставки: " << now.order << " " << now.oquantity << "заказов" <<endl;
                    }
                }
                cout << endl << endl;
            }
            
            
            if(menunumber == 4){
                int min = 100;
                for(auto now: array1){
                    if(now.oquantity < min){
                        min = now.oquantity;
                    }
                }
                for(auto now: array1){
                    if(now.oquantity == min){
                        cout << "Товар с самым меньшим количеством заказов : " << now.order << " " << now.oquantity << "заказов" << endl;
                    }
                }
                cout << endl << endl;
            }
            
            
            if(menunumber == 5){
                cout << endl << "Программа завершена, мы будем рады вашему возвращению!";
                return 0;
            }

        }
    }
    
    return 0;
}