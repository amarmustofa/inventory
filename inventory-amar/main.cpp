#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


int main()
{

    vector<int>::iterator penunjuk;
    vector< vector<string> > items{ {"item a",  "8"}, {"item b",   "5"}, {"item c",   "7"}, {"item d",  "9"}, };
    vector<int> inventory;

    int maks, pilihan, hapus;
    srand(static_cast<unsigned int>(time(0)));
    char ulang;

    cout << "Jumlah Items : " << items.size() << endl;
    cout << "Maksimal Inventory : "; cin >> maks;

    while(true){
        cout << "Inventory System" << endl;
        cout << "1. Tampilkan Inventory" << endl;
        cout << "2. Hapus Item" << endl;
        cout << "3. Tambah Item" << endl;
        cout << "Masukan Pilihan Anda : "; cin >> pilihan;

        switch(pilihan){
            case 1 :
                if(!inventory.empty()){
                    for(penunjuk=inventory.begin(); penunjuk!=inventory.end(); penunjuk++){
                        cout << items[*penunjuk][0] << ", stat : " << items[*penunjuk][1] << endl;
                    }
                }else{
                    cout << "Inventory Kosong" << endl;
                }
                break;
            case 2 :
                if(!inventory.empty()){
                    cout << "Hapus Item Ke - : "; cin >> hapus;
                    inventory.erase(inventory.begin()+(hapus-1));
                    cout << "Jumlah Inventory Sekarang : " << inventory.size() << endl;
                }else{
                    cout << "Inventory masih kosong" << endl;
                }
                break;
            case 3 :
                if(inventory.size() < maks){
                    int acak = rand() % items.size();
                    inventory.push_back(acak);
                    cout << "Anda mendapat : " << items[acak][0] << " , stat : " << items[acak][1] << endl;
                    cout << "Jumlah inventory sekarang : " << inventory.size() << endl;
                }else{
                    cout << "Inventory Penuh" << endl;
                }
                break;
            default :
                cout << "Pilihan Tidak Tersedia" << endl;
                break;
        }

        cout << "Gunakan Inventory Lagi [y/n] ? "; cin >> ulang;
        if(ulang == 'n' || ulang == 'N'){
            break;
        }

    }

    return 0;
}
