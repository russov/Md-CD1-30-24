#include <iostream>
#include <cstring>
#include "NewString.h"


int main(){

    NewString s1;
    NewString s2;
    s2 = s1;
    NewString s3 = s2;
    NewString s4("ffjfj");

    return 0;
}

// class NewString {
    
//     public:

//     NewString();
//     NewString(const NewString& LinkString);
//     NewString(const NewString& LinkString, int pos, int len);
//     NewString(char* s);
//     NewString(const char* buffer);
//     NewString(int length, char FillChar);
//     NewString(const char* start, const char* end);
//     NewString(std::initializer_list<char> initializer);
//     NewString(NewString&& object);
//     const NewString& operator=(const NewString& ObjectRef);
//     bool operator==(const NewString& other) const;

//     ~NewString(){
//         delete[] str;
//     };

    // void Set(const char* s) {
    //     if (str != nullptr) {
    //         delete[] str;
    //         str = nullptr;
    //     }
    //     str = new char[strlen(s) + 1];
    //     strcpy(str, s);
    //     StrLength = strlen(str);
    // }

    // const char* GetChar() const {
    //     return str;
    // }

    // int GetInt() const {
    //     return StrLength;
    // }

//     private:
//         char* str = nullptr;
//         int StrLength = 0;

// };

// const NewString& NewString::operator=(const NewString& ObjectRef){

//         delete[] str;
//         str = nullptr;

//         this->StrLength = ObjectRef.StrLength;       //нашу переменную текущего объекта, в которую копируется информация, инициализируем тем же значением StrLength объекта, из которого мы копируем
//         this->str = new char[this->StrLength +1];
//         for(int i{0}; i<StrLength; ++i){
//             this->str[i] = ObjectRef.str[i];         //все значения переписываем из копируемого объекта в копируемый объект
//         }
//         str[StrLength] = '\0';
        
//         return *this;                                //возвращаем ссылку на текущий объект
//     }

// bool NewString::operator==(const NewString& other) const {
//     return strcmp(GetChar(), other.GetChar()) == 0;
// }

// // default (1)	
// NewString::NewString(){

//     str = nullptr;
//     str = new char[1];
//     str[0]= '\0';
// }

// //copy (2)
// NewString::NewString(const NewString& LinkString){

//     if(LinkString.str){  //указатель на массив символов (строку), хранящуюся в другом объекте класса
//         StrLength = strlen(LinkString.str);
//         str = new char[StrLength + 1]; //1 байт для нуля в конце
//         strcpy(str, LinkString.str); //Функция копирует Си-строку srcptr, включая завершающий нулевой символ в строку назначения, на которую ссылается указатель str
//     }
//     else{
//         str = nullptr;
//     }
// }

// //substring (3)
// NewString::NewString(const NewString& LinkString, int pos, int len){

//     str = new char[len + 1];
//     strncpy(str, LinkString.str + pos, len);
//     str[len] = '\0';
// }

// //from c-string (4)	
// NewString::NewString(char* s){
    
//     str = nullptr;
//     if(s == nullptr){  // && str == nullptr){
//         str = new char[1];
//         str[0] = '\0';
//     }
// }

// //from buffer (5)	
// NewString::NewString(const char* buffer){

//     StrLength = strlen(buffer);
//     str = new char[StrLength + 1];
//     strcpy(str, buffer);
// }

// //fill (6)	
// NewString::NewString(int length, char FillChar){

//     StrLength = length;
//     str = new char[length + 1];

//     for(int i{0}; i < StrLength; ++i){
//         str[i] = FillChar;
//     }

//     str[StrLength] = '\0';
// }

// //range (7)
// NewString::NewString(const char* start, const char* end){

//     StrLength = end - start;
//     str = new char[StrLength + 1];
//     strncpy(str, start, StrLength);
//     str[StrLength] = '\0';
// }

// //initializer list (8)
// NewString::NewString(std::initializer_list<char> initializer){

//     StrLength = initializer.size();
//     str = new char[StrLength + 1];
//     int i{0};
//     for(char c : initializer){  //цикл, который проходит по каждому символу в строке initializer (предполагается, что это массив символов), и добавляет каждый символ в объект класса.
//         str[i++] = c;
//     }
//     str[StrLength] = '\0';
// }

// //move (9)
// NewString::NewString(NewString&& object) {// noexcept{    //осуществляется перемещение объекта object в объект, который создается конструктором. С помощью && указывается на это перемещение.

//     StrLength = object.StrLength;
//     str = object.str;
//     object.StrLength = 0;
//     object.str = nullptr;
// }
