#pragma once

#include"container.h"
class PyList
{
    std::vector<std::shared_ptr<Box>> data;
public:
    PyList() {}
    template <typename T>
    void append(const T& val)
    {
        data.push_back(std::make_shared<Boxed<T>>(val));
    }

    template <typename T>
    int count(const T& val) const
    {
        int count = 0;
        for (auto& obj : data)
        {
            Boxed<T>& temp = static_cast<Boxed<T>&>(*obj);
            if (temp.getVal() == val)
                count++;
        }
        return count;
    }

    void extend(const PyList& other)
    {
        if (data.size()==0 && other.data.size()==0)
            throw std::out_of_range("Both are null nothing to extend");
        for (auto& obj : other.data)
        {
            data.push_back(obj);
        }
    }

    template <typename T>
    int index(const T& val) const
    {
        int idx = 0;
        for (auto& obj : data)
        {
            Boxed<T>& temp = static_cast<Boxed<T>&>(*obj);
            if (val==temp.getVal())
                return idx;
            idx++;
        }
        throw std::out_of_range("Not present in the list.");
    }

    template <typename T>
    void insert(long long int i, const T& val)
    {
        if (abs(i) >= data.size())
            throw std::out_of_range("Out of range");
        std::shared_ptr<Box> temp = std::make_shared<Boxed<T>>(val);
        std::vector<std::shared_ptr<Box>> data_temp;

        if (i >= 0)
        {
            for (long long int j = 0;j < i;j++)
            {
                data_temp.push_back(data[j]);
            }
            data_temp.push_back(temp);
            for (long long int j = i;j < data.size();j++)
            {
                data_temp.push_back(data[j]);
            }
        }
        else
        {
            for (long long int j = 0;j < data.size() + i;j++)
            {
                data_temp.push_back(data[j]);
            }
            data_temp.push_back(data[data.size() + i]);
            for (long long int j = data.size()+i;j < data.size();j++)
            {
                data_temp.push_back(data[j]);
            }
        }
        
        data = data_temp;
    }

    std::shared_ptr<Box> pop()
    {
        std::shared_ptr<Box> temp = data.back();
        data.pop_back();
        return temp;
    }

    std::shared_ptr<Box> pop(size_t i)
    {
        std::vector<std::shared_ptr<Box>> data_temp;
        for (size_t j = 0;j < i;j++)
        {
            data_temp.push_back(data[j]);
        }
        std::shared_ptr<Box> temp = data[i];
        for (size_t j = i+1;j < data.size();j++)
        {
            data_temp.push_back(data[j]);
        }
        data = data_temp;
        return temp;
    }

    template <typename T>
    void remove(const T& val)
    {
        int idx = 0;
        bool found = false;
        std::vector<std::shared_ptr<Box>> data_temp;
        for (int i = 0;i < data.size();i++)
        {
            Boxed<T>& temp = static_cast<Boxed<T>&>(*data[i]);
            if (temp.getVal() == val)
            {
                found = true;
                idx = i;
                break;
            }
            data_temp.push_back(data[i]);
        }
        for (int i = idx + 1;i < data.size();i++)
        {
            data_temp.push_back(data[i]);
        }
        if (data_temp.size() < data.size())
            data = data_temp;
        else
            throw std::out_of_range("Value not present");
    }

    void reverse()
    {
        std::vector<std::shared_ptr<Box>> data_temp;
        for (int i = 0;i < data.size();i++)
        {
            data_temp.push_back(data[data.size() - 1 - i]);
        }
        data = data_temp;
    }

    void sort(bool reverse = false)
    {
        if (!reverse)
        {
            std::sort(data.begin(), data.end(), [](const std::shared_ptr<Box>& a, const std::shared_ptr<Box>& b)
                {
                return a->less(*b);
                }
            );
        }
        else
        {
            std::sort(data.begin(), data.end(), [](const std::shared_ptr<Box>& a, const std::shared_ptr<Box>& b)
                {
                    return b->less(*a);
                }
            );
        }
    }

    void clear()
    {
        while (data.size() != 0)
        {
            data.pop_back();
        }
    }

    PyList operator+(const PyList& other) const
    {
        PyList p;
        p.extend(*this);
        p.extend(other);
        return p;
    }

    template <typename T>
    bool contains(const T& val) const
    {
        if (data.size() == 0)
            throw std::out_of_range("No value present");
        for (int i = 0;i < data.size();i++)
        {
            Boxed<T>& temp = static_cast<Boxed<T>&>(*data[i]);
            if (temp.getVal() == val)
            {
                return true;
            }
        }
        return false;
    }

