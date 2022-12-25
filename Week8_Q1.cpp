#include <iostream>
using namespace std;
class IntArr
{
public:
    int *ar;
    int size;
    IntArr(int size=1)
    {
        ar = new int[size];
        IntArr::size = size;
    }
    IntArr(IntArr &o)
    {
        this->size = o.size;
        this->ar = o.ar;
       
    }
    void input()
    {
        int length = size;
        cout << "Enter the Values" << endl;
        for (int i = 0; i < length; i++)
        {
            cin >> ar[i];
            fflush(stdin);
        }
    }
    void show()
    {
    	cout<<"MOHAMMAD SHAHID RAZA"<<endl;
        cout << "A35404821013" << endl;
		cout << "Week 8 Question 1 output:"<<endl;
	}
    void display(int a[])
    {

        int length = size;
        cout << "Dispaly function" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void search(int ar[], int search)
    {
        cout << "\nSEARCH FUNCTION" << endl;
        int count = 0;
        int length = size;
        for (int i = 0; i < length; i++)
        {
            if (search == ar[i])
                count++;
        }
        if (count != 0)
            cout << "element found\n";
        else
            cout << "element not found\n";
    }

    bool operator==(IntArr &obj)
    {
        cout << "\n == OP FUNCTION" << endl;
        int count = 0;
        int length1 = size;
        int length2 = obj.size;
        cout << length1 << "   " << length2 << endl;
        if (length1 == length2)
        {
            for (int i = 0; i < length1; i++)
            {
                if (ar[i] == obj.ar[i])
                    count++;
                else
                    break;
            }
            if (count == length1)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    
    IntArr operator+(IntArr &obj)
    {
        cout << "\n + OP FUNCTION" << endl;
        int length = size;
        IntArr ax(length);
        for (int i = 0; i < length; i++)
        {
            ax.ar[i] = ar[i] + obj.ar[i];
        }
        return ax;
    }
    
    friend void compare(IntArr ob1, IntArr ob2);
    
};

void compare(IntArr ob1, IntArr ob2)
{
    cout << "\nCOMPARE FUNCTION" << endl;
    int count = 0;
    int length1 = ob1.size;
    int length2 = ob2.size;
    cout << length1 << "   " << length2 << endl;
    if (length1 == length2)
    {
        for (int i = 0; i < length1; i++)
        {
            if (ob1.ar[i] == ob2.ar[i])
                count++;
            else
                break;
        }
        if (count == length1)
            cout << "Both equal\n";
        else
            cout << "Both not equal\n";
    }
    else
        cout << "Both not equall\n";
}

int main()
{
    //NORMAL CONSTRUCTORS
    IntArr temp(3);

    IntArr ob(3);
    ob.show();
	ob.input();
    ob.display(ob.ar);

    IntArr ob1(3);
    ob1.input();
    ob.display(ob1.ar);

    ob.search(ob.ar, 1);

    compare(ob, ob1);

    temp = ob + ob1;
    temp.display(temp.ar);

    cout << (ob == ob1) << endl;


    //COPY CONSTRUCTORS
    IntArr copy(temp);
    copy.display(copy.ar);
}
