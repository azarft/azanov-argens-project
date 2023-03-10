

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Menu for saleman by array
    string salemenu[] = {
    "1. Показать весь список товаров для продажи",
    "2. Искать товар",
    "3. Показать отчет по продаже",
    "4. Сделать заказ отсутствующего товара",
    "5. Удалить заказ",
    "6. Выход"
    };
    
    
    //choosing accaunt type 
    start: cout << "Типы аккаунтов: " << endl << "1.Saleman" << endl << "2.Deliveryman" << endl << "3.Provider" << endl << endl;
    cout << "Для запуска программы, пожалуйста выберите тип аккаунта(напишите порядковый номер): ";
    int a; 
    cin >> a;
    
    
    //answer for wrong accaunt type
    if(a > 3 or 1 > a){
        cout << "Извините, но у нас только 3 типа аккаунта выберите один из них! " << endl << endl;
        goto start;
    }

    //login page
    signin:
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
    cout << "Login: ";
    cin >> login;
    cout << "password: ";
    cin >> password;



    //login data check
    int pass = 0;  // integer for login and password check
    if(login == "saleshoro" and password == "shorosale123"){
        pass++;
    }
    if(login == "deliveryshoro" and  password == "shorodelivery123"){
        pass++;
    }
    if(login == "providershoro" and password == "shoroprovider123"){
        pass++;
    }
    if(pass == 0){
        cout << "Извините, неверный login или password" << endl;
        goto signin;
    }
    
    int menunumber;
    //menu for saleman
    if(a == 1){
        cout << endl << "Приветствую дорогой, Продавец!" << endl;
        while(1 < 2){
            for(auto now: salemenu){
                cout << now << endl;
            }
            
            cout << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 6: ";
            cin >> menunumber;
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
            if(menunumber == 2){
                searching: cout << "Выберите как вы хотите искать товар: " << endl;
                cout << "1. По названию " << endl << "2. По дате" << endl; 
                cout << "Для выбора напишите порядковый номер: ";
                int temp;
                cin >> temp;
                if(temp == 1){
                    string search;
                    cout << endl << "Напишите название товара для поиска: ";
                    cin >> search;
                    
                }
                if(temp == 2){
                    string search;
                    cout << endl << "Напишите дату для поиска: ";
                    cin >> search;
                    
                }
                if(temp != 1 and temp != 2){
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
            if(menunumber == 4){
                string missproduct;
                ifstream missings("missitem.txt");
                if (!missings.is_open()) {
                    cout << "Отсутствующих товаров нет" << endl;
                } else {
                    cout << endl << "Список отсутствующих товаров: " << endl;
                    while (getline(missings, missproduct)) {
                        cout << missproduct << endl;
                    }
                    missings.close();
                    int quantity, product;
                    cout << "Пожалуйста напишите какой отстустующий товар вы хотите заказать(напишите порядковый номер): ";
                    cin >> product;
                    cout << "Пожалуйста напишите сколько таких товаров вы хотите заказать: ";
                    cin >> quantity;
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
    
    return 0;
}
