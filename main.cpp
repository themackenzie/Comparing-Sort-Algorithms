#include <iostream>
#include <ctime>
#include <iomanip>


using namespace std;


int steps = 0;


void f_fill ( int e_val[], int e_size, int r_01, int r_02 ){
    for ( int n = 0; n < e_size; n++ ){
       e_val[n] = ( rand() % ( ( r_02 - r_01 ) ) + r_01 );
    }//fr

    e_val[e_size] = NULL;
}//fn


void f_copy ( int e_val0[], int e_val1[], int e_size ){
    for ( int n = 0; n < e_size; n++ ){
        e_val1[n] = e_val0[n];
    }//fr
}//fn


void f_printl ( int e_val[] ){
    int *rr = &e_val[0];

    while ( *rr != NULL ){
        cout << *rr << ' ';

        rr++;
    }//wh


    cout << endl;
}//fn



void f_cselectionSort( int arr[], int e_size ) {
    int n = e_size;
    int swp;

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;


        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {


                min_idx = j;

                //+++
                steps++;
            }//cd
        }//fr

        swp = arr[i];

        arr[i] = arr[min_idx];
        arr[min_idx] = swp;


        //+++
        steps++;
    }//fr
}//fn


void f_cbubbleSort( int arr[], int e_size ) {
    int n = e_size;
    bool swapped;

    int swp;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = swp;


                swapped = true;

                //+++
                steps++;
            }//cd
        }//fr

        // If no two elements were swapped, then break
        if ( swapped == false ){
            break;
        }//cd
    }//fr
}//fnc


void f_cinsertionSort(int arr[], int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];

        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];

            //+++
            steps++;

            j = j - 1;
        }//wh
        arr[j + 1] = key;

        //+++
        steps++;
    }//fr
}//fn


//Merge Sort
void f_merge( int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    int L[n1], R[n2];


    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];

        steps++;
    }//fr
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];

        steps++;
    }//fr

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;

            //+++
            steps++;
        }//cd
        else {
            arr[k] = R[j];
            j++;

            //+++
            steps++;
        }//cd
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

        //+++
        steps++;
    }//wh

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;

        steps++;
    }//wh
}//fn


void f_cmergeSort( int arr[], int left, int right){
    if (left >= right){
        return;
    }//cd

    int mid = left + (right - left) / 2;
    f_cmergeSort(arr, left, mid);
    f_cmergeSort(arr, mid + 1, right);
    f_merge(arr, left, mid, right);
}//fn


//Quick Sort
int f_partition( int arr[], int low, int high) {
    // choose the pivot
    int pivot = arr[high];

    int swp;

    // undex of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;

            swp = arr[i];

            arr[i] = arr[j];
            arr[j] = swp;

            //+++
            steps++;
        }//cd
    }//fr

    // move pivot after smaller elements and
    // return its position
    swp = arr[i + 1];

    arr[i + 1] = arr[high];
    arr[high] = swp;


    //+++
    steps++;

    return i + 1;
}//fn


void f_cquickSort( int arr[], int low, int high) {
    if (low < high) {

        // pi is the partition return index of pivot
        int pi = f_partition( arr, low, high);

        // recursion calls for smaller elements
        // and greater or equals elements
        f_cquickSort(arr, low, pi - 1);
        f_cquickSort(arr, pi + 1, high);
    }//cd
}//fn


//Heap Sort
void f_heapify( int arr[], int n, int i){
    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;


    int swp;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }//cd

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }//cd

    // If largest is not root
    if (largest != i) {
        swp = arr[i];

        arr[i] = arr[largest];
        arr[largest] = swp;

        //+++
        steps++;

        // Recursively heapify the affected sub-tree
        f_heapify(arr, n, largest);
    }//cd
}//fn


void f_cheapSort( int arr[], int e_size ){
    int n = e_size;

    int swp;

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--){
        f_heapify(arr, n, i);
    }//fr

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swp = arr[0];

        arr[0] = arr[i];
        arr[i] = swp;


        //+++
        steps++;

        // Move current root to end

        // Call max heapify on the reduced heap
        f_heapify(arr, i, 0);
    }//fr
}//fn


void f_ccycleSort( int arr[], int e_size ){
    int n = e_size;
    int swp;


    // traverse array elements and put it to on
    // the right place
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {

        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++){
            if (arr[i] < item){
                pos++;
            }//cd
        }//fr

        // If item is already in correct position
        if (pos == cycle_start){
            continue;
        }//cd

        // ignore all duplicate  elements
        while (item == arr[pos]){
            pos += 1;
        }//wh

        // put the item to its right position
        if (pos != cycle_start) {
            swp = item;

            item = arr[pos];
            arr[pos] = swp;

            //+++
            steps++;
        }//cd

        // Rotate rest of the cycle
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start + 1; i < n; i++){
                if (arr[i] < item){
                    pos += 1;
                }//cd
            }//fr

            // ignore all duplicate  elements
            while (item == arr[pos]){
                pos += 1;
            }//wh

            // put the item to it's right position
            if (item != arr[pos]) {
                swp = item;

                item = arr[pos];
                arr[pos] = swp;


                //+++
                steps++;
            }//cd
        }//wh
    }//fr
}//fn


int f_maxmin ( int arr[], int e_size, bool maxmin = 0 ){
    int n = arr[0];
    int r = 0;

    for ( int i = 1; i < e_size; i++ ){
        if ( n < arr[i] && maxmin == 1 ){
            n = arr[i];
            r = i;
        }//cd
        else if ( n > arr[i] && maxmin == 0 ){
            n = arr[i];
            r = i;
        }//cd
    }//fr

    return ( r );
}//fn



