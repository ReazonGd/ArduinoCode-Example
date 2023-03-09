
/*
PROGAM PEREMPATAN

Untuk preview ada di sini : https://wokwi.com/projects/341373428311261779

urutan :
> utara
> timur dan barat
> selatan
*/

// int / integers sellu berisi angka Ex: int myNumber = 18;
// array / kumpulan dari sebuah variabel angka (int) maupun huruf (char). harus ada '[]' di akhir nama variable.
int merah[] = {13, 10, 7}, // kumpulan pin lampu merah.
    utara[] = {13, 12, 11}, // berisi pin lampu merah, kuning, hijau.
    timur[] = {10, 9, 8},
    selatan[] = {7, 6, 5};

// setup dijalankan sekali saat pertama kali saat arduino dihidupkan
void setup() {
  // mengkonfigurasi secara spesifik dari pin 5 sampai 13 sebagai OUTPUT.
  // for / perulangan. menjalankan argument secara berulang saat kondisi terpenuhi. dalam hal ini pinMode() akan diijalankan sampai 9 kali
  for(int i = 5; i < 14; i++){
    // for berisi 3 statment. 
    // statment 1 berisi variable angka. dijalankan 1 kali.
    // statment 2 berisi kondisi. for dijalankan saat kondisi bersifat TRUE. dalam ini ketika statment 1 `i` kurang dari '<' 14.
    // statment 3 dijalankan berulangkali saat statment 2 terpenuhi. tambahan `++` artinya variabel i akan ditambah 1 setiap kali dijalankan.
    pinMode(i, OUTPUT);
  }
}

// fungsi loop akan dipangil arduino itu sendiri secara berulang
void loop() {
  
  // memanggil / menjalankan  function jalan.
  // `` namaFuction(parameter) `` parameter berisi data yang akan dikirimkan.
  jalan(utara);
  jalan(timur);
  jalan(selatan);
}

// Mendeklarasi jalan() sebagai function. dan lampu[] sebagai parameter
/* 
`` void namaFuction(parameter){ argument } ``  
  function adalah sebuah kumpulan kode yang akan dijalankan hanya saat dipanggil.
 kamu bisa mengirim data ke function menggunakan `parameter`. kedalam sebuah functioon.
 function dapat di exsekusi berkali kali.

  `void` adalah salah satu type function yang tidak mengembalikan nilai. 
    lainnya : int - mengembalikan angka, char - menggembalikan String.
  namaFuction ditulis seperti nama variable lainya.
  `parameter` sebuah variable didalam function. kamu dapat menambah parameter sebanyak yang kamu inginkan cukup pisahkan dengan koma ','.
  `argument` kumpulan sebuah kode yang akan dijalankan ketika dipanggil. 
*/
void jalan(int lampu[]) {
  // menghidupkan lampu merah selain lampu[0] / lampu merah dari parameter
  for(int i = 0; i < (sizeof merah / sizeof *merah); i++) {
    if(merah[i] == lampu[0] ) digitalWrite(merah[i], LOW);
    else digitalWrite(merah[i], HIGH);
  }
  // menghidupkan lampu kuning.
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
  
}
