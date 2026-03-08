//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}
/**
 * @brief Fuegt ein neues Listenelement am Anfang der Liste ein.
 *
 * Erstellt ein neues Listenelement mit den übergebenen Student-Daten.
 * Falls die Liste leer ist, wird das neue Element sowohl `front` als auch `back`.
 * Andernfalls wird das neue Element vor dem bisherigen ersten Element eingefügt.
 *
 * @param pData Ein Objekt der Klasse Student, das eingefügt werden soll.
 */

void Liste::pushFront(Student pData)
{
	ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

	if (front == nullptr)
	{ //if the list is empty
		front = neuesElement;
		back = neuesElement;
	} else {
		front->setPrev(neuesElement);
		front=neuesElement;
	}
}

/**
 * @brief Fügt ein neues Listenelement am Ende der doppelt verketteten Liste hinzu.
 *
 * @param pData Ein Objekt der Klasse Student, das eingefügt werden soll.
 *
 * Das neue Element wird hinten an die Liste angehängt. Dabei werden sowohl
 * der next-Zeiger des bisherigen letzten Elements als auch der prev-Zeiger
 * des neuen Elements gesetzt.
 */

void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr , back );

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Entfernt das erste Listenelement aus der doppelt verketteten Liste.
 *
 * Wenn die Liste nur ein Element enthält, wird sowohl front als auch back
 * auf nullptr gesetzt. Andernfalls wird das erste Element entfernt und der
 * prev-Zeiger des neuen ersten Elements auf nullptr gesetzt.
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr); //doubly linked list
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein gObjekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 *
 *
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element und ruft für jedes Element die Methode `ausgabe()` des Studentenobjekts auf.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Gibt die Liste von letzten bis zum ersten Element aus
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}

/**
 * @brief Loescht ein Listenelement anhand der Matrikelnummer.
 *
 * Sucht nach einem Listenelement mit der gegebenen Matrikelnummer
 * und entfernt es aus der Liste.
 *
 * - Wenn es das einzige Element ist, werden `front` und `back` auf `nullptr` gesetzt.
 * - Wenn es das erste oder letzte Element ist, wird `front` oder `back` entsprechend angepasst.
 * - Wenn es ein mittleres Element ist, werden die Nachbarn miteinander verknüpft.
 *
 * @param matNr Die Matrikelnummer des zu loeschenden Studenten.
 * @return true, wenn das Element gefunden und geloescht wurde, sonst false.
 */

bool Liste::loescheElement(unsigned int matNr)
{
	ListenElement* cursor = front;

	while (cursor != nullptr)
	{
		if ( cursor->getData().getMatNr() == matNr)
		{
			if ( cursor == front && cursor == back) // only one val
			{
				delete cursor;
				front = nullptr;
				back = nullptr;
				return true;
			}
			else if (cursor == front) // ilk eleman
			{
			    front = front->getNext();
			    if (front) front->setPrev(nullptr);
			    else back = nullptr;
			    delete cursor;
			    return true;
			}
			else //if we delete middle var
			{
				cursor->getPrev()->setNext(cursor->getNext());
				cursor->getNext()->setPrev(cursor->getPrev());
				delete cursor;
			}
			return true;
	    }
		cursor = cursor-> getNext();
}
	return false;
}
