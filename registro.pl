:- discontiguous unidades/1, vivo/2, revivido/2, morto/3, tipo/2, ataca/3, tipo_dano/2, tipo_armadura/2, hp/3, dano/3.
/* unidades criadas */
unidades([dreadLord, dreadLord, dreadLord, ghoul]).
minhas_unidades(X) :- unidades(L), member(X,L).

/*unidades inimigas*/
inimigos([knight, paladin, rifleman, knight, footman]).
unidades_inimigas(X) :- inimigos(L), member(X,L).

/*fatos sobre unidades aliadas*/
tipo(dreadLord, terrestre).
ataca(dreadLord, terrestre,_).
tipo_dano(dreadLord, hero).
tipo_armadura(dreadLord, hero).
dano(dreadLord, 60,_).

tipo(ghoul, terrestre).
ataca(ghoul, terrestre,_).
tipo_dano(ghoul, normal).
tipo_armadura(ghoul, medium).
dano(ghoul, 17,_).

/*fatos sobre unidades inimigas*/
tipo(knight, terrestre).
ataca(knight, terrestre, _).
tipo_dano(knight, normal).
tipo_armadura(knight, heavy).
dano(knight, 43,_).

tipo(paladin, terrestre).
ataca(paladin, terrestre, _).
tipo_dano(paladin, hero).
tipo_armadura(paladin, hero).
dano(paladin, 55,_).

tipo(rifleman, terrestre).
ataca(rifleman, todos, _).
tipo_dano(rifleman, piercing).
tipo_armadura(rifleman, sem).
dano(rifleman, 33,_).

tipo(footman, terrestre).
ataca(footman, terrestre, _).
tipo_dano(footman, normal).
tipo_armadura(footman, heavy).
dano(footman, 17,_).

/*regras*/

pode_atacar(A,B,T) :-
	(ataca(A,todos,T) , tipo(B,_));
	(tipo(B, terrestre), ataca(A,terrestre,T));
	(tipo(B,aereo), ataca(A,aereo,T)).

dano_causado(X,Y,T):-
	pode_atacar(X,Y,T),
	((tipo_dano(X,normal), tipo_armadura(Y,heavy)) -> write_ln('vai causar 75% do dano');
	((tipo_dano(X,normal); tipo_dano(X,piercing)), tipo_armadura(Y,medium)) -> write_ln('vai causar 150% do dano');
	((tipo_dano(X,normal); tipo_dano(X,hero)), tipo_armadura(Y,hero)) -> write_ln('vai causar 100% do dano');
	((tipo_dano(X,normal); tipo_dano(X,hero); tipo_dano(X,magic)), tipo_armadura(Y,sem)) -> write_ln('vai causar 100% do dano');
	((tipo_dano(X,normal); tipo_dano(X,hero)), tipo_armadura(Y,light)) -> write_ln('vai causar 100% do dano');
	((tipo_dano(X,piercing); tipo_dano(X,hero)), tipo_armadura(Y,heavy)) -> write_ln('vai causar 100% do dano');
	(tipo_dano(X,piercing), tipo_armadura(Y,sem)) -> write_ln('vai causar 150% do dano');
	(tipo_dano(X,piercing), tipo_armadura(Y,light)) -> write_ln('vai causar 200% do dano');
	(tipo_dano(X,piercing), tipo_armadura(Y,hero)) -> write_ln('vai causar 50% do dano');
	(tipo_dano(X,hero), tipo_armadura(Y,medium)) -> write_ln('vai causar 100% do dano');
	(tipo_dano(X,magic), tipo_armadura(Y,heavy)) -> write_ln('vai causar 200% do dano');
	(tipo_dano(X,magic), tipo_armadura(Y,medium)) -> write_ln('vai causar 75% do dano');
	((tipo_dano(X,magic); tipo_dano(X,piercing)), tipo_armadura(Y,hero)) -> write_ln('vai causar 50% do dano');
	(tipo_dano(X,magic), tipo_armadura(Y,light))-> write_ln('vai causar 125% do dano')).
