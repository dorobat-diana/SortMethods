#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void selectionsort(unsigned short arr[],unsigned short n){
unsigned short i,j,min_idx;
for(i=0;i<n-1;i++){                     //everything before 'i' is sorted
    min_idx=i;
    for(j=i+1;j<n;j++)                  //'j' searches elements after 'i' to find the smallest
        if(arr[j]<arr[min_idx])
            min_idx=j;
    swap(arr[min_idx],arr[i]);          //element on 'i' position gets swapped with the smallest element
}                                       //on the right of it and 'i' gets incremented afterwards
}
/**==========================================================*/
void bubblesort(unsigned short arr[],unsigned short n){
unsigned short i;
bool verif=true;
while(verif==true){                     //as long as a swap has happened during a loop, the same loop will repeat itself
    verif=false;                        //at first we say that no loops have happened
    for(i=0;i<n-1;i++)
        if(arr[i]>arr[i+1]){
            verif=true;                 //if a loop happened then make 'verif' true
            swap(arr[i],arr[i+1]);
        }
}
}
/**==========================================================*/
void insertionsort(unsigned short arr[],unsigned short n){
unsigned short i,key;
short j;
for(i=1;i<n;i++){
    key=arr[i];
    for(j=i-1;j>=0&&arr[j]>key;j--) //Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position

        swap(arr[j+1],arr[j]);
    arr[j+1]=key;
}
}
/**==========================================================*/
void merge(int arr[],int firstindex,int mid,int lastindex){ // Merges two subarrays of arr[]. First subarray is arr[firstindex..mid]. Second subarray is arr[mid+1..lastindex]
/*arr=initial array, larr=temporary left array, rarr=temporary right array,
n=nb of elem for larr, m=nb of elem for rarr. firstindex, mid, lastindex are
the indexes of the current array(arr, larr or rarr)
*/
int i,j,k;
int n=mid-firstindex+1;
int m=lastindex-mid;
/* create temp arrays */
int larr[n],rarr[m];
/* Copy data to temp arrays larr[] and rarr[] */
for(i=0;i<n;i++)
    larr[i]=arr[firstindex+i];
for(j=0;j<m;j++)
    rarr[j]=arr[mid+1+j];
/* Merge the temp arrays back into arr[firstindex..lastindex]*/
i=0; // Initial index of first subarray
j=0; // Initial index of second subarray
 // Initial index of merged subarray
for(k=firstindex;i<n&&j<m;k++){
    if(larr[i]<=rarr[j]){
        arr[k]=larr[i];
        i++;
    }
    else{
        arr[k]=rarr[j];
        j++;
    }
}
/* Copy the remaining elements of larr[], if there are any */
while(i<n){
    arr[k]=larr[i];
    i++;
    k++;
}
/* Copy the remaining elements of rarr[], if there are any */
while(j<m){
    arr[k]=rarr[j];
    j++;
    k++;
}
}

void mergesort(int arr[],int firstindex,int lastindex){
// firstindex is for left index and lastindex is right index of the sub-array of arr to be sorted
if(firstindex<lastindex){
    //Same as (firstindex+lastindex)/2, but avoids overflow for large firstindex and lastindex
    int mid=firstindex+(lastindex-firstindex)/2;
    //Sort first and second halves
    mergesort(arr,firstindex,mid);
    mergesort(arr,mid+1,lastindex);
    merge(arr,firstindex,mid,lastindex);
}
}
/**==========================================================*/
int partition(int arr[],int firstindex,int lastindex){  // This function takes the last element as pivot, places the pivot element at its correct position in sorted array, and places all the smaller elements than the pivot to the left of it and all the greater elements to the right of it
int j,pivot=arr[lastindex],i=firstindex;// Index of smaller element
for(j=firstindex;j<=lastindex-1;j++){
    // If current element is smaller than the pivot
    if(arr[j]<pivot)
        swap(arr[i++],arr[j]);
}
swap(arr[i],arr[lastindex]);  //its arr[lastindex] instead of pivot because the function swaps the elements on the indexes ("pointed" by the indexes).swap() looks at the indexes not at the elements themselves
return (i);
}

