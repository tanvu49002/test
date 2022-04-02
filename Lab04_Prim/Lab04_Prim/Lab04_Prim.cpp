#include <iostream>
using namespace std;

struct GRAPH
{
	bool bNhan[50]; //true la chua xet, false la da xet
	int iMaTranKe[50][50];
	int iSoDinh;
};
struct CANH
{
	int iTrongSo;
	int iDinhDau;
	int iDinhCuoi;
};
CANH CayKhung[50];
void Prim(GRAPH g)
{
	for (int i = 0; i < g.iSoDinh; i++) {
		g.bNhan[i] = true;
	}
	g.bNhan[0] = false;
	int iSoCanh = 0; //so canh cua cay khung
	while (iSoCanh < g.iSoDinh - 1)
	{
		CANH Canh;
		Canh.iDinhDau = 0;
		Canh.iDinhCuoi = 0;
		Canh.iTrongSo = 0;
		int min = -1;
		for (int i = 0; i < g.iSoDinh; i++) {
			if (g.bNhan[i] == true)
			{
				for (int j = 0; j < g.iSoDinh; j++) {
					if (g.bNhan[j] == false && (g.iMaTranKe[i][j] != 0)) {
						if (min == -1 || g.iMaTranKe[i][j] < min) {
							min = g.iMaTranKe[i][j];
							Canh.iDinhDau = i;
							Canh.iDinhCuoi = j;
							Canh.iTrongSo = g.iMaTranKe[i][j];
						}
					}
				}
			}
		}
		CayKhung[iSoCanh] = Canh;
		iSoCanh++;
		g.bNhan[Canh.iDinhDau] = false;
	}

	int iTongTrongSo = 0;
	for (int i = 0; i < iSoCanh; i++) {
		iTongTrongSo += CayKhung[i].iTrongSo;
	}
	cout << "CAY KHUNG NHO NHAT CUA DO THI GOM CAC CANH: " << endl;
	for (int i = 0; i < iSoCanh; i++) {
		cout << "(" << CayKhung[i].iDinhCuoi << "," << CayKhung[i].iDinhDau << ") " << endl;
	}
	cout << "VOI TONG TRONG LUONG LA: " << iTongTrongSo << endl;
}

int main() {
	GRAPH g;
	cout << "Tan Vu";
	cout << "Huynh Thi Thu Thao" << endl;
	cout << "NHAP VAO SO DINH CUA DO THI: ";
	cin >> g.iSoDinh;
	cout << "NHAP VAO MA TRAN KE: " << endl;
	for (int i = 0; i < g.iSoDinh; i++) {
		for (int j = 0; j < g.iSoDinh; j++) {
			cin >> g.iMaTranKe[i][j];
		}
	}
	Prim(g);
	cout << endl;
	return 0;
}
