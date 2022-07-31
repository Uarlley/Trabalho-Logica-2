#include <bits/stdc++.h>

using namespace std;

int numClasses = 3;
int maxFood = 20;
int numUnidades = 3;

//Estrutura que compoe uma unidade
struct unidade {
	string name;
	float HP;
	int damage;
	string armorType;
	string damageType;
	string tipo;
	string atacks;
	int food;
	bool status = 1;

	void inicializa(string name, float HP, int damage, string armorType, string damageType,string type,
	string atacks, int food){

		this->name = name;
		this->HP = HP;
		this->damage = damage;
		this->armorType = armorType;
		this->damageType = damageType;
		this->tipo = type;
		this->atacks = atacks;
		this->food = food;

	}

	void imprimeDados(){
		cout << "   " << this->name << ":\n";
		cout << "\tVida --> " << this->HP << endl;
		cout << "\tDano --> " << this->damage << endl;
		cout << "\tTipo de Armadura --> " << this->armorType << endl;
		cout << "\tTipo de Dano --> " << this->damageType << endl;
		cout << "\tTipo --> " << this->tipo << endl;
		cout << "\tAtaca --> " << this->atacks << endl;
		cout << "\tFood -->" << this->food << endl;
	}

	void imprimeDadosS(){
		cout << this->name << "\tVida --> " << this->HP << endl;
	}

    bool operator< (const unidade& o) const{
        return  o.status <= status;
    }
};



//Função que retorna o dano causado pelo atacante ao defensor
float danoCausado(unidade atacante, unidade defensor){

	if(atacante.damageType == "normal"){

		if(defensor.armorType == "medium") return atacante.damage*1.5;

		else if(defensor.armorType  == "light") return atacante.damage;

		else if(defensor.armorType  == "hero") return atacante.damage;

		else if(defensor.armorType  == "sem") return atacante.damage;

		else return atacante.damage*0.7;
	}

	else if(atacante.damageType == "piercing"){
		
		if(defensor.armorType == "medium") return atacante.damage*1.5;

		else if(defensor.armorType  == "light") return atacante.damage*2;

		else if(defensor.armorType  == "hero") return atacante.damage*0.5;

		else if(defensor.armorType  == "sem") return atacante.damage*1.5;

		else return atacante.damage;
	}

	else if(atacante.damageType == "magic"){
		
		if(defensor.armorType == "medium") return atacante.damage*0.75;

		else if(defensor.armorType  == "light") return atacante.damage*1.25;

		else if(defensor.armorType  == "hero") return atacante.damage*0.5;

		else if(defensor.armorType  == "sem") return atacante.damage;

		else return atacante.damage*2;
	}

	else{
		
		if(defensor.armorType == "medium") return atacante.damage;

		else if(defensor.armorType  == "light") return atacante.damage;

		else if(defensor.armorType  == "hero") return atacante.damage;

		else if(defensor.armorType  == "sem") return atacante.damage;

		else return atacante.damage;
	}
}


