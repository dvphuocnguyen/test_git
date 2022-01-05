#include "QLSV.h"
#include<iostream>
using namespace std;
int QLSV::Length()
{
    return this->_Length;
}
void QLSV::Length(int value)
{
    this->_Length = value;
}
QLSV::QLSV()
{
    this->p = nullptr;
    this->_Length = 0;
}
QLSV::~QLSV()
{
    delete[] this->p;
}
void QLSV::Add(SV s)
{
    if (this->_Length==0)
    {
        this->p=new SV[this->_Length + 1];
        *(this->p + this->_Length)=s;
    }
    else{
        SV*temp=new SV[this->_Length];
        for(int i=0;i<this->_Length;i++){
            *(temp+i)=*(this->p+i);
        }
        delete[] this->p;
        this->p=new SV[this->_Length+1];
        for(int i=0;i<this->_Length;i++)
            *(this->p+i)=*(temp+i);
        *(this->p+this->_Length)=s;
        }
        this->_Length++;
    }
    


void QLSV::Show()
{
    for (int i = 0; i < this->_Length; i++)
    {
        (*(this->p+i)).Show();
    }
    
}
void QLSV::Update(int m)
{
    int index = IndexOf(m);
    if(index>=0){
        double d;
        cout <<"DTB= ";
        cin>>d;
        (this->p+index)->DTB(d);
    }
}
int QLSV::IndexOf(SV s)
{
    int index = -1;
    return index;
}
void QLSV::Delete (SV s)
{
    int index = IndexOf(s.MSSV());
    if (index >= 0)
    {
        if (this->_Length==1)
        {
            delete[] this->p;
        }
    }
    else{
        SV *temp=new SV[this->_Length];
        for(int i=0;i<this->_Length;i++)
            *(temp+i)=*(this->p+i);
        delete[] this->p;
        this->p = new SV[this->_Length-1];
        for (int i = 0; i < this->_Length; ++i)
        {
             if(i<index){
                 *(this->p+i)=*(temp+i);
             }
             else{
                 *(this->p+i)=*(temp+i+1);
             }
        }
          
    }
    this->_Length--;
}

void QLSV::ABC()
{
    return "ABC";
}