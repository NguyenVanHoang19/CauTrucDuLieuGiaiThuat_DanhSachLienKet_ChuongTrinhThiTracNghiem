#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include<windows.h>
#include<time.h>
#include "ThuVienDoHoa.h"
#include <algorithm>
#include <vector>
using namespace std;
typedef struct CAUHOI
{
	string stt;
	string cauHoi;
	string cauA;
	string cauB;
	string cauC;
	string cauD;
	string dapAn;
};
typedef struct LogIn
{
	string hoTen,gioiTinh,namSinh,taiKhoan,matKhau;
};
struct node
{
	CAUHOI data;
	node *link;
};
struct list
{
	node *first,*last;
};
void init(list &l)
{
	l.first=l.last=NULL;
}
node *GetNode(CAUHOI dulieu)
{
	node *p;
	p= new node;
	if(p==NULL)
		return NULL;
	p->data=dulieu;
	p->link = NULL;
	return p;
}
void addfirst(list &l,node *new_ele)
{
	if(l.last == NULL)
	{
		l.first=l.last=new_ele;
	}
	else
	{
		l.last->link = new_ele;
		l.last = new_ele;
	}
}
void insertFirst(list &l,CAUHOI dulieu)
{
	node *new_ele = GetNode(dulieu);
	if(new_ele ==NULL)
	{
		return;
	}
	addfirst(l,new_ele);
}
struct nodeLogIn
{
	LogIn data;
	nodeLogIn *next;
};
struct listLogIn
{
	nodeLogIn *dau,*cuoi;
};
void initLogIn(listLogIn &l)
{
	l.dau=l.cuoi=NULL;
}
nodeLogIn *GetNodeLogIn(LogIn dulieu)
{
	nodeLogIn *p;
	p= new nodeLogIn;
	if(p==NULL)
		return NULL;
	p->data=dulieu;
	p->next = NULL;
	return p;
}
void addfirstLogIn(listLogIn &l,nodeLogIn *new_eleLogIn)
{
	if(l.cuoi == NULL)
	{
		l.dau=l.cuoi=new_eleLogIn;
	}
	else
	{
		l.cuoi->next = new_eleLogIn;
		l.cuoi = new_eleLogIn;
	}
}
void insertFirstLogIn(listLogIn &l,LogIn dulieu)
{
	nodeLogIn *new_eleLogIn = GetNodeLogIn(dulieu);
	if(new_eleLogIn ==NULL)
	{
		return;
	}
	addfirstLogIn(l,new_eleLogIn);
}
void DocFileKhoiDau( char *tenfile ){
	string s;
	int dem = 0;
	system("cls");
	char *a ="		";
	ifstream fin(tenfile);
	while( getline( fin , s )){
		dem++;
		if( dem <= 5){
			textcolor(9);
		//	SetBGColor(1);
		}
		else if( dem >= 14 && dem < 18 ){
			textcolor(9);
		//	SetBGColor(1);
		}
		else if( dem >= 18 ){
			textcolor(9);
			SetBGColor(0);
		}
		else if( dem > 2 && dem < 14 ){
			textcolor(9);
		//	SetBGColor(0);
		}
			cout<<" "<<endl;
			cout<<a;
			cout<<s<<endl;
	}
	fin.close();
}
void DocFileCauTrucDuLieu( char *tenfile ){
	string s;
	int dem = 0;
	system("cls");
	char *a ="		";
	ifstream fin(tenfile);
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	while( getline( fin , s )){
		dem++;
		if( dem <= 5){
			textcolor(9);
		//	SetBGColor(1);
		}
		else if( dem >= 14 && dem < 18 ){
			textcolor(9);
		//	SetBGColor(1);
		}
		else if( dem >= 18 ){
			textcolor(9);
			SetBGColor(0);
		}
		else if( dem > 2 && dem < 14 ){
			textcolor(9);
		//	SetBGColor(0);
		}
//			cout<<" "<<endl;
			cout<<a;
			cout<<s<<endl;
	}
	fin.close();
}
void docTungCau(ifstream &file_in,CAUHOI &dulieu)
{
		getline(file_in,dulieu.stt);
		getline(file_in,dulieu.cauHoi);
		getline(file_in,dulieu.cauA);
		getline(file_in,dulieu.cauB);
		getline(file_in,dulieu.cauC);
		getline(file_in,dulieu.cauD);
		getline(file_in,dulieu.dapAn);

}
void docDanhSach(ifstream &file_in,list &l)
{
	while(!file_in.eof())
	{
		CAUHOI dulieu;
		docTungCau(file_in,dulieu);
		node *p = GetNode(dulieu);
		addfirst(l,p);
	}
}
void docPW(ifstream &fileLogin,LogIn &dulieu)
{
	getline(fileLogin,dulieu.hoTen);
	getline(fileLogin,dulieu.gioiTinh);
	getline(fileLogin,dulieu.namSinh);
	getline(fileLogin,dulieu.taiKhoan);
	getline(fileLogin,dulieu.matKhau);
}
void docLogIn(ifstream &fileLogIn,listLogIn &l)
{
	while(!fileLogIn.eof())
	{
		LogIn dulieu;
		docPW(fileLogIn,dulieu);
		nodeLogIn *p1 = GetNodeLogIn(dulieu);
		addfirstLogIn(l,p1);
	}
}
int size(list l)
{

	node *p = l.first;
	int size=0;
	for(p;p!=NULL;p=p->link)
	{
		size++;
	} 
	return size;
}
string chuyenDoi(int num)
{
	char s[20];
	sprintf(s,"%d",num);
	return s;
}
void xuat1CauHoi(CAUHOI dulieu,int timeout)
{	
		KhungCauHoi();
		KhungTraLoiPhaiTren();
		KhungTraLoiBenPhaiDuoi();
		KhungTraLoiTraiTren();
		KhungTraLoiTraiDuoi();
		KhungTimeCauhoi(timeout);
		gotoxy(30,9);
		cout<<" "<<dulieu.cauHoi<<endl;
		gotoxy(22,15);
		cout<<" "<<dulieu.cauA<<endl;
		gotoxy(65,15);
		cout<<" "<<dulieu.cauB<<endl;
		gotoxy(22,20);
		cout<<" "<<dulieu.cauC<<endl;
		gotoxy(65,20);
		cout<<" "<<dulieu.cauD<<endl;
		khunglon();
}
void GhiVaoFile(ofstream &fileout,CAUHOI dulieu) //ghi du lieu theo thu tu tung dong
{
	fileout<<dulieu.stt<<endl;
	fileout<<dulieu.cauHoi<<endl;
	fileout<<dulieu.cauA<<endl;
	fileout<<dulieu.cauB<<endl;
	fileout<<dulieu.cauC<<endl;
	fileout<<dulieu.cauD<<endl;
	fileout<<dulieu.dapAn;
}
int  LuuDanhSach_VaoFile(list l)
{
	ofstream fileout;
	fileout.open("cauhoi.txt",ios::out);
	if (!fileout)
		return 0;
	for(node *k=l.first;k!=NULL;k=k->link)
	{
		GhiVaoFile(fileout,k->data);
		if (k != l.last)
			fileout << endl;
	}
	fileout.close();
	return 1;
}
//Ghi Vao File Pw
void GhiVaoFilePw(ofstream &fileout,LogIn dulieu) //ghi du lieu theo thu tu tung dong
{
	fileout<<dulieu.hoTen<<endl;
	fileout<<dulieu.gioiTinh<<endl;
	fileout<<dulieu.namSinh<<endl;
	fileout<<dulieu.taiKhoan<<endl;
	fileout<<dulieu.matKhau;
}
// luu pw
int  LuuPw_VaoFile(listLogIn logIn)
{
	ofstream fileout;
	fileout.open("DangNhap.txt",ios::out);
	if (!fileout)
		return 0;
	for(nodeLogIn *k=logIn.dau;k!=NULL;k=k->next)
	{
		GhiVaoFilePw(fileout,k->data);
		if (k != logIn.cuoi)
			fileout << endl;
	}
	fileout.close();
	return 1;
}
//Dang Ki Tai Khoan
void DangKiTaiKhoan(LogIn &logIn){
	string ktPw;
	bool t=true;
	while(t)
	{
		system("cls");
		KhungDangKiTaiKhoan(35,7,45,15,true);
		fflush(stdin);
		gotoxy(46,10);
		getline(std::cin,logIn.hoTen);
		gotoxy(49,12);
		fflush(stdin);
		getline(std::cin,logIn.gioiTinh);
		gotoxy(48,14);
		fflush(stdin);
		getline(std::cin,logIn.namSinh);
		gotoxy(53,16);
		fflush(stdin);
		getline(std::cin,logIn.taiKhoan);
		gotoxy(49,18);
		fflush(stdin);
		getline(std::cin,logIn.matKhau);
		gotoxy(58,20);
		fflush(stdin);
		getline(std::cin,ktPw);
		if(ktPw.compare(logIn.matKhau)!=0)
		{
			gotoxy(45,6);
			cout<<"Xac Nhan Mat Khau Sai"<<endl;
			Sleep(1000);
		}	
		if(ktPw.compare(logIn.matKhau)==0)
		{
			t = false;
		}
	}
}
// luu pw
void themPw(listLogIn &l){
	 LogIn logIn;
		DangKiTaiKhoan(logIn);
		nodeLogIn *them = GetNodeLogIn(logIn);
		addfirstLogIn(l,them);
}
void XoaDau(list &l)
{
	
	if (l.first == NULL)
	{
		return;
	}
	node *p = l.first;
	l.first = l.first->link;
	delete p;
}
void XoaCuoi(list &l)
{


	if (l.first == NULL)
	{
		return;
	}
	
	if (l.first->link == NULL)
	{
		XoaDau(l);
		return;
	}
	
	for (node *k = l.first; k != NULL; k = k->link)
	{
	
		if (k->link == l.last)
		{
			delete l.last; 
			k->link = NULL; 
			l.last = k; 
			return;
		}
	}
}

