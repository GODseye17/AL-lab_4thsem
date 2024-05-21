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

void fifo(int ref[], int r, int f)
{
    int frames[f];
    int j = 0;
    int count = 0;
    while (j != r)
    {
        if (pagefault(frames, f, ref[j]))
        {
            count = count % f;
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