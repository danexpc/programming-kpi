#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int** creatingArray(int m, int n)
{
        int **arr = new int*[m];

        for(int i = 0; i < m; i++)
        {
                arr[i] = new int[n];
                for(int j = 0; j < n; j++)
                {
                        arr[i][j] = 0;
                }
        }

        return arr;
}

int** readFile(int &n, int &m)
{
       int **graph;
       string path;

       cout << "Enter path: " << endl;
       getline(cin, path);

       ifstream fin;
       fin.open(path);

       if(!fin.is_open())
       {
             cout << "Error open file" << endl;
             assert(0);
       }
       else
       {
             cout << "File is open!" << endl;
             char ch;
             bool temp = false;
             while(fin.get(ch) and (ch != '\n'))
             {
                     if (ch == ' ')
                     {
                             temp = true;
                             continue;
                     }

                     if(!temp)
                     {
                             n = (n * 10) + int(ch) - 48;
                     }

                     else
                     {
                             m = (m * 10) + int(ch) - 48;
                     }
             }

             graph = creatingArray(m, 2);

             int index1 = 0;
             int index2 = 0;

             while(fin.get(ch))
             {
                     if(ch == ' ')
                     {
                             index2 += 1;
                     }
                     else if(ch == '\n')
                     {
                             index2 -= 1;
                             index1 += 1;
                     }
                     else
                     {
                             graph[index1][index2] = graph[index1][index2] * 10 + (int(ch) - 48);
                     }
             }
       }
       fin.close();
       return graph;
}

void creatingMatrixAdjacency(int **matrix, int **arr, int m)
{
        for(int i = 0; i < m; i++)
        {
                int v = arr[i][0];
                int u = arr[i][1];
                matrix[v - 1][u - 1] = 1;
        }
}

void creatingMatrixIncedence(int **matrix, int **arr, int m)
{
        for(int i = 0; i < m; i++)
        {
                int v = arr[i][0];
                int u = arr[i][1];
                matrix[v - 1][i] = -1;
                matrix[u - 1][i] = 1;
        }
}


void printArray(int **arr, int m, int n)
{
        for(int i = 0; i < m; i++)
        {
                for(int j = 0; j < n; j++)
                {
                        cout << setw(4) << arr[i][j];
                }
                cout << endl;
        }
}

void halfStepsFind(int **arr, int **matrix, int *step, int n)
{
        for(int i = 0; i < n; i++)
        {
              for(int j = 0; j < n; j++)
              {
                      arr[i][0] += matrix[j][i];
                      arr[i][1] += matrix[i][j];
              }
              step[i] = arr[i][0] + arr[i][1];
        }
}

void homogetety(int *arr, int n)
{
        bool isH = true;
        int index = 1;
        while(index < n)
        {
                if(arr[index] != arr[index-1])
                {
                        isH = false;
                }
                index++;
        }
        if(isH)
        {
                cout << "The graph is homogeneous \n" << "Degree of homogeneity: " << arr[0] << endl;

        }
        else
        {
                cout << "The graph is not homogeneous" << endl;
        }
}       

void isIsolated(int *arr, int n)
{
        bool isolated = false;
        for(int i = 0; i < n; i++)
        {
                if(arr[i] == 0)
                {
                        isolated = true;
                        cout << i + 1 << endl;
                }
        }
        if(!isolated)
            cout << "Isolated vertices do not exist. " << endl;
        else
        {
                cout << "Isolated tops: ";
                for(int i = 0; i < n; i++)
                {
                        if(arr[i] == 1)
                           cout << i + 1 << ", ";
                }
                cout << endl;
        }
}

void isHanging(int *arr, int n)
{
        bool hanging = false;
        for(int i = 0; i < n; i++)
        {
                if(arr[i] == 1)
                {
                        hanging = true;
                        break;
                }
        }
        if(!hanging)
            cout << "Hanging vertices do not exist. " << endl;
        else
        { 
            cout << "Hanging tops: ";
            for(int i = 0; i < n; i++)
            {
                    if(arr[i] == 1)
                       cout << i + 1 << ", ";
            }
            cout << endl;
        }
}
              
void decorate()
{
        cout << "#########################################################" << endl;
}

void delete_arr(int **arr, int m)
{
        for(int i = 0; i < m; i++)
        {
                delete[] arr[i];
        }
        delete[] arr;
}
int main()
{        
        int n = 0;
        int m = 0;

        int **inputFile = readFile(n, m);

        int **matrixAdjacency = creatingArray(n, n);

        creatingMatrixAdjacency(matrixAdjacency, inputFile, m);

 
        int **matrixIncedence = creatingArray(m, n);

        creatingMatrixIncedence(matrixIncedence, inputFile, m);

        int **halfSteps = creatingArray(n, 2);

        int *totalStep = new int[n];

        halfStepsFind(halfSteps, matrixAdjacency, totalStep, n);
        
        bool exit = false;

        while(!exit)
        {
                decorate();
                cout << "Choose ane action: \n"
                     << "\t1) Output the incidence matrix;"<< endl
                     << "\t2) Output the ajency marix;"<< endl
                     << "\t3) Output the degree of vertices of graph;" << endl
                     << "\t4) Uniformity check;" << endl
                     << "\t5) Identify all hanging and isolated vertices;" << endl
                     << "\t6) Exit " << endl;

                int choise;
                cout << "Enter command: ";
                cin >> choise;
                decorate();
                switch(choise)
                {
                        case 1:
                                system("clear");
                                decorate();
                                printArray(matrixIncedence, m, n);
                                decorate();
                                break;
                        case 2:
                                system("clear");
                                decorate();
                                printArray(matrixAdjacency, n, n);
                                decorate();
                                break;
                        case 3:
                                system("clear");
                                decorate();
                                printArray(halfSteps, n, 2);
                                decorate();
                                break;
                        case 4:
                                system("clear");
                                decorate();
                                homogetety(totalStep, n);
                                decorate();
                                break;
                        case 5:
                                system("clear");
                                decorate();
                                isIsolated(totalStep, n);
                                isHanging(totalStep, n);
                                decorate();
                                break;
                        case 6:
                                system("clear");
                                cout << "Bye-bye :)" << endl;
                                exit = true;
                                break;
                        default:
                                system("clear");
                                cout << "Command not found!" << endl;
                                break;
                }
                if(choise != 6)
                {
                        cout << "Continue?(0 - no, 1 - yes) " << endl;
                        cin >> choise;
                        if(choise == 0)
                                exit = true;
                        else if(choise == 1)
                                system("clear");
                        else 
                                break;
                }

        }                                  
        delete_arr(inputFile, n);
        delete_arr(matrixAdjacency, n);
        delete_arr(matrixIncedence, n);
        delete_arr(halfSteps, n);
        delete [] totalStep; 
        return 0;
}
