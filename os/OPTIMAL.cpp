#include <iostream>
using namespace std;
int fault, hit;
bool pagefault(int frames[], int f, int ref)
{
    bool flag = true;
    for (int i = 0; i < f; i++)
    {
        if (frames[i] == ref)
        {
            flag = false;
            hit++;
            return flag;
        }
    }
    fault++;
    return flag;
}

int optimal(int ref[], int r, int frames[], int f, int j)
{
    int check[f];
    int count = 0;
    for (int i = 0; i < f; i++)
    {
        check[i] = 0;
    }
    while (j < r)
    {
        for (int i = 0; i < f; i++)
        {
            if (frames[i] == ref[j])
            {
                if (check[i] == 0)
                {
                    check[i] = 1;
                    count++;
                }
            }
            if (count == f)
            {
                return i;
            }
        }
        j++;
    }
    for (int i = 0; i < f; i++)
    {
        if (check[i] == 0)
        {
            return i;
        }
    }
    return 0;
}

void fifo(int ref[], int r, int f)
{
    int frames[f];
    for (int i = 0; i < f; i++)
    {
        frames[i] = 0;
    }
    int j = 0;
    int count = 0;
    while (j != r)
    {
        if (pagefault(frames, f, ref[j]))
        {
            count = optimal(ref, r, frames, f, j);
            frames[count] = ref[j];
            j++;
            count++;
            continue;
        }
        j++;
    }
}
int main()
{
    fault = 0;
    hit = 0;
    int f, r;
    cout << "Enter Number of Frames : " << endl;
    cin >> f;
    cout << "Enter Number of References : " << endl;
    cin >> r;
    cout << "Enter the reference array : " << endl;
    int ref[r];
    for (int i = 0; i < r; i++)
    {
        cin >> ref[i];
    }
    fifo(ref, r, f);
    cout << "Number of Faults : " << fault << endl;
    cout << "Number of Hits : " << hit << endl;
    return 0;
}