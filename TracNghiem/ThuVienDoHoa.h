#include<stdio.h>
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<conio.h>
using namespace std;
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
//to mau BG
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
// tat hien con tro chuot
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
int wherey()
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
//to mau
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void ToMau(int x, int y, char *a, int color) // x, y là t?a d? con tr? c?n nh?y d?n d? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
//mau
//mau
void setColor(short x) { 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}
//di chuyen den x,y

////hien loi chao
//void DocFileKhoiDau( char *tenfile ){
//	string s;
//	int dem = 0;
//	ifstream fin(tenfile);
//	while( getline( fin , s )){
//		dem++;
//		if( dem <= 5){
//			textcolor(15);
//			SetBGColor(1);
//		}
//		else if( dem >= 14 && dem < 18 ){
//			textcolor(15);
//			SetBGColor(1);
//		}
//		else if( dem >= 18 ){
//			textcolor(0);
//			SetBGColor(0);
//		}
//		else if( dem > 2 && dem < 14 ){
//			textcolor(12);
//			SetBGColor(0);
//		}
//	//	gotoxy(15,4);
//		cout << s << endl;
//	}
//	fin.close();
//}
// man hinh loading
void manHinhLoading()
{
	system("cls");

	gotoxy(51,12);cout << "LOADING...";
	for( int i = 0 ; i <= 50 ; i++ ){
		textcolor(13);
		gotoxy(34 + i,13);cout << char(219);
		textcolor(23);
		gotoxy(55,14);cout << i * 2 << "%";
			Sleep(30);
		}
}
// tao khung hinh
void KhungHinh( int x , int y , int w ){
	gotoxy(x,y);
	SetBGColor(10);
	for(int i = 0 ; i < w ; i++ ){
		if( i == 0 ){
			cout << char(218);
		}
		else if( i == w - 1 ){
			cout << char(191);
		}
		else{ 
			cout << char(196);
		}
	}
	gotoxy(x,y + 1);
	cout << char(179);
	gotoxy(x + w - 1,y + 1);
	cout << char(179);
	gotoxy(x,y + 2);
	for( int i = 0 ; i < w ; i++ ){
		if( i == 0 ){
			cout << char(192);
		}
		else if( i == w - 1 ){
			cout << char(217);
		}
		else{ 
			cout << char(196);
		}
	}
	gotoxy(x + 1,y + 1);
}
// tao thanh ngang
void ThanhNgang( int x , int y , int maunen , int mauchu , int makitu ){
	SetBGColor(maunen);
	textcolor(mauchu);
	for( int i = x ; i < 79 ; i++ ){
		gotoxy(i , y); cout << char(makitu);
	}
}
// hien bang lua chon
void BangLuaChon(int x , int y , string noidung , bool &btn_Co ){
	ShowCur(false);
	SetBGColor(9);
	textcolor(15);
	gotoxy(x,y);
	for( int i = 0 ; i < 6 ; i++ ){
		for( int j = 0 ; j < 32 ; j++ ){
			cout<<" ";
		}
		gotoxy(x,y + 1 + i);
	}
	gotoxy(x,y);
	for( int i = 0 ; i < 32 ; i++ ){
		if( i == 0 ){
			cout << char(201);
		}
		else if( i == 31 ){
			cout << char(187);
		}
		else{
			cout << char(205);
		}
	}
	for( int i = 0 ; i < 4 ; i++ ){
		gotoxy(x,y + i + 1);
		cout << char(186);
		gotoxy(x + 31,y + i + 1);
		cout << char(186);
	}
	gotoxy(x,y+5);
	for( int i = 0 ; i < 32 ; i++ ){
		if( i == 0 ){
			cout << char(200);
		}
		else if( i == 31 ){
			cout << char(188);
		}
		else{
			cout << char(205);
		}
	}
	gotoxy(x + 1,y + 1);
	cout << noidung;
	char yes[3][13]={ 218,196,196,196,196,196,196,196,196,196,191,' ',' ',
		              179,' ',' ',' ','C','o',' ',' ',' ',' ',179,' ',' ',
		              192,196,196,196,196,196,196,196,196,196,217,' ',' ' };
	char no[3][13]={ ' ',218,196,196,196,196,196,196,196,196,196,191,' ',
		             ' ',179,' ',' ','K','h','o','n','g',' ',' ',179,' ',
		             ' ',192,196,196,196,196,196,196,196,196,196,217,' ' };
	gotoxy(x + 3,y + 2);
	for( int i = 0 ; i < 3 ; i++ ){
		for( int j = 0 ; j < 13 ; j++ ){
			cout << yes[i][j];
		}
		gotoxy(x + 3,y + 3 + i);
	}
	gotoxy(x + 16,y + 2);
	for( int i = 0 ; i < 3 ; i++ ){
		for( int j = 0 ; j < 13 ; j++ ){
			cout << no[i][j];
		}
		gotoxy(x + 16,y + 3 + i);
	}
	gotoxy(x + 7,y + 3);
	textcolor(0);
	cout << "Co";
	int plagS = 0;
	while(1){
		while(!kbhit()){
			Sleep(100);
		}
		char kk = getch();
		if( kk == -32 ){
			char cc = getch();
			if( cc == 75 && plagS == 0 ){
				gotoxy(32,8);
				textcolor(15);
				cout << "Co";
				gotoxy(45,8);
				plagS = 1;
				textcolor(0);
				cout << "Khong";
			}
			if( cc == 77 && plagS == 1 ){
				gotoxy(45,8);
				textcolor(15);
				cout << "Khong";
				gotoxy(32,8);
				plagS = 0;
				textcolor(0);
				cout << "Co";
			}
		}
		if( kk == 13 ){
			if( plagS == 0 ){
				btn_Co = true;
				break;
			}
			else break;
		}
	}

	ShowCur(true);
}
// hien bang menu
void BangMenu( int Ox , int Oy , string tenban ){
	for(int x = 0 ; x < 65 ; x++ ){
		for( int y = 0 ; y < 11 ; y++ ){
			textcolor(7);
			if( y < 3 || y > 7 ){
				gotoxy(Ox + x, Oy + y);cout << char(177);
			}
			if( x < 10 || x >50 ){
				gotoxy(Ox + x, Oy + y);cout << char(177);
			}
		}
	}
	gotoxy(52,8);
	SetBGColor(0);
	textcolor(13);cout << char(15) << tenban << char(15);
}
// thong bao loi
void ThongBaoNhapNhay( string s , int maunen , int mauchu , int cot , int hang ){
	do{
		setColor(13);
		gotoxy(cot,hang);cout << s;
		Sleep(700);
		gotoxy(cot,hang);
		for( int i = 0 ; i < s.length() ; i++){
			cout << " ";
		}
		Sleep(300);
	}while(!kbhit());
	char x = getch();
	gotoxy(cot,hang);
	for(int i = 0 ; i < s.length() ; i++){
		cout << " ";
	}
}
int wherex()
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}
// khung cau hoi
void KhungCauHoi(){
	textcolor(10);
	gotoxy(19, 7);cout << char(201); //34
	for(int i = 0; i < 76 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(19,8);cout << char(186); //10
	gotoxy(96, 8);cout << char(186); // 
	gotoxy(19,9);cout << char(186);
	gotoxy(96,9);cout << char(186); // 48
	gotoxy(96,10);cout << char(186);
	gotoxy(19,10);cout << char(186);
	gotoxy(19,11);cout << char(200);
	for(int i = 0; i < 76 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
void KhungTraLoiTraiTren(){
	textcolor(13);
	gotoxy(21, 13);cout << char(201); //34
	for(int i = 0; i < 29 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(21,14);cout << char(186); //10
	gotoxy(51, 14);cout << char(186); // 
	gotoxy(21,15);cout << char(186);
	gotoxy(51,15);cout << char(186); // 48
	gotoxy(51,16);cout << char(186);
	gotoxy(21,16);cout << char(186);
	gotoxy(21,17);cout << char(200);
	for(int i = 0; i < 29 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
void KhungTraLoiBenPhaiDuoi(){
	textcolor(13);
	gotoxy(64, 18);cout << char(201); //46
	for(int i = 0; i < 29 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(64,19);cout << char(186); //10
	gotoxy(94, 19);cout << char(186); // 
	gotoxy(64,20);cout << char(186);
	gotoxy(94,20);cout << char(186); // 48
	gotoxy(94,21);cout << char(186);
	gotoxy(64,21);cout << char(186);
	gotoxy(64,22);cout << char(200);
	for(int i = 0; i < 29 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
void KhungTraLoiPhaiTren(){
	textcolor(13);
	gotoxy(64, 13);cout << char(201); //34
	for(int i = 0; i < 29 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(64,14);cout << char(186); //10
	gotoxy(94, 14);cout << char(186); // 
	gotoxy(64,15);cout << char(186);
	gotoxy(94,15);cout << char(186); // 48
	gotoxy(94,16);cout << char(186);
	gotoxy(64,16);cout << char(186);
	gotoxy(64,17);cout << char(200);
	for(int i = 0; i < 29 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
void KhungTraLoiTraiDuoi(){
	textcolor(13);
	gotoxy(21, 18);cout << char(201); //34
	for(int i = 0; i < 29 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(21,19);cout << char(186); //10
	gotoxy(51, 19);cout << char(186); // 
	gotoxy(21,20);cout << char(186);
	gotoxy(51,20);cout << char(186); // 48
	gotoxy(51,21);cout << char(186);
	gotoxy(21,21);cout << char(186);
	gotoxy(21,22);cout << char(200);
	for(int i = 0; i < 29 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
void KhungTraLoi(){
	textcolor(13);
	gotoxy(48, 24);cout << char(201); //34
	for(int i = 0; i < 17 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(48,25);cout << char(186); //10
	gotoxy(66, 25);cout << char(186); // 
	gotoxy(48,26);cout << char(186);
	gotoxy(66,26);cout << char(186); // 48
	gotoxy(66,27);cout << char(186);
	gotoxy(48,27);cout << char(186);
	gotoxy(48,28);cout << char(200);
	for(int i = 0; i < 17 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
void BangGioiThieuTacGia(){
	ThanhNgang(1, 13 , 7 , 14 , 177 );
	SetBGColor(0);
	textcolor(15);
	gotoxy(5,15);cout << "* GVHD Ths.Nguyen Thi Phuc";
	gotoxy(5,16);cout<<"* Ths.Vo Thi Xuan Thieu";
	gotoxy(40,15);cout << "* Coder : Nguyen Van Hoang,Mai Quang Huy";
	gotoxy(45,17);cout << "       Pham Quoc Toan,Mai Van Hung";
	ThanhNgang(1, 19 , 7 , 14 , 177 );
	getch();
}
void KhungVien( int mauvien )
{
	textcolor(mauvien);
	gotoxy(0,0);
	for(int i = 0 ; i < 80 ; i++){
		if( wherex() == 0 && wherey() == 0 ){
			cout << char(201);
		}
		else if( wherex() == 79 && wherey() == 0 ){
			cout << char(187);
		}
		else{
			cout << char(205);
		}
	}
	for(int i = 1 ; i < 24 ; i++){
		gotoxy(0,i);
		cout << char(186);
		gotoxy(79,i);
		cout << char(186);
	}
	gotoxy(0,24);
	for(int i = 0 ; i < 80 ; i++){
		if( wherex() == 0 && wherey() == 24 ){
			cout << char(200);
		}
		else if( wherex() == 79 && wherey() == 24 ){
			cout << char(188);
		}
		else{
			cout << char(205);
		}
	}
}
void ThanhTru( int x , int y , int maunen , int mauchu , int makitu ){
	SetBGColor(maunen);
	textcolor(mauchu);
	for( int j = y ; j < 7 ; j++ ){
			gotoxy( x , j );cout << char(makitu);
	}
}
void ChayChu( int y ){
	int dem = 0;
	int toadomoi = 81;
	textcolor(15);
	for( int x = 0 ; x < 80 ; x++ ){
		SetBGColor(0);
		gotoxy(x,y);cout << char(17) << " Hen gap lai ban lan sau " << char(16);
		for( int i = 0 ; i < 28 ; i++){
			gotoxy(79 + i,y);cout << " ";
		}
		gotoxy(x - 1,y);cout << " ";
		Sleep(100);
	}
}
void BangKetQua( int Ox , int Oy , string tenban ){
	for(int x = 0 ; x < 65 ; x++ ){
		for( int y = 0 ; y < 11 ; y++ ){
			textcolor(7);
			if( y < 3 || y > 7 ){
				gotoxy(Ox + x, Oy + y);cout << char(177);
			}
			if( x < 10 || x >50 ){
				gotoxy(Ox + x, Oy + y);cout << char(177);
			}
		}
	}
	gotoxy(52,8);
	SetBGColor(0);
	textcolor(13);cout << char(15) << tenban << char(15);
}
void khunglon()
{
	 int i,j;
 
 for(i=2;i<120;i++) // tao dong ngang
  {
  gotoxy(i,1);
  	printf("%c",205); // dong ngang tren
  gotoxy(i,30);
  	printf("%c",205);  // dong ngang duoi
  }
  for(j=2;j<30;j++)  // dong ke thang dung
  {
  gotoxy(1,j);
  	printf("%c",186); // dong thang ben trai
  gotoxy(120,j);
 	printf("%c",186);// dong thang ben phai
  }
  gotoxy(120,1);
  	printf("%c",187); // cai moc cau ben phai ben tre^n
  gotoxy(120,30);
  	printf("%c",188); // cai moc cau ben phai ben duoi
  gotoxy(1,1);
  	printf("%c",201); // cai moc cau ben trai tren
  gotoxy(1,30);
  	printf("%c",200); // moc cau ben trai duoi
}
// Khung Testing
void KhungTimeCauhoi(int x)
{
	ThanhTru(34,3,10,29,254);
	ThanhNgang(35,3,12,25,254);
	ThanhNgang(35,6,12,25,254);
	ThanhTru(79,3,10,29,254);
	if(x==10)
	{
		gotoxy(47,4);
		textcolor(11);
		cout<<"Ban Co 5 Phut De Tra Loi"<<endl;
		gotoxy(40,5);
		cout<<"Het Thoi Gian He Thong Tu Nop Bai"<<endl;
	}
	else if(x==20)
	{
		gotoxy(47,4);
		textcolor(11);
		cout<<"Ban Co 10 Phut De Tra Loi"<<endl;
		gotoxy(40,5);
		cout<<"Het Thoi Gian He Thong Tu Nop Bai"<<endl;
	}
	else if(x==30)
	{
		gotoxy(47,4);
		textcolor(11);
		cout<<"Ban Co 15 Phut De Tra Loi"<<endl;
		gotoxy(40,5);
		cout<<"Het Thoi Gian He Thong Tu Nop Bai"<<endl;
	}
	else if(x==40)
	{
		gotoxy(47,4);
		textcolor(11);
		cout<<"Ban Co 20 Phut De Tra Loi"<<endl;
		gotoxy(40,5);
		cout<<"Het Thoi Gian He Thong Tu Nop Bai"<<endl;
	}

}
void KhungTestingCauhoi()
{
	ThanhTru(34,3,10,29,254);
	ThanhNgang(35,3,12,25,254);
	ThanhNgang(35,6,12,25,254);
	ThanhTru(79,3,10,29,254);
}
void xuatGiaoDienChinh()
{
	system("cls");
	char *s = "CAU TRUC DU LIEU GIAI THUAT";
	char *s1 = "+---------------------------------------+";
	setColor(13);
	gotoxy(18,2);
	cout<<"       ___________    _ _ _       _ __ _       _ _  _ _ _     _ _      _ _ _	            ";
	gotoxy(18,3);
    cout<<"       \\__    __//   /  _ _\\     /  /\\  \\    |    \\/     |   /_   |   /_ _  \\	    ";
    gotoxy(18,4);
    cout<<"          |   |      \\  \\       /  /  \\  \\   |  |\\ _ /|  |     |  |      /  /	    ";
    gotoxy(18,5);
    cout<<"          |   |       >  >     /  /====\\  \\  |  |     |  |     |  |     /  /	        ";
    gotoxy(18,6);
    cout<<"          |   |      /  /_ _  |  |      |  | |  |     |  |     |  |    /  /_ _		    ";
    gotoxy(18,7);
    cout<<"          |_ _|      \\_ _ _/  |__|      |__| |__|     |__|     |_ |   /_ _ _ /		    ";
    gotoxy(18,8);
 	cout<<"                                                                                 	    ";
	setColor(200);
	ToMau(42,9,s1,10);
	ToMau(49,10,s,13);
	ToMau(42,11,s1,10);
	setColor(10);
	gotoxy(42,13);
	cout<<"      CHUONG TRINH THI TRAC NGHIEM                               "<<endl;
	setColor(12);
	gotoxy(42,14);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,15);
	cout<<"+"<<"         "<<char(254)<<"F1: Vao Phong Thi.           +"<<endl;
	gotoxy(42,16);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,17);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,18);
	cout<<"+"<<"         "<<char(254)<<"F2: Xoa Cau Hoi.             +"<<endl;
	gotoxy(42,19);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,20);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,21);
	cout<<"+"<<"         "<<char(254)<<"F3:Sua Cau Hoi               +"<<endl;
	gotoxy(42,22);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,23);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,24);
	cout<<"+"<<"         "<<char(254)<<"F4: Them Cau Hoi.            +"<<endl;
	gotoxy(42,25);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,26);
	cout<<"+---------------------------------------+"<<endl;
	gotoxy(42,27);
	cout<<"+"<<"         "<<char(254)<<"F5: Ket Qua Thi.             +"<<endl;
	gotoxy(42,28);
	cout<<"+---------------------------------------+"<<endl;
	setColor(10);
	gotoxy(51,29);
	cout<<"ESC Thoat Chuong Trinh"<<endl;
	khunglon();
}
void khungxoacauhoi(int x, int y, int w, int h, bool draw){
	if(draw){
		gotoxy(x,y);
		cout << char(218);
		gotoxy(x+w,y);
		cout<< char(191);
		gotoxy(x,y+h);
		cout<< char(192);
		gotoxy(x+w,y+h);
		cout<< char(217);
			for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << char(196);
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y+h);
			cout << char(196);
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << char(179);
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x+w, i);
			cout << char(179);
		}
	}
	else {
		gotoxy(x, y);
		cout << " ";
		
		gotoxy(x + w, y);
		cout << " ";
	
		gotoxy(x, y + h);
		cout << " ";
	
		gotoxy(x + w, y + h);
		cout << " ";


		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << " ";
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y + h);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x + w, i);
			cout << " ";
		}

	}
}
void KhungThongTinNguoiDung(int x, int y, int w, int h, bool draw){
	if(draw){
		gotoxy(x,y);
		cout << char(218); // 218
		gotoxy(x+w,y);
		cout<< char(191); //191
		gotoxy(x,y+h);
		cout<< char(192); //192
		gotoxy(x+w,y+h);
		cout<< char(217); //217
			for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << char(254);  // 196
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y+h);
			cout << char(254); //196
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << char(254); //179
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x+w, i);
			cout << char(254);  //179
		}
	}
	else {
		gotoxy(x, y);
		cout << " ";
		
		gotoxy(x + w, y);
		cout << " ";
	
		gotoxy(x, y + h);
		cout << " ";
	
		gotoxy(x + w, y + h);
		cout << " ";


		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << " ";
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y + h);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x + w, i);
			cout << " ";
		}
		
	}
	gotoxy(38,12);
	cout<<"Ho Ten: "<<endl;
	gotoxy(38,14);
	cout<<"Gioi Tinh: "<<endl;
	gotoxy(38,16);
	cout<<"Nam Sinh: "<<endl;
}
void KhungDangKiTaiKhoan(int x, int y, int w, int h, bool draw){
	if(draw){
		gotoxy(x,y);
		cout << char(218); // 218
		gotoxy(x+w,y);
		cout<< char(191); //191
		gotoxy(x,y+h);
		cout<< char(192); //192
		gotoxy(x+w,y+h);
		cout<< char(217); //217
			for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << char(254);  // 196
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y+h);
			cout << char(254); //196
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << char(254); //179
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x+w, i);
			cout << char(254);  //179
		}
	}
	else {
		gotoxy(x, y);
		cout << " ";
		
		gotoxy(x + w, y);
		cout << " ";
	
		gotoxy(x, y + h);
		cout << " ";
	
		gotoxy(x + w, y + h);
		cout << " ";


		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << " ";
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y + h);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x + w, i);
			cout << " ";
		}
		
	}
