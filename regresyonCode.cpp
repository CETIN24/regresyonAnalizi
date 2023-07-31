#include <vector>
#include <iostream>
using namespace std;

class Sonuc{

private:
	float egim;
	float n;

public:
	float getEgim() {
		return egim;
	}

	void setEgim(float egim) {
		this->egim = egim;
	}

	float getN() {
		return n;
	}

	void setN(float n) {
		this->n = n;
	}

};

class Regresyon{
public:
	vector<int> x;
	vector<int> y;
public:
	Regresyon(vector<int> x,vector<int> y){
		this->x = x;
		this->y = y;
	}
public:
	Sonuc egimHesapla(){
		float toplam1 = 0;
			for(int i = 0; i < x.size(); i++) {
				 toplam1 += x[i]*y[i];
			}

		float toplam2 = 0;
		float toplam3 = 0;
			for(int j = 0; j < x.size(); j++) {
				toplam2 += x[j];
				toplam3 += y[j];
			}
			float arort1 = toplam2/x.size();
			float arort2 = toplam3/y.size();
			float ort3 = arort1*arort2*x.size();

		float x_kare = 0;
			for(int k = 0; k<x.size(); k++) {
			x_kare += x[k]*x[k];
			}

		float xarkare = x.size()*arort1*arort1;

		float egim = ((toplam1) - (ort3)) / ((x_kare) - (xarkare));

		float n;
		n = arort2 - (egim*arort1);

		Sonuc sonuc;
		sonuc.setEgim(egim);
		sonuc.setN(n);
		return sonuc;

}

};


int main(){

vector<int> x {1, 3, 5, 4, 4, 8, 7, 9};
vector<int> y {3, 7, 9, 2, 3, 1, 9, 8};
Regresyon regresyon(x,y);
Sonuc result = regresyon.egimHesapla();
float egim = result.getEgim();
float n = result.getN();
cout << "Eğim:" <<egim<< endl;
cout << "n:" <<n<< endl;
	return 0;
}

