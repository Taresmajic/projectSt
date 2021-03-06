#ifndef VEKTOR_H_
#define VEKTOR_H_
#include<functional>

#include "List.h"
#include "osoba.h"
#include "student.h"
#include "teacher.h"
#include "subject.h"

auto Poprezimenus=[](student a,student b){
  return a.getLastName()<b.getLastName();
};

auto Poprezimenut=[](teacher a,teacher b){
  return a.getLastName()<b.getLastName();
};

auto Poid=[](subject a,subject b){
  return a.getId()<b.getId();
};

template<typename T>
class Vektor{
private:
int cap_;
int size_;
T* elem_;
public:
 int size()const{return size_;}
 bool isFull(){return cap_==size_;}
 Vektor(){}
 Vektor(int cap=10):cap_(cap),size_(0),elem_(new T[cap_]){}
 Vektor(const Vektor<T>& b){
   cap_=b.cap_;
   size_=b.size_;
   elem_=new T[cap_];
   for(int i=0;i<b.size_;++i)
     elem_[i]=b.elem_[i];
 }
 void push(const T& b){
     if(isFull())
     throw std::string("puna");
   elem_[size_++]=b;
 }
 Vektor<T> operator=(const List<T>& b){
  cap_=b.size()+1;
  size_=0;
  elem_=new T[cap_];
  for(int i=0;i<b.size();++i)
    push(b[i]);
 return *this;
 }

 T& operator[](int indeks){
   return elem_[indeks];
 }
  const T& operator[](int indeks)const{
   return elem_[indeks];
 }
   void sort(std::function<bool(T,T)> lambda){
     for(int i=size();i>1;--i)
     {for(int j=1;j<size();j++)
         if(lambda(elem_[j],elem_[j-1]))
         std::swap(elem_[j-1],elem_[j]);
      }
   }
 ~Vektor(){
   delete [] elem_;
 }
};


#endif
