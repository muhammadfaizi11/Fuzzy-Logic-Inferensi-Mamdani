//--- Fuzzy Variabel ---
//Variabel Nilai Linguistik Input
float mLeftMarker[4] = {170, 170, 240, 260};
float vLeftMarker[4] = {240, 260, 280, 300};
float leftMarker[4] = {280, 300, 330, 350};
float trackMarker[4] = {330, 350, 370, 390};
float rightMarker[4] = {370, 390, 420, 440};
float vRightMarker[4] = {420, 440, 460, 480};
float mRightMarker[4] = {460, 480, 550, 550};
float mNegatif[4] = {-20, -20, -15, -10};
float vNegatif[4] = {-15, -10, -10, -5};
float negatif[4] = {-10, -5, -5, 0};
float zero[4] = {-5, 0, 0, 5};
float positif[4] = {0, 5, 5, 10};
float vPositif[4] = {5, 10, 10, 15};
float mPositif[4] = {10, 15, 20, 20};

//Variabel Nilai Linguistik Output
float veryLow[4] = {25, 25, 35, 45};
float low[4] = {35, 45, 55, 65};
float mediumLow[4] = {55, 65, 75, 85};
float medium[4] = {75, 85, 95, 105};
float mediumFast[4] = {95, 105, 115, 125};
float fast[4] = {115, 125, 135, 145};
float veryFast[4] = {135, 145, 155, 155};

//Variabel Fuzzyfikasi
float magnetic = 0;
float magneticPrev = 0;
float selisih = 0;
float mlm; //most left marker
float vlm; //very left marker
float lm; //lef marker
float tm; //track marker
float rm; //right marker
float vrm; //very right marker
float mrm; //most rig ht marker
float mn; //most negatif
float vn; //very negatif
float n; //negatif
float z; //zero
float p; //positif
float vp; //very positif
float mp; //most positif

//Variabel Inferensi
float maxA, maxB, maxC, maxD, maxE, maxF, maxG, maxH, maxI, maxJ, maxK, maxL, maxM, maxN, maxO;

//Variabel Defuzzifikasi
float hasilPembilang1, hasilPembilang2;
float hasilPenyebut1, hasilPenyebut2;
float hasilDefuzzyfikasi1, hasilDefuzzyfikasi2;
float pengaliA, pengaliB, pengaliC, pengaliD, pengaliE, pengaliF, pengaliG, pengaliH, pengaliI, pengaliJ, pengaliK, pengaliL, pengaliM, pengaliN, pengaliO;
float sampelAKiri, sampelBKiri, sampelCKiri, sampelDKiri, sampelEKiri, sampelFKiri, sampelGKiri, sampelHKiri, sampelIKiri, sampelJKiri, sampelKKiri, sampelLKiri, sampelMKiri, sampelNKiri, sampelOKiri;
float sampelAKanan, sampelBKanan, sampelCKanan, sampelDKanan, sampelEKanan, sampelFKanan, sampelGKanan, sampelHKanan, sampelIKanan, sampelJKanan, sampelKKanan, sampelLKanan, sampelMKanan, sampelNKanan, sampelOKanan;
//float titik_sampelAKiri,titik_sampelBKiri, titik_sampelCKiri, titik_sampelDKiri, titik_sampelEKiri, titik_sampelFKiri, titik_sampelGKiri, titik_sampelHKiri, titik_sampelIKiri, titik_sampelJKiri, titik_sampelKKiri, titik_sampelLKiri, titik_sampelMKiri, titik_sampelNKiri, titik_sampelOKiri;
//float titik_sampelAKanan,titik_sampelBKanan, titik_sampelCKanan, titik_sampelDKanan, titik_sampelEKanan, titik_sampelFKanan, titik_sampelGKanan, titik_sampelHKanan, titik_sampelIKanan, titik_sampelJKanan, titik_sampelKKanan, titik_sampelLKanan, titik_sampelMKanan, titik_sampelNKanan, titik_sampelOKanan;
float jumlah_sampelAKiri, jumlah_sampelBKiri, jumlah_sampelCKiri, jumlah_sampelDKiri, jumlah_sampelEKiri, jumlah_sampelFKiri, jumlah_sampelGKiri, jumlah_sampelHKiri, jumlah_sampelIKiri, jumlah_sampelJKiri, jumlah_sampelKKiri, jumlah_sampelLKiri, jumlah_sampelMKiri, jumlah_sampelNKiri, jumlah_sampelOKiri;
float jumlah_sampelAKanan, jumlah_sampelBKanan, jumlah_sampelCKanan, jumlah_sampelDKanan, jumlah_sampelEKanan, jumlah_sampelFKanan, jumlah_sampelGKanan, jumlah_sampelHKanan, jumlah_sampelIKanan, jumlah_sampelJKanan, jumlah_sampelKKanan, jumlah_sampelLKanan, jumlah_sampelMKanan, jumlah_sampelNKanan, jumlah_sampelOKanan;
float titik_sampel = 1;

