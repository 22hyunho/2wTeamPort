#pragma once
#include "singletonBase.h"
#include "Pokemon.h"
#include "PokemonHeader.h"
#include <map>

class pokeDex : public singletonBase<pokeDex>
{
private:
	typedef Pokemon*(pokeDex::*func)();
	typedef map<int, func>		pokemonList;

private:
	pokemonList _pokemonList;

	int _index;

public:
	HRESULT init();
	void release();

	void addPokemon(func f);
	void setPokeDex();

	Pokemon* makePokemon(int num) { return (this->*_pokemonList[num])(); }

	int getIndex() { return _index; }

	//======================== 포켓몬 도감 ========================//
	//No.01 ~ 09
	Pokemon* charmander() { return new Charmander; }
	Pokemon* charmeleon() { return new Charmeleon; }
	Pokemon* charizard() { return new Charizard; }

	Pokemon* pichu() { return new Pichu; }
	Pokemon* pikachu() { return new Pikachu; }
	Pokemon* raichu() { return new Raichu; }

	Pokemon* bulbasaur() { return new Bulbasaur; }
	Pokemon* ivysaur() { return new Ivysaur; }
	Pokemon* venusaur() { return new Venusaur; }


	//No.10 ~ 19
	Pokemon* squirtle() { return new Squirtle; }
	Pokemon* wartortle() { return new Wartortle; }
	Pokemon* blastoise() { return new Blastoise; }

	Pokemon* dratini() { return new Dratini; }
	Pokemon* dragonair() { return new Dragonair; }
	Pokemon* dragonite() { return new Dragonite; }

	Pokemon* zubat() { return new Zubat; }
	Pokemon* golbat() { return new Golbat; }
	Pokemon* crobat() { return new Crobat; }

	Pokemon* darkrai() { return new Darkrai; }


	//N0.20 ~ 29
	Pokemon* eevee() { return new Eevee; }
	Pokemon* vaporeon() { return new Vaporeon; }
	Pokemon* jolteon() { return new Jolteon; }
	Pokemon* flareon() { return new Flareon; }
	Pokemon* espeon() { return new Espeon; }
	Pokemon* umbreon() { return new Umbreon; }

	Pokemon* diglett() { return new Diglett; }
	Pokemon* dugtrio() { return new Dugtrio; }

	Pokemon* lapras() { return new Lapras; }

	Pokemon* mawile() { return new Mawile; }


	//No.30 ~ 39
	Pokemon* lunatone() { return new Lunatone; }
	Pokemon* solrock() { return new Solrock; }

	Pokemon* regirock() { return new Regirock; }
	Pokemon* regice() { return new Regice; }
	Pokemon* registeel() { return new Registeel; }

	Pokemon* makuhita() { return new Makuhita; }
	Pokemon* hariyama() { return new Hariyama; }

	Pokemon* celebi() { return new Celebi; }

	Pokemon* giratina() { return new Giratina; }
};