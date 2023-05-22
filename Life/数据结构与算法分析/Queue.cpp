#include "Queue.h"

Queue::Queue()
    : myFront(0), myBack(0)
{
}

bool Queue::empty() const
{
    return myFront == myBack;
}

void Queue::enqueue(const ElementType& value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
    if (newBack != myFront)     // 队列没有满
    {
        myArray[newBack] = value;
        myBack = newBack;
    }
    else
    {
        std::cerr << "*** Queue full -- can't add new value ***\n";
        "Must increase value of QUEUE_CAPACITY in Queue.h\n";
        exit(1);
    }
}

void Queue::dequeue()
{
    if (!empty())
    {
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    }
    else
    {
        std::cerr << "*** Queue is empty -- can't remove a value ***\n";
    }
}

ElementType Queue::front() const
{
    if (!empty())
    {
        return myArray[myFront];
    }
    else
    {
        std::cerr << "*** Queue is empty -- returning garbage value ***\n";
        return ElementType();
    }
}

void Queue::display(std::ostream& out) const
{
    for (int i = myFront; i != myBack; i = (i + 1) % QUEUE_CAPACITY)
        out << myArray[i] << " ";
    out << std::endl;
}
