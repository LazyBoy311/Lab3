#include "dataGenerator.h"
#include "Sort.h"
#include "compSort.h"


using namespace std;

int* copy(int a[], int n) {
    int* b = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    return b;
}
int checkInputOrder(string s) {
    if (s == "-rand") return 0;
    if (s == "-nsorted") return 3;
    if (s == "-sorted") return 1;
    if (s == "-rev") return 2;
    return 5;
}
double checkTime(string s, int a[], int n) {
    if (s == "selection-sort") {
        clock_t start = clock();
        selectionSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "insertion-sort") {
        clock_t start = clock();
        insertionSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "bubble-sort" ) {
        clock_t start = clock();
        bubbleSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "shaker-sort" ) {
        clock_t start = clock();
        shakerSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "shell-sort" ) {
        clock_t start = clock();
        shellSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "heap-sort" ) {
        clock_t start = clock();
        heapSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "merge-sort") {
        clock_t start = clock();
        mergeSort(a, 0, n - 1);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "quick-sort") {
        clock_t start = clock();
        quickSort(a, 0, n - 1);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "counting-sort") {
        clock_t start = clock();
        countingSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "radix-sort") {
        clock_t start = clock();
        radixSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    if (s == "flash-sort") {
        clock_t start = clock();
        flashSort(a, n);
        return (double(clock() - start) / double(CLOCKS_PER_SEC)) * 1000;
    }
    return 0;
}
long long checkComp(string s, int a[], int n) {
    if (s == "selection-sort") {
        return selectionSortComp(a, n);
    }
    if (s == "insertion-sort") {
        return insertionSortComp(a, n);
    }
    if (s == "bubble-sort") {
        return bubbleSortComp(a, n);
    }
    if (s == "shaker-sort") {
        return shakerSortComp(a, n);
    }
    if (s == "shell-sort") {
        return shellSortComp(a, n);
    }
    if (s == "heap-sort") {
        return heapSortComp(a, n);
    }
    if (s == "merge-sort") {
        return mergeSortComp(a, 0, n - 1);
    }
    if (s == "quick-sort") {
        return quickSortComp(a, 0, n - 1);
    }
    if (s == "counting-sort") {
        return countingSortComp(a, n);
    }
    if (s == "radix-sort") {
        return radixSortComp(a, n);
    }
    if (s == "flash-sort") {
        return flashSortComp(a, n);
    }
    return 0;
}
void command1(string A1, string inputFile, string Out) {
    ifstream fi;
    fi.open(inputFile);
    int n;
    fi >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        fi >> a[i];
    fi.close();
    int* b = copy(a, n);
    cout << "ALGORITHM MODE\n";
    cout << "Algorith: " << A1 <<"\n";
    cout << "Input file: " << inputFile << "\n";
    cout << "Input size: " << n << "\n";
    cout << "------------------------------------- \n";
    if (Out == "-both" || Out == "-time") cout << "Running time: " << checkTime(A1, a, n) << "\n";
    if (Out == "-both" || Out == "-comp") cout << "Comparisions: " << checkComp(A1, b, n);
    ofstream fo;
    fo.open("output.txt");
    fo << n << "\n";
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();
    delete[] a;
    delete[] b;
}

void command2(string A1, string inputSize, string inputOrder, string Out) {
    int n = stoi(inputSize);
    int *a = new int[n];
    GenerateData(a, n, checkInputOrder(inputOrder));
    int* b = copy(a, n);
    ofstream fo;
    fo.open("input.txt");
    fo << n << "\n";
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();
    cout << "ALGORITHM MODE \n";
    cout << "Algorithm: " << A1 << "\n";
    cout << "Input size: " << n << "\n";
    cout << "Input order: ";
    if (inputOrder == "-rand") cout << "Randomized data\n";
    if (inputOrder == "-nsorted") cout << "Nearly sorted data\n";
    if (inputOrder == "-sorted") cout << "Sorted data\n";
    if (inputOrder == "-rev") cout << "Reverse sorted data\n";
    cout << "-------------------------------------\n";
    if (Out == "-both" || Out == "-time") cout << "Running time: " << checkTime(A1, a, n);
    if (Out == "-both" || Out == "-comp") cout << "Comparisions: " << checkComp(A1, b, n);
    fo.open("output.txt");
    fo << n << "\n";
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();
    delete[] a;
    delete[] b;
}

void command3(string A1, string inputSize, string Out) {
    int n = stoi(inputSize);
    int* a = new int[n];
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << A1 << "\n";
    cout << "Input size: " << n << "\n\n";
    for (int i = 0; i <= 3; i++) {
        GenerateData(a, n, i);
        int* b = copy(a, n);
        ofstream fo;
        if (i == 0) fo.open("input1.txt");
        if (i == 1) fo.open("input2.txt");
        if (i == 2) fo.open("input3.txt");
        if (i == 3) fo.open("input4.txt");
        fo << n << "\n";
        for (int i = 0; i < n; i++)
            fo << a[i] << " ";
        fo.close();
        if (i == 0) cout << "Input order: Randomize";
        if (i == 1) cout << "Input order: Sorted";
        if (i == 2) cout << "Input order: Reversed";
        if (i == 3) cout << "Input order: Nearly sorted";
        cout << "\n";
        cout << "-------------------------------------\n";
        if (Out == "-both" || Out == "-time") cout << "Running time: " << checkTime(A1, a, n) << "\n";
        if (Out == "-both" || Out == "-comp") cout << "Comparisions: " << checkComp(A1, b, n) << "\n\n";
    }
}
void command4(string A1, string A2, string inputFile) {
    ifstream fi;
    fi.open(inputFile);
    int n;
    fi >> n; 
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        fi >> a[i];
    fi.close();
    int* a1 = copy(a, n);
    int* a2 = copy(a, n);
    int* a3 = copy(a, n);
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << A1 << " | " << A2 << "\n";
    cout << "Inputfile: " << inputFile << "\n";
    cout << "Inputsize: " << n << "\n";
    cout << "------------------------------------- \n";
    cout << "Running time: " << checkTime(A1, a1, n) << " ms | " << checkTime(A2, a2, n) << " ms \n";
    cout << "Comparisions: " << checkComp(A1, a, n) << " | " << checkComp(A2, a3, n) <<"\n";
    
    delete[] a;
    delete[] a1;
    delete[] a2;
    delete[] a3;
    /**/
}
void command5(string A1, string A2, string inputSize, string inputOrder) {
    int n = stoi(inputSize);
    int *a = new int[n];
    GenerateData(a, n, checkInputOrder(inputOrder));
    int* a1 = copy(a, n);
    int* a2 = copy(a, n);
    int* a3 = copy(a, n);
    ofstream fo;
    fo.open("input.txt");
    fo << n << "\n";
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << A1 << " | " << A2 << "\n";
    cout << "Inputsize: " << n << "\n";
    cout << "Input order: ";
    
    if (inputOrder == "-rand") cout << "Randomized data\n";
    if (inputOrder == "-nsorted") cout << "Nearly sorted data\n";
    if (inputOrder == "-sorted") cout << "Sorted data\n";
    if (inputOrder == "-rev") cout << "Reverse sorted data\n";
    cout << "-------------------------------------\n";
    cout << "Running time: " << checkTime(A1, a1, n) << " ms | " << checkTime(A2, a2, n) << " ms \n";
    cout << "Comparisions: " << checkComp(A1, a, n) << " | " << checkComp(A2, a3, n);
    delete[] a;
    delete[] a1;
    delete[] a2;
    delete[] a3;
    /**/
}

bool compare(char* a, string b) {
    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}
int main(int argc, char* argv[])
{
   
    if (compare(argv[1], "-a")) {
        if (argc == 6) 
            command2(argv[2], argv[3], argv[4], argv[5]);
        else if (argc == 5) {
            if (atoi(argv[3]))
                command3(argv[2], argv[3], argv[4]);
            else 
                command1(argv[2], argv[3], argv[4]);
        }
    else cout << "Error: unknown data type!\n";
    }
    else if (compare(argv[1], "-c")) {
        if (argc == 5)
            command4(argv[2], argv[3], argv[4]);
        else if (argc == 6)
            command5(argv[2], argv[3], argv[4], argv[5]);
        else cout << "Error: unknown data type!\n";
    }
    else cout << "Error: unknown data type!\n";
    return 0;
}   