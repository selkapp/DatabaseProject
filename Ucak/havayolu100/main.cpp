#include <iostream>
#include <winsock.h>
#include "include/mysql.h"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{

while(1){
MYSQL *_mysql;
MYSQL *baglan;

_mysql = mysql_init(NULL);
baglan= mysql_real_connect(_mysql, "localhost", "selcan", "5520", "havayolu", 3306, NULL, 0);

cout<<"\nANA MENU"<<endl;


int tus;
cout<<"Yeni sefer tanimlama icin : 1 \nBilet satma icin : 2\nYolcu sorgulama icin : 3\nUcus iptali icin : 4\nBilet iptali icin : 5\nSefer sorgulama icin : 6\n "<<endl;

cin>>tus;

switch(tus) {
case 1:{


    string x; string y; string z; string w; string d;
cout<<"Ucus baslangic noktasini giriniz\n"<<endl;
cin>>x;
cout<<"Ucus bitis noktasini giriniz\n"<<endl;
cin>>y;

cout<<"Ucus tarihini giriniz\n"<<endl;
cin>>z;

cout<<"Ucus saatini giriniz\n"<<endl;
cin>>d;

cout<<"Ucak kuyruk numarasini giriniz\n"<<endl;
cin>>w;




string sql ="INSERT INTO seferler VALUES ('"+x+"','"+y+"','"+z+"','"+d+"','"+w+"')";
const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);

cout<<"Kayit eklendi.\n"<<endl;
break;




}


case 2:{

int i;
string tc;
string x; string y; string z; int d; string w; string u;
cout<<"Ucus baslangic noktasini giriniz\n"<<endl;
cin>>x;
cout<<"Ucus bitis noktasini giriniz\n"<<endl;
cin>>y;

cout<<"Tarih giriniz\n"<<endl;
cin>>z;

cout<<"Bilet adedini giriniz\n"<<endl;
cin>>d;

cout<<"Ucus numarasini giriniz\n"<<endl;
cin>>w;

cout<<"Ucak kuyruk numarasi giriniz\n"<<endl;
cin>>u;

string sql ="INSERT INTO yolcu VALUES ('"+x+"','"+y+"','"+z+"',NULL,'"+w+"')";

const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);


MYSQL_RES * result = mysql_store_result(_mysql);
unsigned long row_result = mysql_num_rows(result);

MYSQL_ROW row;

row = mysql_fetch_row(result);
cout <<"Sefer baslangic  " << row[0]<< endl;
cout <<"Sefer bitis :  " << row[1]<< endl;
cout <<"Sefer tarih :  " << row[2]<< endl;
cout <<"Sefer saat :  " << row[3]<< endl;
cout <<"Sefer ukn :  " << row[4]<< endl;



for( i=0 ; i<d ; i++){


cout<<"Kisi tckn giriniz\n"<<endl;
cin>>tc;


string sql ="INSERT INTO yolcu VALUES ( '"+x+"','"+y+"','"+z+"','"+tc+"','"+u+"')";
const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);


}
cout<< i <<"adet bilet eklendi.\n"<<endl;
break;
}




case 3:{

string numara;

cout<< "TCKN numaranizi giriniz \n" << endl;
cin>>numara;

string sql = "SELECT yolcu_bn,yolcu_bin FROM yolcu WHERE yolcu_tckn= '"+numara+"' ";
const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);


MYSQL_RES * result = mysql_store_result(_mysql);
unsigned long row_result = mysql_num_rows(result);

MYSQL_ROW row;

row = mysql_fetch_row(result);
cout <<"Ucak Kalkis :  " << row[0]<< endl;
cout <<"Ucak Inis :  " << row[1]<< endl;

break;

}


case 4:{


 string a;

cout<<"Iptal ucusun ucak kuyruk numarasini giriniz\n"<<endl;
cin>>a;


string sql = "DELETE  FROM yolcu WHERE (yolcu_ukn = '"+a+"')";

const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);

cout<<"Ucus yolcular tablosundan silindi.\n"<<endl;

break;


}



case 5:{


    string x; string y; string z;
cout<<"Ucus tarihini giriniz\n"<<endl;
cin>>x;
cout<<"Ucak kuyruk numarasini giriniz\n"<<endl;
cin>>y;

cout<<"TCKN giriniz\n"<<endl;
cin>>z;


string sql = " DELETE  FROM yolcu WHERE (yolcu_tarih = '"+x+"' AND yolcu_ukn = '"+y+"' AND yolcu_tckn = '"+z+"')" ;
const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);
cout<<"Bilet yolcular tablosundan silindi.\n"<<endl;

break;


}

case 6: {

string tarihim; string numaram;

cout<< "Ucus tarihini giriniz \n" << endl;
cin>>tarihim;

cout<< "Ucak kuyruk numarasi giriniz \n" << endl;
cin>>numaram;


string sql = "SELECT y.yolcubilgi_isim,y.yolcubilgi_eposta,y.yolcubilgi_tckn,y.yolcubilgi_adres,y.yolcubilgi_sehir FROM yolcu_bilgisi y,yolcu yo WHERE yo.yolcu_tarih= '"+tarihim+"' AND yo.yolcu_ukn = '"+numaram+"' AND yo.yolcu_tckn=y.yolcubilgi_tckn ";
const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);

//
MYSQL_RES * result = mysql_store_result(_mysql);
unsigned long row_result = mysql_num_rows(result);

MYSQL_ROW row;

row = mysql_fetch_row(result);
cout <<"Isim :  " << row[0]<< endl;
cout <<"Eposta : " << row[1]<< endl;
cout <<"Tckn :  " << row[2]<< endl;
cout <<"Adres :  " << row[3]<< endl;
cout <<"Sehir :  " << row[4]<< endl;

break;


}
/*

case 8:{


    string x; string y;
cout<<"Ucak modeli giriniz\n"<<endl;
cin>>x;
cout<<"Ucak kapasitesi giriniz\n"<<endl;
cin>>y;



string sql ="INSERT INTO seferler VALUES ('"+x+"','"+y+"','"+z+"','"+d+"','"+w+"')";
const char * sql2 = sql.c_str();
int query = mysql_query(_mysql, sql2);

cout<<"Kayit eklendi.\n"<<endl;
break;





}
*/




}





}

 return 0 ;


}







