//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* prev;

public:
    ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrev);


    void setPrev(ListenElement* pPrev);
    void setData(Student pData);
    void setNext(ListenElement* pNext);

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const;

    bool loescheElement(unsigned int matNr);
};

#endif
