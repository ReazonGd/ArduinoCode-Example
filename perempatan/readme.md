# Program Perempatan #

preview : [https://wokwi.com/projects/341373428311261779](https://wokwi.com/projects/341373428311261779)

# penjelasan

  Program perempatan, program sederhana untuk miniatur perempatan. progam ini disarankan untuk digunakan untuk lebih dari 2 arah.
  
##  variable

```c
int merah[] = {13, 10, 7}, // kumpulan pin lampu merah.
    utara[] = {13, 12, 11}, // berisi pin lampu merah, kuning, hijau.
    timur[] = {10, 9, 8},
    selatan[] = {7, 6, 5};
```

Terdapat 2 variable array yang paling penting. `merah` dan `utara, timur, selatan (arah)`. merah adalah kumpulan warna merah satu lampulalu lintas. dan yang lain adalah lampu lalulintas.
semisal:
```c
int utara[] = {
      13, // lampu warna merah
      12, // lampu warna kuning
      11  // lampu warna hijau
    };
```

Dilihat dari contoh variable di atas, `utara` memiliki tiga anka. 13,12,11 ini mewakili pin untuk masing masing lampu.

## function
```c
void jalan(int lampu[]) {
  ...
}
```

Terdapat 1 function penting disini yaitu `jalan()`. menggunakan parameter lampu yang akan dijalankan. semisal :

```c
jalan(utara); 
```
`utara` adalah aray yang berisi pin untuk lampu lalulintas bagian utara. mari kita proses.

```c
 for(int i = 0; i < (sizeof merah / sizeof *merah); i++) {
    if(merah[i] == lampu[0] ) digitalWrite(merah[i], LOW);
    else digitalWrite(merah[i], HIGH);
  }
```
Pertama, seperti code diatas. semua lampu merah pada semua lampu. inilah pentingnya variable `merah`. perintah ini akan membuat semua pin yang berada di variable `merah` akan menyala kecuali jika pin tersebut sama dengan pin pertama pada parameter (lampu[]).

selanjutnya tinggal kita pakai kode berikut: 
```c
  digitalWrite(lampu[1], HIGH);
  delay(500);
  // mematikan lampu kuning dan menghidupkan lampu hijau.
  digitalWrite(lampu[1], LOW);
  digitalWrite(lampu[2], HIGH);
  // delay 1 detik dikali angka random dari 1 sampai 3. artinya lampu hiijau hidup diantara 1 sampai 3 detik.
  delay(1000 * random(1,3));
  // mematikan lampu hijau lalu menghidupkan lampu kuning
  digitalWrite(lampu[2], LOW);
  digitalWrite(lampu[1], HIGH);
  delay(700) ;
  // mematikan lampu kuning.
  digitalWrite(lampu[1], LOW);
```
Menghidupkan pin kedua(kuning) dari parameter. lalu ke tiga(hijau) dan ke kuning lagi dan selesai.

Q : lalu dimana dan ssat apa harus memaggil `jalan()`?
A : saat berada dalam function `loop` semisal:

```c
void loop() {
  jalan(utara);
  jalan(timur);
  jalan(selatan);
}
```

# Kostumisasi.

jika kalian ingin mungubah pin atau hanya memerlukan 2 lampu saja, maka ikuti langkah berikut.

1. menggurangi / menambah lampulalulintas.
 
1.1 menguragi : untuk megurangi hapus salah satu variable arah. misal, kita hapus variable `selatan`.
```c
int merah[] = {13, 10},
    utara[] = {13, 12, 11},
    timur[] = {10, 9, 8};
```    
untuk mengurangi arah kalian hapus variable arah dan menghapus pin lampu merah dari arah tersebut pada variable `merah` selanjutnya hapus finctin `jalan(selatan);` pada loop() function.

1.2 menambahkan : mari buat satu variable baru semisal `barat`.
```c
int merah[] = {13, 10, 7, 4},
    utara[] = {13, 12, 11},
    timur[] = {10, 9, 8},
    selatan[] = {7, 6, 5},
    barat[] = {4, 3, 2};
```
sama seperti menguragi, menabahkan lampu lalu lintas harus menabahkan lampu merah pada `merah`. lalu menabahkan function `jalan(barat)` pada loop() function.

# End

semoga membantu kalian.



