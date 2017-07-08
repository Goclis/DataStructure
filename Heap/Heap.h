#pragma once
#include <vector>
#include <iostream>
#include <initializer_list>
#include <functional>
using namespace std;

template<typename T>
class Heap
{
    vector<T> m_vals;
    function<bool(T &, T &)> m_cmp;

public:
    Heap(std::initializer_list<T> _vals, bool _minFlag = true)
    {
        m_cmp = _minFlag ? ([](const T &_l, const T &_r) { return _l <= _r; })
            : ([](const T &_l, const T &_r) { return _l >= _r; });

        int index = 0;
        for (auto &v : _vals)
        {
            m_vals.push_back(v);
            ShiftUp(index++);
        }
    }

    bool Empty() const
    {
        return m_vals.empty();
    }

    void Insert(const T &_v)
    {
        m_vals.push_back(_v);
        ShiftUp(m_vals.size() - 1);
    }

    T Pop()
    {
        if (m_vals.empty()) throw "EmptyHeap";

        size_t size = m_vals.size();
        T ret = m_vals[0];
        m_vals[0] = m_vals[size - 1];
        m_vals.resize(size - 1);
        ShiftDown(0);

        return ret;
    }

    void Print()
    {
        if (m_vals.empty())
        {
            std::cout << "Empty heap" << std::endl;
            return;
        }

        auto size = m_vals.size();
        vector<int> layer = {0};
        while (!layer.empty())
        {
            vector<int> nextLayer;
            for (auto i : layer)
            {
                int left = GetLeftChild(i);
                int right = GetRightChild(i);
                if (left < size) nextLayer.push_back(left);
                if (right < size) nextLayer.push_back(right);

                std::cout << m_vals[i] << " ";
            }
            std::cout << std::endl;
            layer = std::move(nextLayer);
       }
    }

private:
    int GetParent(int _index) { return 0 == _index % 2 ? (_index / 2 - 1) : (_index / 2); }

    int GetLeftChild(int _index) { return _index * 2 + 1; }

    int GetRightChild(int _index) { return _index * 2 + 2; }

    void Swap(int _i1, int _i2)
    {
        T temp = m_vals[_i1];
        m_vals[_i1] = m_vals[_i2];
        m_vals[_i2] = temp;
    }

    void ShiftUp(int _index)
    {
        while (_index > 0)
        {
            int parentIndex = GetParent(_index);
            if (!m_cmp(m_vals[parentIndex], m_vals[_index]))
            {
                Swap(parentIndex, _index);
                _index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void ShiftDown(int _index)
    {
        int size = m_vals.size();
        while (_index < size)
        {
            int leftChildIndex = GetLeftChild(_index);
            int rightChildIndex = GetRightChild(_index);

            if (leftChildIndex >= size) break;
          
            int swapIndex = -1; 
            if (rightChildIndex >= size)
            {
                if (m_cmp(m_vals[_index], m_vals[leftChildIndex])) break;

                swapIndex = leftChildIndex;
            }
            else
            {
                if (m_cmp(m_vals[_index], m_vals[leftChildIndex])
                    && m_cmp(m_vals[_index], m_vals[rightChildIndex])) break;
    
                swapIndex = m_cmp(m_vals[leftChildIndex], m_vals[rightChildIndex])
                    ? leftChildIndex : rightChildIndex;
            }
            
            Swap(_index, swapIndex);
            _index = swapIndex;
        }
    }
};

