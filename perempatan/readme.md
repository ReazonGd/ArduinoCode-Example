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

Terdapat 1 function penting disini yaitu `jalan()`