//função que cria uma unidade
unidade criaUnidade(int cls, int t) {
	unidade novaUnidade;int i;
	vector<unidade> todasUnidades;
	if(t==0){
		for(int i = 1;i <= 4; i++){
			cout << i <<  " - ";
			criaUnidade(cls,i).imprimeDados();
			cout << endl;
		}
		cout << "Escolha a unidade:\n";
		cin >> t;
	}
	if (cls == 1) {
		if (t == 1) novaUnidade.inicializa("footman", 420, 17, "heavy", "normal", "terrestre", "terrestre", 2);
		else if (t == 2) novaUnidade.inicializa("rifleman", 520, 33, "sem", "piercing", "terrestre", "todos", 3);
		else if (t == 3) novaUnidade.inicializa("knight", 950, 43, "heavy", "normal", "terrestre", "terrestre", 4);
		else novaUnidade.inicializa("paladin", 1200, 55, "hero", "hero", "terrestre", "terrestre", 6);

	}
	else if (cls == 2){
		if (t == 1) novaUnidade.inicializa("ghoul", 340, 17, "medium", "normal", "terrestre", "terrestre", 2);
		else if (t == 2) novaUnidade.inicializa("abomination", 2000, 40, "medium", "normal", "terrestre", "terrestre", 4);
		else if (t == 3) novaUnidade.inicializa("frostWyrm", 1350, 100, "light", "magic", "aereo", "todos", 8);
		else novaUnidade.inicializa("dreadLord", 1100, 60, "hero", "hero", "terrestre", "terrestre", 6);

	}
	else {
		if (t == 1) novaUnidade.inicializa("archer", 350, 30, "medium", "piercing", "terrestre", "todos", 2);
		else if (t == 2) novaUnidade.inicializa("mountainGiant", 1600, 60, "medium", "normal", "terrestre", "terrestre", 5);
		else if (t == 3) novaUnidade.inicializa("chimera", 1000, 100, "light", "magic", "aereo", "terrestre", 6);
		else novaUnidade.inicializa("demonHunter", 1100, 59, "hero", "hero", "terrestre", "terrestre", 6);

	}
	
	return novaUnidade;
}




//funcao que procura uma unidade com uma armadura especifica em uma lista de unidades
int procuraArmor(vector<unidade> &unidades ,string armor){
	int n = unidades.size();
	for(int i =0; i < n; i++){
		if(unidades[i].armorType == armor && unidades[i].status == 1) return i;
	}
	return -1;
}

//funcao que verifica se uma unidade pode atacar uma outra unidade ou nao
bool podeAtacar(unidade atacante, unidade inimigo){
	if(atacante.atacks == "todos") return true;
	else if (atacante.atacks == "terrestre"){
		
		if(inimigo.tipo == "terrestre") return true;

		else return false;
	}
	else{
		
		if(inimigo.tipo == "terrestre") return false;
		
		else return true;
	}
}

//Função que retorna qual inimigo deve ser atacada por uma unidade
int quemAtacar(unidade unit, vector<unidade> &enemies) {
	int n = enemies.size(), i;

	if(unit.damageType == "normal"){
		
		i = procuraArmor(enemies,"medium");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"sem");
		
		if (i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"leve");

		if (i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"hero");

		if(i == -1|| podeAtacar(unit, enemies[i]) == false)  i = procuraArmor(enemies,"heavy");
				
	}

	else if(unit.damageType == "piercing"){

		
		i = procuraArmor(enemies,"light");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"sem");
		
		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"heavy");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"medium");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false)  i = procuraArmor(enemies,"hero");

	}

	else if(unit.damageType == "magic"){
		
		i = procuraArmor(enemies,"heavy");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"light");
		
		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"sem");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"medium");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false)  i = procuraArmor(enemies,"hero");

	}
	else{
	
		i = procuraArmor(enemies,"heavy");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"light");
		
		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"sem");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false) i = procuraArmor(enemies,"medium");

		if(i == -1 || podeAtacar(unit, enemies[i]) == false)  i = procuraArmor(enemies,"hero");

	}

	return i;
}


//Função que verifica se alguem ja perdeu
bool perdeu(vector<unidade> &unidades){
	int i;
	int n = unidades.size();
	for(i = 0;i < n; i++){
		if(unidades[i].status == 1) return 0;
	}
	return 1;
}

int revive(vector<unidade> &unidades){
	int n = unidades.size(),i;
	for(i = 0; i < n; i++){
		if(unidades[i].status == 0){
			if(unidades[i].name == "footman") unidades[i] = criaUnidade(1,1);
			if(unidades[i].name == "rifleman") unidades[i] = criaUnidade(1,2);
			if(unidades[i].name == "knight") unidades[i] = criaUnidade(1,3);
			unidades[i].status = 1;
			return i;
		}
	}
	return -1;
}

unidade invocaInfernal(){
	unidade infernal;
	infernal.inicializa("infernal",1400,100,"hero","hero","terrestre","terrestre",0);
	return infernal;
}