node *XoaNodeCoKhoaBatKy(list &l)
{
	textcolor(12);
	
	cout<<"Ban muon xoa cau nao @@!~~: ";
	string x;
//	cin.ignore(); 
	getline(std::cin,x);
	if (l.first == NULL)
	{
		return NULL;
	}
	if (l.first->data.stt == x)
	{
		XoaDau(l);
		return l.first;
	}

	if (l.last->data.stt == x)
	{
		XoaCuoi(l);
		return l.last;
	}

	node *g = new node; 

	for (node *k = l.first; k != NULL; k = k->link)
	{
	
		if (k->data.stt == x)
		{
			g->link = k->link; 
			delete k; 	
			return g;
		}
		g = k; 
	}
	return NULL;
		
}
void capnhatstt(list &l){
	int dem=0;
	for(node *p=l.first;p!=NULL;p=p->link){
		int num1 = atoi(p->data.stt.c_str()); 
		dem++;
		p->data.stt=chuyenDoi(dem);
		LuuDanhSach_VaoFile(l);
		
	}
}
void nhapcauhoi(CAUHOI &ch){
	khungxoacauhoi(61,11,50,2,true);
	gotoxy(65,12);
	cout<<"Nhap cau hoi: ";
	getline(std::cin,ch.cauHoi);
	khungxoacauhoi(61,14,40,2,true);
	gotoxy(65,15);
	cout<<"Nhap dap an A: ";
	getline(std::cin,ch.cauA);	
	khungxoacauhoi(61,17,40,2,true);
	gotoxy(65,18);
	cout<<"Nhap dap an B: ";
	getline(std::cin,ch.cauB);
	khungxoacauhoi(61,20,40,2,true);
	gotoxy(65,21);
	cout<<"Nhap dap an C: ";
	getline(std::cin,ch.cauC);
	khungxoacauhoi(61,23,40,2,true);
	gotoxy(65,24);
	cout<<"Nhap dap an D: ";
	getline(std::cin,ch.cauD);
	khungxoacauhoi(61,26,40,2,true);
	gotoxy(65,27);
	cout<<"Nhap dap an chinh xac: ";
	getline(std::cin,ch.dapAn);
	cout<<endl<<endl<<endl;
	
}
void xuatcauhoibixoa(CAUHOI dulieu)
{

	khungxoacauhoi(35,7,60,2,true);
	gotoxy(39,8);
	cout<<"Cau hoi ma ban vua moi xoa xong:";
	textcolor(3.6);
	khungxoacauhoi(35,11,60,2,true);
	khungxoacauhoi(35,14,60,2,true);
	khungxoacauhoi(35,17,60,2,true);
	khungxoacauhoi(35,20,60,2,true);
	khungxoacauhoi(35,23,60,2,true);
	khungxoacauhoi(35,26,60,2,true);
	gotoxy(39,12);
	cout<<dulieu.cauHoi;
	gotoxy(39,15);
	cout<<dulieu.cauA;
	gotoxy(39,18);
	cout<<dulieu.cauB;
	gotoxy(39,21);
	cout<<dulieu.cauC;
	gotoxy(39,24);
	cout<<dulieu.cauD;
	gotoxy(39,27);
	cout<<"Dap an: "<<dulieu.dapAn<<endl<<endl;
}
void xuatcauhoibisua(CAUHOI dulieu)
{
	khunglon();
	khungxoacauhoi(1,7,60,2,true);
	gotoxy(2,8);
	textcolor(12);
	cout<<"Cau hoi ban sap sua";
	textcolor(14);	
	khungxoacauhoi(61,7,45,2,true);
	gotoxy(66,8);
	cout<<"Ban sua thanh ";
	textcolor(12);
	khungxoacauhoi(1,11,60,2,true);
	khungxoacauhoi(1,14,60,2,true);
	khungxoacauhoi(1,17,60,2,true);
	khungxoacauhoi(1,20,60,2,true);
	khungxoacauhoi(1,23,60,2,true);
	khungxoacauhoi(1,26,60,2,true);
	gotoxy(2,12);
	cout<<dulieu.cauHoi;
	gotoxy(2,15);
	cout<<dulieu.cauA;
	gotoxy(2,18);
	cout<<dulieu.cauB;
	gotoxy(2,21);
	cout<<dulieu.cauC;
	gotoxy(2,24);
	cout<<dulieu.cauD;
	gotoxy(2,27);
	cout<<"Dap an: "<<dulieu.dapAn<<endl<<endl;
}
void nhapcauhoithem(CAUHOI &ch,int &sttt){ 
	textcolor(16);
	gotoxy(56,8);
	cout<<"Them Cau Hoi";
	khungxoacauhoi(49,7,25,2,true);
	ch.stt=chuyenDoi(sttt);	
	textcolor(4);
	khungxoacauhoi(47,11,70,2,true);
	gotoxy(23,12);
	cout<<"Nhap cau hoi: ";
	khungxoacauhoi(22,11,23,2,true);
	gotoxy(48,12);
	getline(std::cin,ch.cauHoi);
	textcolor(4);
	khungxoacauhoi(47,14,70,2,true);
	gotoxy(23,15);
	cout<<"Nhap dap an A: ";
	khungxoacauhoi(22,14,23,2,true);
	gotoxy(48,15);
	getline(std::cin,ch.cauA);
	textcolor(4);	
	khungxoacauhoi(47,17,70,2,true);
	gotoxy(23,18);
	cout<<"Nhap dap an B: ";
	khungxoacauhoi(22,17,23,2,true);
	gotoxy(48,18);
	getline(std::cin,ch.cauB);
	textcolor(4);
	khungxoacauhoi(47,20,70,2,true);
	gotoxy(23,21);
	cout<<"Nhap dap an C: ";
	khungxoacauhoi(22,20,23,2,true);
	gotoxy(48,21);
	getline(std::cin,ch.cauC);
	textcolor(4);
	khungxoacauhoi(47,23,70,2,true);
	gotoxy(23,24);
	cout<<"Nhap dap an D: ";
	khungxoacauhoi(22,23,23,2,true);
	gotoxy(48,24);
	getline(std::cin,ch.cauD);
	textcolor(4);
	khungxoacauhoi(47,26,70,2,true);
	gotoxy(23,27);
	cout<<"Nhap dap an chinh xac: ";
	khungxoacauhoi(22,26,23,2,true);
	gotoxy(48,27);
	getline(std::cin,ch.dapAn);
	cout<<endl<<endl;
	
}
void themcauhoi(list &l){
		int dem=0;
	 	CAUHOI ch;
		dem=size(l)+1;
		nhapcauhoithem(ch,dem);
		node *them = GetNode(ch);
		addfirst(l,them);
}


