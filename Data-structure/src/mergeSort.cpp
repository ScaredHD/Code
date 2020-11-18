#include <iostream>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;


void mergeSort(std::vector<int>::iterator beg, std::vector<int>::iterator end);


int main()
{
    std::vector<int> v = {10, 65, 42, 32, 11, 4, 89, 185, 122};
    mergeSort(v.begin(), v.end());

    for (auto it : v)
    {
        cout << it << " ";
    }


    system("pause");
	return 0;
}

void mergeSort(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
    std::vector<int> vv(beg, end);

    auto originBeg = beg;
    auto mid = beg + (end - beg) / 2;
    auto originMid = mid;
    auto it = vv.begin();

    // recursion condition
    if (end - beg > 1)
    {
        // merge sort left half
        mergeSort(beg, mid);
        // merge sort right half
        mergeSort(mid, end);
    }

    // merge left and right
    while (beg != originMid && mid != end)
    {
        if (*beg < *mid)
        {
            *it++ = *beg++;
        }
        else
        {
            *it++ = *mid++;
        }
    }

    // copy the rest
    if (beg != originMid)
    {
        copy(beg, originMid, it);
    }
    else if (mid != end)
    {
        copy(mid, end, it);
    }

    // copy work vector to original vector
    copy(vv.begin(), vv.end(), originBeg);

}