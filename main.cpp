#include <iostream>


using namespace std;

class MyCircularQueue {
public:
    int size_queue; //Размер циклической очереди
    int *head; //Создаем указатель, который может хранить только адрес переменной типа int, но пока данный указатель не ссылается ни на какой объект и хранит случайное значение
    int *tail; //Указатель на последний входящий элемент - изменяется
    int *beginQue; //"Фиксированный" указатель на начало очереди - не  двигается
    int *endQue; //"Фиксированный" указатель на конец очереди - не двигается


    MyCircularQueue(int volume, int *phead, int *ptail, int *pbegin, int *pend) //Инициализирует объект с размером очереди volume
    {

        int *Que = new int[volume];
        phead = Que;
        ptail = Que;
        pbegin = Que;
        pend = pbegin + volume -1;

        size_queue = volume;
        head = phead;
        tail = ptail;
        beginQue = pbegin;
        endQue = pend;

//        delete [] Que;
//        Que = nullptr;
//        beginQue = nullptr;
//        endQue = nullptr;
//        head = nullptr;
//        tail = nullptr;
    }

    ~MyCircularQueue() {}

    void PrintQue() // Печать адресов - проверка
    {
        cout << "begin = " << beginQue << "\n";
        cout << "head = " << head << "\n";
        cout << "tail = " << tail << "\n";
        cout << "end = " << endQue << "\n";
    }

    void PrQue() // Печать элементов - проверка
    {
        for (int i=0; i<size_queue; i++)
        {
            cout << *(beginQue+i) << "\n";
        }
    }

    bool enQueue(int value) // Вставляет элемент в циклическую очередь. Возвращает true, если операция прошла успешно
    {
        if(tail == beginQue && head == beginQue && *tail == '\0') // Для первого элемента в очереди при первом вхождении
        {
            *tail = value;
        }

        else if(tail < endQue) // Ввод данных в очередь до его конца, включая последний элемент
        {
            tail++;
            if(tail != head)
                *tail = value;
            else
            {
                tail--;
                cout << "You cannot add an element\n" << "Q is full\n";
            }
        }

        else if(tail == endQue && head != beginQue) // Дошли до конца очереди и возвращаемся в начало для заполнения свободных ячеек
        {
            tail = beginQue;
            *tail = value;
        }

        else if(head == beginQue && tail == endQue)
        {
            cout << "You cannot add an element\n" << "Q is full\n";
        }

        return true;
    }

    bool deQueue() // Удаляет элемент из циклической очереди. Возвращает true, если операция прошла успешно
    {
        if(*head == '\0' && *tail == '\0')
            cout << "Q is empty\n";

        else if(head < endQue)
        {
            *head = '\0';
            head++;
        }
        else if(head == endQue)
        {
            head = beginQue;
            *head = '\0';
        }

        return true;
    }

    int Front() // Получает первый элемент из очереди. Если очередь пуста, возвращает -1
    {
        if(*head == '\0' && *tail == '\0')
        {
            cout << "Q is empty\n";
            return -1;
        }

        return *beginQue;
    }

    int Rear() // Получает последний элемент из очереди. Если очередь пуста, возвращает -1
    {
        if(*head == '\0' && *tail == '\0')
        {
            cout << "Q is empty\n";
            return -1;
        }

        return *endQue;
    }

    bool isEmpty() // Проверяет, пуста ли циклическая очередь или нет
    {
        if(*head == '\0' && *tail == '\0')
        {
            cout << "Q is empty\n";
            return -1;
        }
        cout << "Q is NOT empty\n";
        return 1;
    }

    bool isFull() // Проверяет, заполнена ли циклическая очередь или нет
    {
        if(head == beginQue && tail == endQue)
        {
            cout << "Q is full\n";
            return -1;
        }
        else if ((tail + 1) == head)
        {
            cout << "Q is full\n";
            return -1;
        }

        return 1;
    }

};


int main()
{
    int sz_que{2};
    int ptrhead, ptrtail, ptrbegin, ptrend;
    MyCircularQueue CircularQue(sz_que, &ptrhead, &ptrtail, &ptrbegin, &ptrend); //Создание объекта класса с размером очереди = 6
    int x;

    cout << "1 - печать указателей\n" << "2 - печать элементов\n" << "3 - ввод элементов\n";
    cout << "4 - удаление элементов\n" << "5 - печать первого элемента очереди\n" << "6 - печать последнего элемента очереди\n";
    cout << "7 - проверка пустоты очереди\n" << "8 - проверка заполненности очереди\n";
    cout << "\vВведите номер операции = ";

    while(cin>>x)
    {
        switch(x)
        {
            case 1:
            {
                CircularQue.PrintQue();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 2:
            {
                CircularQue.PrQue();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 3:
            {
                int value_input;
                cout << "\vВведите элемент = ";
                cin >> value_input;
                CircularQue.enQueue(value_input);
                cout << "\vВведите номер операции = ";
                break;
            }
            case 4:
            {
                CircularQue.deQueue();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 5:
            {
                CircularQue.Front();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 6:
            {
                CircularQue.Rear();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 7:
            {
                CircularQue.isEmpty();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 8:
            {
                CircularQue.isFull();
                cout << "\vВведите номер операции = ";
                break;
            }
            default:
            {
                cout << "Ошибка ввода\n";
                cout << "\vВведите номер операции = ";
                break;
            }
        }
    }


    return 0;
}

