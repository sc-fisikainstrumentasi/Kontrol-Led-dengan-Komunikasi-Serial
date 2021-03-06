
/*SC-FISIKA INSTRMENTASI UIN SUKA
 Note : 
 a. Perhatikan Setiap penjelasan progam
 b. penjelasan progam diawali dengan tanda "//"
 c. penjelasan progam bukan bagian dari skecth progam yang akan di jalankan

 PROYEK : Komunikasi Serial Arduino
 
*/

int LED = 13; //memberikan variable pada pin 13 dengan nama LED


//fungsi void setup untuk mendelarasikan pin pada arduino & menjalankan progam sekali
void setup()
{
    pinMode(LED, OUTPUT);//mendelarasikan LED sebagai OUTPUT
    Serial.begin(9600); //untuk menentukan kecepatan pengiriman dan penerimaan data melalui port serial(9600 bit per detik (bps))

}


//fungsi void loop untuk menjalankan progam berulangkali
void loop() 
{
  if (Serial.available())//Untuk mengecek apakah data sudah ada di buffer penerima
    {
      if (Serial.parseInt() == 1)//membuat code dalam bentuk angka untuk menyalakan LED
        {
          digitalWrite(LED, HIGH);//Memberi LED tegangan Max (5 Volt)
          Serial.println("Command completed LED turned ON"); //mengirim data string tersebut ke Serial Monitor
        }

      else if (Serial.parseInt()== 2)//membuat code dalam bentuk angka untuk Mematikan LED
        {
          digitalWrite(13, LOW);//Memberi LED tegangan Min (0 Volt)
          Serial.println("Command completed LED turned OFF");//mengirim data string tersebut ke Serial Monitor

        }
    }

}

/*
Fungsi-Fungsi Komuniasi Serial ARDUINO

if (Serial) : Untuk mengecek apakah Port sudah siap
Serial.available() : Untuk mengecek apakah data sudah ada di buffer penerima
Serial.begin() : untuk mengeset kecepatan transmisi data
Serial.end() : Untuk menon-aktifkan pin rx dan tx sbg fungsi serial dan kembali sbg pin I/O
Serial.find() : mencari string dlm buffer data
Serial.findUntil(): mencari buffer data sampai data dgn panjang/terminator nya yg diberikan ditemukan
Serial.flush(): menunggu data terkirim semua
Serial.parseFloat(): mengambil data float pertama dari data di buffer serial.
Serial.parseInt(): mengambil data integer pertama dari data di buffer serial.
Serial.peek(): mengambil data berikutnya di bufer penerima
Serial.print() : mengirim data ASCII
Serial.println() : mengirimdata ASCII + CR,LF (kode enter)
Serial.read(): membaca data yg diterima
Serial.readBytes(): membaca data byte yg diterima
Serial.readBytesUntil()
Serial.setTimeout(): mengeset batas maksimum waktu  tunggu(timeout)  transmisi data.
Serial.write() : mengirim data byte (numerik)
Serial.serialEvent(): fungsi ini akan dipanggil jika data datang/diterima.berlaku spt interupsi serial.

*/
