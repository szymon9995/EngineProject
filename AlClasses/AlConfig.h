#pragma once
#include <iostream>
#include <vector>

typedef struct ALLEGRO_CONFIG ALLEGRO_CONFIG;

class AlConfig//klasa do przetrzymywania configu (pliku .cfg ladowanie i zapis)
{
private:
    ALLEGRO_CONFIG *config;
    std::string name;
    bool creation;
public:
    AlConfig(std::string name);//Konstruktor do configu, podajemy nazwe pliku konfiguracyjnego do załadowania/stworzenia
    ~AlConfig();//Destruktor configu
    
    void addConfigSection(std::string section_name);//dodanie skecji z pliku configuracyjnym

    void setConfigValue(std::string section_name,std::string key,std::string value);//ustawienie/stworzneie wartosci do danego klucza w danej sekcji, przeciąznono na wiele zmiennych, przeciozana funckja dla kilku typow
    void setConfigValue(std::string section_name,std::string key,const char* value);
    void setConfigValue(std::string section_name,std::string key,int value);
    void setConfigValue(std::string section_name,std::string key,long value);
    void setConfigValue(std::string section_name,std::string key,double value);
    void setConfigValue(std::string section_name,std::string key,bool value);

    std::string getConfigValue(std::string section_name,std::string key);//dostanie wartosci, w formie stringa, znadjujaca sie w podanej sekcji pod podanym kluczem
    std::vector<std::string> getConfigValueRows(std::string section_name);
    std::vector<std::string> getConfigValueRows(std::string section_name,std::string key,int n);

    bool isFirstCreation(); //zwraca prawde jezeli poraz pierwszy tworzymy plik
};