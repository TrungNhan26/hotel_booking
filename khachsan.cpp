#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
//========================================================
void checkin(int kiemtradatphongch, int fakema,int select);
int bienKhoa=0;
int b;
int thoatbangdieukhien = 0;
int chonbangdieukhien;
int thoatchonbangdieukhien = 0;
int select; 
int thoatthanhtoan = 0;
int chonthanhtoan;
int thoatchonthanhtoan = 0;
int fakeID;
int thimang;
int fakema;
int fakepp; 

int kiemtradatphongch = 0;
int kiemtrasonguoi = 0;
int kiemtraxoa = 0;
int tongtien = 0;
int biendem = 0;

void service(); 

class Date
    {   int d,m,y;
        public:
            int songay(int y);
            int isdate();
            int TTngay();
            void nhap();
            double kc(Date d2);
    };
int Date::isdate()
    {   int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
                if (y % 4 == 0 && y%100 != 0 || y % 400 == 0) a[1]=29;
                if (m < 1 || m >12) return 0;
                if (d < 1 || d > a[m-1]) return 0;
                return 1;
    }
void Date::nhap()
    {   cout<<"\n      dd mm yyyy: ";
        tt:;
        cin>>d>>m>>y;
        if(!(isdate())) {cout<<"Ban nhap sai! moi nhap lai"; goto tt;}
    }
