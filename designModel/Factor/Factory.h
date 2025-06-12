#ifndef FACTORY_H
#define FACTORY_H
class Product
{
public:
    Product() {}
    virtual ~Product() {}
};

class ConcreateProduct : public Product
{
public:
    ConcreateProduct() {};
    virtual ~ConcreateProduct() {};
};

class Creator
{
public:
    Creator() {};
    virtual ~Creator() {};

    void AnOperation();

protected:
    virtual Product *FactorMethod() = 0;
};

class ConcreateCreator : public Creator
{
public:
    ConcreateCreator();
    virtual ~ConcreateCreator();

protected:
    virtual Product *FactoryMethod();
};

#endif