#include<iostream>

using namespace std;
struct Cay{					// cau truc cua moi nut cua cay
	int cha=-1;
	int socon=0 ;
};

void Prufer(struct Cay *nut,int soNut, int *pru){
	bool *la;
	la=new bool [soNut];
	int nutXoa=0;
	for(int i=0;i<soNut;i++){				//kiem tra nut i co phai lá k
		if(nut[i].socon==0)la[i]= true;
			else la[i]=false;
		}
		
	
	for(int i=0;i<soNut-1;i++){
		while(la[nutXoa]==false)nutXoa++;							//xoa lá co so nho nhat
		pru[i]=nut[nutXoa].cha;										//ghi nut cha cua nut xoa vao mang prufer
		la[nutXoa]=false;											//xoa lá
		nut[nut[nutXoa].cha].socon--;								//giam so con cua lá cha di 1	
		if(nut[nut[nutXoa].cha].socon==0){							// neu cha het con thi cha tro thanh lá
			la[nut[nutXoa].cha]=true;
			if(nut[nutXoa].cha< nutXoa)nutXoa=nut[nutXoa].cha;		// Neu cha nho hon nut xoa thi cha thành nút xóa moi
		}	
		
	}
}		
int main(){
	int soNut;
	//	printf("Nhap so canh cua cay:"); 
	cin>> soNut;
	cout << endl;
	
	struct Cay *nut;
	nut= new Cay[soNut];
	int *pru;
	pru=new int [soNut];
	int con,cha;
	
	// nhap canh
	for (int i=0;i<soNut;i++){								
	//	printf("nhap canh thu %d \n",i+1);
		scanf("%d",&cha);
		scanf("%d",&con);
		nut[con].cha=cha;
		nut[cha].socon++;
		}
		
	Prufer(nut,soNut,pru);
	
	// in mang pruper
	for(int i=0;i<soNut-1;i++)								
		printf("%4d",pru[i]);
	
	return 0;
	}

	
