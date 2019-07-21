#include <iostream>
#include <algorithm>

int main()
{
    int n;

    std::cout << "";
    std::cin >> n;

    int myints[n];

    for (int i = 0; i < n; i++)
        myints[i] = i + 1;

    std::sort(myints, myints + n);

    do {
        for (int i = 0; i < n; i++)
            std::cout << myints[i] << "";
        std::cout << '\n';
    } while (std::next_permutation(myints, myints+n));

  return 0;
}
