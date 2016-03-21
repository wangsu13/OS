#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

struct page {
    int no;
    bool A;
    bool M;
} pm[10];

int main() {
    srand((int)time(NULL));
	ofstream fout("output");
    for (int i = 0; i < 10; i++) {
        pm[i].no = -1;
        pm[i].A = 0;
        pm[i].M = 0;
    }

    for (int i = 0; i < 20; i++) {
        int vp = rand() % 20;
        int op = rand() % 2;
        fout << "virtual page:" << vp << "\t";
        fout << "op:" << (op ? "write" : "read") << endl;

        bool hit = false;

        for(int j = 0;j < 10;j++) {
            if(vp == pm[j].no) {
                pm[j].A = true;
                pm[j].M |= op;
                hit = true;
                fout << "hit" << endl;
            }
        }

        if(!hit) {
            while (!hit) {
                for (int j = 0;j < 10; j++) {
                    if (pm[j].A==0 && pm[j].M == 0) {
                        fout << "page" << j << "replaced" << endl;
                        pm[j].A = true;
                        pm[j].M |= op;
                        pm[j].no = vp;
                        hit = true;
                        break;
                    }
                }
                if (hit) continue;
				for (int j = 0; j < 10; j++) {
                    if (pm[j].A==0 && pm[j].M==1) {
                        fout << "page" << j << "replaced" << endl;
                        pm[j].A = true;
                        pm[j].M |= op;
                        pm[j].no = vp;
                        hit = true;
                        break;
                    }
                    pm[j].A = 0;
                }
            }
        }
    }
	fout.close();
    return 0;
}