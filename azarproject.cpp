

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
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
    signin:
    //login page
    string login, password;
    if(a == 1){
        cout << endl << "Вы выбрали первый тип аккаунта Saleman." << endl << endl;
        cout << "Login: ";
        cin >> login;
        cout << "password: ";
        cin >> password;
    }
    if(a == 2){
        cout << endl << "Вы выбрали второй тип аккаунта Deliveryman." << endl << endl;
        cout << "Login: ";
        cin >> login;
        cout << "password: ";
        cin >> password;
    }
    if(a == 3){
        cout << endl << "Вы выбрали третий тип аккаунта Provider." << endl << endl;
        cout << "Login: ";
        cin >> login;
        cout << "password: ";
        cin >> password;
    }
    
    
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
    
    
    return 0;
}