void imprimeUnidadesS(vector<unidade> &unidades){
	int n = unidades.size();
	for(int i = 0; i < n; i++){
		unidades[i].imprimeDadosS();
		cout << endl;
		//cout << unidades[i].name << "\tVida --> " << unidades[i].HP << endl;
	}
	cout << endl;
}

int encontraUnidade(string nome, vector<unidade> unidades){
	int n, i;
	n = unidades.size();
	for(i = 0;i < n; i++){
		if(unidades[i].name == nome && unidades[i].status == 1) return i;
	}
	return -1;
}
//Função que imprime as unidades de um exercito
void imprimeUnidades(vector<unidade> &unidades){
	int n = unidades.size();
	for(int i = 0; i < n; i++){
		unidades[i].imprimeDados();
		cout << endl;
	}
	cout << endl;
}

int main() {
    srand(clock());
	int i, j, k;
	fstream file;
	string text;
	vector<string> proFinal;
	vector<vector<string>> resumos;
	vector<string> auxResumos;
	vector<unidade> enemies;
	vector<string> tipos;
	vector<string> pode_atacar;
	vector<string> tipo_dano;
	vector<string> tipos_armor;
	vector<string> dano;

	file.open("registro.pl",ios::out);
	file << ":- discontiguous unidades/1, vivo/2, revivido/2, morto/3, tipo/2, ataca/3, tipo_dano/2, tipo_armadura/2, hp/3, dano/3." << endl;
	file << "/* unidades criadas */" << endl;
	vector<unidade>  unidades;
	int armazenamento = 0;

	int food = 0, classe;
	cout << "Escolha uma classe para o inimigo ";
	cin >> classe;
	while(food < maxFood){
		if(food+1 == maxFood) break;
		unidade aux = criaUnidade(classe,0);
		if(food + aux.food > maxFood){
			cout << "Esta unidade não pode ser criada!" << endl;
		}
		else{
			food+= aux.food;
			enemies.push_back(aux);
			cout << "Armazenamento restante : " << maxFood - food << endl;
		}

	}

	imprimeUnidades(enemies);
	i = 0;
	food = 0;
	cout << "Jogador 2: escolha uma classe: ";
	cin >> classe;
	while(food < maxFood){
		if(food+1 == maxFood) break;
		unidade aux = criaUnidade(classe,0);
		if(food + aux.food > maxFood){
			cout << "Esta unidade não pode ser criada!" << endl;
		}
		else{
			food+= aux.food;
			unidades.push_back(aux);
			cout << "Armazenamento restante : " << maxFood - food << endl;
		}

	}
	
	imprimeUnidades(unidades);


	int n = unidades.size();
	file << "unidades([";
	for(i = 0;i < n; i++){
		file << unidades[i].name;
		if(i != n-1) file << ", ";
		text = "tipo(" + unidades[i].name + ", " + unidades[i].tipo + ").";
		auto it = find(tipos.begin(), tipos.end(), text);
		if(it == tipos.end()){
			tipos.push_back(text);
			if(unidades[i].name == "demonHunter"){
				pode_atacar.push_back("ataca(" + unidades[i].name + ",X ,T) :- \n\tT < 15 -> X = terrestre;\n\tX = todos.");
				dano.push_back("dano(" + unidades[i].name + ", X, T) :- \n\tT < 15 -> X is 59;\n\tX is 109.");
			}
			else {
				pode_atacar.push_back("ataca(" + unidades[i].name + ", " + unidades[i].atacks + ",_).");
				dano.push_back("dano(" + unidades[i].name + ", " + to_string(unidades[i].damage) + ",_).");
			}
			tipo_dano.push_back("tipo_dano(" + unidades[i].name + ", " + unidades[i].damageType + ").");
			tipos_armor.push_back("tipo_armadura(" + unidades[i].name + ", " + unidades[i].armorType + ").");
		}
	}
	file << "]).\n";

	file << "minhas_unidades(X) :- unidades(L), member(X,L).\n\n";
	int indiceInimigos = tipos.size();


	file << "/*unidades inimigas*/";
	n = enemies.size();	
	file << "\ninimigos([";
	for(i = 0;i < n; i++){
		file << enemies[i].name;
		if(i != n-1) file << ", ";
		text = "tipo(" + enemies[i].name + ", " + enemies[i].tipo + ").";
		auto it = find(tipos.begin(), tipos.end(), text);
		if(it == tipos.end()){
			tipos.push_back(text);
			if(enemies[i].name == "demonHunter"){
				pode_atacar.push_back("ataca(" + unidades[i].name + ",X ,T) :- \n\tT < 15 -> X = terrestre;\n\tX = todos.");
				dano.push_back(("dano(" + enemies[i].name + ", X ,T) :- \n\tT < 15 -> X = 59;\n\tX = 109."));

			}
			else{
				pode_atacar.push_back("ataca(" + enemies[i].name + ", " + enemies[i].atacks + ", _).");
				dano.push_back("dano(" + enemies[i].name + ", " + to_string(enemies[i].damage) + ",_).");


			}
			tipo_dano.push_back("tipo_dano(" + enemies[i].name + ", " + enemies[i].damageType + ").");
			tipos_armor.push_back("tipo_armadura(" + enemies[i].name + ", " + enemies[i].armorType + ").");
		}
	}
	file << "])." << endl;

	file << "unidades_inimigas(X) :- inimigos(L), member(X,L).\n\n";
	
	file << "/*fatos sobre unidades aliadas*/\n";
	n = tipos.size();
	for(i = 0; i < n; i++){
		if(i == indiceInimigos) file << "/*fatos sobre unidades inimigas*/\n";
		file << tipos[i] << endl;
		file << pode_atacar[i] << endl;
		file << tipo_dano[i] << endl;
		file << tipos_armor[i] << endl;
		file << dano[i] << endl;
		file << endl;
	}

	tipos.clear();
	pode_atacar.clear();
	tipo_dano.clear();
	tipos_armor.clear();
	dano.clear();

	file << "/*regras*/\n";
	file << "\npode_atacar(A,B,T) :-\n\t(ataca(A,todos,T) , tipo(B,_));\n";
	file << "\t(tipo(B, terrestre), ataca(A,terrestre,T));\n";
	file << "\t(tipo(B,aereo), ataca(A,aereo,T)).\n\n";


	file << "dano_causado(X,Y,T):-\n";
	file << "\tpode_atacar(X,Y,T),\n";
	file << "\t((tipo_dano(X,normal), tipo_armadura(Y,heavy)) -> write_ln('vai causar 75% do dano');\n";
	file << "\t((tipo_dano(X,normal); tipo_dano(X,piercing)), tipo_armadura(Y,medium)) -> write_ln('vai causar 150% do dano');\n";
	file << "\t((tipo_dano(X,normal); tipo_dano(X,hero)), tipo_armadura(Y,hero)) -> write_ln('vai causar 100% do dano');\n";
	file << "\t((tipo_dano(X,normal); tipo_dano(X,hero); tipo_dano(X,magic)), tipo_armadura(Y,sem)) -> write_ln('vai causar 100% do dano');\n";
	file << "\t((tipo_dano(X,normal); tipo_dano(X,hero)), tipo_armadura(Y,light)) -> write_ln('vai causar 100% do dano');\n";
	file << "\t((tipo_dano(X,piercing); tipo_dano(X,hero)), tipo_armadura(Y,heavy)) -> write_ln('vai causar 100% do dano');\n";
	file << "\t(tipo_dano(X,piercing), tipo_armadura(Y,sem)) -> write_ln('vai causar 150% do dano');\n";
	file << "\t(tipo_dano(X,piercing), tipo_armadura(Y,light)) -> write_ln('vai causar 200% do dano');\n";
	file << "\t(tipo_dano(X,piercing), tipo_armadura(Y,hero)) -> write_ln('vai causar 50% do dano');\n";
	file << "\t(tipo_dano(X,hero), tipo_armadura(Y,medium)) -> write_ln('vai causar 100% do dano');\n";
	file << "\t(tipo_dano(X,magic), tipo_armadura(Y,heavy)) -> write_ln('vai causar 200% do dano');\n";
	file << "\t(tipo_dano(X,magic), tipo_armadura(Y,medium)) -> write_ln('vai causar 75% do dano');\n";
	file << "\t((tipo_dano(X,magic); tipo_dano(X,piercing)), tipo_armadura(Y,hero)) -> write_ln('vai causar 50% do dano');\n";
	file << "\t(tipo_dano(X,magic), tipo_armadura(Y,light))-> write_ln('vai causar 125% do dano')).\n";
	
	int time = 1, end = false;
	file << "/*inicio do combate*/" << endl;
	while(end == false){
		file << "\n/*tempo " << time << "*/\n";
		cout << "//------------------------- tempo " << time << " ---------------------------------//" << endl << endl;
		int n1 = unidades.size();
		int n2 = enemies.size();
		text = "resumo(" + to_string(time) + ") :-";
		auxResumos.push_back(text);
		for(i = 0; i < n1; i++){
			if(unidades[i].status == 1){
				if(unidades[i].name == "demonHunter" && time == 15){
					unidades[i].damage += 50;
					unidades[i].atacks = "todos";
					unidades[i].HP += 450;
					text = "\twrite_ln('seu demon hunter usou metamophosis')";
					auxResumos.push_back(text);
				}
				
				if(unidades[i].name == "paladin" && time%10 == 0){
					int j = revive(unidades);
					auxResumos.push_back("\twrite_ln('seu paladin reviveu um" + unidades[j].name + "')");
					proFinal.push_back(("revivido(" + unidades[j].name + ", " + to_string(time) + ")."));
				}
					
				if(unidades[i].name == "dreadLord" && time == 19){
					unidades.push_back(invocaInfernal());
					n1++;
					file << "\ntipo(infernal, terrestre).";
					file << "\nataca(infernal, terrestre,_).";
					file << "\ntipo_dano(infernal, hero).";
					file << "\ntipo_armadura(infernal, hero).";
					file << "\ndano(infernal,100,_).";
					auxResumos.push_back("\twrite_ln('seu dread lord invocou um infernal!')");
					file << "\n";
				}
				if(time%3 ==0){
					int un = encontraUnidade("mountainGiant", enemies);
					if(un != -1 && unidades[i].tipo == "terrestre"){
						auxResumos.push_back("\twrite_ln('seu mountain giant forcou o ataque!')");
						k = un;
					}
				}
				else k = quemAtacar(unidades[i], enemies);
				
				if (k != -1){
					float dano = danoCausado(unidades[i], enemies[k]);
					if(unidades[i].name == "rifleman"){
						int chance = rand()%10;
						if(chance <= 4) dano += dano;
					}
					if(enemies[k].name == "mountainGiant") dano -= dano*0.8;
					if(enemies[k].name == "footman" && unidades[i].damageType != "magic") dano-= dano*0.7;
					if(unidades[i].name == "knight" && enemies[k].armorType != "medium") dano += dano*0.4;
					if(enemies[k].name == "archer"){
						int chance = rand()%10;
						if(chance <= 4) dano = 0;
					}
					enemies[k].HP -= dano;
					text = "\twrite_ln(\'" +  unidades[i].name + " causou " + to_string(dano) + " de dano em " + enemies[k].name + "\')" ;
					auxResumos.push_back(text);
					if(enemies[k].HP <= 0){
						if(unidades[i].name == "ghoul") unidades[i].HP += 150;
						enemies[k].HP = 0;
						enemies[k].status = 0;
						text = "morto(" + enemies[k].name + "," + unidades[i].name +"," + to_string(time) + ").";
						proFinal.push_back(text);
						text = "\twrite_ln('um " + enemies[k].name + " morreu!')";
						auxResumos.push_back(text);
					}
					file << "hp(" << enemies[k].name << ", " << enemies[k].HP << ", " << time << ").\n";
				}
			}
			if(perdeu(enemies) == 1){
				text = "vitoria(" + to_string(time) + ").";
				proFinal.push_back(text);
				text = "\twrite('voce venceu!')";
				auxResumos.push_back(text);
				end = true;
				break;
			}
		}
		imprimeUnidadesS(enemies);
		for(i = 0; i < n2; i++){
			if(enemies[i].status == 1){
				if(enemies[i].name == "demonHunter" && time == 15){
					enemies[i].damage += 50;
					enemies[i].atacks = "todos";
					enemies[i].HP += 450;
					text = "\twrite_ln('demon hunter inimigo usou metamophosis')";
					auxResumos.push_back(text);
				}
				
				if(enemies[i].name == "paladin" && time%10 == 0){
					int j = revive(enemies);
					auxResumos.push_back("\twrite_ln('paladin inimigo reviveu um" + enemies[j].name + "')");
					proFinal.push_back(("revivido(" + enemies[j].name + ", " + to_string(time) + ")."));
				}
					

				if(enemies[i].name == "dreadLord" && time == 17){
					enemies.push_back(invocaInfernal());
					n1++;
					file << "\ntipo(infernal, terrestre).";
					file << "\nataca(infernal, terrestre,T).";
					file << "\ntipo_dano(infernal, hero).";
					file << "\ntipo_armadura(infernal, hero).";
					file << "\ndano(infernal,100,T).\n";
					auxResumos.push_back("\twrite_ln('dread lord inimigo invocou um infernal!')");
				}
				if(time%3==0){
					int un = encontraUnidade("mountainGiant", enemies);
					if(un != -1 && enemies[i].tipo == "terrestre"){
						auxResumos.push_back("\twrite_ln('mountain giant  inimigo forcou o ataque!')");
						k = un;
					}
				}
				else k = quemAtacar(enemies[i], unidades);

				float dano = danoCausado(enemies[i], unidades[k]);
				if(enemies[i].name == "rifleman"){
						int chance = rand()%10;
						if(chance <= 4) dano += dano;
				}
				if(unidades[k].name == "mountainGiant") dano -= dano*0.8;
				if(unidades[k].name == "footman" && enemies[i].damageType != "magic") dano-= dano*0.7;
				if(enemies[i].name == "knight" && unidades[k].armorType != "medium") dano += dano*0.4;

				if(unidades[k].name == "archer"){
						int chance = rand()%10;
						if(chance <= 4) dano  = 0;
				}
				unidades[k].HP -= dano;
				text = "\twrite_ln(\'" +  enemies[i].name + " causou " + to_string(dano) + " de dano em " + unidades[k].name + "\')" ;
				auxResumos.push_back(text);
				if(unidades[k].HP <= 0) {
					if(enemies[i].name == "ghoul") enemies[i].HP += 150;
					unidades[k].HP = 0;
					unidades[k].status = 0;
					text = "morto(" + unidades[k].name + "," + enemies[i].name +"," + to_string(time) + ").";
					proFinal.push_back(text);
					text = "\twrite_ln('um " + unidades[k].name + " morreu!')";
					auxResumos.push_back(text);
				}
				file << "hp(" << unidades[k].name << ", " << unidades[k].HP << ", " << time << ").\n";

			}
			if(perdeu(unidades) == 1){
				text = "derrota(" + to_string(time) + ").";
				proFinal.push_back(text);
				text = "\twrite('voce foi derrotado!')";
				end = true;
				break;
			}

		}
		time ++;
		imprimeUnidadesS(unidades);
		resumos.push_back(auxResumos);
		auxResumos.clear();
				
	}
	
	file << "\n/*resumo das iterações/segundos*/" << endl;
	n = resumos.size();
	for(i = 0; i< n; i++){
		int m = resumos[i].size();
		file << resumos[i][0] << endl;
		for(int j = 1; j < m; j++){
			file << resumos[i][j];
			if(j+1 == m) file << "." << endl;
			else file << "," << endl;
		}	
		file << endl;
	}

	file << "\n/*iteração/tempo em que cada unidade morreu*/" << endl;
	n = proFinal.size();
	for(i = 0;i < n; i++){
		file << proFinal[i] << endl;
	}

	
	file.close();
}