/*inicio do combate*/

/*tempo 1*/
hp(knight, 890, 1).
hp(knight, 830, 1).
hp(knight, 770, 1).
hp(rifleman, 503, 1).
hp(ghoul, 275.5, 1).
hp(ghoul, 220.5, 1).
hp(ghoul, 121.5, 1).
hp(ghoul, 57, 1).
hp(ghoul, 31.5, 1).

/*tempo 2*/
hp(knight, 710, 2).
hp(knight, 650, 2).
hp(knight, 590, 2).
hp(rifleman, 486, 2).
hp(ghoul, 0, 2).
hp(dreadLord, 1045, 2).
hp(dreadLord, 1028.5, 2).
hp(dreadLord, 968.3, 2).
hp(dreadLord, 951.3, 2).

/*tempo 3*/
hp(knight, 530, 3).
hp(knight, 470, 3).
hp(knight, 410, 3).
hp(dreadLord, 891.1, 3).
hp(dreadLord, 836.1, 3).
hp(dreadLord, 803.1, 3).
hp(dreadLord, 742.9, 3).
hp(dreadLord, 725.9, 3).

/*tempo 4*/
hp(knight, 350, 4).
hp(knight, 290, 4).
hp(knight, 230, 4).
hp(dreadLord, 665.7, 4).
hp(dreadLord, 610.7, 4).
hp(dreadLord, 577.7, 4).
hp(dreadLord, 517.5, 4).
hp(dreadLord, 500.5, 4).

/*tempo 5*/
hp(knight, 170, 5).
hp(knight, 110, 5).
hp(knight, 50, 5).
hp(dreadLord, 440.3, 5).
hp(dreadLord, 385.3, 5).
hp(dreadLord, 368.8, 5).
hp(dreadLord, 308.6, 5).
hp(dreadLord, 291.6, 5).

/*tempo 6*/
hp(knight, 0, 6).
hp(knight, 0, 6).
hp(knight, 0, 6).
hp(dreadLord, 236.6, 6).
hp(dreadLord, 203.6, 6).
hp(dreadLord, 143.4, 6).
hp(dreadLord, 126.4, 6).

/*tempo 7*/
hp(knight, 890, 7).
hp(knight, 830, 7).
hp(knight, 770, 7).
hp(dreadLord, 71.3999, 7).
hp(dreadLord, 54.8999, 7).
hp(dreadLord, 0, 7).
hp(dreadLord, 1083, 7).

/*tempo 8*/
hp(knight, 710, 8).
hp(knight, 650, 8).
hp(dreadLord, 1028, 8).
hp(dreadLord, 1011.5, 8).
hp(dreadLord, 951.3, 8).
hp(dreadLord, 934.3, 8).

/*tempo 9*/
hp(paladin, 1140, 9).
hp(paladin, 1080, 9).
hp(dreadLord, 879.3, 9).
hp(dreadLord, 846.3, 9).
hp(dreadLord, 786.1, 9).
hp(dreadLord, 769.1, 9).

/*tempo 10*/
hp(knight, 590, 10).
hp(knight, 530, 10).
hp(dreadLord, 714.1, 10).
hp(dreadLord, 681.1, 10).
hp(dreadLord, 620.9, 10).
hp(dreadLord, 603.9, 10).

/*tempo 11*/
hp(knight, 890, 11).
hp(knight, 830, 11).
hp(dreadLord, 543.7, 11).
hp(dreadLord, 488.7, 11).
hp(dreadLord, 472.2, 11).
hp(dreadLord, 412, 11).
hp(dreadLord, 395, 11).

/*tempo 12*/
hp(paladin, 1020, 12).
hp(paladin, 960, 12).
hp(dreadLord, 334.8, 12).
hp(dreadLord, 279.8, 12).
hp(dreadLord, 263.3, 12).
hp(dreadLord, 203.1, 12).
hp(dreadLord, 186.1, 12).