//--- Fuzzy Logic ---
//Fuzzyfikasi
void fuzzyfikasi(){
  //Inisiasi awal nilai tiap membership function sama dengan nol
  mlm=0; vlm=0; lm=0; tm=0; rm=0; vrm=0; mrm=0;
  mn=0; vn=0; n=0; z=0; p=0; vp=0; mp=0;
  magnetic = 279;
  selisih = -12;
  
  //**Membership function input sensor**
  //Most Left Marker
  if(magnetic >= mLeftMarker[1] && magnetic <= mLeftMarker[2]){
    mlm = 1;
  }
  else if(magnetic > mLeftMarker[2] && magnetic < mLeftMarker[3]){
    mlm = (float)((mLeftMarker[3] - magnetic)/(mLeftMarker[3] - mLeftMarker[2]));
  }
  else if(magnetic < mLeftMarker[0] && magnetic > mLeftMarker[3]){
    mlm = 0;
  }

  //Very Left Marker
  if(magnetic >= vLeftMarker[1] && magnetic <= vLeftMarker[2]){
    vlm = 1;  
  }
  else if(magnetic > vLeftMarker[0] && magnetic < vLeftMarker[1]){
    vlm = (float)((magnetic - vLeftMarker[0])/(vLeftMarker[1] - vLeftMarker[0]));
  }
  else if(magnetic > vLeftMarker[2] && magnetic < vLeftMarker[3]){
    vlm = (float)((vLeftMarker[3] - magnetic)/(vLeftMarker[3] - vLeftMarker[2]));
  }
  else if(magnetic < vLeftMarker[0] && magnetic > vLeftMarker[3]){
    vlm = 0;
  }

  //Left Marker
  if(magnetic >= leftMarker[1] && magnetic <= leftMarker[2]){
    lm = 1;
  }
  else if(magnetic > leftMarker[0] && magnetic < leftMarker[1]){
    lm = (float)((magnetic - leftMarker[0])/(leftMarker[1] - leftMarker[0]));
  }
  else if(magnetic > leftMarker[2] && magnetic < leftMarker[3]){
    lm = (float)((leftMarker[3] - magnetic)/(leftMarker[3] - leftMarker[2]));
  }
  else if(magnetic < leftMarker[0] && magnetic > leftMarker[3]){
    lm = 0;
  }

  //Track Marker
  if(magnetic >= trackMarker[1] && magnetic <= trackMarker[2]){
    tm = 1;
  }
  else if(magnetic > trackMarker[0] && magnetic < trackMarker[1]){
    tm = (float)((magnetic - trackMarker[0])/(trackMarker[1] - trackMarker[0]));
  }
  else if(magnetic > trackMarker[2] && magnetic < trackMarker[3]){
    tm = (float)((trackMarker[3] - magnetic)/(trackMarker[3] - trackMarker[2]));
  }
  else if(magnetic < trackMarker[0] && magnetic > trackMarker[3]){
    tm = 0;
  }

  //Right Marker
  if(magnetic >= rightMarker[1] && magnetic <= rightMarker[2]){
    rm = 1;
  }
  else if(magnetic > rightMarker[0] && magnetic < rightMarker[1]){
    rm = (float)((magnetic - rightMarker[0])/(rightMarker[1] - rightMarker[0]));
  }
  else if(magnetic > rightMarker[2] && magnetic < rightMarker[3]){    
    rm = (float)((rightMarker[3] - magnetic)/(rightMarker[3] - rightMarker[2]));
  }
  else if(magnetic < rightMarker[0] && magnetic > rightMarker[3]){
    rm = 0;
  }

  //Very Right Marker
  if(magnetic >= vRightMarker[1] && magnetic <= vRightMarker[2]){
    vrm = 1;
  }
  else if(magnetic > vRightMarker[0] && magnetic < vRightMarker[1]){
    vrm = (float)((magnetic - vRightMarker[0])/(vRightMarker[1] - vRightMarker[0]));
  }
  else if(magnetic > vRightMarker[2] && magnetic < vRightMarker[3]){
    vrm = (float)((vRightMarker[3] - magnetic)/(vRightMarker[3] - vRightMarker[2]));
  }
  else if(magnetic < vRightMarker[0] && magnetic > vRightMarker[3]){
    vrm = 0;
  }

  //Most Right Marker
  if(magnetic >= mRightMarker[1] && magnetic <= mRightMarker[2]){
    mrm = 1;
  }
  else if(magnetic > mRightMarker[0] && magnetic < mRightMarker[1]){
    mrm = (float)((magnetic - mRightMarker[0])/(mRightMarker[1] - mRightMarker[0]));
  }
  else if(magnetic < mRightMarker[0] && magnetic > mRightMarker[3]){
    mrm = 0;
  }

  //**Membership function input selisih**
  //Most Negatif
  if(selisih >= mNegatif[1] && selisih <= mNegatif[2]){
    mn = 1;
  }
  else if(selisih > mNegatif[2] && selisih < mNegatif[3]){
    mn = (float)((mNegatif[3] - selisih)/(mNegatif[3] - mNegatif[2]));
  }
  else if(selisih < mNegatif[0] && selisih > mNegatif[3]){
    mn = 0;
  }

  //Very Negatif
  if(selisih >= vNegatif[1] && selisih <= vNegatif[2]){
    vn = 1;
  }
  else if(selisih > vNegatif[0] && selisih < vNegatif[1]){
    vn = (float)((selisih - vNegatif[0])/(vNegatif[1] - vNegatif[0]));
  }
  else if(selisih > vNegatif[2] && selisih < vNegatif[3]){
    vn = (float)((vNegatif[3] - selisih)/(vNegatif[3] - vNegatif[2]));
  }
  else if(selisih < vNegatif[0] && selisih > vNegatif[3]){
    vn = 0;
  }

  //Negatif
  if(selisih >= negatif[1] && selisih <= negatif[2]){
    n = 1;
  }
  else if(selisih > negatif[0] && selisih < negatif[1]){
    n = (float)((selisih - negatif[0])/(negatif[1] - negatif[0]));
  }
  else if(selisih > negatif[2] && selisih < negatif[3]){
    n = (float)((negatif[3] - selisih)/negatif[3] - negatif[2]);
  }
  else if(selisih < negatif[0] && selisih > negatif[3]){
    n = 0;
  }

  //Zero
  if(selisih >= zero[1] && selisih <= zero[2]){
    z = 1;
  }
  else if(selisih > zero[0] && selisih < zero[1]){
    z = (float)((selisih - zero[0])/(zero[1] - zero[0]));
  }
  else if(selisih > zero[2] && selisih < zero[3]){
    z = (float)((zero[3] - selisih)/(zero[3] - zero[2]));
  }
  else if(selisih < zero[0] && selisih > zero[3]){
    z = 0;
  }

  //Positif
  if(selisih >= positif[1] && selisih <= positif[2]){
    p = 1;
  }
  else if(selisih > positif[0] && selisih < positif[1]){
    p = (float)((selisih - positif[0])/(positif[1] - positif[0]));
  }
  else if(selisih > positif[2] && selisih < positif[3]){
    p = (float)((positif[3] - selisih)/(positif[3] - positif[2]));
  }
  else if(selisih < positif[0] && selisih > positif[3]){
    p = 0;
  }

  //Very Positif
  if(selisih >= vPositif[1] && selisih <= vPositif[2]){
    vp = 1;
  }
  else if(selisih > vPositif[0] && selisih < vPositif[1]){
    vp = (float)((selisih - vPositif[0])/(vPositif[1] - vPositif[0]));
  }
  else if(selisih > vPositif[2] && selisih < vPositif[3]){
    vp = (float)((vPositif[3] - selisih)/(vPositif[3] - vPositif[2]));
  }
  else if(selisih < vPositif[0] && selisih > vPositif[3]){
    vp = 0;
  }

  //Most Positif
  if(selisih >= mPositif[1] && selisih <= mPositif[2]){
    mp = 1;
  }
  else if(selisih > mPositif[0] && selisih < mPositif[1]){
    mp = (float)((selisih - mPositif[0])/(mPositif[1] - mPositif[0]));
  }
  else if(selisih > mPositif[2] && selisih < mPositif[3]){
    mp = (float)((mPositif[3] - selisih)/(mPositif[3] - mPositif[2]));
  }
  else if(selisih < mPositif[0] && selisih > mPositif[3]){
    mp = 0;
  }

  //Display Hasil Fuzzyfikasi
  Serial.print("Nilai Sensor Magnetic : ");
  Serial.println(magnetic);
  Serial.print("Most Left Marker : ");
  Serial.println(mlm);
  Serial.print("Very Left Marker : ");
  Serial.println(vlm);
  Serial.print("Left Marker : ");
  Serial.println(lm);
  Serial.print("Track Marker : ");
  Serial.println(tm);
  Serial.print("Right Marker : ");
  Serial.println(rm);
  Serial.print("Very Right Marker : ");
  Serial.println(vrm);
  Serial.print("Most Right Marker : ");
  Serial.println(mrm);
  Serial.print("Nilai Selisih : ");
  Serial.println(selisih);
  Serial.print("Most Negatif : ");
  Serial.println(mn);
  Serial.print("Very Negatif : ");
  Serial.println(vn);
  Serial.print("Negatif : ");
  Serial.println(n);
  Serial.print("Zero : ");
  Serial.println(z);
  Serial.print("Positif : ");
  Serial.println(p);
  Serial.print("Very Positif : ");
  Serial.println(vp);  
  Serial.print("Most Positif : ");
  Serial.println(mp);
}

