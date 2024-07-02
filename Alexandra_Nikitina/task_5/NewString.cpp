#include <iostream>
#include <cstring>
#include "NewString.h"


void NewString::Set(const char* s) {
    
    if (str != nullptr) {
        delete[] str;
        str = nullptr;
    }
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    StrLength = strlen(str);
}

const char* NewString::GetChar() const {

    return str;
}

int NewString::GetInt() const {

    return StrLength;
}

const NewString& NewString::operator=(const NewString& ObjectRef){

    delete[] str;
    str = nullptr;

    this->StrLength = ObjectRef.StrLength;      
    this->str = new char[this->StrLength +1];

    for(int i{0}; i<StrLength; ++i){
        this->str[i] = ObjectRef.str[i];         
    }
    str[StrLength] = '\0';      
    return *this;                        
    }

bool NewString::operator==(const NewString& other) const {

    return strcmp(GetChar(), other.GetChar()) == 0;
}

NewString::NewString(){

    str = nullptr;
    str = new char[1];
    str[0]= '\0';
}

NewString::NewString(const NewString& LinkString){

    if(LinkString.str){
        StrLength = strlen(LinkString.str);
        str = new char[StrLength + 1];  
        strcpy(str, LinkString.str);
        str[StrLength] = '\0'; 
    }
    else {
        str = nullptr;
        StrLength = 0;
    }
}

NewString::NewString(const NewString& LinkString, int pos, int len){

    str = new char[len + 1];
    strncpy(str, LinkString.str + pos, len);
    str[len] = '\0';
}

NewString::NewString(char* s){
    
    str = nullptr;
    if(s == nullptr){ 
        str = new char[1];
        str[0] = '\0';
    }
}

NewString::NewString(const char* buffer){

    str = nullptr;
    StrLength = strlen(buffer);
    str = new char[StrLength + 1];
    strcpy(str, buffer);
    str[StrLength] = '\0';
}

NewString::NewString(int length, char FillChar){

    StrLength = length;
    str = new char[length + 1];

    for(int i{0}; i < StrLength; ++i){
        str[i] = FillChar;
    }

    str[StrLength] = '\0';
}

NewString::NewString(const char* start, const char* end){

    StrLength = end - start;
    str = new char[StrLength + 1];
    strncpy(str, start, StrLength);
    str[StrLength] = '\0';
}

NewString::NewString(std::initializer_list<char> initializer){

    StrLength = initializer.size();
    str = new char[StrLength + 1];
    int i{0};
    for(char c : initializer){ 
        str[i++] = c;
    }
    str[StrLength] = '\0';
}

NewString::NewString(NewString&& object) {

    StrLength = object.StrLength;
    str = object.str;
    object.StrLength = 0;
    object.str = nullptr;
}

void NewString::push_back(char c) {

    char* newStr = new char[StrLength + 2];
    strcpy(newStr, str);
    newStr[StrLength] = c;
    newStr[StrLength + 1] = '\0';
    delete[] str;
    str = newStr;
    StrLength++;
}

int NewString::size() const {

    return StrLength;
}

int NewString::find(const char* subStr) const {

    char* found = strstr(str, subStr);
    if (found) {
        return found - str;
    }
    return -1;  
}

char NewString::back() const {

    if (StrLength > 0) {
        return str[StrLength - 1];
    }
    return '\0';
}

void NewString::clear() {

    delete[] str;
    str = new char[1];
    str[0] = '\0';
    StrLength = 0;
}