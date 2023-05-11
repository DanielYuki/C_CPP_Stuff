//DANIEL YUKI LAB03 CORRIDA.CPP

#include <iostream>

using namespace std;

int checkGeral(int estPist, int estPneu) {
    if (estPist == 0 && estPneu == 0) {
        return 0; //pista molhada / pneu duro de chuva
    } else if (estPist == 0 && estPneu == 1) {
        return 1; //pista molhada / pneu macio de chuva
    } else if (estPist == 0 && estPneu == 2) {
        return 2; //pista molhada / pneu duro seco
    } else if (estPist == 0 && estPneu == 3) {
        return 3; //pista molhada / pneu macio seco
    } else if (estPist == 1 && estPneu == 0) {
        return 10; //pista umida / pneu duro de chuva
    } else if (estPist == 1 && estPneu == 1) {
        return 11; //pista umida / pneu macio de chuva
    } else if (estPist == 1 && estPneu == 2) {
        return 12; //pista umida / pneu duro seco
    } else if (estPist == 1 && estPneu == 3) {
        return 13; //pista umida / pneu macio seco
    } else if (estPist == 2 && estPneu == 0) {
        return 20; //pista seca / pneu duro de chuva
    } else if (estPist == 2 && estPneu == 1) {
        return 21; //pista seca / pneu macio de chuva
    } else if (estPist == 2 && estPneu == 2) {
        return 22; //pista seca / pneu duro seco
    } else if (estPist == 2 && estPneu == 3) {
        return 23; //pista seca / pneu macio seco
    } else {
        cout << "\nfk\n";
        return 404;
    }

}

float veloMedCarro(int condGeral, float vmm) {
    float vmc = vmm;
    switch (condGeral) {
        //pista seca
        case 20:
            vmc -= 8;
            break;
        case 21:
            vmc -= 4;
            break;
        case 22:
            vmc += 2;
            break;
        case 23:
            vmc += 4;
            break;

            //pista umida
        case 10:
            break;
        case 11:
            vmc += 2;
            break;
        case 12:
            break;
        case 13:
            vmc += 2;
            break;

            //pista molhada
        case 0:
            vmc -= 1;
            break;
        case 1:
            break;
        case 2:
            vmc -= 10;
            break;
        case 3:
            vmc -= 6;
            break;

        default:
            cout << "\n\n mamou \n\n";
            break;
    }

    return vmc;
}

int autonomeme(int condGeral) {
    switch (condGeral) {
        //pneu macio seco
        case 3:
            return 20000;
        case 13:
            return 20000;
        case 23:
            return 20000;

            //pneu duro seco
        case 2:
            return 30000;
        case 12:
            return 30000;
        case 22:
            return 30000;

            //pneu macio chuva na molhada ou umida
        case 1:
            return 20000;
        case 11:
            return 20000;

            //pneu macio chuva na seca
        case 21:
            return 15000;

            //pneu duro chuva na molhada ou umida
        case 0:
            return 30000;
        case 10:
            return 30000;

            //pneu duro chuva na seca
        case 20:
            return 25000;

        default:
            //cout << "\n\n mamou momua \n\n";
            return 0;
    }
}

int main() {
    int voltas, extecaoV, condPista; //pista

    cin >> voltas >> extecaoV >> condPista;

    float temp = 0, dist = 0, distPercP = 0, proxTemp = 0;
    float tempo[3][voltas + 1];

    for (int i = 0; i < 3; i++) { //cria os 3 carros
        int pneu, tempTrocaP, autonomiaP, estado;
        float velMedMot = 0, velMedCar = 0;

        cin >> pneu >> velMedMot >> tempTrocaP;

        estado = checkGeral(condPista, pneu);

        autonomiaP = autonomeme(estado);

        velMedCar = veloMedCarro(estado, velMedMot);

        for (int j = 0; j <= voltas; j++) {
            if (proxTemp == 1) {
                temp += tempTrocaP;
                proxTemp = 0;
            }

            tempo[i][j] = temp;

            if (distPercP >= autonomiaP) {
                proxTemp = 1;
                distPercP = 0;
            }

            temp += extecaoV / velMedCar;
            distPercP += extecaoV;

            //cout << tempo[i][j] << " ";
        }
        temp = 0;
        distPercP = 0;
        proxTemp = 0;
        //cout << velMedCar;
    }

    for (int i = 0; i <= voltas; i++) {
        if (tempo[0][i] <= tempo[1][i] && tempo[0][i] <= tempo[2][i]) {
            if (i == voltas)
                cout << "\nVencedor: Carro 1";
            else
                cout << "\n" << i + 1 << ": Carro 1";
        } else if (tempo[1][i] <= tempo[2][i] && tempo[1][i] <= tempo[0][i]) {
            if (i == voltas)
                cout << "\nVencedor: Carro 2";
            else
                cout << "\n" << i + 1 << ": Carro 2";
        } else {
            if (i == voltas)
                cout << "\nVencedor: Carro 3";
            else
                cout << "\n" << i + 1 << ": Carro 3";
        }
    }

    return 0;
}