void sua(list &l,string s){
	CAUHOI ch;
	 
	for(node *k=l.first;k!=NULL;k=k->link){
		
		if(s==k->data.stt){
		system("cls");
		xuatcauhoibisua(k->data);
		ch.stt=s;
		nhapcauhoi(ch);
		node *them = GetNode(ch);
		k->data=them->data;			
		}
		
	}
}

// Huy Toan Bo Danh Sach
void deleteAll(list &l)
{
	for(node *p=l.first;p!=NULL;p=p->link)
	{
		node *temp =  p;
		delete temp;
	}
	l.first = l.last = NULL;
}
//file
void GhiVaoFile1(ofstream &fileout1,CAUHOI dulieu) //ghi du lieu theo thu tu tung dong
{
	fileout1<<dulieu.cauHoi<<endl;
	fileout1<<dulieu.dapAn<<endl;
}
int LuuLichSu(list LichSu,list LichSu2,string ten,string GioiTinh,string Tuoi)
{
	ofstream fileout1;
	fileout1.open("LichSuThi.txt",ios::out);
	fileout1<<"***"<<ten<<endl;
	fileout1<<"**"<<GioiTinh<<endl;
	fileout1<<"**"<<Tuoi<<endl;
	fileout1<<"--Cac Cau Ban Tra Loi Dung"<<endl;
	for(node *p1=LichSu.first;p1!=NULL;p1=p1->link)
	{
		GhiVaoFile1(fileout1,p1->data);
	}
	fileout1<<"--Cac Cau Ban Tra Loi Sai"<<endl;
	for(node *p2=LichSu2.first;p2!=NULL;p2=p2->link)
	{
		GhiVaoFile1(fileout1,p2->data);
	}
	return 1;
}
/*
	Xuat cau hoi Ngau Nhien
*/
int diem = 0; // bien cuc bo tinh diem 
void XuatCauNgauNhien(list &l,list &l2,list &l3,list &LichSu,list &LichSu1,CAUHOI dulieu,int timeout,string stt) //timeout la bien de in khung thoi gian cau hoi
{
	node *p=l.first;
	SetBGColor(160);
	node *p1; // luu dap an dung vao danh sach
	node *p3; //luu dap an sai vao danh sach
	string dapAn;
	for(p;p!=NULL;p=p->link)
	{
		if(p->data.stt.compare(stt)==0)
		{
			system("cls");
			xuat1CauHoi(p->data,timeout); // xuat ra 1 cau hoi
			KhungTraLoi();
			gotoxy(57,27);
			cin>>dapAn;
			cin.ignore();
			if(dapAn == p->data.dapAn)
			{
				diem++;
				insertFirst(l2,p->data); // luu cau tra loi  dung vao danh sach
				insertFirst(LichSu,p->data); 
			}
			else 
			{
				insertFirst(l3,p->data); //luu cau tra loi  sai vao danh sach
				insertFirst(LichSu1,p->data);		
			}
		}
	}	
}
void xuatRanDom(list &l,list &l2,list &l3,list &LichSu,list &LichSu1,CAUHOI dulieu)
{
	int x; // la bien cung voi timeout
	string dapAn;
	string HoTen,GioiTinh,NamSinh;
	string stt;
	node *p1; // luu dap an dung vao danh sach
	node *p3; //luu dap an sai vao danh sach
	float sum =0;
	bool f=true;
	string ten;
	system("cls");
	clockid_t t1,t2;
	SetBGColor(9);
	do
	{
		system("cls");
		gotoxy(49,5);
		cout<<"SO LUONG CAU HOI??"<<endl;
		gotoxy(45,6);
		cout<<"Moc 10 , 20 , 30 ,40 Cau Hoi"<<endl;
		BangKetQua(26,8,"LUA CHON");
		gotoxy(57,12);
		cin>>x;
		if(x==10 || x==20 || x==30 || x==40)
			f=false;
		else 
		{
			gotoxy(43,3);
			cout<<"Enter De Xac Nhan Va Nhap Lai"<<endl;
			ThongBaoNhapNhay("Moc Lua Chon Cua Ban Sai",12,12,45,2);
		}
	}
	while(f);
	int times;
	int bienChay = 0;
	int a;
	int dai = size(l); // chieu dai max cua danh sach
	srand(time(NULL));
	t1 = clock();
	for(int i=1;i<=x;i++)
	{
		if(x == 10)
		{
			a = 1+ rand() % dai; // random trong khoang tu 1 den chieu dai danh sach max
		} 
		else
		{	
			a = rand() % (dai - 5 + 1) + 5;
		}
		stt = chuyenDoi(a); // chuyen doi ki tu int sang string
		XuatCauNgauNhien(l,l2,l3,LichSu,LichSu1,dulieu,x,stt); 
		t2 = clock(); 
	 	times = (double)(t2-t1)/CLOCKS_PER_SEC;
		if(x==10)
		{
			if(times>300)
				break;
		}
		else if(x==20)
		{
			if(times>600)
				break;
		}
		else if(x==30)
		{
			if(times>900)
				break;
		}
		else if(x==40)
		{
			if(times>1200)
				break;
		}
		
	}
//	LuuLichSu(l2,l3);
	LuuLichSu(LichSu,LichSu1,HoTen,GioiTinh,NamSinh);
	system("cls");
	BangKetQua(26,8,"KET QUA");
	gotoxy(41,12);
	cout<<"Thoi Gian Ma Ban Da Lam Bai: "<<times<<"s"<<endl;
	gotoxy(41,13);
	cout<<"So Cau Tra Loi Dung: "<<diem<<endl;
	if(x==40)
	{
		sum+=(float)diem*0.4;
		gotoxy(41,14);
		cout<<"DIEM CUA BAN = "<<sum<<endl;
	}
	else if(x==10)
	{
		sum+=diem;
		gotoxy(41,14);
		cout<<"DIEM CUA BAN = "<<sum<<endl;
	}
	else if(x==20)
	{
		gotoxy(41,14);
		sum += (float)diem * 0.5;
		cout<<"DIEM CUA BAN = "<<sum<<endl;
	}
	else if(x==30)
	{
		gotoxy(41,14);
		sum += (float)diem * 0.3;
		cout<<"DIEM CUA BAN = "<<sum<<endl;
	}
	Sleep(4000);
		system("cls");
		BangKetQua(26,8,"LUA CHON");
		gotoxy(41,5);
		cout<<"Ban Muon Xem Nhung Cau Dung Khong?"<<endl;
		gotoxy(53,6);
		cout<<"1.Co 2.Khong"<<endl;
		int e;
		int chon ;
		gotoxy(57,12);
		cin>>e;
		int i=44;
		if(e==1)
		{	
			gotoxy(41,9);
			system("cls");
			BangKetQua(26,8,"KET QUA");
			gotoxy(41,6);
			cout<<"Cac Cau Ma Ban Da Tra Loi Dung."<<endl;
			gotoxy(38,13);
			cout<<"Cau: ";
			for(p1=l2.first;p1!=NULL;p1=p1->link)
			{
					system("cls");
					KhungCauHoi();
					gotoxy(30,9);
					cout<<" "<<p1->data.cauHoi<<endl;
					KhungTestingCauhoi();
					gotoxy(52,4);
					textcolor(28);
					cout<<"DAP AN."<<endl;
					KhungTraLoiBenPhaiDuoi();
					KhungTraLoiPhaiTren();
					KhungTraLoiTraiDuoi();
					KhungTraLoiTraiTren();
					if(p1->data.dapAn == "a")
					{
						gotoxy(22,15);
						cout<<" "<<p1->data.cauA<<endl;		
					}
					else if(p1->data.dapAn == "b")
					{
						gotoxy(65,15);
						cout<<" "<<p1->data.cauB<<endl;
					}
					else if(p1->data.dapAn == "c")
					{
						gotoxy(22,20);
						cout<<" "<<p1->data.cauC<<endl;
					}						
					else if(p1->data.dapAn == "d")
					{
						gotoxy(65,20);
						cout<<" "<<p1->data.cauD<<endl;
					}
					gotoxy(41,30);
					cout<<"Nhan Phim Bat Ki De Xem Dap An Cua Cau Tiep Theo"<<endl;
					gotoxy(53,31);
					cout<<"ESC De Dung Xem Dap An"<<endl;
					int chon = getch();
					if(chon==27)
						break;
				}
			}
			gotoxy(41,30);
			cout<<"Nhan Phim Bat Ki De Xem Chuc Nang Ke Tiep"<<endl;
			getch();
			system("cls");
			BangKetQua(26,8,"LUA CHON");
			gotoxy(41,5);
			cout<<"Ban Muon Xem Nhung Cau Tra Loi Sai Khong?"<<endl;
			gotoxy(53,6);
			cout<<"1.Co 2.Khong"<<endl;
			gotoxy(57,12);
			cin>>chon;
			int temp=11;
			if(chon == 1)
			{
				system("cls");
				gotoxy(47,10);
				cout<<"Cau Ma Ban Da Tra Loi Sai"<<endl;
				for(p3=l3.first;p3!=NULL;p3=p3->link)
				{
					gotoxy(59,temp);
					cout<<p3->data.stt<<endl;
					temp++;
				}
				gotoxy(41,30);
				cout<<"Nhan Phim Bat Ki De Xem Cac Chuc Nang Tiep Theo"<<endl;
				getch();
				system("cls");
				BangKetQua(26,8,"LUA CHON");
				gotoxy(41,5);
				cout<<"Ban Muon Xem Dap An Nhung Cau Tra Loi Sai Khong?"<<endl;
				gotoxy(53,6);
				cout<<"1.Co 2.Khong"<<endl;
				gotoxy(57,12);
				cin>>chon;
				if(chon == 1)
				{
					for(p3=l3.first;p3!=NULL;p3=p3->link)
					{
						system("cls");
						KhungCauHoi();
						gotoxy(30,9);
						cout<<" "<<p3->data.cauHoi<<endl;
						KhungTestingCauhoi();
						gotoxy(52,4);
						textcolor(28);
						cout<<"DAP AN."<<endl;
						KhungTraLoiBenPhaiDuoi();
						KhungTraLoiPhaiTren();
						KhungTraLoiTraiDuoi();
						KhungTraLoiTraiTren();
						if(p3->data.dapAn == "a")
						{
							gotoxy(22,15);
							cout<<" "<<p3->data.cauA<<endl;		
						}
						else if(p3->data.dapAn == "b")
						{
							gotoxy(65,15);
							cout<<" "<<p3->data.cauB<<endl;
						}
						else if(p3->data.dapAn == "c")
						{
							gotoxy(22,20);
							cout<<" "<<p3->data.cauC<<endl;
						}						
						else if(p3->data.dapAn == "d")
						{
							gotoxy(65,20);
							cout<<" "<<p3->data.cauD<<endl;
						}
						gotoxy(41,30);
						cout<<"Nhan Phim Bat Ki De Xem Dap An Cua Cau Tiep Theo"<<endl;
						getch();
					}
				}
				gotoxy(41,30);
				cout<<"Nhan Phim Bat Ki De Xem Cac Chuc Nang Tiep Theo"<<endl;
				getch();
			}
		khunglon();
}
void xuLyChuongTrinh(CAUHOI dulieu,list l,list &l2,list &l3,list &LichSu,list &LichSu1,listLogIn &DslogIn)
{
	string passwordNhap;
	string usueNhap;
	LogIn login;
	int diemPrintf;
	bool e = true;
	bool t = true;
	bool y = true;
	int ktTaiKhoan = 0;
	int ktMatKhau = 0;
	int luaChon;
		while(t)
		{
			xuatGiaoDienChinh();
			char banphim =  _getch();
			switch(banphim)
			{
				
				case 59: // F1
				manHinhLoading();
				system("cls");
				KhungDangNhap(35,7,45,15,true);
				gotoxy(57,10);
				cin>>luaChon;
				if(luaChon == 2)
				{
					SetBGColor(9);
					gotoxy(55,5);
					textcolor(12);
					cout<<"Registration"<<endl;
					themPw(DslogIn);
					system("cls");
					gotoxy(45,14);
					cout<<"Dang Ki Thanh Cong"<<endl;
					Sleep(1000);
					LuuPw_VaoFile(DslogIn);
					while(y)
					{
						system("cls");
						gotoxy(47,5);
						cout<<"Xac Nhan Lai Tai Khoan"<<endl;
						gotoxy(55,6);
						cout<<"LOGIN"<<endl;
						KhungDangNhap2(35,7,45,15,true);
						gotoxy(53,13);
						fflush(stdin);
						getline(std::cin,usueNhap);
						gotoxy(48,15);
						fflush(stdin);
						getline(std::cin,passwordNhap);
						for(nodeLogIn *r=DslogIn.dau;r!=NULL;r=r->next)
						{
							if(passwordNhap.compare(r->data.matKhau)==0 && usueNhap.compare(r->data.taiKhoan)==0 && passwordNhap.compare("\n")!=0 && usueNhap.compare("\n")!=0)
							{
								ktMatKhau++;	
							}
						}
						if(ktMatKhau!=0)
						{
							system("cls");
							khungxoacauhoi(45,12,30,4,true);
							gotoxy(49,14);
							textcolor(12);
							cout<<"Dang Xac Nhan"<<endl;
							Sleep(1000);
							y = false;
						}
						else 
						{
							gotoxy(43,5);
							cout<<"Tai Khoan Hoac Mat Khau Sai"<<endl;
							Sleep(1000);
						}
					}
				}
				if(luaChon == 1)
				{
					while(y)
					{
						system("cls");
						gotoxy(55,6);
						cout<<"LOGIN"<<endl;
						KhungDangNhap2(35,7,45,15,true);
						gotoxy(53,13);
						fflush(stdin);
						getline(std::cin,usueNhap);
						gotoxy(48,15);
						fflush(stdin);
						getline(std::cin,passwordNhap);
						for(nodeLogIn *r=DslogIn.dau;r!=NULL;r=r->next)
						{
							if(passwordNhap.compare(r->data.matKhau)==0 && usueNhap.compare(r->data.taiKhoan)==0 && passwordNhap.compare("")!=0 && usueNhap.compare("")!=0)
							{
								ktMatKhau++;
								
							}
						}
						if(ktMatKhau!=0)
						{
							system("cls");
							khungxoacauhoi(45,12,30,4,true);
							gotoxy(49,14);
							textcolor(12);
							cout<<"Dang Xac Nhan"<<endl;
							Sleep(1000);
							y = false;
						}
						else 
						{
							gotoxy(43,5);
							cout<<"Tai Khoan Hoac Mat Khau Sai"<<endl;
							Sleep(1000);
						}
					}
				}
				xuatRanDom(l,l2,l3,LichSu,LichSu1,dulieu);
				gotoxy(41,23);
				cout<<"Backspace Ve Lai Giao Dien Chinh."<<endl;
				deleteAll(l2);
				deleteAll(l3);
				diemPrintf = diem;
				diem = 0;
				getch();
				if(banphim==8)
					t= true;
				break;
				case 60: //F2
				{
					system("cls");
					manHinhLoading();
					system("cls");
					textcolor(16);
					khungxoacauhoi(40,10,50,5,true);	
					gotoxy(50,12);
					node *xoa = XoaNodeCoKhoaBatKy(l);
					if(xoa!=NULL)
					{
						gotoxy(50,12);
						cout<<"Xong roi nha! "<<endl<<endl;
						system("cls");
						xuatcauhoibixoa(xoa->data);
						LuuDanhSach_VaoFile(l);	
					}
					else
					{
						gotoxy(50,12);
						cout<<"Xoa khong thanh cong nha"<<endl<<endl;
					}
					system("pause");
					system("cls");				
					break;
				}
				case 61: // f3
				{
					system("cls");
					textcolor(13);
					
					khungxoacauhoi(37,10,50,2,true);
					gotoxy(35,10);
					cout<<"\n\t\t\t\t\t\tNhap vao cau hoi muon sua: ";
					string suasai;
					getline(std::cin,suasai);
					//xuat1CauHoi()
					sua(l,suasai);
					LuuDanhSach_VaoFile(l);
					system("pause");
					system("cls");
					break;
				}	
				case 62: //f4
				{
					system("cls");
					themcauhoi(l);
					LuuDanhSach_VaoFile(l) ;
					break;
				}
				case 63: //f5
					{
						system("cls");
					//	LichSuThi(l,l2,l3,dulieu);
						cout<<char(254)<<"Cau Ban Tra Loi Dung"<<endl;
						cout<<"--------------------------------------------------------------------------"<<endl;
						for(node *p4=LichSu.first;p4!=NULL;p4=p4->link)
						{
							cout<<p4->data.cauHoi<<endl;
							cout<<"Dap An: "<<p4->data.dapAn<<endl;
						}
						cout<<char(254)<<"Cau Ban Tra Loi Sai"<<endl;
						cout<<"--------------------------------------------------------------------------"<<endl;
						for(node *p5=LichSu1.first;p5!=NULL;p5=p5->link)
						{
							cout<<p5->data.cauHoi<<endl;
							cout<<"Dap An: "<<p5->data.dapAn<<endl;
						}
						cout<<"--------------------------------------------------------------------------"<<endl;
						cout<<"Diem: "<<diemPrintf<<endl;
						getch();
						gotoxy(41,23);
						cout<<"Backspace Ve Lai Giao Dien Chinh."<<endl;
						if(banphim==8)
							t= true;
						break;
					}
				case 27: //esc
					system("cls");
					BangGioiThieuTacGia();
					Sleep(1000);
					t=false;
				break;
			}
		}		
}
int main()
{
	list l;
	init(l);
	list l2;
	init(l2);
	list l3;
	init(l3);
	listLogIn dslogin;
	initLogIn(dslogin);
	list LichSu;
	init(LichSu);
	list LichSu1;
	init(LichSu1);
	CAUHOI dulieu;
	system("cls");
	DocFileCauTrucDuLieu("chu.txt");
	Sleep(2000);
	SetBGColor(29);
	manHinhLoading();
	SetBGColor(0);
	DocFileKhoiDau("manhinhchao.txt");
	Sleep(1000);
	ifstream file_in;
	ifstream file_inPw;
	file_in.open("cauhoi.txt",ios::in);
	docDanhSach(file_in,l);
	file_inPw.open("DangNhap.txt",ios::in);
	docLogIn(file_inPw,dslogin);
	xuLyChuongTrinh(dulieu,l,l2,l3,LichSu,LichSu1,dslogin);
	file_in.close();
	file_inPw.close();
	getch();
	return 0;
}