/*tempo 13*/
hp(knight, 770, 13).
hp(knight, 710, 13).
hp(dreadLord, 125.9, 13).
hp(dreadLord, 70.8999, 13).
hp(dreadLord, 37.8999, 13).
hp(dreadLord, 0, 13).
hp(dreadLord, 1083, 13).

/*tempo 14*/
hp(knight, 650, 14).
hp(dreadLord, 1022.8, 14).
hp(dreadLord, 967.8, 14).
hp(dreadLord, 951.3, 14).
hp(dreadLord, 891.1, 14).
hp(dreadLord, 874.1, 14).

/*tempo 15*/
hp(rifleman, 426, 15).
hp(dreadLord, 813.9, 15).
hp(dreadLord, 758.9, 15).
hp(dreadLord, 725.9, 15).
hp(dreadLord, 665.7, 15).
hp(dreadLord, 648.7, 15).

/*tempo 16*/
hp(knight, 590, 16).
hp(dreadLord, 588.5, 16).
hp(dreadLord, 533.5, 16).
hp(dreadLord, 500.5, 16).
hp(dreadLord, 440.3, 16).
hp(dreadLord, 423.3, 16).

/*tempo 17*/
hp(knight, 530, 17).
hp(dreadLord, 363.1, 17).
hp(dreadLord, 308.1, 17).
hp(dreadLord, 291.6, 17).
hp(dreadLord, 231.4, 17).
hp(dreadLord, 214.4, 17).

/*tempo 18*/
hp(rifleman, 366, 18).
hp(dreadLord, 154.2, 18).
hp(dreadLord, 99.1999, 18).
hp(dreadLord, 66.1999, 18).
hp(dreadLord, 5.99992, 18).
hp(dreadLord, 0, 18).

/*resumo das iterações/segundos*/
resumo(1) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('ghoul causou 17.000000 de dano em rifleman'),
	write_ln('knight causou 64.500000 de dano em ghoul'),
	write_ln('paladin causou 55.000000 de dano em ghoul'),
	write_ln('rifleman causou 99.000000 de dano em ghoul'),
	write_ln('knight causou 64.500000 de dano em ghoul'),
	write_ln('footman causou 25.500000 de dano em ghoul').

resumo(2) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('ghoul causou 17.000000 de dano em rifleman'),
	write_ln('knight causou 64.500000 de dano em ghoul'),
	write_ln('um ghoul morreu!'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(3) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(4) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(5) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(6) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('um knight morreu!'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('um knight morreu!'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('um knight morreu!'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(7) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('um dreadLord morreu!'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(8) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(9) :-
	write_ln('dreadLord causou 60.000000 de dano em paladin'),
	write_ln('dreadLord causou 60.000000 de dano em paladin'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(10) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('paladin inimigo reviveu umknight'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(11) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(12) :-
	write_ln('dreadLord causou 60.000000 de dano em paladin'),
	write_ln('dreadLord causou 60.000000 de dano em paladin'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(13) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('um dreadLord morreu!'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(14) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(15) :-
	write_ln('dreadLord causou 60.000000 de dano em rifleman'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(16) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(17) :-
	write_ln('dreadLord causou 60.000000 de dano em knight'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 16.500000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord').

resumo(18) :-
	write_ln('dreadLord causou 60.000000 de dano em rifleman'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('paladin causou 55.000000 de dano em dreadLord'),
	write_ln('rifleman causou 33.000000 de dano em dreadLord'),
	write_ln('knight causou 60.200001 de dano em dreadLord'),
	write_ln('footman causou 17.000000 de dano em dreadLord'),
	write_ln('um dreadLord morreu!').


/*iteração/tempo em que cada unidade morreu*/
morto(ghoul,knight,2).
morto(knight,dreadLord,6).
morto(knight,dreadLord,6).
morto(knight,dreadLord,6).
morto(dreadLord,knight,7).
revivido(knight, 10).
morto(dreadLord,knight,13).
morto(dreadLord,footman,18).
derrota(18).