void inferensi(){
  //**Metode Inferensi Min-Max Mamdani
  //Inisiasi awal nilai tiap max value sama dengan nol
  maxA = 0; //Very Low Motor Kiri LPWM & Very Fast Motor Kanan LPWM
  maxB = 0; //Low Motor Kiri LPWM & Very Fast Motor Kanan LPWM
  maxC = 0; //Low Motor Kiri LPWM & Fast Motor Kanan LPWM
  maxD = 0; //Medium Low Motor Kiri LPWM & Fast Motor Kanan LPWM
  maxE = 0; //Low Motor Kiri LPWM & Medium Fast Motor Kanan LPWM
  maxF = 0; //Medium Low Motor Kiri LPWM & Medium Fast Motor Kanan LPWM
  maxG = 0; //Medium Motor Kiri LPWM & Medium Low Motor Kanan LPWM
  maxH = 0; //Fast Motor Kiri LPWM & Fast Motor Kanan LPWM
  maxI = 0; //Medium Fast Motor Kiri LPWM & Low Motor Kanan LPWM
  maxJ = 0; //Medium Fast Motor Kiri LPWM & Medium Low Motor Kanan LPWM
  maxK = 0; //Medium Low Motor Kiri LPWM & Medium Motor Kanan LPWM
  maxL = 0; //Fast Motor Kiri LPWM & Low Motor Kanan LPWM
  maxM = 0; //Very Fast Motor Kiri LPWM & Low Motor Kanan LPWM
  maxN = 0; //Very Fast Motor Kiri LPWM & Very Low Motor Kanan LPWM
  maxO = 0; //Fast Motor Kiri LPWM & Medium Low Motor Kanan LPWM
  int k;
  float nilaiMin[49];
  String kondisiOut1[49]; //Motor Kiri LPWM
  String kondisiOut2[49]; //Motor Kanan LPWM
  String kondisiSensor[49]; //Kondisi Sensor Magnetic
  String kondisiSelisih[49]; //Kondisi Selisih
  float nilaiMagnetic[7] = {mlm, vlm, lm, tm, rm, vrm, mrm};
  float nilaiSelisih[7] = {mn, vn, n, z, p, vp, mp};
  k = 0;

  //Penentuan Rules dan Nilai Minimum
  for(int i=0; i<7; i++){ //i = untuk nilai sensor magnetic
    for(int j=0; j<7; j++){ //j = untuk nilai selisih
      if((nilaiMagnetic[i]>=0) && (nilaiSelisih[j]>=0)){
        //Nilai Min tiap kondisi
        nilaiMin[k] = nilaiMagnetic[i];
        if(nilaiSelisih[j] < nilaiMin[k]){
          nilaiMin[k] = nilaiSelisih[j];
        }

        //Menentukan Kondisi Sensor
        if(i==0){
          kondisiSensor[k] = "Most Left Marker";
        }
        else if(i==1){
          kondisiSensor[k] = "Very Left Marker";
        }
        else if(i==2){
          kondisiSensor[k] = "Left Marker";
        }
        else if(i==3){
          kondisiSensor[k] = "Track Marker";
        }
        else if(i==4){
          kondisiSensor[k] = "Right Marker";
        }
        else if(i==5){
          kondisiSensor[k] = "Very Right Marker";
        }
        else if(i==6){
          kondisiSensor[k] = "Most Right Marker";
        }

        //Menentukan Kondisi Selisih
        if(j==0){
          kondisiSelisih[k] = "Most Negatif";
        }
        else if(j==1){
          kondisiSelisih[k] = "Very Negatif";
        }
        else if(j==2){
          kondisiSelisih[k] = "Negatif";
        }
        else if(j==3){
          kondisiSelisih[k] = "Zero";
        }
        else if(j==4){
          kondisiSelisih[k] = "Positif";
        }
        else if(j==5){
          kondisiSelisih[k] = "Very Positif";
        }
        else if(j==6){
          kondisiSelisih[k] = "Most Positif";
        }

        //Penentuan Rules Kondisi Most Left Marker dengan Kondisi Selisih
        if((i == 0) && (j == 0)){
          kondisiOut1[k] = "Very Low";
          kondisiOut2[k] = "Very Fast";
        }
        else if((i == 0) && (j == 1)){
          kondisiOut1[k] = "Very Low";
          kondisiOut2[k] = "Very Fast";
        }
        else if((i == 0) && (j == 2)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Very Fast";
        }
        else if((i == 0) && (j == 3)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Very Fast";
        }
        else if((i == 0) && (j == 4)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Fast";
        }
        else if((i == 0) && (j == 5)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Fast";
        }
        else if((i == 0) && (j == 6)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Fast";
        }

        //Penentuan Rules Kondisi Very Left Marker dengan Kondisi Selisih
        if((i == 1) && (j == 0)){
          kondisiOut1[k] = "Very Low";
          kondisiOut2[k] = "Very Fast";
        }
        else if((i == 1) && (j == 1)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Very Fast";
        }
        else if((i == 1) && (j == 2)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Fast";
        }
        else if((i == 1) && (j == 3)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Fast";
        }
        else if((i == 1) && (j == 4)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Medium Fast";
        }
        else if((i == 1) && (j == 5)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Medium Fast";
        }
        else if((i == 1) && (j == 6)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Medium Fast";
        }

        //Penentuan Rules Kondisi Left Marker dengan Kondisi Selisih
        if((i == 2) && (j == 0)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Very Fast";
        }
        else if((i == 2) && (j == 1)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Fast";
        }
        else if((i == 2) && (j == 2)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Medium Fast";
        }
        else if((i == 2) && (j == 3)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Medium Fast";
        }
        else if((i == 2) && (j == 4)){
          kondisiOut1[k] = "Medium";
          kondisiOut2[k] = "Medium Low";
        }
        else if((i == 2) && (j == 5)){
          kondisiOut1[k] = "Medium";
          kondisiOut2[k] = "Medium Low";
        }
        else if((i == 2) && (j == 6)){
          kondisiOut1[k] = "Medium";
          kondisiOut2[k] = "Medium Low";
        }

        //Penentuan Rules Kondisi Track Marker dengan Kondisi Selisih
        if((i == 3) && (j == 0)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Medium Fast";
        }
        else if((i == 3) && (j == 1)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Medium Fast";
        }
        else if((i == 3) && (j == 2)){
          kondisiOut1[k] = "Low";
          kondisiOut2[k] = "Medium Fast";
        }
        else if((i == 3) && (j == 3)){
          kondisiOut1[k] = "Fast";
          kondisiOut2[k] = "Fast";
        }
        else if((i == 3) && (j == 4)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 3) && (j == 5)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 3) && (j == 6)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Medium Low";
        }

        //Penentuan Rules Kondisi Right Marker dengan Kondisi Selisih
        if((i == 4) && (j == 0)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Medium";
        }
        else if((i == 4) && (j == 1)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Medium";
        }
        else if((i == 4) && (j == 2)){
          kondisiOut1[k] = "Medium Low";
          kondisiOut2[k] = "Medium";
        }
        else if((i == 4) && (j == 3)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Medium Low";
        }
        else if((i == 4) && (j == 4)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 4) && (j == 5)){
          kondisiOut1[k] = "Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 4) && (j == 6)){
          kondisiOut1[k] = "Very Fast";
          kondisiOut2[k] = "Low";
        }

        //Penentuan Rules Kondisi Very Right Marker dengan Kondisi Selisih
        if((i == 5) && (j == 0)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Medium Low";
        }
        else if((i == 5) && (j == 1)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Medium Low";
        }
        else if((i == 5) && (j == 2)){
          kondisiOut1[k] = "Medium Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 5) && (j == 3)){
          kondisiOut1[k] = "Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 5) && (j == 4)){
          kondisiOut1[k] = "Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 5) && (j == 5)){
          kondisiOut1[k] = "Very Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 5) && (j == 6)){
          kondisiOut1[k] = "Very Fast";
          kondisiOut2[k] = "Very Low";
        }

        //Penentuan Rules Kondisi Most Right Marker dengan Kondisi Selisih
        if((i == 6) && (j == 0)){
          kondisiOut1[k] = "Fast";
          kondisiOut2[k] = "Medium Low";
        }
        else if((i == 6) && (j == 1)){
          kondisiOut1[k] = "Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 6) && (j == 2)){
          kondisiOut1[k] = "Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 6) && (j == 3)){
          kondisiOut1[k] = "Very Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 6) && (j == 4)){
          kondisiOut1[k] = "Very Fast";
          kondisiOut2[k] = "Low";
        }
        else if((i == 6) && (j == 5)){
          kondisiOut1[k] = "Very Fast";
          kondisiOut2[k] = "Very Low";
        }
        else if((i == 6) && (j == 6)){
          kondisiOut1[k] = "Very Fast";
          kondisiOut2[k] = "Very Low";
        }

        Serial.print("Ketika Sensor Magnetic : ");
        Serial.println(kondisiSensor[k]);
        Serial.print("Maka Nilai Fuzzy Sensor : ");
        Serial.println(nilaiMagnetic[i]);

        Serial.print("Ketika Nilai Selisih : ");
        Serial.println(kondisiSelisih[k]);
        Serial.print("Maka Nilai Fuzzy Selisih : ");
        Serial.println(nilaiSelisih[j]);

        Serial.print("Output Motor Kiri LPWM : ");
        Serial.println(kondisiOut1[k]);
        Serial.print("Output Motor Kanan LPWM : ");
        Serial.println(kondisiOut2[k]);
        Serial.print("Nilai Fuzzy Min : ");
        Serial.println(nilaiMin[k]);
        k++;  
        Serial.println(k);
      }
    }
  }

  //Menentukan Nilai Max
  for(int i=0; i<k; i++){
    //Motor Kiri Very Low (LPWM) dan Motor Kanan Very Fast (LPWM)
    if(kondisiOut1[i]=="Very Low" && kondisiOut2[i]=="Very Fast"){
      if(i==0){
        maxA=nilaiMin[i];
      }
      else{
        if(maxA<nilaiMin[i]){
          maxA=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Low (LPWM) dan Motor Kanan Very Fast (LPWM)
    if(kondisiOut1[i]=="Low" && kondisiOut2[i]=="Very Fast"){
      if(i==0){
        maxB=nilaiMin[i];
      }
      else{
        if(maxB<nilaiMin[i]){
          maxB=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Low (LPWM) && Motor Kanan Fast (LPWM)
    if(kondisiOut1[i]=="Low" && kondisiOut2[i]=="Fast"){
      if(i==0){
        maxC=nilaiMin[i];
      }
      else{
        if(maxC<nilaiMin[i]){
          maxC=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Medium Low (LPWM) && Motor Kanan Fast (LPWM)
    if(kondisiOut1[i]=="Medium Low" && kondisiOut2[i]=="Fast"){
      if(i==0){
        maxD=nilaiMin[i];
      }
      else{
        if(maxD<nilaiMin[i]){
          maxD=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Low (LPWM) && Motor Kanan Medium Fast (LPWM)
    if(kondisiOut1[i]=="Low" && kondisiOut2[i]=="Medium Fast"){
      if(i==0){
        maxE=nilaiMin[i];
      }
      else{
        if(maxE<nilaiMin[i]){
          maxE=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Medium Low (LPWM) && Motor Kanan Medium Fast (LPWM)
    if(kondisiOut1[i]=="Medium Low" && kondisiOut2[i]=="Medium Fast"){
      if(i==0){
        maxF=nilaiMin[i];
      }
      else{
        if(maxF<nilaiMin[i]){
          maxF=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Medium (LPWM) && Motor Kanan Medium Low (LPWM)
    if(kondisiOut1[i]=="Medium" && kondisiOut2[i]=="Medium Low"){
      if(i==0){
        maxG=nilaiMin[i];
      }
      else{
        if(maxG<nilaiMin[i]){
          maxG=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Fast (LPWM) && Motor Kanan Fast (LPWM)
    if(kondisiOut1[i]=="Fast" && kondisiOut2[i]=="Fast"){
      if(i==0){
        maxH=nilaiMin[i];
      }
      else{
        if(maxH<nilaiMin[i]){
          maxH=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Medium Fast (LPWM) && Motor Kanan Low (LPWM)
    if(kondisiOut1[i]=="Medium Fast" && kondisiOut2[i]=="Low"){
      if(i==0){
        maxI=nilaiMin[i];
      }
      else{
        if(maxI<nilaiMin[i]){
          maxI=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Medium Fast (LPWM) && Motor Kanan Medium Low (LPWM)
    if(kondisiOut1[i]=="Medium Fast" && kondisiOut2[i]=="Medium Low"){
      if(i==0){
        maxJ=nilaiMin[i];
      }
      else{
        if(maxJ<nilaiMin[i]){
          maxJ=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Medium Low (LPWM) && Motor Kanan Medium (LPWM)
    if(kondisiOut1[i]=="Medium Low" && kondisiOut2[i]=="Medium"){
      if(i==0){
        maxK=nilaiMin[i];
      }
      else{
        if(maxK<nilaiMin[i]){
          maxK=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Fast (LPWM) && Motor Kanan Low (LPWM)
    if(kondisiOut1[i]=="Fast" && kondisiOut2[i]=="Low"){
      if(i==0){
        maxL=nilaiMin[i];
      }
      else{
        if(maxL<nilaiMin[i]){
          maxL=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Very Fast (LPWM) && Motor Kanan Low (LPWM)
    if(kondisiOut1[i]=="Very Fast" && kondisiOut2[i]=="Low"){
      if(i==0){
        maxM=nilaiMin[i];
      }
      else{
        if(maxM<nilaiMin[i]){
          maxM=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Very Fast (LPWM) && Motor Kanan Very Low (LPWM)
    if(kondisiOut1[i]=="Very Fast" && kondisiOut2[i]=="Very Low"){
      if(i==0){
        maxN=nilaiMin[i];
      }
      else{
        if(maxN<nilaiMin[i]){
          maxN=nilaiMin[i];
        }
      }
    }

    //Motor Kiri Fast (LPWM) && Motor Kanan Medium Low (LPWM)
    if(kondisiOut1[i]=="Fast" && kondisiOut2[i]=="Medium Low"){
      if(i==0){
        maxO=nilaiMin[i];
      }
      else{
        if(maxO<nilaiMin[i]){
          maxO=nilaiMin[i];
        }
      }
    }
  }

  //Display Inferensi
  Serial.println("--- Nilai Max Inferensi ---");
  Serial.print("Nilai Max Motor Kiri Very Low dan Motor Kanan Very Fast : ");
  Serial.println(maxA);
  Serial.print("Nilai Max Motor Kiri Low dan Motor Kanan Very Fast : ");
  Serial.println(maxB);
  Serial.print("Nilai Max Motor Kiri Low dan Motor Kanan Fast : ");
  Serial.println(maxC);
  Serial.print("Nilai Max Motor Kiri Medium Low dan Motor Kanan Fast : ");
  Serial.println(maxD);
  Serial.print("Nilai Max Motor Kiri Low dan Motor Kanan Medium Fast : ");
  Serial.println(maxE);
  Serial.print("Nilai Max Motor Kiri Medium Low dan Motor Kanan Medium Fast : ");
  Serial.println(maxF);
  Serial.print("Nilai Max Motor Kiri Medium dan Motor Kanan Medium Low : ");
  Serial.println(maxG);
  Serial.print("Nilai Max Motor Kiri Fast dan Motor Kanan Fast : ");
  Serial.println(maxH);
  Serial.print("Nilai Max Motor Kiri Medium Fast dan Motor Kanan Low : ");
  Serial.println(maxI);
  Serial.print("Nilai Max Motor Kiri Medium Fast dan Motor Kanan Medium Low : ");
  Serial.println(maxJ);
  Serial.print("Nilai Max Motor Kiri Medium Low dan Motor Kanan Medium : ");
  Serial.println(maxK);
  Serial.print("Nilai Max Motor Kiri Fast dan Motor Kanan Low : ");
  Serial.println(maxL);
  Serial.print("Nilai Max Motor Kiri Very Fast dan Motor Kanan Low : ");
  Serial.println(maxM);
  Serial.print("Nilai Max Motor Kiri Very Fast dan Motor Kanan Very Low : ");
  Serial.println(maxN);
  Serial.print("Nilai Max Motor Kiri Fast dan Motor Kanan Medium Low : ");
  Serial.println(maxO);
}

void defuzzyfikasi(){
  //Inisiasi awal nilai tiap variabel defuzzfikasi sama dengan nol
  hasilPembilang1 = 0; //Motor Kiri LPWM
  hasilPenyebut1 = 0; //Motor Kiri LPWM
  hasilPembilang2 = 0; //Motor Kanan LPWM
  hasilPenyebut2 = 0; //Motor Kanan LPWM
  hasilDefuzzyfikasi1 = 0; //Motor Kiri LPWM
  hasilDefuzzyfikasi2 = 0; //Motor Kanan LPWM
  pengaliA = maxA;  pengaliF = maxF;  pengaliK = maxK;
  pengaliB = maxB;  pengaliG = maxG;  pengaliL = maxL;
  pengaliC = maxC;  pengaliH = maxH;  pengaliM = maxM;
  pengaliD = maxD;  pengaliI = maxI;  pengaliN = maxN;
  pengaliE = maxE;  pengaliJ = maxJ;  pengaliO = maxO;
  jumlah_sampelAKiri = 0; jumlah_sampelAKanan = 0; //1
  jumlah_sampelBKiri = 0; jumlah_sampelBKanan = 0; //2
  jumlah_sampelCKiri = 0; jumlah_sampelCKanan = 0; //3
  jumlah_sampelDKiri = 0; jumlah_sampelDKanan = 0; //4
  jumlah_sampelEKiri = 0; jumlah_sampelEKanan = 0; //5
  jumlah_sampelFKiri = 0; jumlah_sampelFKanan = 0; //6
  jumlah_sampelGKiri = 0; jumlah_sampelGKanan = 0; //7
  jumlah_sampelHKiri = 0; jumlah_sampelHKanan = 0; //8
  jumlah_sampelIKiri = 0; jumlah_sampelIKanan = 0; //9
  jumlah_sampelJKiri = 0; jumlah_sampelJKanan = 0; //10
  jumlah_sampelKKiri = 0; jumlah_sampelKKanan = 0; //11
  jumlah_sampelLKiri = 0; jumlah_sampelLKanan = 0; //12
  jumlah_sampelMKiri = 0; jumlah_sampelMKanan = 0; //13
  jumlah_sampelNKiri = 0; jumlah_sampelNKanan = 0; //14
  jumlah_sampelOKiri = 0; jumlah_sampelOKanan = 0; //15

  //Defuzzyfikasi untuk Motor Kiri Very Low (LPWM) & Motor Kanan Very Fast (LPWM)
  if(pengaliA>0){
    //Motor Kiri LPWM VL
    sampelAKiri = 20;
    for(int i=25; i<=45; i++){
      jumlah_sampelAKiri = ((titik_sampel*i+jumlah_sampelAKiri)+pengaliA);
    }
    //Motor Kanan LPWM VF
    sampelAKanan = 20;
    for(int i=135; i<=155; i++){
      jumlah_sampelAKanan = ((titik_sampel*i+jumlah_sampelAKanan)+pengaliA);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Low (LPWM) & Motor Kanan Very Fast (LPWM)
  if(pengaliB>0){
    //Motor Kiri LPWM L
    sampelBKiri = 30;
    for(int i=35; i<=65; i++){
      jumlah_sampelBKiri = ((titik_sampel*i+jumlah_sampelBKiri)+pengaliB);
    }
    //Motor Kanan LPWM VF
    sampelBKanan = 20;
    for(int i=135; i<=155; i++){
      jumlah_sampelBKanan = ((titik_sampel*i+jumlah_sampelBKanan)+pengaliB);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Low (LPWM) & Motor Kanan Fast (LPWM)
  if(pengaliC>0){
    //Motor Kiri LPWM L
    sampelCKiri = 30;
    for(int i=35; i<=65; i++){
      jumlah_sampelCKiri = ((titik_sampel*i+jumlah_sampelCKiri)+pengaliC);
    }
    //Motor Kanan LPWM F
    sampelCKanan = 30;
    for(int i=115; i<=145; i++){
      jumlah_sampelCKanan = ((titik_sampel*i+jumlah_sampelCKanan)+pengaliC);
    }
  }

  
  //Defuzzyfikasi untuk Motor Kiri Medium Low (LPWM) & Motor Kanan Fast (LPWM)
  if(pengaliD>0){
    //Motor Kiri LPWM ML
    sampelDKiri = 30;
    for(int i=55; i<=85; i++){
      jumlah_sampelDKiri = ((titik_sampel*i+jumlah_sampelDKiri)+pengaliD);
    }
    //Motor Kanan LPWM F
    sampelDKanan = 30;
    for(int i=115; i<=145; i++){
      jumlah_sampelDKanan = ((titik_sampel*i+jumlah_sampelDKanan)+pengaliD);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Low (LPWM) & Motor Kanan Medium Fast (LPWM)
  if(pengaliE>0){
    //Motor Kiri LPWM L
    sampelEKiri = 30;
    for(int i=35; i<=65; i++){
      jumlah_sampelEKiri = ((titik_sampel*i+jumlah_sampelEKiri)+pengaliE);
    }
    //Motor Kanan LPWM MF
    sampelEKanan = 30;
    for(int i=95; i<=125; i++){
      jumlah_sampelEKanan = ((titik_sampel*i+jumlah_sampelEKanan)+pengaliE);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Medium Low (LPWM) & Motor Kanan Medium Fast (LPWM)
  if(pengaliF>0){
    //Motor Kiri LPWM ML
    sampelFKiri = 30;
    for(int i=55; i<=85; i++){
      jumlah_sampelFKiri = ((titik_sampel*i+jumlah_sampelFKiri)+pengaliF);
    }
    //Motor Kanan LPWM MF
    sampelFKanan = 30;
    for(int i=95; i<=125; i++){
      jumlah_sampelFKanan = ((titik_sampel*i+jumlah_sampelFKanan)+pengaliF);
    }
  }
  
  //Defuzzyfikasi untuk Motor Kiri Medium (LPWM) & Motor Kanan Medium Low (LPWM)
  if(pengaliG>0){
    //Motor Kiri LPWM M
    sampelGKiri = 30;
    for(int i=75; i<=105; i++){
      jumlah_sampelGKiri = ((titik_sampel*i+jumlah_sampelGKiri)+pengaliG);
    }
    //Motor Kanan LPWM ML
    sampelGKanan = 30;
    for(int i=55; i<=85; i++){
      jumlah_sampelGKanan = ((titik_sampel*i+jumlah_sampelGKanan)+pengaliG);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Fast (LPWM) & Motor Kanan Fast (LPWM)
  if(pengaliH>0){
    //Motor Kiri LPWM F
    sampelHKiri = 30;
    for(int i=115; i<=145; i++){
      jumlah_sampelHKiri = ((titik_sampel*i+jumlah_sampelHKiri)+pengaliH);
    }
    //Motor Kanan LPWM F
    sampelHKanan = 30;
    for(int i=115; i<=145; i++){
      jumlah_sampelHKanan = ((titik_sampel*i+jumlah_sampelHKanan)+pengaliH);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Medium Fast (LPWM) & Motor Kanan Low (LPWM)
  if(pengaliI>0){
    //Motor Kiri LPWM MF
    sampelIKiri = 30;
    for(int i=95; i<=125; i++){
      jumlah_sampelIKiri = ((titik_sampel*i+jumlah_sampelIKiri)+pengaliI);
    }
    //Motor Kanan LPWM L
    sampelIKanan = 30;
    for(int i=35; i<=65; i++){
      jumlah_sampelIKanan = ((titik_sampel*i+jumlah_sampelIKanan)+pengaliI);
    }
  }
  
  //Defuzzyfikasi untuk Motor Kiri Medium Fast (LPWM) & Motor Kanan Medium Low (LPWM)
  if(pengaliJ>0){
    //Motor Kiri LPWM MF
    sampelJKiri = 30;
    for(int i=95; i<=125; i++){
      jumlah_sampelJKiri = ((titik_sampel*i+jumlah_sampelJKiri)+pengaliJ);
    }
    //Motor Kanan LPWM ML
    sampelJKanan = 30;
    for(int i=55; i<=85; i++){
      jumlah_sampelJKanan = ((titik_sampel*i+jumlah_sampelJKanan)+pengaliJ);
    }
  }
  
  //Defuzzyfikasi untuk Motor Kiri Medium Low (LPWM) & Motor Kanan Medium (LPWM)
  if(pengaliK>0){
    //Motor Kiri LPWM ML
    sampelKKiri = 30;
    for(int i=55; i<=85; i++){
      jumlah_sampelKKiri = ((titik_sampel*i+jumlah_sampelKKiri)+pengaliK);
    }
    //Motor Kanan LPWM M
    sampelKKanan = 30;
    for(int i=75; i<=105; i++){
      jumlah_sampelKKanan = ((titik_sampel*i+jumlah_sampelKKanan)+pengaliK);
    }
  }
  
  //Defuzzyfikasi untuk Motor Kiri Fast (LPWM) & Motor Kanan Low (LPWM)
  if(pengaliL>0){
    //Motor Kiri LPWM F
    sampelLKiri = 30;
    for(int i=115; i<=145; i++){
      jumlah_sampelLKiri = ((titik_sampel*i+jumlah_sampelLKiri)+pengaliL);
    }
    //Motor Kanan LPWM L
    sampelLKanan = 30;
    for(int i=35; i<=65; i++){
      jumlah_sampelLKanan = ((titik_sampel*i+jumlah_sampelLKanan)+pengaliL);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Very Fast (LPWM) & Motor Kanan Low (LPWM)
  if(pengaliM>0){
    //Motor Kiri LPWM VF
    sampelMKiri = 20;
    for(int i=135; i<=155; i++){
      jumlah_sampelMKiri = ((titik_sampel*i+jumlah_sampelMKiri)+pengaliM);
    }
    //Motor Kanan LPWM L
    sampelMKanan = 30;
    for(int i=35; i<=65; i++){
      jumlah_sampelMKanan = ((titik_sampel*i+jumlah_sampelMKanan)+pengaliM);
    }
  }
 
  //Defuzzyfikasi untuk Motor Kiri Very Fast (LPWM) & Motor Kanan Very Low (LPWM)
  if(pengaliN>0){
    //Motor Kiri LPWM VF
    sampelNKiri = 20;
    for(int i=135; i<=155; i++){
      jumlah_sampelNKiri = ((titik_sampel*i+jumlah_sampelNKiri)+pengaliN);
    }
    //Motor Kanan LPWM VL
    sampelNKanan = 20;
    for(int i=25; i<=45; i++){
      jumlah_sampelNKanan = ((titik_sampel*i+jumlah_sampelNKanan)+pengaliN);
    }
  }

  //Defuzzyfikasi untuk Motor Kiri Fast (LPWM) & Motor Kanan Medium Low (LPWM)
  if(pengaliO>0){
    //Motor Kiri LPWM F
    sampelOKiri = 30;
    for(int i=115; i<=145; i++){
      jumlah_sampelOKiri = ((titik_sampel*i+jumlah_sampelOKiri)+pengaliO);
    }
    //Motor Kanan LPWM ML
    sampelOKanan = 30;
    for(int i=55; i<=85; i++){
      jumlah_sampelOKanan = ((titik_sampel*i+jumlah_sampelOKanan)+pengaliO);
    }
  }

  hasilPembilang1 = (jumlah_sampelAKiri*pengaliA)+(jumlah_sampelBKiri*pengaliB)+(jumlah_sampelCKiri*pengaliC)+(jumlah_sampelDKiri*pengaliD)+(jumlah_sampelEKiri*pengaliE)+(jumlah_sampelFKiri*pengaliF)+(jumlah_sampelGKiri*pengaliG)+(jumlah_sampelHKiri*pengaliH)+(jumlah_sampelIKiri*pengaliI)+(jumlah_sampelJKiri*pengaliJ)+(jumlah_sampelKKiri*pengaliK)+(jumlah_sampelLKiri*pengaliL)+(jumlah_sampelMKiri*pengaliM)+(jumlah_sampelNKiri*pengaliN)+(jumlah_sampelOKiri*pengaliO);
  hasilPembilang2 = (jumlah_sampelAKanan*pengaliA)+(jumlah_sampelBKanan*pengaliB)+(jumlah_sampelCKanan*pengaliC)+(jumlah_sampelDKanan*pengaliD)+(jumlah_sampelEKanan*pengaliE)+(jumlah_sampelFKanan*pengaliF)+(jumlah_sampelGKanan*pengaliG)+(jumlah_sampelHKanan*pengaliH)+(jumlah_sampelIKanan*pengaliI)+(jumlah_sampelJKanan*pengaliJ)+(jumlah_sampelKKanan*pengaliK)+(jumlah_sampelLKanan*pengaliL)+(jumlah_sampelMKanan*pengaliM)+(jumlah_sampelNKanan*pengaliN)+(jumlah_sampelOKanan*pengaliO);
  hasilPenyebut1 = (sampelAKiri*pengaliA)+(sampelBKiri*pengaliB)+(sampelCKiri*pengaliC)+(sampelDKiri*pengaliD)+(sampelEKiri*pengaliE)+(sampelFKiri*pengaliF)+(sampelGKiri*pengaliG)+(sampelHKiri*pengaliH)+(sampelIKiri*pengaliI)+(sampelJKiri*pengaliJ)+(sampelKKiri*pengaliK)+(sampelLKiri*pengaliL)+(sampelMKiri*pengaliM)+(sampelNKiri*pengaliN)+(sampelOKiri*pengaliO);
  hasilPenyebut2 = (sampelAKanan*pengaliA)+(sampelBKanan*pengaliB)+(sampelCKanan*pengaliC)+(sampelDKanan*pengaliD)+(sampelEKanan*pengaliE)+(sampelFKanan*pengaliF)+(sampelGKanan*pengaliG)+(sampelHKanan*pengaliH)+(sampelIKanan*pengaliI)+(sampelJKanan*pengaliJ)+(sampelKKanan*pengaliK)+(sampelLKanan*pengaliL)+(sampelMKanan*pengaliM)+(sampelNKanan*pengaliN)+(sampelOKanan*pengaliO); 
  hasilDefuzzyfikasi1 = hasilPembilang1/hasilPenyebut1;
  hasilDefuzzyfikasi2 = hasilPembilang2/hasilPenyebut2;

  if(isnan(hasilDefuzzyfikasi1)){
    hasilDefuzzyfikasi1 = 0;
  }
  if(isnan(hasilDefuzzyfikasi2)){
    hasilDefuzzyfikasi2 = 0;
  }

  //Display Hasil Defuzzyfikasi
  Serial.println(jumlah_sampelBKiri);
  Serial.print("Hasil Pembilang 1 : ");
  Serial.println(hasilPembilang1);
  Serial.print("Hasil Penyebut 1 : ");
  Serial.println(hasilPenyebut1);
  Serial.print("Hasil Pembilang 2 : ");
  Serial.println(hasilPembilang2);
  Serial.print("Hasil Penyebut 2 : ");
  Serial.println(hasilPenyebut2);
  Serial.print("Hasil Defuzzyfikasi 1 : ");
  Serial.println(hasilDefuzzyfikasi1);
  Serial.print("Hasil Defuzzyfikasi 2 : ");
  Serial.println(hasilDefuzzyfikasi2);  

}
void fuzzy(){
  fuzzyfikasi();
  inferensi();
  defuzzyfikasi();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  fuzzy();
}