void quicksort(int arr[],int firstindex,int lastindex){
if(firstindex<lastindex){
    // pi is partitioning index, arr[pi] is at the right place
    int pi=partition(arr,firstindex,lastindex);
    // Separately sort elements before
    // partition and after partition
    quicksort(arr,firstindex,pi-1);
    quicksort(arr,pi+1,lastindex);
}
}
/**==========================================================*/
bool isSorted(int arr[],int n){   //To check if array is sorted or not
while(--n>=1)
    if (arr[n]<arr[n-1])
        return false;
return true;
}

void shuffle(int arr[],int n){    //To generate permuatation of the array
srand(time(NULL));  //srand is used here instead of the main subfunction knowing that Bogo Sort doesnt have a patter and that the shuffle is as random as possible
for(int i=0;i<n;i++)
    swap(arr[i],arr[(rand()%100+1)%n]);
}

void bogosort(int arr[],int n){   //Sorts array a[0..n-1] using Bogo Sort
//if array is not sorted then shuffle the array again
while(!isSorted(arr,n))
    shuffle(arr,n);
}
/**==========================================================*/

int main(){
cout<<"                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      \n                       |  Un algoritm de sortare este un algoritm care pune elementele unei liste | \n                         \\ intr-o anumita ordine. Cel mai des intalnite sunt ordinea numerica si / \n                            \\ ordinea lexicografica. Chiar daca problema sortarii unei liste / \n                               \\  de elemente pare triviala, ea a fost si este cerce-   / \n                                  \\  tata in mod foarte serios. Ca rezultat al aces- / \n                                     \\    tei cercetari s-au elaborat mai multi   / \n                                        \\    algoritmi de sortare. Primii din- / \n                                           |   tre ei dateaza de prin anii  | \n                                         /   '50 (bubble sort-1956), iar cei  \\ \n                                      /   mai recenti au aparut cu putini ani in  \\ \n                                 / urma (library sort-2004). O asemenea activitate de \\ \n                             / cercetare este pe deplin justificata deoarece, pe de o parte \\ \n                          /  rezolvarea in mod eficient a problemei sortarii nu este deloc sim-\\ \n                        /   pla, iar pe de alta parte sortarea este o operatie foarte des folosi-  \\ \n                     | ta si este necesar ca ea sa se efectueze intr-un mod cat se poate de eficient.| \n                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      \n";
for(unsigned long delay=0;delay<299999999;delay++); //in loc de Sleep() sau sleep_for()
cout<<".";
for(unsigned long delay=0;delay<299999999;delay++);
cout<<".";
for(unsigned long delay=0;delay<299999999;delay++);
cout<<".";
for(unsigned long delay=0;delay<299999999;delay++);
cout<<"\n";
char m;
do{
    cout<<"\n(introduceti orice caracter pentru a continua)\n";
    cin>>m;
    cin.ignore(256,'\n');
    cout<<"\n^^^^^^^^^^^^^^^^^^\n0. Detalii autor\n1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n6. Bogo Sort\n7. Alti algoritmi de sortare \n8. Comparatia algoritmilor\npentru a se iesi din aplicatie introduceti orice alt caracter\n";
    cin>>m;
    cin.ignore(256,'\n');
    switch(m){
        case '0':{
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout<<"Nume si prenume:Petrea Cristian-Stefanel\nScoala de provenienta:Liceul Teoretic 'Callatis'\n";
            cout<<"Clasa:a XII-a A\nProfesor Coordonator:Magaz Georgeta\nTitlu proiect:Algoritmi de sortare";
        break;}
        case '1':{
            cout<<"\n~~~~~~~~~~~~~~~\nSelection Sort\n~~~~~~~~~~~~~~~\n";
            int sls_m;  //sls-->selection sort
            cout<<"-pentru informatii legate de algoritmul de sortare selectat introduceti 0 \n-pentru explicarea functionalitatii algoritmului dar si pentru rularea acestuia introduceti 1\n";
            cin>>sls_m;
            if(sls_m==0){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nSelection Sort (sau sortarea prin selectie) este unul dintre cei mai simpli \nalgoritmi de sortare si probabil cel mai bun algoritm de sortare in complexitate \nO(n^2), datorita numarului foarte mic de interschimbari pe care le efectueaza \nin comparatie cu Bubble Sort, dar si a constantei 1/2 din spatele acestei \ncomplexitati. Selection Sort este ineficient in cazul listelor mari, insa \nacesta este cunoscut pentru dificultatea usoara si performanta acestuia \nin cazul unei memorii limitate. \n";
            }
            else if(sls_m==1){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nSortarea foloseste doua variabile 'i' si 'j' drept indecsi pentru a realiza \ninterschimbari intre elementele de pe pozitiile acestora. Programul se foloseste \nde 'i' acesta pentru a realiza sortarea. Programul cauta cel mai mic element \nde la dreapta lui 'i' cu ajutorul lui 'j'. Dupa gasirea acestuia se \ninterschimba valorile dintre 'i' si cel mai mic element gasit iar 'i'-ul se \nincrementeaza. Astfel partea din stanga a lui 'i' este sortata.\n";
                unsigned short n;
                ifstream fisier1("sir nesortat.txt");
                fisier1>>n;
                unsigned short arr[n],i=0;
                while(fisier1>>arr[i])
                    i++;
                fisier1.close();
                cout<<"pentru sirul de numere:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                selectionsort(arr,n);
                cout<<"\navem sirul sortat:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
            }
            else{
                cout<<"Oops! Se pare ca a fost introdusa o valoare gresita.\n";
            }
        break;}
        case '2':{
            cout<<"\n~~~~~~~~~~~~~~~\nBubble Sort\n~~~~~~~~~~~~~~~\n";
            int bbs_m;  //bbs-->bubble sort
            cout<<"-pentru informatii legate de algoritmul de sortare selectat introduceti 0 \n-pentru explicarea functionalitatii algoritmului dar si pentru rularea acestuia introduceti 1\n";
            cin>>bbs_m;
            if(bbs_m==0){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nBubble Sort (sau sortarea prin metoda bulelor) este cea mai simpla metoda de \nsortare a unui vector. Aceasta se numeste metoda bulelor deoarece modul \nin care elementele vectorului se deplaseaza spre pozitia lor finala poate fi \nasemanat cu felul in care bulele de aer se ridica in partea superioara a unei \nsticle. Cu toate ca Bubble Sort este un algoritm foarte simplu, acesta este si \nfoarte ineficient. In cel mai rau caz, acesta facand O(n^2) pasi. Un n vine de la \nnumarul de iteratii din cadrul for-ului, iar celalalt din numarul de intrari in \ndo while. ";
                cout<<"Cel mai rau caz este cel in care vectorul dat este sortat descrescator \n(in ordinea opusa celei in care vrem sa-l sortam). Singurul avantaj al Bubble \nSort-ului e ca este proiectat de asa natura incat se opreste la doar o intrare \nin do while dupa ce vectorul este deja sortat. Foarte putini algoritmi de sortare \nsunt capabili sa detecteze daca au terminat de sortat vectorul si sa se opreasca. \nDesi exista mai multe metode de sortare cu aceeasi complexitate ca Bubble Sort, \nele sunt mai rapide in practica. Asta se datoreaza numarului foarte mare de \ninterschimbari (swap-uri) efectuate de Bubble Sort. In medie, eficienta acestui \nalgoritm reprezinta 70% din cea a sortarii prin selectie.";
            }
            else if(bbs_m==1){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nSortarea foloseste un vector 'i' drept index,comparand valoarea elementului de \npe pozitia acestuia cu valoarea elementului vecin (in general cel din dreapta). \nDaca valoarea din dreapta este mai mica decat cea curenta atunci se interschimba \nvalorile urmand ca indexul sa fie incrementat. Pentru a se sorta sirul este \nnecesara repetitia acestui pas de cate ori este nevoie pana cand programul \ndetecteaza ca sirul este sortat.\n";
                unsigned short n;
                ifstream fisier1("sir nesortat.txt");
                fisier1>>n;
                unsigned short arr[n],i=0;
                while(fisier1>>arr[i])
                    i++;
                fisier1.close();
                cout<<"pentru sirul de numere:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                bubblesort(arr,n);
                cout<<"\navem sirul sortat:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
            }
            else{
                cout<<"Oops! Se pare ca a fost introdusa o valoare gresita.\n";
            }
        break;}
        case '3':{
            cout<<"\n~~~~~~~~~~~~~~~\nInsertion Sort\n~~~~~~~~~~~~~~~\n";
            int iss_m;  //iss-->insertion sort
            cout<<"-pentru informatii legate de algoritmul de sortare selectat introduceti 0 \n-pentru explicarea functionalitatii algoritmului dar si pentru rularea acestuia introduceti 1\n";
            cin>>iss_m;
            if(iss_m==0){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nSortarea prin insertie (Insertion Sort) este o metoda de sortare a vectorilor \nin complexitate O(n^2) oarecum asemanatoare cu cea prin selectie. Primul for \nefectueaza O(n) iteratii, iar al doilea, in cel mai rau caz, tot O(n). Prin \nurmare, complexitatea in timp a sortarii prin insertie este O(n^2). \n";
            }
            else if(iss_m==1){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nAlgoritmul se foloseste de un index 'j' pentru a sorta toate elementele din \nstanga lui 'i'. Programul muta spre dreapta toate elementele din stanga lui 'i' \nmai mari decat acesta, urmand ca acesta sa fie pus pe pozitia lui 'j'. In \ncele din urma 'i'-ul este incrementat.\n";
                unsigned short n;
                ifstream fisier1("sir nesortat.txt");
                fisier1>>n;
                unsigned short arr[n],i=0;
                while(fisier1>>arr[i])
                    i++;
                fisier1.close();
                cout<<"pentru sirul de numere:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                insertionsort(arr,n);
                cout<<"\navem sirul sortat:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
            }
            else{
                cout<<"Oops! Se pare ca a fost introdusa o valoare gresita.\n";
            }
        break;}
        case '4':{
            cout<<"\n~~~~~~~~~~~~~~~\nMerge Sort\n~~~~~~~~~~~~~~~\n";
            int mgs_m;  //mgs-->merge sort
            cout<<"-pentru informatii legate de algoritmul de sortare selectat introduceti 0 \n-pentru explicarea functionalitatii algoritmului dar si pentru rularea acestuia introduceti 1\n";
            cin>>mgs_m;
            if(mgs_m==0){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nMerge Sort este unul dintre cei mai optimi algoritmi de sortare, acesta fiind \nbazat pe comparari eficiente. Algoritmul care sta la baza Merge Sort-ului este \nde tip divide et impera si are o complexitate de O(nlogn). \n";
            }
            else if(mgs_m==1){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nFiind un algoritm bazat pe metoda divide et impera, Merge Sort se foloseste de \naceasta metoda pentru a sorta eficient un sir de numere. Este necesara existenta \na doua subprograme astfel: primul subprogram 'mergesort' imparte sirul in \njumatati pana cand fiecare parte ajunge sa consiste dintr-un singur element. \nAl doilea subprogram 'merge' creeaza doua subsiruri 'larr' si 'rarr', compara \nelementele acestora si dupa le cupleaza in functie de recursivitatea \nprogramului 'mergesort'. \n";
                int n;
                ifstream fisier1("sir nesortat.txt");
                fisier1>>n;
                int arr[n],i=0;
                while(fisier1>>arr[i])
                    i++;
                fisier1.close();
                cout<<"pentru sirul de numere:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                mergesort(arr,0,n-1);
                cout<<"\navem sirul sortat:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
            }
            else{
                cout<<"Oops! Se pare ca a fost introdusa o valoare gresita.\n";
            }
        break;}
        case '5':{
            cout<<"\n~~~~~~~~~~~~~~~\nQuick Sort\n~~~~~~~~~~~~~~~\n";
            int qks_m;  //qks-->quick sort
            cout<<"-pentru informatii legate de algoritmul de sortare selectat introduceti 0 \n-pentru explicarea functionalitatii algoritmului dar si pentru rularea acestuia introduceti 1\n";
            cin>>qks_m;
            if(qks_m==0){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nCa si Merge Sort, Quick Sort este un algoritm de sortare de tip divide et \nimpera. Acesta ia un element drept pivot, impartind sirurile din jurul lui. \nEste cunoscut de multi drept cel mai bun algoritm de sortat pentru avantajul \npe care il are in a sorta liste mari eficient. Exista diferite modalitati de \na alege un pivot: -se alege primul element \n-se alege ultimul element \n-se alege elementul din centru \n-se alege un element aleatoriu \n";
            }
            else if(qks_m==1){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nQuick Sort foloseste un element drept pivot. Spre deosebire de Merge Sort, \npivotul poate fi la centru, sau in oricare alta locatie. Acest lucru este \ndeterminat de subprogramul 'quicksort'. Pe langa acestea, pe cand Merge Sort \nintai imparte sirul in parti de cate un element fiecare, mai apoi sortandu-le, \n";
                cout<<"Quick Sort ia pivotul, muta toate elementele mai mici decat acesta spre stanga \nlocatiei unde elementul 'pivot' trebuie sa se afle si cele mai mari in dreapta. \nDupa ce gaseste locul in care acesta trebuie sa fie, algoritmul imparte sirul \nin doua parti, luand mai intai ceea ce se afla la stanga pivotului si repetand \naceiasi pasi pana cand sirul este sortat. \n";
                int n;
                ifstream fisier1("sir nesortat.txt");
                fisier1>>n;
                int arr[n],i=0;
                while(fisier1>>arr[i])
                    i++;
                fisier1.close();
                cout<<"pentru sirul de numere:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                quicksort(arr,0,n-1);
                cout<<"\navem sirul sortat:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
            }
            else{
                cout<<"Oops! Se pare ca a fost introdusa o valoare gresita.\n";
            }
        break;}
        case '6':{
            cout<<"\n~~~~~~~~~~~~~~~\nBogo Sort\n~~~~~~~~~~~~~~~\n";
            int bgs_m;  //bgs-->bogo sort
            cout<<"-pentru informatii legate de algoritmul de sortare selectat introduceti 0 \n-pentru explicarea functionalitatii algoritmului dar si pentru rularea acestuia introduceti 1\n";
            cin>>bgs_m;
            if(bgs_m==0){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nBogo Sort, cunoscut si drept Stupid Sort, Slow Sort, Shotgun Sort sau Monkey \nSort, este posibil cel mai ineficient algoritm de sortare bazat pe o metoda de \ngenerare si testare. Acesta amesteca elementele intre ele, analizeaza daca \nsirul este sortat iar, in caz de nu este, le amesteca din nou, acest lucru \nrepetandu-se pana cand vectorul ajunge sa fie sortat. Complexitatea acestuia \neste in general O(n*n!) sau, in cel mai rau caz, O(infinit) daca nu are \no margine superioara. \n";
            }
            else if(bgs_m==1){
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nSortarea foloseste trei subprograme astfel: 'bogosort' verifica daca sirul este \nsortat prin intermediul subprogramului 'isSorted'. Cat timp isSorted este fals, \nacesta apeleaza subprogramul 'shuffle' care va amesteca sirul ''la intamplare''. \n";
                int n,i=0;
                int arr[5]={56,3,17,4,2};
                n=5;
                cout<<"pentru sirul de numere:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                for(unsigned long delay=0;delay<999999999;delay++);
                for(unsigned long delay=0;delay<999999999;delay++);
                for(unsigned long delay=0;delay<999999999;delay++);
                cout<<"\nOof, se pare ca va trebui sa astepti un moment avand in vedere metoda de sortare aleasa :\\";
                bogosort(arr,n);
                cout<<"\navem sirul sortat:";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
            }
            else{
                cout<<"Oops! Se pare ca a fost introdusa o valoare gresita.\n";
            }
        break;}
        case '7':{
            cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~\nAlti algoritmi de sortare\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout<<"Pana in ziua de astazi s-au creat peste 30 de algoritmi de sortare si numarul \nlor va continua sa creasca in viitor. Majoritatea metodelor de a sorta un sir \nsunt derivate din algoritmi cunoscuti precum sortarea prin selectie sau a \nbulelor. Printre alte metode de sortare se numara si: \n";
            cout<<"(introduceti orice caracter pentru a continua)\n";
            char key[20];
            cin.get(key,21,'\n');
            cin.ignore(21,'\n');
            cout<<"Next up: Heap Sort";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<"\n\n-Heap Sort (derivat din Selection Sort) care in prima faza reordoneaza \nelementele sirului pentru a satisface proprietatea arborelui (heap). Algoritmul \nschimba apoi in mod repetat prima valoare a listei cu ultima valoare, micsorand \nintervalul de elemente considerate in operatia heap si mutand noua prima valoare \nin pozitia sa in heap. Acestea se repeta pana cand intervalul valorilor luate \nin considerare are o valoare in lungime. \n";
            cout<<"(introduceti orice caracter pentru a continua)\n";
            cin.get(key,21,'\n');
            cin.ignore(21,'\n');
            cout<<"Next up: Gnome Sort";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<"\n\n-Gnome Sort (numit si Stupid Sort) care este bazat pe ideea ca daca elementul \ncurent si cel din stanga sunt in ordinea corespunzatoare 'i' se muta la dreapta, \ninsa daca elementul din stanga este mai mare decat cel curent acestea isi \nschimba pozitiile iar 'i' se da cu un pas inapoi. Cand 'i' trece de capatul \nsirului se considera ca sirul a fost sortat. \n";
            cout<<"(introduceti orice caracter pentru a continua)\n";
            cin.get(key,21,'\n');
            cin.ignore(21,'\n');
            cout<<"Next up: Cocktail Sort";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<"\n\n-Cocktail Sort (derivat din sortarea prin metoda bulelor) care spre deosebire \nde Bubble Sort (cauta doar cel mai mic numar de dupa capatul din stanga), \nacesta cauta in acelasi timp si cel mai mic numar de dupa capatul din stanga \ndar si cel mai mare numar de dinaintea capatului din dreapta, sortand astfel \npe ambele parti sirul pana la centru, metoda fiind asemanatoare agitarii \nunui cocktail. ";
        break;}
        case '8':{
            cout<<"Algoritm      |Time complexity                         |Space complexity \n              |Best      |Average       |Worst         |Worst \n______________|__________|______________|______________|________________\nQuicksort     |O(nlog(n))|O(nlog(n))    |O(n^2)        |O(nlog(n)) \nMergesort     |O(nlog(n))|O(nlog(n))    |O(nlog(n))    |O(n)       \nHeapsort      |O(nlog(n))|O(nlog(n))    |O(nlog(n))    |O(1)       \nSelection Sort|O(n^2)    |O(n^2)        |O(n^2)        |O(1)       \nBubble Sort   |O(n)      |O(n^2)        |O(n^2)        |O(1)       \nInsertion Sort|O(n)      |O(n^2)        |O(n^2)        |O(1)       \nShell Sort    |O(nlog(n))|O(n(log(n))^2)|O(n(log(n))^2)|O(1)       \nTree Sort     |O(nlog(n))|O(nlog(n))    |O(n^2)        |O(n)       \nBucket Sort   |O(n+k)    |O(n+k)        |O(n^2)        |O(n)       \nRadix Sort    |O(nk)     |O(nk)         |O(nk)         |O(n+k)     \nCounting Sort |O(n+k)    |O(n+k)        |O(n+k)        |O(k)       \n \n";
        break;}
        default:{
            cout<<"Iesire din aplicatie";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
            cout<<".";
            for(unsigned long delay=0;delay<499999999;delay++);
        break;}
    }
}while(m>=48&&m<=56);
cout<<"\n\n\n\n";
}