int f_maxmin ( double arr[], int e_size, bool maxmin = 0 ){
    double n = arr[0];
    int r = 0;

    for ( int i = 1; i < e_size; i++ ){
        if ( n < arr[i] && maxmin == 1 ){
            n = arr[i];
            r = i;
        }//cd
        else if ( n > arr[i] && maxmin == 0 ){
            n = arr[i];
            r = i;
        }//cd
    }//fr

    return ( r );
}//fn



int main(){
    int val0, val1, val2;

    int reff = 0;
    clock_t timer_s, timer_e;
    double cnt;

    double reffs_t[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int reffs_s[7] = { 0, 0, 0, 0, 0, 0, 0 };
    string reffs_n[7] = {
        "Selection Sort",
        "Bubble Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quick Sort",
        "Heap Sort",
        "Cycle Sort"
    };



    srand ( time ( 0 ) );


    cin >> val0;
    cin >> val1;
    cin >> val2;


    int regsb[val0 + 1];

    f_fill ( regsb, val0, val1, val2 );

    cout << "Numbers: " << val0 << endl;
    cout << "Range: " << val1 << " - " << val2 << endl;

    cout << endl << "Base Array Reference" << endl;
    f_printl ( regsb );


    int regst[val0 + 1];


    //S.A. 01
    steps = 0;
    f_copy ( regsb, regst, val0 );

    timer_s = clock();
    f_cselectionSort ( regst, val0 );
    timer_e = clock();

    cnt = double ( timer_e - timer_s ) / CLOCKS_PER_SEC;
    cnt = cnt * 1000;

    reffs_s[reff] = steps;
    reffs_t[reff] = cnt;


    reff++;
    //S.A. 02
    steps = 0;
    f_copy ( regsb, regst, val0 );

    timer_s = clock();
    f_cbubbleSort ( regst, val0 );
    timer_e = clock();
    cnt = double ( timer_e - timer_s ) / CLOCKS_PER_SEC;
    cnt = cnt * 1000;

    reffs_s[reff] = steps;
    reffs_t[reff] = cnt;


    reff++;
    //S.A. 03
    steps = 0;
    f_copy ( regsb, regst, val0 );

    timer_s = clock();
    f_cinsertionSort ( regst, val0 );
    timer_e = clock();
    cnt = double ( timer_e - timer_s ) / CLOCKS_PER_SEC;
    cnt = cnt * 1000;

    reffs_s[reff] = steps;
    reffs_t[reff] = cnt;

    reff++;
    //S.A. 04
    steps = 0;
    f_copy ( regsb, regst, val0 );

    timer_s = clock();
    f_cmergeSort ( regst, 0, val0 - 1 );
    timer_e = clock();
    cnt = double ( timer_e - timer_s ) / CLOCKS_PER_SEC;
    cnt = cnt * 1000;

    reffs_s[reff] = steps;
    reffs_t[reff] = cnt;


    reff++;
    //S.A. 05
    steps = 0;
    f_copy ( regsb, regst, val0 );

    timer_s = clock();
    f_cquickSort ( regst, 0, val0 - 1 );
    timer_e = clock();
    cnt = double ( timer_e - timer_s ) / CLOCKS_PER_SEC;
    cnt = cnt * 1000;

    reffs_s[reff] = steps;
    reffs_t[reff] = cnt;


    reff++;
    //S.A. 06
    steps = 0;
    f_copy ( regsb, regst, val0 );

    timer_s = clock();
    f_cheapSort ( regst, val0 );
    timer_e = clock();
    cnt = double ( timer_e - timer_s ) / CLOCKS_PER_SEC;
    cnt = cnt * 1000;

    reffs_s[reff] = steps;
    reffs_t[reff] = cnt;


    reff++;
    //S.A. 07
    steps = 0;
    f_copy ( regsb, regst, val0 );

    timer_s = clock();
    f_ccycleSort ( regst, val0 );
    timer_e = clock();
    cnt = double ( timer_e - timer_s ) / CLOCKS_PER_SEC;
    cnt = cnt * 1000;

    reffs_s[reff] = steps;
    reffs_t[reff] = cnt;


    cout << endl << "Number of Steps(swaps) per Algorithm" << endl;
    for ( int n = 0; n < 7; n++ ){
        cout << reffs_n[n] << ": " << reffs_s[n] << endl;
    }//fr

    cout << endl << "Best Sort Algorithm in steps is " << reffs_n[f_maxmin( reffs_s, 6, 0 )] << " with " << reffs_s[f_maxmin( reffs_s, 6, 0 )] << endl;
    cout << "NOTE: Cycle Sort almost always is the less on steps, for that, it wont be count" << endl << endl;



    cout << endl << "Time (ms) per Algorithm" << endl;
    for ( int n = 0; n < 7; n++ ){
        cout << fixed << setprecision ( 10 );
        cout << reffs_n[n] << ": " << reffs_t[n] << endl;
    }//fr

    cout << endl << "Best Sort Algorithm in times (ms) is " << reffs_n[f_maxmin( reffs_t, 6, 0 )] << " with " << reffs_t[f_maxmin( reffs_t, 6, 0 )] << endl;
    cout << "WARNING: Because is using ctime library, the time will be minimun, recommended use more numbers";


    return 0;
}//main
