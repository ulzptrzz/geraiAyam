#include <stdio.h>

#define MAX_Jenis 30
#define MAX_potongAyam 10
#define PAJAK 0.10

// buat menyimpan informasi tentang jenis ayam
typedef struct {
    char hitung;
    char nama[50];
    int harga;
} JenisAyam;

// buat menyimpan informasi tentang setiap pesanan
typedef struct {
    int no;
    char jenisPotong;
    int banyak;
    int hargaTotal;
} Pesanan;

// Fungsi untuk mencari harga berdasarkan kode jenis
int mencariHarga(JenisAyam jenis[], char hitung) {
    for (int i = 0; i < MAX_Jenis; i++) {
        if (jenis[i].hitung == hitung) {
            return jenis[i].harga;
        }
    }
    return 0;
}

int main() {
    // Memproses jenis potong
    JenisAyam jenis[MAX_Jenis] = {
        {'D', "Dada", 2500},
        {'P', "Paha", 2000},
        {'S', "Sayap", 1500}
    };

    Pesanan pesanan[MAX_potongAyam];
    int totalPesanan = 0;
    int totalBayar = 0;
    int pajak = 0;

    // Input pesanan
    printf("\nLayar Masukkan\n");
    printf("\nGEROBAK FRIED CHICKEN\n----------------------------------------------\n");
    printf("Kode Jenis Harga\n----------------------------------------------\n");
    printf("D Dada Rp. 2500\n");
    printf("P Paha Rp. 2000\n");
    printf("S Sayap Rp. 1500\n----------------------------------------------\n");
    printf("Banyak Jenis: ");
    scanf("%d", &totalPesanan);

    // Mencari jenis ayam berdasarkan Input
    for(int i = 0; i < totalPesanan; i++) {
        printf("Jenis ke %d\n", i+1);
        printf("Jenis Potong [D/P/S] : ");
        scanf(" %c", &pesanan[i].jenisPotong);
        printf("Banyak Potong : ", i + 1);
        scanf("%d", &pesanan[i].banyak);

        // Hitung total harga untuk jenis tersebut
        pesanan[i].hargaTotal = mencariHarga(jenis, pesanan[i].jenisPotong) * pesanan[i].banyak;
        totalBayar += pesanan[i].hargaTotal;

        // Isi struktur pesanan
        pesanan[i].no = i + 1;
    }

    // Hitung pajak
    pajak = totalBayar * PAJAK;

    // Tampilan layar keluaran
    printf("\nLayar Keluaran\n");
    printf("\nGEROBAK FRIED CHICKEN\n----------------------------------------------\n");
    printf("No\tJenis\tHarga\tBanyak\tJumlah\n");
    printf("  \tPotong\tSatuan\tBeli\tharga\n----------------------------------------------\n");
    
    for (int i = 0; i < totalPesanan; i++) {
        printf("%d\t%c\t%d\t%d\t%d\n",
               pesanan[i].no,
               pesanan[i].jenisPotong,
               mencariHarga(jenis, pesanan[i].jenisPotong),
               pesanan[i].banyak,
               pesanan[i].hargaTotal);
    }

    // Tampilan total & pajak
    printf("\n----------------------------------------------\n\t\tJumlah bayar\tRp. %d\n", totalBayar);
    printf("\t\tPajak 10%%\tRp. %d\n", pajak);
    printf("\t\tTotal Bayar\tRp. %d\n\n", totalBayar + pajak);

    getch();
    return 0;
}
