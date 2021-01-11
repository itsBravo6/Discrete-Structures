
//MINOR BUG : TABLE IS NOT GENERATED IN THIS CODE... OTHERWISE, IT SHOWS CORRECT OUTPUT i.e, The correct Path

#include<iostream> 
using namespace std;


class algo
{
public:

    int maximumValue;
    int STARTING;
    int ENDING;
    int path[9];
    int n;
    algo()
    {


        n = 9;

        cout << "Enter Starting Point : ";
        cin >> STARTING;
        cout << "Enter Ending Point   : ";
        cin >> ENDING;
        maximumValue = 99999;

        path[9] = NULL;
    }




    int MinimumDistance(int path[], bool SeparateSet[])
    {
        int min = 9999;
        int minimumIndex;

        for (int i = 0; i < 9; i++)
            if (SeparateSet[i] == false && path[i] <= min)
                min = path[i], minimumIndex = i;

        return minimumIndex;
    }

    void  Print(int matrix[9][9])



    {

        cout << endl;

        cout << "THE GRAPH IS :" << endl;
        for (int i = 0; i < 9; i++)
        {
            cout << "\t | ";
            for (int j = 0; j < 9; j++)
            {
                cout << matrix[i][j] << " ";

            }
            cout << "|";
            cout << endl;
        }



        cout << "--------------------------------------------------------" << endl;


        cout << "Start Point" << "\t" << "End Point" << "\t" << "Minimum Path" << endl;

        for (int i = STARTING; i < ENDING + 1; i++)
            cout << STARTING << "\t \t" << i << "\t \t" << path[i] << endl;

        cout << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << " Minimum Path from Entered Start Node to End Node is: " << endl;
        cout << endl;
        cout << endl;
        cout << "Start Point" << "\t" << "End Point" << "\t" << "Minimum Path" << endl;
        cout << STARTING << "\t \t" << ENDING << "\t \t" << path[ENDING] << endl;

    }


    void calculation(int matrix[9][9])  //main functio
    {



        bool SeparateSet[9];

        for (int i = 0; i < 9; i++)
            path[i] = maximumValue, SeparateSet[i] = false;

        path[STARTING] = 0;

        for (int count = 0; count < 9 - 1; count++)
        {
            int u = MinimumDistance(path, SeparateSet);

            SeparateSet[u] = true;


            for (int k = 0; k < 9; k++)
            {

                if (!SeparateSet[k] && matrix[u][k] && path[u] != maximumValue && path[u] + matrix[u][k] < path[k])
                {
                    path[k] = path[u] + matrix[u][k];
                }
            }
        }

        Print(matrix);
    }



};

int main()
{
    int  matrix[9][9] = { {0, 3, 0, 2, 0, 0, 0, 0, 4},
                                {3, 0, 0, 0, 0, 0, 0, 4, 0},
                                {0, 0, 0, 6, 0, 1, 0, 2, 0},
                                {2, 0, 6, 0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0, 0, 0, 0, 8},
                                {0, 0, 1, 0, 0, 0, 8, 0, 0},
                                {0, 0, 0, 0, 0, 8, 0, 0, 0},
                                {0, 4, 2, 0, 0, 0, 0, 0, 0},
                                {4, 0, 0, 0, 8, 0, 0, 0, 0} };
    algo A;

    A.calculation(matrix);
    cout << endl << endl;
    system("pause");
    return 0;
}
