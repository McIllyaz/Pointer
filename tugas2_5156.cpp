#include <iostream>
#include <cstring>
using namespace std;

int banyak; 
int counter(char *str) {
    int count = 0;
    bool kataBaru = true;

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            kataBaru = true;
        }
        else if (kataBaru) {
            count++;
            kataBaru = false;
        }
        str++;
    }

    return count;
}

void changer(char *str, char mode){
    while (*str){
        switch (mode){
        case 'a':
            for(int i = 0; i < strlen(str); i++) {
                if(str[i] == ' ') {
                    str[i+1] = tolower(str[i+1]);
                }
            }
            break;
        case 'b':
            *str = toupper(*str);
            break;
            
        case 'c':
            *str = tolower(*str);
            break;
            
        default:
            break;
        }
        str++;
    }
}

void sortbubble(int nilai[], int banyak){
    for (int i = 0; i < banyak; i++){
        for (int j = 0; j < (banyak-1); j++){
            if (nilai[j+1] > nilai[j]){
                int temp = nilai[j+1];
                nilai[j+1] = nilai[j];
                nilai[j] =  temp;
            }
        } 
    }
}

int *carinilai(int nilai[], int banyak, int value){
    for (int i = 0; i < banyak; i++){
        if (nilai[i] == value){
            return &nilai[i];
        }
    }
    return NULL;
}


int main() {
    char input[50];
    cout << "Masukkan kalimat\t: ";
    cin.getline(input, 50);

    //Ini soal nomor 1.
    int jumlahKata = counter(input);
    cout << "Jumlah kata\t\t: " << jumlahKata << endl;
    cout << "================================================================================\n";

    //Ini soal nomor 2.
    changer(input, 'a');
    cout << "Huruf awal kapital\t= " << input << endl;
    changer(input, 'b');
    cout << "Huruf besar\t\t= " << input << endl;
    changer(input, 'c');
    cout << "Huruf kecil\t\t= " << input << endl;
    cout << "================================================================================\n";

    //Ini soal nomor 3.
    cout << "Masukkan banyak data yang ingin di inputkan : ";
    cin >> banyak;

    int nilai[banyak];

    for (int i = 0; i < banyak; i++)
    {
        cout << "Masukkan data ke- " << (i+1) << " : " ;
        cin >> nilai[i];
    }

    sortbubble(nilai, banyak);
    for (int i = 0; i < banyak; i++)
    {
        cout << nilai[i] << " ";
    }

    cout << "\n================================================================================\n";
    int value;
    cout << "Masukkan nilai yang ingin dicari : ";
    cin >> value;
    
    int *ptrNilai = carinilai(nilai, banyak, value);
    if (ptrNilai != NULL) {
        cout << "Nilai " << value << " ditemukan pada alamat memori " << ptrNilai << endl;
    } else {
        cout << "Nilai " << value << " tidak ditemukan" << endl;
    }
    
    return 0;
}