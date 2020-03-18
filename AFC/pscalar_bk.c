nbla[0][t][c1][c2]=vector_products[1][t][c1][c2];
nbla[1][t][c1][c2]=vector_products[2][t][c1][c2];
nbla[2][t][c1][c2]=vector_products[3][t][c1][c2];

B[0][t][c1][c2]  = vector_products[11][t][c1][c2]-vector_products[9][t][c1][c2];
B[1][t][c1][c2] = vector_products[6][t][c1][c2]-vector_products[10][t][c1][c2];
B[2][t][c1][c2] = vector_products[7][t][c1][c2]-vector_products[5][t][c1][c2];
D[0][t][c1][c2] = vector_products[11][t][c1][c2]+vector_products[9][t][c1][c2];
D[1][t][c1][c2] = vector_products[6][t][c1][c2]+vector_products[10][t][c1][c2];
D[2][t][c1][c2] = vector_products[7][t][c1][c2]+vecotr_products[5][t][c1][c2];

Operator1[0][0][t][c1][c2][s1][s2] =  gamma5[s1][s2]*nbla[0][t][c1][c2];
Operator1[0][1][t][c1][c2][s1][s2] = gamma5[s1][s2]*nbla[1][t][c1][c2];
Operator1[0][2][t][c1][c2][s1][s2] = gamma5[s1][s2]*nbla[2][t][c1][c2];
Operator1[1][0][t][c1][c2][s1][s2] = (1/sqrt(2))*gamma5[s1][ss1]*(B[1][t][c1][c2]*gamma3[ss1][s2]-B[2][t][c1][c2]*gamma1[ss1][s2]);
Operator1[1][1][t][c1][c2][s1][s2] = (1/sqrt(2))*gamma5[s1][ss1]*(B[0][t][c1][c2]*gamma3[ss1][s2]-B[2][t][c1][c2]*gamma1[ss1][s2]);

Operator1[1][2][t][c1][c2][s1][s2] = (1/sqrt(2))*gamma5[s1][ss1]*(B[0][t][c1][c2]*gamma2[ss1][s2]-B[1][t][c1][c2]*gamma1[ss1][s2]);

Operator1[2][0][t][c1][c2][s1][s2] = (1/sqrt(2))*gamma4[s1][ss1]*gamma5[ss1][ss2]*(D[1][t][c1][c2]*gamma3[ss2][s2]+D[2][t][c1][c2]*gamma2[ss2][s2]);

Operator1[2][1][t][c1][c2][s1][s2] =(1/sqrt(2))*gamma4[s1][ss1]*gamma5[ss1][ss2]*(D[0][t][c1][c2]*gamma3[ss2][s2]+D[2][t][c1][c2]*gamma1[ss2][s2]);

Operator1[2][2][t][c1][c2][s1][s2]=(1/sqrt(2))*gamma4[s1][ss1]*gamma5[ss1][ss2]*(D[0][t][c1][c2]*gamma2[ss2][s2]+D[1][t][c1][c2]*gamma1[ss2][s2]);

Operator1[3][0][t][c1][c2][s1][s2] = B[0][t][c1][c2]*ONE[s1][s2];

Operator1[3][1][t][c1][c2][s1][s2] = B[1][t][c1][c2]*ONE[s1][s2];

Operator1[3][2][t][c1][c2][s1][s2] = B[2][t][c1][c2]*ONE[s1][s2];

Operator1[4][0][t][c1][c2][s1][s2] = gamma4[s1][ss1]*gamma5[ss1][ss2]*gamma1[ss2][s2];

Operator1[4][1][t][c1][c2][s1][s2] = gamma4[s1][ss1]*gamma5[ss1][ss2]*gamma2[ss2][s2];

Operator1[4][2][t][c1][c2][s1][s2] = gamma4[s1][ss1]*gamma5[ss1][ss2]*gamma3[ss2][s2];



Operator2[0][0][t][c1][c2][s1][s2] =  gamma5[s1][s2]*B[0][t][c1][c2];
Operator2[0][1][t][c1][c2][s1][s2] = gamma5[s1][s2]*B[1][t][c1][c2];
Operator2[0][2][t][c1][c2][s1][s2] = gamma5[s1][s2]*B[2][t][c1][c2];

Operator2[1][0][t][c1][c2][s1][s2] = (1/sqrt(2))*(D[1][t][c1][c2]*gamma3[s1][s2]+D[2][t][c1][c2]*gamma2[s1][s2]);
Operator2[1][1][t][c1][c2][s1][s2] = (1/sqrt(2))*(D[0][t][c1][c2]*gamma3[s1][s2]+D[2][t][c1][c2]*gamma1[s1][s2]);
Operator2[1][2][t][c1][c2][s1][s2] = (1/sqrt(2))*(D[0][t][c1][c2]*gamma2[s1][s2]+D[1][t][c1][c2]*gamma1[s1][s2]);

Operator2[2][0][t][c1][c2][s1][s2] = (1/sqrt(2))*gamma5[s1][ss1]*(nbla[1][t][c1][c2]*gamma3[ss1][s2]-nbla[2][t][c1][c2]*gamma2[ss1][s2]);
Operator2[2][1][t][c1][c2][s1][s2] = (1/sqrt(2))*gamma5[s1][ss1]*(nbla[2][t][c1][c2]*gamma1[ss1][s2]-nbla[0][t][c1][c2]*gamma3[ss1][s2]);
Operator2[2][2][t][c1][c2][s1][s2] = (1/sqrt(2))*gamma5[s1][ss1]*(nbla[0][t][c1][c2]*gamma2[ss1][s2]-nbla[1][t][c1][c2]*gamma1[ss1][s2]);

Operator2[3][0][t][c1][c2][s1][s2] = B[0][t][c1][c2]*ONE[s1][s2];
Operator2[3][1][t][c1][c2][s1][s2] = B[1][t][c1][c2]*ONE[s1][s2];
Operator2[3][2][t][c1][c2][s1][s2] = B[2][t][c1][c2]*ONE[s1][s2];

Operator2[4][0][t][c1][c2][s1][s2] = gamma1[s1][s2];
Operator2[4][1][t][c1][c2][s1][s2] = gamma2[s1][s2];
Operator2[4][2][t][c1][c2][s1][s2] = gamma3[s1][s2];


pscalar[i][j][t][c1][c2][s1][s2] = (1/sqrt(3))*(Operator1[i][0][t][c1][c11][s1][s11]*Operator2[j][0][t][c11][c2][s11][s2]+Operator1[i][1][t][c1][c11][s1][s11]*Operator2[j][1][c11][c2][s11][s2]+Operator1[i][2][t][c1][c11][s1][s11]*Operator2[j][2][t][c1][c11][s1][s11]);

peram_back[ti][tf][s2][s1][c2][c1]=conj(gamma5[s1][ss1]*peram[ti][tf][ss1][ss2][c1][c2]*gamma5[ss2][s2]);

corr[i][j][ti][tf] = pscalar[i][j][tf][c1][c2][s1][s2]*peram[ti][tf][s2][s11][c2][c11]*conj(pscalar[i][j][ti][c11][c22][s11][s22])*peram_back[ti][tf][s22][s1][c22][c1];

