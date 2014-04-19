#include <iostream>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);			   \
	void operator=(const TypeName&)

class Foo
{
public:
	
    Foo(int f)
	{
        
	}
	~Foo()
	{

	}

private:
    DISALLOW_COPY_AND_ASSIGN(Foo);
};

// calculate factorial of n recursively
int RecursiveFactorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * RecursiveFactorial(n - 1);
    }
}

// Print all perms of a list[k:m]
template <class T>
void Perm(T list[], int k, int m) {
    int i;
    if (k == m) {
        for (i = 0; i <= m; ++i) {
            std::cout << list[i];
        }

        std::cout << std::endl;
    } else {
        for (i = k; i <= m; ++i) {
            Swap(list[k], list[i]);
            Perm(list, k + 1, m);
            Swap(list[k], list[i]);
        }
    }
}

// Swap two element
template <class T>
inline void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Print all subsets of list
template <class T>
void SubSet(T list[], int k, int m, int flags[]) {
    int j;
    if (k <= m) {
        SubSet(list, k + 1, m, flags);
        flags[k] = 1 - flags[k]; // Two states for a element in a subset, change it here
        SubSet(list, k + 1, m, flags);
    } else {
        std::cout << "{";
        for (j = 0; j <= m; ++j) {
            if (flags[j]) {
                std::cout << list[j] << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
}

//int main()
//{
//    int l[] = {1,2,3};
//
//    // Perm(l, 0, 2);
//    int flags[3] = {0}; 
//    SubSet(l, 0, 2, flags);
//	return 0;
//}