    std::shared_ptr<Box> operator[](long long int i) const
    {
        if (abs(i) >= data.size())
            throw std::out_of_range("Index out of range");
        if (i >= 0)
        {
            return data[i];
        }
        else
        {
            return data[data.size() + i];
        }
    }

    size_t len() const
    {
        return data.size();
    }

    template <typename T>
    void setitem(long long int i, const T& val)
    {
        if (abs(i) >= data.size())
            throw std::out_of_range("Index out of range");
        if(i>=0)
        data[i] = std::make_shared<Boxed<T>>(val);
        else
        data[data.size()+i]= std::make_shared<Boxed<T>>(val);
    }

    auto begin()
    { 
        if (data.size() == 0)
            throw std::out_of_range("No data present");
        return data.begin();
    }

    auto end()
    {
        if (data.size() == 0)
            throw std::out_of_range("No data present");
        return data.end();
    }

    auto begin() const
    {
        if (data.size() == 0)
            throw std::out_of_range("No data present");
        return data.begin();
    }

    auto end() const
    {
        if (data.size() == 0)
            throw std::out_of_range("No data present");
        return data.end();
    }

    PyList slice(long long int start, long long int end) const
    {
        if (data.size() == 0)
            throw std::out_of_range("Empty List cannot be sliced");
        PyList p;
        if (start >= 0 && end >= 0)
        {
            if (start == end)
                throw std::out_of_range("Cannot be sliced");
            if (start < end)
            {
                for (int i = start;i < end;i++)
                {
                    p.data.push_back(data[i]);
                }
            }
            else
                throw std::out_of_range("Cannot be sliced");
        }

        else if (start < 0 && end >= 0)
        {
            if (data.size() + start == end)
                throw std::out_of_range("Cannot be sliced");
            if (data.size() + start < end)
            {
                for (int i = data.size() + start;i < end;i++)
                    p.data.push_back(data[i]);
            }
            else
                throw std::out_of_range("Cannot be sliced");
        }
        else if (start >= 0 && end < 0)
        {
            if (start == data.size() + end)
                throw std::out_of_range("Cannot be sliced");
            if (start < data.size() + end)
            {
                for (int i = start;i < data.size() + end;i++)
                    p.data.push_back(data[i]);
            }
            else
                throw std::out_of_range("Cannot be sliced");
        }
        else if (start < 0 && end < 0)
        {
            if(start==end)
                throw std::out_of_range("Cannot be sliced");
            if (data.size() + start < data.size() + end)
            {
                for (int i = data.size() + start;i < data.size() + end;i++)
                    p.data.push_back(data[i]);
            }
            else
                throw std::out_of_range("Cannot be sliced");
        }
        return p;
    }

    template <typename T>
    void push(const T& val)
    {
        append(val);
    }

    std::shared_ptr<Box> pop_stack()
    {
        std::shared_ptr<Box> temp = data.back();
        data.pop_back();
        return temp;
    }

    void enqueue(const std::shared_ptr<Box>& val)
    {
        std::vector<std::shared_ptr<Box>> data_temp;
        data_temp.push_back(val);
        for (int i = 0;i < data.size();i++)
            data_temp.push_back(data[i]);
        data = data_temp;
    }

    bool operator==(const PyList& other)const
    {
        if (len() == 0 || other.len() == 0)
            throw std::out_of_range("Empty");
        if (len() != other.len())
            return false;
        for (int i = 0;i < data.size();i++)
        {
            if (data[i]->type() == other.data[i]->type())
            {
                if ((data[i])->less(*(other.data[i])) || other.data[i]->less(*data[i]))return false;
            }
            else
                return false;
        }
        return true;
    }

    std::shared_ptr<Box> dequeue()
    {
        std::shared_ptr<Box> obj = data[0];
        std::vector<std::shared_ptr<Box>> data_temp;
        for (int i = 1;i < data.size();i++)
            data_temp.push_back(data[i]);
        data = data_temp;
        return obj;
    }

    void print() const
    {
        int count = 0;
        for (auto& obj : data)
        {
            obj->print();
            if (count !=data.size() - 1)
                std::cout<< " , ";
            count++;
        }
    }

    PyList copy() const
    {
        PyList temp;

        for (const auto& item : data)

        {
            temp.data.push_back(item);
        }

        return temp;
    }

    bool operator<(const PyList& b) const
    {
        size_t n = std::min(this->len(), b.len());
        for (size_t i = 0; i < n; i++)
        {
            if (this->data[i]->less(*b.data[i]))
                return true;
            if (b.data[i]->less(*this->data[i]))
                return false;
        }
        return this->len() < b.len();
    }
};

std::ostream& operator<<(std::ostream& os, const PyList& p)
{
    int count = 0;
    os << "[ ";
    p.print();
    os << " ]";
    return os;
}