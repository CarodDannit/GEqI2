#ifndef ILISTABLE_H
#define ILISTABLE_H

class IListable { // "Interface" class for list-able stuff
public:
    static void printListLabel() {};
    virtual void printListItem() = 0; // Virtual function
    virtual ~IListable() {}
};

#endif // !

