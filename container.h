#pragma once
#include<iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include<exception>
#include<string>

class Box
{
public:
    virtual ~Box() = default;
    virtual void print() const = 0;
    virtual const std::type_info& type() const = 0;
    virtual bool less(const Box& other) const = 0;
};

template <typename T>
class Boxed : public Box
{
    T value;
public:
    Boxed(const T& v) : value(v) {}

    void print() const override
    {
        std::cout << value;
    }

    const std::type_info& type() const override
    {
        return typeid(value);
    }

    bool less(const Box& other) const override
    {
        if (type() == other.type())
        {
            const Boxed<T>& derived = static_cast<const Boxed<T>&>(other);
            return value < derived.getVal();
        }
        else
        {
            return type().before(other.type());
        }
    }

    const T& getVal() const
    {
        return value;
    }
};