int Date::TTngay()
    {   int ngaynam[2][12]={{31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
        int i;
        int s=d;
        if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) i=0;
            else i=1;
        for(int j=0;j<m-1;j++)  s+=ngaynam[i][j];
        return s;
    }
int Date::songay(int y)
    {   if(y%4 == 0 && y%100 != 0 || y%400 == 0) return 365;
        return 366;
    }
double Date::kc(Date N)
    {   int d1=TTngay();
        int d2=N.TTngay();
        if(y==N.y) return(abs(d1-d2));
        int s=0;
        if(y<N.y)
            {   d1=songay(y)-d1;
                for(int i=y+1;i<N.y;i++) s+=songay(i);
                return(s+d1+d2);
            }
        else
            {   d2=songay(N.y)-d2;
                for(int i=N.y+1;i<y;i++) s+=songay(i);
                return(s+d1+d2);
            }
}
class hotel
{
public:
    int phong[50];
    int ma[50];
    /*
	int *phong = new int[50];
	int *ma = new int[50];
	int size = 50;
	int count  = 0; 
	bool isFull(){ return count == size()};
	void resize(){
		if(isFull()){
			int *a = new int[size];
			int *b = new int[size];
			for(int i = 0; i < size; i++){
				a[i] = phong[i];
				b[i] = ma[i];
			}
			delete[] phong;
			delete[] ma;
			size *= 2;
			phong = new int[size];
			ma = new int[size];
		}
	}
	*/
    hotel()
    {
        for (int i = 0; i < 50; i++)
        {
            ma[i] = i;
            phong[i] = 0;
        }
    }
    void tinhtrang()
    {
        cout << "==========DANH SACH PHONG============" <<endl;
		cout <<"|| "<<setw(7) << "Phong"<<setw(8)<<"||"<<setw(17) << "Tinh trang "<<"||"<<endl;
		cout<<"||--------------||-----------------||"<<endl; 
		for (int i = 0; i < 50; i++){
            cout <<"|| "<<setw(7)<<i;
if (phong[i] == 0 && i<10){
                cout<<setw(9)<<"|| "<<setw(13)<<"Free" <<setw(5)<<"||"<<endl;
            }else if(phong[i] != 0 &&i<10){
                cout <<setw(9)<<"|| "<<setw(13) <<"Being used" <<setw(5)<<"||"<<endl;
            }else if(phong[i] == 0 && i>9){
            	cout <<setw(9)<<"|| "<<setw(13)<<"Free" <<setw(5)<<"||"<<endl;
			}else if(phong[i] != 0 && i>9){
				cout <<setw(9)<<"|| "<<setw(13) <<"Being used" <<setw(5)<<"||"<<endl;
			} 
        }
        cout << "=====================================" <<endl; 
    }
};
Date D1,D2; 
class khachhang
{
public:
    int room_no;
    string name;
    int ID;
    string address;
    string phone;
    string cccd; 
    int tien;

    khachhang()
    {
    	cccd = "trong" ; 
        room_no = 0;
        name = "trong";
        ID = 0;
        address = "trong";
        phone = "trong";
        tien = 0;
    }
    void check_in(int r)
    {
        ofstream file;
        file.open("test.txt",ios::app);
        fflush(stdin);
        cout << "=====Nhap thong tin khach hang ======" << endl;
        
		cout << "Nhap Ma Khach Hang :";
        cin >> ID;
		cout << "Nhap ten :";
		cin.ignore(); 
        getline(cin, name);
		fflush(stdin);
		cout<<"Nhap can cuoc cong dan : ";
		getline(cin,cccd);
		fflush(stdin); 
        cout << "Nhap dia chi khach hang :";
        getline(cin, address);
        fflush(stdin);
        cout << "Nhap so dien thoai khach hang :";
        cin.ignore(0);
        getline(cin, phone);
        fflush(stdin); 
        file<<setw(15)<<left<<b<<setw(20)<<left<<ID<<setw(20)<<left<<name<<setw(17)<<left<<cccd<<setw(15)<<left<<address<<setw(15)<<left<<phone;
        file<<endl;
        this->room_no = r;
    }
     
	void whatch_infor()
    {
        cout << "----------------------------------------------" << endl;
        cout << "Ma khach hang : " << ID << endl;
		cout << "Ho ten khach hang :" << name << endl;
        cout << "CMND/CCCD : " << cccd <<endl; 
        cout << "Dia chi :" << address << endl;
        cout << "Lien lac :" << phone << endl;
        cout << "SO PHONG: " << room_no << endl;
        cout << "----------------------------------------------" << endl;
    }
    void Bill(int bienKhoa1)
    {

        int lua_chon;
        float soluong = 0;

        int thoathoadon;
        int thoatchonhoadon;
        int s[18];

        for (int t = 0; t < 21; t++)
        {
            s[t] = 0;
        }
        if (room_no >= 0 && room_no < 6)
        {
            cout << "Odinary room (single bed)" << endl;
			cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[9] += soluong * 1000000;
            cout << "gia :" << s[9] << "vnd " << endl;
            s[9] = 0;
            tien += soluong * 1000000;
        }
        if (room_no >= 6 && room_no < 12)
        {
            cout << "Odinary room (two single beds)" << endl;
			cout<<"Nhap ngay khach den : "; D1.nhap();
cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[10] += soluong * 1200000;
            cout << "gia :" << s[10] << "vnd " << endl;
            s[10] = 0;
            tien += soluong * 1200000;
        }
        if (room_no >= 12 && room_no < 18)
        {
            cout << "Odinary room (double bed)" << endl;
			cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[11] += soluong * 1300000;
            cout << "gia :" << s[11] << "vnd " << endl;
            s[11] = 0;
            tien += soluong * 1300000;
        }
        if (room_no >= 18 && room_no < 24)
        {
            cout << "Odinary room (two double beds)" << endl;
			cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[12] += soluong * 1500000;
            cout << "gia :" << s[12] << "vnd " << endl;
            s[12] = 0;
            tien += soluong * 1500000;
        }
        else if (room_no >= 24 && room_no < 28)
        {
            cout << "luxury room (queen size bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[13] += soluong * 2000000;
            cout << "gia :" << s[13] << "vnd " << endl;
            s[13] = 0;
            tien += soluong * 2000000;
        }
        else if (room_no >= 28 && room_no < 32)
        {
            cout << "luxury room (two queen size bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[14] += soluong * 2500000;
            cout << "gia :" << s[14] << "vnd " << endl;
            s[14] = 0;
            tien += soluong * 2500000;
        }
        else if (room_no >= 32 && room_no < 34)
        {
            cout << "luxury room (two queen size bed with extra bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[15] += soluong * 2700000;
            cout << "gia :" << s[15] << "vnd " << endl;
            s[15] = 0;
            tien += soluong * 2700000;
        }
        else if (room_no >= 34 && room_no < 38)
        {
            cout << "Royal room (queen size bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[16] += soluong * 3000000;
            cout << "gia :" << s[16] << "vnd " << endl;
            s[16] = 0;
            tien += soluong * 3000000;
        }
        else if (room_no >= 38 && room_no < 42)
        {
            cout << "Royal room (queen size bed with sofa bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[17] += soluong * 3200000;
cout << "gia :" << s[17] << "vnd " << endl;
            s[17] = 0;
            tien += soluong * 3200000;
        }
        else if (room_no >= 42 && room_no < 44)
        {
            cout << "Royal room (king size bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); 
            s[18] += soluong * 330000;
            cout << "gia :" << s[18] << "vnd " << endl;
            s[18] = 0;
            tien += soluong * 3300000;
        }
        else if(room_no >= 44 && room_no < 48)
        {
            cout << "Golden room (super king size bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); ;
            s[19] += soluong * 3500000;
            cout << "gia :" << s[17] << "vnd " << endl;
            s[19] = 0;
            tien += soluong * 3500000;
        }
        else if(room_no >= 48 && room_no < 50)
        {
            cout << "President room (grand king size bed)" << endl;
            cout<<"Nhap ngay khach den : "; D1.nhap();
			cout<<"Nhap ngay khach di : "; D2.nhap();
			soluong=D1.kc(D2); ;
            s[20] += soluong * 4000000;
            cout << "gia :" << s[17] << "vnd " << endl;
            s[20] = 0;
            tien += soluong * 4000000;
        }


        cout << "nhap hoa don dich vu: " << endl;
        thoathoadon = 0;

        while (thoathoadon == 0)
        {
            cout << "nhap dich vu bo sung (1-9,10 de thanh toan) :";
            thoatchonhoadon = 0;
            while (thoatchonhoadon == 0)
            {
                cin >> lua_chon;
                if (lua_chon >= 1 && lua_chon <= 21)
                {
                    thoatchonhoadon = 1;
                }
                else
                {
                    cout << "SAI CU PHAI VUI LONG NHAP LAI :";
                }
            }
            switch (lua_chon)
            {
            case 1:
                cout << "Buffet sang " << endl;
                cout << "nhap so luong : ";
                cin >> soluong;
                s[0] += soluong * 250000;
                cout << "gia :" << s[0] << "vnd " << endl;
                s[0] = 0;
                tien += soluong * 250000;
                break;
            case 2:
                cout << "Buffet trua " << endl;
                cout << "nhap so luong : ";
                cin >> soluong;
                s[1] += soluong * 400000;
                cout << "gia :" << s[1] << "vnd " << endl;
                s[1] = 0;
                tien += soluong * 400000;
                break;
            case 3:
                cout << "Buffet toi " << endl;
                cout << "nhap so luong : ";
                cin >> soluong;
                s[2] += soluong * 550000;
                cout << "gia :" << s[2] << "vnd " << endl;
                s[2] = 0;
                tien += soluong * 550000;
                break;
            case 4:
cout << "Buffet 3 bua " << endl;
                cout << "nhap so luong : ";
                cin >> soluong;
                s[3] += soluong * 1000000;
                cout << "gia :" << s[3] << "vnd " << endl;
                s[3] = 0;
                tien += soluong * 1000000;
                break;
            case 5:
                cout << "trang tri phong " << endl;
                s[4] += 500000;
                cout << "gia :" << s[4] << "vnd " << endl;
                s[4] = 0;
                tien += 500000;
                break;
            case 6:
                cout << "xe dua don " << endl;
                cout << " nhap so luong :";
                cin >> soluong;
                s[5] += soluong * 500000;
                cout << "gia :" << s[5] << "vnd " << endl;
                s[5] = 0;
                tien += soluong * 500000;
                break;
            case 7:
                cout << "dich vu giat ui" << endl;
                s[6] += 50000;
                cout << "gia :" << s[6] << "vnd " << endl;
                s[6] = 0;
                tien += 50000;
                break;
            case 8:
                cout << "Bua an tai phong" << endl;
                cout << " nhap so luong :" << endl;
                cin >> soluong;
                s[7] += soluong * 250000;
                cout << "gia :" << s[7] << "vnd " << endl;
                s[7] = 0;
                tien += soluong * 250000;
                break;
            case 9:
                cout << "Dich vu spa" << endl;
                cout << "nhap so luong : ";
                cin >> soluong;
                s[8] += soluong * 300000;
                cout << "gia :" << s[8] << "vnd " << endl;
                s[8] = 0;
                tien += soluong * 300000;
                cout << "tong tien :" << tien << "vnd" << endl;
                break;

            case 10:
                cout << "tong tien :" << tien << "vnd" << endl;
                bienKhoa1++;
                thoathoadon = 1;
                break;
            }
        }
    }
    void reset()
    {
    	cccd = "trong"; 
        room_no = 0;
        name = "trong";
        ID = 0;
        address = "trong";
        phone = "trong";
        tien = 0;
    }
};
class save_khachhang
{
public:
	string save_cccd; 
    int save_room_no;
    string save_name;
    int save_ID;
    string save_address;
    string save_phone;
    int save_tien;

    save_khachhang()
    {
    	save_cccd = "trong"; 
        save_room_no = 0;
        save_name = "trong";
        save_ID = 0;
        save_address = "trong";
        save_phone = "trong";
        save_tien = 0;
    }
};
hotel r;
khachhang h[50];
save_khachhang s[50];
//=========================================================
//=========================BIEN DIEU KHIEN==================
 void price()
    {
        cout << "================Bang gia phong khach san==============================" << endl;
        cout << "1.Odinary room (1.000.000-1.500.000 VND/NGAY)"<<endl;
cout << "2.luxury room (2.000.000-2.700.000 VND/NGAY)"<<endl; 
        cout << "3.Royal room (3.000.000-3.300.000 VND/NGAY)"<<endl; 
        cout << "4.Golden room (3.500.000 VND/NGAY)" << endl;
        cout << "5.President room (4.000.000 VND/NGAY)" << endl;
        cout << "======================================================================" << endl;
    }

void xemthongtin(int kiemtrasonguoi,int fakepp)
{
    kiemtrasonguoi = 0;
 	cout<<"nhap ma khach hang can tra cuu thong tin : "; 
    cin>>fakepp;
    for (int i = 0; i < 50; i++)
    { 
        if ( fakepp == h[i].ID)
        {
            kiemtrasonguoi++;
            h[i].whatch_infor();
        }
    }
    if (kiemtrasonguoi == 0)
    {
        cout << "KHONG CO THONG TIN KHACH HANG" << '\n';
    }
}
void thanhtoan(int thoatthanhtoan, int fakeID, int thimang, int chonthanhtoan, int thoatchonthanhtoan, int biendem)
{

    thoatthanhtoan = 0;
    thimang = 0;
    biendem = 0;
    cout << "NHAP MA KHACH HANG MUON THANH TOAN: ";
    cin >> fakeID;
     
    for (int i = 0; i < 50; i++)
    {
        if (h[i].ID == fakeID)
        {
            thimang = i;
            biendem++;
            service(); 
        }
    }
    if (biendem == 0)
    {
        cout << "KHONG CO THONG TIN KHACH HANG" << endl;
        cout << "VUI LONG KIEM TRA LAI" << endl;
        thoatthanhtoan = 1;
    }
    while (thoatthanhtoan == 0)
    {
        cout << "===============Thanh Toan===============" << endl;
        cout << "1.Tinh tien" << endl;
        cout << "2.Thoat" << endl;
        cout << "Nhap lua chon (1-2): ";
        thoatchonthanhtoan = 0;
        while (thoatchonthanhtoan == 0)
        {
            cin >> chonthanhtoan; 
            if (chonthanhtoan >= 1 && chonthanhtoan <= 2)
            {
                thoatchonthanhtoan = 1;
            }
            else
            {
                cout << "SAI CU PHAI VUI LONG NHAP LAI: ";
            }
        }
        switch (chonthanhtoan)
        {
        case 1:
            h[thimang].Bill(bienKhoa);
            break;
        case 2:
            thoatthanhtoan = 1;
            break;
        }
    }
}
void checkout(int kiemtraxoa, int fakeID,int bienKhoa2)
{
    kiemtraxoa = 0;
    cout << "NHAP MA KHACH HANG CHECK OUT: ";
    cin >> fakeID;
if(bienKhoa2==0){
    cout<<"khach hang chua thanh toan";
}else{
    for (int i = 0; i < 50; i++)
    {
        if (r.phong[i] == fakeID)
        {
            r.phong[i] = 0;
            kiemtraxoa++;
            break;
        }
    }
    for (int i = 0; i < 50; i++)
    {
        if (h[i].ID == fakeID)
        {
        	s[i].save_cccd = h[i].cccd; 
            s[i].save_address = h[i].address;
            s[i].save_ID = h[i].ID;
            s[i].save_name = h[i].name;
            s[i].save_phone = h[i].phone;
            s[i].save_room_no = h[i].room_no;
            s[i].save_tien = h[i].tien;
            h[i].reset();
            kiemtraxoa++;
            break;
        }
    }
    if (kiemtraxoa == 2)
    {
        cout << "==>	DA CHECK OUT." << '\n';
    }
    else
    {
cout << "KHONG CO THONG TIN KHACH HANG " << endl;
        cout << "VUI LONG KIEM TRA LAI " << endl;
    }
}
    
}
void doanhthu(int tongtien)
{
    for (int i = 0; i < 50; i++)
    {
        if (s[i].save_ID != 0)
        {	
			cout << "ma khach hang :" << s[i].save_ID << endl;
            cout << "ten khach hang :" << s[i].save_name << endl;
            cout << "cmnd/cccd : " << s[i].save_cccd << endl; 
            cout << "da o phong :" << s[i].save_room_no << endl;
            cout << "so tien khach tra :" << s[i].save_tien << "vnd" << endl;
            cout << "-----------------------------" << endl;
        }
        tongtien += s[i].save_tien;
    }
    cout << "tong doanh thu la :" << tongtien << "vnd" << endl;
}

void checkin(int kiemtradatphongch, int fakema,int select,int &b)
{
    ofstream file;
    file.open("test.txt",ios::app);
	do{
		cout <<"========CHECK IN=====================" << endl;
		cout<<"1/Odinary room"<<endl;
		cout<<"2/luxury room" <<endl; 
		cout<<"3/Royal room"<<endl;
		cout<<"4/Golden room"<<endl;
		cout<<"5/President room"<<endl; 
		cout<<"Chon kieu phong :"; 
		cin>>select; 
		}while(select<1 || select>5);
	if(select==1){
		do{ 
			cout <<"A single room include bed,fridge and bathroom"<<endl; 
			cout << "Odinary room (single bed) 0-5" << endl;
    		cout << "Odinary room (2 single bed) 6-11" << endl;
    		cout << "Odinary room (double bed) 12-17" << endl;
    		cout << "Odinary room (two double beds) 18-23" << endl;  
    		cout<<"Nhap so phong: "; 
			cin>>fakema; 
		}while(fakema<0 || fakema>23);
	}else if(select==2){
		do{
		cout <<"A room is suitable for family's vacation include TV,bacony,bed,fridge and bathroom"<<endl;	
		cout << "luxury room (queen size bed) 24-27" << endl;
    	cout << "luxury room (two queen size bed) 28-31" << endl;
    	cout << "luxury room (two queen size bed with extra bed) 32-33" << endl;
    	cout<<"Nhap so phong: "; 
		cin>>fakema; 
		}while(fakema<24 || fakema>33); 
	}else if(select==3){
		do{
			cout <<"A room with mid size swimming pool,a bacony with a lounger with a stove that you can make a party" <<endl; 
			cout << "Royal room (queen size bed) 34-37 " << endl;
			cout << "Royal room (queen size bed with sofa bed) 38-41" << endl;
			cout << "Royal room (king size bed) 42-43 " << endl;
			cout<<"Nhap so phong: "; 
			cin>>fakema; 
		}while(fakema<34 || fakema>37); 	
	}else if(select ==4){
		do{
			cout<<"A room with two bedroom large size swimming pool,a fridge that include some kind of wine and fruits," <<endl; 
			cout << "Golden room (super king size bed) 44-47 " << endl;
			cout<<"Nhap so phong: "; 
			cin>>fakema; 
		}while(fakema<44 || fakema>47); 	
	}else if(select ==5){
		do{
				cout<< "A super super cool room " <<endl; 
				cout << "President room (grand king size bed) 48-49 " << endl;
				cout<<"Nhap so phong: "; 
				cin>>fakema; 
		}while(fakema<48 || fakema>49); 
	}
    for (int i = 0; i < 50; i++)
    {
        if (fakema == r.ma[i])
        {
if (r.phong[i] == 0)
            {
                for (int a = 0; a < 50; a++)
                {
                    if (h[a].ID == 0)
                    {
                        b=fakema;
                        h[a].check_in(fakema);
                        r.phong[i] = h[a].ID;
                        kiemtradatphongch++;
                        break;
                    }
                }
            }
            else
            {
                cout << "DA DUOC DAT." << '\n';
                break;
            }
        }
        if (kiemtradatphongch == 1)
        {
            break;
        }
    }

}
void service()
{
    cout << "============Bang dich vu cua khach san============" << endl;
        cout << "1.Buffet sang : 250.000vnd/nguoi" << endl;
        cout << "2.Buffet trua : 400.000vnd/nguoi" << endl;
        cout << "3.Buffet toi  : 550.000vnd/nguoi" << endl;
        cout << "4.Buffet 3 bua : 1.000.000vnd/nguoi" << endl;
        cout << "5.Trang tri phong :500.000vnd/phong" << endl;
        cout << "6.Dua don xe san bay : 500.000vnd/1 xe" << endl;
        cout << "7.Giat ui don dep : 50.000vnd/1 phong" << endl;
        cout << "8.Phuc vu bua an tai phong :250.000vnd/nguoi" << endl;
        cout << "9.Dich vu spa : 300.000vnd/nguoi" << endl;
        cout << '\n';
        cout << "================Bang gia phong khach san==============================" << endl;
        cout << "10.Odinary room (single bed) : 1.000.000vnd/dem" << endl;
        cout << "11.Odinary room (2 single bed) : 1.000.000vnd/dem" << endl;
        cout << "12.Odinary room (double bed) : 1.000.000vnd/dem" << endl;
        cout << "13.Odinary room (two double beds) : 1.000.000vnd/dem" << endl;
        cout << "14.luxury room (queen size bed) : 2.000.000vnd/dem" << endl;
        cout << "15.luxury room (two queen size bed) : 2.500.000vnd/dem" << endl;
        cout << "16.luxury room (two queen size bed with extra bed) : 2.700.000vnd/dem" << endl;
        cout << "17.Royal room (queen size bed) :3.000.000vnd/dem" << endl;
        cout << "18.Royal room (queen size bed with sofa bed) :3.200.000vnd/dem" << endl;
        cout << "19.Royal room (king size bed) :3.300.000vnd/dem" << endl;
        cout << "18.President room : 7.000.000/dem" << endl;
        cout << "18.President room : 7.000.000/dem" << endl;
        cout << "======================================================================" << endl;
}

int main()
{
		cout << "	  PHAN MEM QUAN LY KHACH SAN "<<endl; 
    while (thoatbangdieukhien == 0)
    {
        cout <<"***********************MENU*******************************" << endl;
        cout <<"**		1.CHECK IN			 	**" << endl;
        cout <<"**		2.CHECK OUT				**" << endl;
        cout <<"**		3.XEM THONG TIN KHACH HANG	        **" << endl;
        cout <<"**		4.TINH TRANG PHONG			**" << endl;
        cout <<"**		5.THANH TOAN				**" << endl;
        cout <<"**		6.Doanh thu				**" << endl;
        cout <<"**		7.THOAT					**" << endl;
cout <<"**********************************************************" << endl; 
        cout << "==> NHAP LUA CHON(1-7): ";
        thoatchonbangdieukhien = 0;
        while (thoatchonbangdieukhien == 0)
        {

            cin >> chonbangdieukhien;
            if (chonbangdieukhien >= 1 && chonbangdieukhien <= 7)
            {
                thoatchonbangdieukhien = 1;
            }
            else
            {
                cout << "SAI CU PHAI VUI LONG NHAP LAI: ";
            }
        }
        switch (chonbangdieukhien)
        {
        case 1:
            price();
            checkin(kiemtradatphongch, fakema,select,b);
            break;
        case 2:
            checkout(kiemtraxoa, fakeID,bienKhoa);
            break;
        case 3:
            xemthongtin(kiemtrasonguoi,fakepp);
            break;
        case 4:
            r.tinhtrang();
            break;
        case 5:
//        	service(); 
            thanhtoan(thoatthanhtoan, fakeID, thimang, chonthanhtoan, thoatchonthanhtoan, biendem);
            break;
        case 6:
            doanhthu(tongtien);
            break;
        case 7:
            thoatbangdieukhien = 1;
            break;
        }
    }
}