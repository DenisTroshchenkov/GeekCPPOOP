#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <cassert> 

class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length):
    m_length(length) {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }

    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength) {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int *data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }
        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index) {
        assert(index >= 0 && index <= m_length);

        int *data = new int[m_length+1];

        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        data [index] = value;

        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void eraseElem(int index) {
        assert(index >= 0 && index < m_length && m_length > 0);
        int *data = new int[m_length-1];
        
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        for (int after=index; after < m_length; ++after)
            data[after] = m_data[after+1];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void print() {
        for (int idx = 0; idx < m_length; ++idx) {
            std::cout << "[" << idx << "]: " << m_data[idx] << "\n";
        }
    }

    void sort (int order=0) {
        for (int s_idx = 0; s_idx < m_length - 1; ++s_idx)
	{
		int min_idx = s_idx;
 		for (int c_idx = s_idx + 1; c_idx < m_length; ++c_idx)
		{
			if (order ? m_data[c_idx] > m_data[min_idx] : m_data[c_idx] < m_data[min_idx])
            	min_idx = c_idx;
		}
 
		std::swap(m_data[s_idx], m_data[min_idx]);
	}
    }

    void pop_back() { eraseElem(m_length - 1); }

    void push_back(int value) { insertBefore(value, m_length); }

    void insertArray(int* v_array, int length, int index) {
        assert(index >= 0 && index <= m_length);

        int *data = new int[m_length+length];

        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        for (int after=index, v_idx = 0; v_idx < length; ++v_idx, ++after)
            data[after] = v_array[v_idx];

        for (int after=index + length, m_idx=index; m_idx < m_length; ++m_idx, ++after)
            data[after] = m_data[m_idx];

        delete[] m_data;
        m_data = data;
        m_length += length;
    }

    ~ArrayInt() {
        delete[] m_data;
    }
};




int from_base_to_dec(const std::vector<int> &value, int base) {
    int result = 0;
    for (int idx = value.size() - 1; idx >= 0; --idx) {
        result += pow(base, idx) * value[idx];
    }
    return result;
}

std::vector<int> from_dec_to_base(int value, int base) {
    std::vector<int> result;
    while(value >= base) {
        result.push_back(value % base);
        value /= base;
    }
    if (value) {
        result.push_back(value);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<int> plus(const std::vector<int> &A, int baseA, const std::vector<int> &B, int baseB, int baseResult) {
    int dec_num = from_base_to_dec(A, baseA) + from_base_to_dec(B, baseB);
    return from_dec_to_base(dec_num, baseResult);
}

void task1() {
    ArrayInt array(10);

    for (int idx = 0; idx < array.getLength(); ++idx) {
        array[idx] = idx;
    }
    array.print();
    std::cout << "pop:\n";
    array.pop_back();
    array.print();
    std::cout << "sort:\n";
    array.sort(1);
    array.print();
    std::cout << "insert Array\n";
    int test_arr[5] = {4,23,5,11,3};
    array.insertArray(test_arr, 5, 4);
    array.print();
}

void task2() {
    std::cout << "task2:\n";
    
    std::vector<int> values;
    for (int idx = 0; idx < 10; ++idx) {
        int num;
        std::cout << "enter number: ";
        std::cin >> num;
        values.push_back(num);
    } 

    std::set<int> count_value;
    for (int v: values) {
        count_value.insert(v);
    }
    std::cout << "uniq value num: " << count_value.size() << "\n";

}



void task4() {
    std::cout << "task4:\n";
    std::vector<int> result = plus(std::vector<int>({15, 15}), 16, std::vector<int>({17, 14, 21, 21, 24}), 36, 2);
    for (int v: result) {
        std::cout << v;
    }
    std::cout << "\n";
}

int main () {
    task1();
    task2();
    // над 3 заданием тоже поработал =) 
    task4();
    return 0;
}