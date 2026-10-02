\\# Copyright (c) 2026 Anton Nikonov
\\# Redistribution and use in source and binary forms, with or without modification,
\\# are permitted provided that the following conditions are met:
\\# 1. Redistributions of source code must retain the above copyright notice,
\\# this list of conditions and the following disclaimer.
\\# 2. Redistributions in binary form must reproduce the above copyright notice,
\\# this list of conditions and the following disclaimer in the documentation and/or other materials
\\# provided with the distribution.
\\# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
\\# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
\\# FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
\\# IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
\\# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
\\# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
\\# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
\\# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
\\# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\\#
\\# Search algorithm author: Anton Nikonov aka Yadryara (dxdy.ru)
\\# URL: https://dxdy.ru/topic148829.html
\\#
\\# Technical adaptation of search: Demis
\\# Version: D48-24.v4.3
\\# Name: D48-24 Starday Dime


GP;install("init_D48_24_fun","v","init_D48_24_fun","./D48-24-fun.so");
GP;install("fun","vLLGLGLGLD0,G,D0,G,D0,G,GGD0,G,D0,G,D0,G,D0,G,D0,G,D0,G,","fun","./D48-24-fun.so");
GP;install("decode_task","D0,G,","decode_task","./D48-24-fun.so");



{t0=getwalltime();t1=getwalltime();

kdel = 48:small; minrkp = 16:small;

name = fileopen("Task_1.txt");
log_name1 ="log_1.txt";

while( nomtask = eval(filereadstr(name) ) :small,

write(log_name1, "#BEGIN ",nomtask);
save_nomtask=nomtask;

vys = floor(nomtask/10^9) :small;

nomtask = nomtask % 10^9;

revs = 0 :small;

patnaun = 144 * 10^(59-vys) :small; 

kolzad = 10! / patnaun :small;

desiz22 = (nomtask-1) \ kolzad \ 40 :small;

stkom = desiz22*10 + ((nomtask-1) \ kolzad) % 10 + 1 :small; finkom = stkom :small;

strass4 = patnaun * ( (nomtask-1) % kolzad) :small;


ki = ceil(1249498 * 10^(vys-60)) :small;

starti = (ki - 1) * (vys-58) :small; koli = ki * (68-vys ):small;

default(factor_add_primes,1);

maxpredp = 600000*(vys-57) :small;

my(predp:vecsmall = Vecsmall(primes( [71, maxpredp] )));
my(kolpredp = #predp):small; 

bolv = [];
nombolv=0:small;
nombolv = decode_task(stkom)[4];

if(nombolv == 1, bolv = [20,3,2,7,72,5,2,3,44,1,1470,169,32,243,2,5,12,7,2,363,200,19,18,17]);
if(nombolv == 2, bolv = [1,20,3,2,7,72,5,2,3,44,1,1470,169,32,243,2,5,12,7,2,363,200,19,18]);
if(nombolv == 3, bolv = [20,3,2,7,72,5,2,3,44,1,1470,169,32,243,2,5,12,7,2,363,200,1,18,17]);


if( ((nomtask-1) \ kolzad \ 20) % 2 == 1, revs = 1);

if( revs == 1, bolv = Vecrev(bolv));


nomra = 0;

mkv = Set(select(x->(numdiv(x)%3<>0),bolv,1));

rkp = primes([minrkp, 67]);

rassprob = [1..#mkv]; v = bolv;



for(j = 1, #mkv, v[mkv[j]] *= rkp[rassprob[j]]^2);

onlyp = Vec(select(x->numdiv(x)==kdel/2, v,1)); if(#onlyp>0, ip = onlyp[1]-1:small);
pq    = Vec(select(x->numdiv(x)==kdel/4, v,1));
pqr   = Vec(select(x->numdiv(x)==kdel/8, v,1));
pqrs  = Vec(select(x->numdiv(x)==kdel/16,v,1));

prter = Set(concat( [5, 7, 11, 13, 17, 19], rkp ));


dopp = primes([ 71, 560 ]); 


if(nombolv == 1, bolv = [20,3,2,7,72,5,2,3,44,1,1470,169,32,243,2,5,12,7,2,363,200,1,18,1]);
if(nombolv == 2, bolv = [1,20,3,2,7,72,5,2,3,44,1,1470,169,32,243,2,5,12,7,2,363,200,1,18]);
if(nombolv == 3, bolv = [20,3,2,7,72,5,2,3,44,1,1470,169,32,243,2,5,12,7,2,363,200,1,18,1]);


if( revs == 1, bolv = Vecrev(bolv));

spichis1 = [17, 19, 23];
spichis4 = [29,31,37,41,43,47,53,59,61,67];

mesta = vector(220, i, [0, 0, 0]);
mesta[stkom] = decode_task(stkom)[1..3];

for(j = 1, #mesta, mesta[j] = [
25*revs + (-1)^revs* mesta[j][1], 
25*revs + (-1)^revs* mesta[j][2], 
25*revs + (-1)^revs* mesta[j][3]
]); 

mesta04 = mkv;
v1 = bolv; 

for(i1 = stkom, finkom, v = v1;

t1=getwalltime();

for(j1 = 1, #mesta[i1], v[mesta[i1][j1]] *= spichis1[j1]^2;

for (vsp = 1, mesta[i1][j1] - 1,
if  (vsp % spichis1[j1] == mesta[i1][j1] % spichis1[j1] , v[vsp] *= spichis1[j1]));

for (vsp = mesta[i1][j1] + 1, #v,
if  (vsp % spichis1[j1] == mesta[i1][j1] % spichis1[j1] , v[vsp] *= spichis1[j1])));

nomra = i1;
mesta4 = setminus(mesta04, Set(mesta[i1]));

v4 = v;

for(j = 1, #v, if(v[j]%32 ==0, m32  = j));
for(j = 1, #v, if(v[j]%243==0, m243 = j));

modchis = ( ((nomtask-1) \ kolzad \ 10) % 2 + 1) * 243 + 1;

obmod = chinese(Mod(33-m32, 64), Mod(modchis-m243, 729));

forperm( numtoperm (#spichis4, strass4), minirass4,

if(permtonum(minirass4) == strass4 + patnaun, break);

v = v4;
for(j4 = 1, #spichis4, v[mesta4[j4]] *= spichis4[minirass4[j4]]^2);

m = 6 * lcm(v) / v[ip+1]:int;
n0 = (lift(chinese(chinese([Mod(-j+1, v[j]) | j<-[1..#v]]), obmod )) + ip) / v[ip+1]:int;

nu = [valuation(kdel/numdiv(t),2)|t<-v];

razr=0; zap=0;

bo=vector(prter[#prter]);

for(perp = 1, #prter,

for( ost = 0, prter[perp] - 1,

for( j = 1, #v,

if( ( ((n0 + m*ost)*v[ip+1] + j - 1 - ip) / v[j] ) % prter[perp] == 0, bo[perp] = ost;next(2) 
))));

T = Vecsmall([( -n0 / m ) % dopp[j] | j<-[1..#dopp]]);

removeprimes(addprimes());

nu = Vecsmall(nu); v = Vecsmall(v); bo = Vecsmall(bo);

fun(starti, koli, v, maxpredp, nu, ip, predp, kolpredp, n0, log_name1, nomtask, bo, T, prter, dopp, pq, pqrs, kdel, m);
));
write(log_name1, "#ok. ",strtime(getwalltime()-t1));

);

write(log_name1, "#END ",save_nomtask);
}quit