gotoxy(38,10);
cout<<"Ho Ten: "<<endl;
gotoxy(38,12);
cout<<"Gioi Tinh: "<<endl;
gotoxy(38,14);
cout<<"Nam Sinh: "<<endl;
gotoxy(38,16);
cout<<"Ten Dang Nhap: "<<endl;
gotoxy(38,18);
cout<<"Mat Khau: "<<endl;
gotoxy(38,20);
cout<<"Xac Nhan Mat Khau: "<<endl;
}
void KhungDangNhap(int x, int y, int w, int h, bool draw){
	textcolor(27);
	gotoxy(43,3);
	cout<<"Moi Ban Dang Nhap Vao Tai Khoan"<<endl;
	gotoxy(48,4);
	cout<<"Bam 1 De Dang Nhap"<<endl;
	gotoxy(46,5);
	cout<<"Neu Chua Co Tai Khoan"<<endl;
	gotoxy(49,6);
	cout<<"Bam 2 de Dang Ki"<<endl;
	gotoxy(53,9);
	cout<<"Lua Chon"<<endl;
	if(draw){
		gotoxy(x,y);
		cout << char(218); // 218
		gotoxy(x+w,y);
		cout<< char(191); //191
		gotoxy(x,y+h);
		cout<< char(192); //192
		gotoxy(x+w,y+h);
		cout<< char(217); //217
			for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << char(254);  // 196
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y+h);
			cout << char(254); //196
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << char(254); //179
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x+w, i);
			cout << char(254);  //179
		}
	}
	else {
		gotoxy(x, y);
		cout << " ";
		
		gotoxy(x + w, y);
		cout << " ";
	
		gotoxy(x, y + h);
		cout << " ";
	
		gotoxy(x + w, y + h);
		cout << " ";


		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << " ";
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y + h);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x + w, i);
			cout << " ";
		}
		
	}
	gotoxy(38,13);
	cout<<"Ten Dang Nhap: "<<endl;
	gotoxy(38,15);
	cout<<"Mat Khau: "<<endl;
}
void KhungDangNhap2(int x, int y, int w, int h, bool draw){
	textcolor(27);
//	gotoxy(43,3);
//	cout<<"Moi Ban Dang Nhap Vao Tai Khoan"<<endl;
//	gotoxy(48,4);
//	cout<<"Bam 1 De Dang Nhap"<<endl;
//	gotoxy(46,5);
//	cout<<"Neu Chua Co Tai Khoan"<<endl;
//	gotoxy(49,6);
//	cout<<"Bam 2 de Dang Ki"<<endl;
//	gotoxy(53,9);
//	cout<<"Lua Chon"<<endl;
	if(draw){
		gotoxy(x,y);
		cout << char(218); // 218
		gotoxy(x+w,y);
		cout<< char(191); //191
		gotoxy(x,y+h);
		cout<< char(192); //192
		gotoxy(x+w,y+h);
		cout<< char(217); //217
			for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << char(254);  // 196
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y+h);
			cout << char(254); //196
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << char(254); //179
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x+w, i);
			cout << char(254);  //179
		}
	}
	else {
		gotoxy(x, y);
		cout << " ";
		
		gotoxy(x + w, y);
		cout << " ";
	
		gotoxy(x, y + h);
		cout << " ";
	
		gotoxy(x + w, y + h);
		cout << " ";


		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y);
			cout << " ";
		}
	
		for (int i = x + 1; i < (x + w); i++){
			gotoxy(i, y + h);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x, i);
			cout << " ";
		}
	
		for (int i = y + 1; i < (y + h); i++){
			gotoxy(x + w, i);
			cout << " ";
		}
		
	}
	gotoxy(38,13);
	cout<<"Ten Dang Nhap: "<<endl;
	gotoxy(38,15);
	cout<<"Mat Khau: "<<endl;
}
